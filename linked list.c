#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*h = NULL;
main(){
    int c;
    do{
        printf("\n1.Push\n2.Display\n3.Append\n4.Insert(value)\n5.Insert(at position)\n6.Delete(value)\n7.Delete Even Numbers\n8.Delete Odd Numbers\n9.Find maximum number\n10.Find minimum number\n0.Exit\nMake a choice: ");
        scanf("%d", &c);
        switch(c){
        case 1:
            push();
            break;
        case 2:
            display();
            break;
        case 3:
            append();
            break;
        case 4:
            insert();
            break;
        case 5:
            insertAtPosition();
            break;
        case 6:
            deleteValue();
            break;
        case 7:
            deleteAllEvenNumbers();
            break;
        case 8:
            deleteAllOddNumbers();
            break;
        case 9:
            printf("The maximum number is: %d", findMax());
            break;
        case 10:
            printf("The minimum number is: %d", findMin());
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
push(){
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    printf("\nPlease enter the number to push: ");
    scanf("%d", &p->data);
    p->next = h;
    h = p;
}
display(){
    struct node *p;
    p = h;
    printf("\nThe list contains the following elements: \n");
    while(p != NULL){
        printf("%d\t", p->data);
        p = p->next;
    }
}
append(){
    struct node *p, *q;
    p = (struct node*)malloc(sizeof(struct node));
    printf("\nPlease enter the number to append: ");
    scanf("%d", &p->data);
    p->next=NULL;
    if(h == NULL)
        h = p;
    else{
        q = h;
        while(q->next != NULL)
            q = q->next;
        q->next = p;
    }
}
insert(){
    int num;
    printf("\nPlease enter the number after which we will insert a number: ");
    scanf("%d", &num);
    struct node *p, *q;
    p = (struct node*)malloc(sizeof(struct node));
    printf("\nPlease enter the number to insert into the list: ");
    scanf("%d", &p->data);
    p->next=NULL;
    if(h == NULL)
        h = p;
    else{
        q = h;
        while(q->data != num){
            if(q->next == NULL) {
                printf("\nThe was not found");
                return;
            }
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
    }
}
int counter(){
    struct node *q;
    q = h;
    int count = 0;
    while(q){
        q = q->next;
        count++;
    }
    return count;
}
insertAtPosition(){
    struct node *p, *q;
    p = (struct node*)malloc(sizeof(struct node));
    int position;
    printf("At which position to insert the number: ");
    scanf("%d", &position);
    if(counter() < position-1 || position < 1){
        printf("the position is not available");
        return;
    }
    else{
        printf("The number to be inserted: ");
        scanf("%d", &p->data);
        if(position == 1){
            p->next = h;
            h = p;
            return;
        }
        q = h;
        for(int i = 1; i < position-1; i++){
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
    }
}
deleteValue(){
    struct node *p, *q;
    p = (struct node*)malloc(sizeof(struct node));
    if(h == NULL){
        printf("there is no value in the list");
        return;
    }
    int value;
    printf("\nPlease enter the number to delete from the list: ");
    scanf("%d", &value);
    q = h->next;
    p = h;
    if(h->data == value){
        h = h->next;
        q = NULL;
        return;
    }
    else{
        while(q->data != value){
            if(q->next==NULL){
                printf("the value wasn't found");
                return;
            }
            q = q->next;
            p = p->next;
        }
        p->next = q->next;
    }
}
deletePosition(){
    int position;
    printf("At which position to delete the element: ");
    scanf("%d", &position);
    if(counter() < position){
        printf("The position was not found");
        return;
    }
    struct node *q;
    q = h;
    for(int i=1; i<position; i++){

    }
}
deleteAllEvenNumbers(){
    struct node *q, *p;
    p = h->next;
    q = h;
    if(h == NULL) return;
    else{
        if(h->data % 2 == 0){
            h = h->next;
            deleteAllEvenNumbers();
        }
        else{
            while(p!=NULL){
                if(p->data % 2 == 0){
                    q->next = p->next;
                    p = p->next;
                }
                else{
                    q = q->next;
                    p = p->next;
                }
            }
        }
    }
}
deleteAllOddNumbers(){
    struct node *q, *p;
    p = h->next;
    q = h;
    if(h == NULL) return;
    else{
        if(h->data % 2 != 0){
            h = h->next;
            deleteAllOddNumbers();
        }
        else{
            while(p!=NULL){
                if(p->data % 2 != 0){
                    q->next = p->next;
                    p = p->next;
                }
                else{
                    q = q->next;
                    p = p->next;
                }
            }
        }
    }
}
int findMax(){
    struct node *p;
    int max;
    if(h == NULL){
        printf("There is no element in the list\n");
        return NULL;
    }
    else{
        max = h->data;
        p = h;
        while(p!=NULL){
            if(max < p->data){
                max = p->data;
            }
            p = p->next;
        }
    }
    return max;
}
int findMin(){
    struct node *p;
    int min;
    if(h == NULL){
        printf("There is no element in the list\n");
        return NULL;
    }
    else{
        min = h->data;
        p = h;
        while(p!=NULL){
            if(min > p->data){
                min = p->data;
            }
            p = p->next;
        }
    }
    return min;
}
