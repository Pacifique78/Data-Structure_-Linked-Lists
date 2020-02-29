#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*front = NULL;

main(){
    int choice;
    do{
        printf("\nPlease enter your choice: ");
        printf("\n1.To Enqueue(add an element in the queue)\n2.To Dequeue(remove an element in the queue)\n3.To Display\n0.To Exit\n");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 0:
            printf("Bye");
            break;
        default:
            printf("Wrong choice, Please choose again");
            break;
        }
    }while(choice != 0);
}

enqueue(){
    struct node *p, *q;
    p = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &p->data);
    p->next = NULL;
    if(front == NULL){
        front = p;
    }
    else{
        q = front;
        while(q->next != NULL)
            q = q->next;
        q->next = p;
    }
}

dequeue(){
    if(front == NULL){
        printf("There is no element in the queue");
        return;
    }else{
        front = front->next;
    }
}
display(){
    struct node *q;
    q = front;
    while(q != NULL){
        printf("%d\t", q->data);
        q = q->next;
    }
}

