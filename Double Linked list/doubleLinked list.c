#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next, *previous;
}*h = NULL;
main(){
    int c;
    do{
        printf("\n1.Push\n2.Append\n3.display forward\n4.display backward\n5.delete\n6.insert(after value)\n7.insert(at a position)\n8.Delete Even Numbers\n9.Find maximum number\n0.Exit\nMake a choice: ");
        scanf("%d", &c);
        switch(c){
        case 1:
            push();
            break;
        case 2:
            append();
            break;
        case 3:
            display_forward();
            break;
        case 4:
            display_backward();
            break;
        case 5:
            delete();
            break;
        case 6:
            insert();
            break;
        case 7:
            insertAtPosition();
            break;
        case 8:
            deleteEvenNumbers();
            break;
        case 9:
            findMax();
            break;
        case 0:
            printf("bye");
            break;
        default:
            printf("you made a wrong choice");
            break;
        }
    }while(c!=0);
}
display_forward(){
    struct node *p;
    p = h;
    while(p){
        printf("\t%d", p->data);
        p=p->next;
    }
}
display_backward(){
    struct node *p;
    if(h == NULL){
        return;
    }
    p = h;
    while(p->next)
        p=p->next;
    while(p){
        printf("\t%d", p->data);
        p=p->previous;
    }
}
push(){
    struct node *p, *q;
    p = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &p->data);
    if(h==NULL){
        p->next = p->previous = NULL;
        h = p;
    }else{
        p->next =h;
        h->previous = p;
        h = p;
    }
}
append(){
    struct node *p, *q;
    p = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &p->data);
    if(h==NULL){
        p->next = p->previous = NULL;
        h = p;
    }else{
        q = h;
        while(q->next)
            q = q->next;
        p->next=NULL;
        q->next=p;
        p->previous=q;
    }

}
delete(){
    int num;
    struct node *p, *q;
    printf("\nEnter the number to delete: ");
    scanf("%d", &num);
    if(!h){
        printf("\nThe list is empty: ");
        return;
    }
    if(h->data==num){
        if(!h->next){
            h=NULL;
            return;
        }
        h = h->next;
        h->previous = NULL;
        free(q);
        return;
    }
    else{
        q = h;
        while(q->data!=num){
            if(!q->next){
                printf("The number was not found");
                return;
            }
            q = q->next;
        }
        if(q->next == NULL){
            q->previous->next = NULL;
            q->previous = NULL;
        }
        else{
            p = q->next;
            q->previous->next = p;
            p->previous = q->previous;
        }
    }
}
insert(){
    struct node *p, *q, *z;
    p = (struct node*)malloc(sizeof(struct node));
    int num;
    printf("enter the number to search: ");
    scanf("%d", &num);
    q = h;
    while(q->data != num){
        if(q->next == NULL){
            printf("The number was not found");
            return;
        }
        q = q->next;
    }
    printf("enter to number to add: ");
    scanf("%d", &p->data);
    if(q->next == NULL){
        q->next=p;
        p->previous=q;
        p->next = NULL;
    }
    else{
        z = q->next;
        p->next=q->next;
        z->previous=p;
        p->previous=q;
        q->next=p;
    }
}
int counter(){
    int count=0;
    struct node *q;
    if(h == NULL){
        return 0;
    }
    q = h;
    while(q){
        count ++;
        q = q->next;
    }
    return count;
}
insertAtPosition(){
    struct node *p, *q;
    p = (struct node*) malloc(sizeof(struct node));
    int position;
    printf("After which position do want to add: ");
    scanf("%d", &position);
    if(h==NULL){
        printf("Number to add: ");
        scanf("%d", &p->data);
        p->next=p->previous = NULL;
        h=p;
    }
    else{
        if(position-1 > counter() || position < 1){
            printf("The position you have chosen does exist");
            return;
        }
        else{
            q = h;
            printf("\nEnter the number to add: ");
            scanf("%d", &p->data);
            if(position == 1){
                p->next=q;
                q->previous=p;
                p->previous=NULL;
                h=p;
            }
            else{
                for(int i=1; i<position-1; i++){
                    q = q->next;
                }
                if(!q->next){
                    q->next = p;
                    p->previous = q;
                    p->next = NULL;
                    return;
                }
                p->next = q->next;
                q->next->previous = p;
                q->next = p;
                p->previous = q;
            }
        }
    }
}
deleteEvenNumbers(){
    struct node *p, *q, *z;
    if(h==NULL) return;
    else{
        if(h->data%2 == 0){
            h = h->next;
            h->previous = NULL;
            deleteEvenNumbers();
            return;
        }
        else{
            p = h;
            q = h->next;
            while(q!=NULL){
                if(q->data%2 == 0){
                    if(q->next == NULL){
                        p->next=NULL;
                        q->previous = NULL;
                        return;
                    }
                    z = q->next;
                    p->next = q->next;
                    z->previous = p;
                    q = q->next;
                }
                p = p->next;
                q = q->next;
            }
        }
    }
}
findMax(){
    struct node *q;
    if(h == NULL) return;
    else{
        int max = h->data;
        q = h;
        while(q != NULL){
            if(max<q->data){
                max = q->data;
            }
            q = q->next;
        }
        printf("\nThe maximum number is %d", max);
    }
}
