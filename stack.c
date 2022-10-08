#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int * arr;
};
int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
            return 1;
        }
        else{
            return 0;
        }
}
 
int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack* ptr, int item){
    if(isFull(ptr)){
        printf("stck is full");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = item;
    }
}
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("stack underflow! can't pop elements");
    }
    else{
        int item = ptr->arr[ptr->top];
        ptr->top--;
        return item;
    }
}
int peek(struct stack* sp,int i){
    int arrayInd = sp->top-i+1;
    if(arrayInd<0){
        printf("not a valid position");
        return -1;
    }
    else{
        return sp->arr[arrayInd];
    }
}
int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
int stackBottom(struct stack* sp)
{
     return sp->arr[0];
}
int main(){
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size =50;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));
    printf("before pushing, Full:%d\n", isFull(sp));
     printf("before pushing, Full:%d\n", isEmpty(sp));
     push(sp, 1);
     push(sp, 41);
     push(sp, 15);
     push(sp, 81);
     push(sp, 91);
     push(sp, 18);
     printf("popped %d from the stack",pop(sp));
     return 0;
}     