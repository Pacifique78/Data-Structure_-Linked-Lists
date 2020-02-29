#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

int arr[MAX_SIZE];
int top=-1;
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
    if(top == MAX_SIZE - 1){
        printf("\nThe stack is full");
        return;
    }
    else{
        int value;
        scanf("%d", &value);
        top = top+1;
        arr[top] = value;
    }
}

pop(){
    if(top == -1){
        printf("\nThere is no element to pop");
        return;
    }
    top = top -1;
}

Top(){
    printf("%d", arr[top]);
}

isEmpty(){
    if(top == -1){
        return 0;
    }
    else{
        return 1;
    }
}

display(){
    int i;
    for(i=0; i<=top; i++){
        printf("%d\t", arr[i]);
    }
}
