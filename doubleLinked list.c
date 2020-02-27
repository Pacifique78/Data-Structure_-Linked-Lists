#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next, *previous;
}*h = NULL;
main(){
    int c;
    do{
        printf("\n1.Push\n2.Append\n3.display forward\n4.display backward\n5.delete\n6.insert(after value)\n0.Exit\nMake a choice");
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
    scanf("%d", &num);
    if(h->data==num){
        h = h->next;
        h->previous = NULL;
        free(q);
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
        p = q->next;
        q->previous->next = p;
        p->previous = q->previous;
    }
}
insert(){
    struct node *p, *q, *z;
    p = (struct node*)malloc(sizeof(struct node));
    int num;
    printf("enter the number to search");
    scanf("%d", &num);
    q = h;
    while(q->data != num){
        if(q->next == NULL){
            printf("The number was not found");
            return;
        }
        q = q->next;
    }
    printf("enter to number to add");
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
