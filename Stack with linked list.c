#include<stdio.h>
#include<stdlib.h>>

struct node{
    int data;
    struct node *next;
}*top = NULL;

main(){
    int choice;
    do{
        printf("\nPress\n1.To Push\n2.Pop\n3.To Top\n4.To Display\n0.To exit\n");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            Top();
            break;
        case 4:
            display();
            break;
        case 0:
            printf("Bye");
            break;
        default:
            printf("Wrong choice please try again");
            break;
        }
    }while(choice != 0);
}
push(){
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &p->data);
    p->next = top;
    top = p;
}

pop(){
    if(top == NULL){
        printf("\nThere is no element to pop");
        return;
    }
    top = top->next;
}

Top(){
    if(top == NULL) printf("The stack is empty");
    else printf("%d", top->data);
}

display(){
    while(top !=NULL){
        Top();
        printf("\t");
        pop();
    }
}
