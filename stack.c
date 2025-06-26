#include<stdio.h>
#define true 1
#define false 0
#define MAX 5

struct STACK
{
    int TOS;
    int data[MAX];
};
int isFull(struct STACK*s)
{
    return s->TOS == MAX-1?true:false;
}
int isEmpty(struct STACK*s)
{
    return s->TOS == -1?true:false;
}
void push(struct STACK *s,int element)
{
    // s->TOS +=1;
    // s->data[s->TOS]=element; 
    s->data[++s->TOS]=element; 
}
int pop(struct STACK*s)
{
    return s->data[s->TOS--];
}
int peek(struct STACK*s){
    return s->data[s->TOS];
}

void display(struct STACK *s) {
    printf("Stack elements: ");
    for (int i = 0; i <= s->TOS; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main(){
    int choice,value;
    struct STACK S={-1};//S.TOS=-1
    do{
        printf("\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT\n");
        printf(">");
        scanf("%d",&choice);
        switch(choice){
            case 1 :
            if(isFull(&S))printf("Stack Overflow\n");
            else{
                printf("Enter element :");
                scanf("%d",&value);
                push(&S,value);
                printf("%d was PUSHED\n",value);
            }
            break;

            case 2 :
            if(isEmpty(&S))printf("Stack Underflow\n");
            else printf("%d was POPPED\n",pop(&S));
            break;

            case 3 :
            if(isEmpty(&S))printf("Stack is Empty\n");
            else printf("%d is at the Top\n",peek(&S));
            break;

            case 4 :
            if(isEmpty(&S))printf("Stack is Empty\n");
            else display(&S);
            break;

            case 5 :
            printf("Bye\n");
            break;

            default:
            printf("Enter 1, 2, 3, 4 or 5 only\n");
            break;
        }

    }
    while(choice!=5);
    return 0;
}