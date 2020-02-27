#include<stdio.h>
#include<stdlib.h>

int myQueue[10];
int front = -1, rear = -1;
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
    if(rear == 9){
        printf("The queue is full");
        return;
    }
    else{
        int value;
        scanf("%d", &value);
        if(front == -1) front = 0;
        rear++;
        myQueue[rear] = value;
    }
}

dequeue(){
    if(front == -1){
        printf("There is no element in the queue");
        return;
    }
    else{
        if(rear == 0 && front == 0){
            front--;
        }
        for(int i=front; i<rear; i++){
            myQueue[i]=myQueue[i+1];
        }
        rear--;
    }
}
display(){
    for(int i=0; i<=rear; i++){
        printf("%d\t", myQueue[i]);
    }
}
