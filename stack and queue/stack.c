#include "stack.h"


/**************************************************************************
function to create a stack of given capacity. It initializes size of stack
parameter : pointer to stack , size of stack
return  : void
*****************************************************************************/

void createStack(ST_stackInfo *info, uint16_t capicity){
info->Size=capicity;
info->stack_pointer=init_stack_pointer;
info->data=(sint32_t *)malloc(sizeof(sint32_t)*capicity);
}

/**************************************************************************
Function to add an item to stack.  It increases stack_pointer by 1
parameter : pointer to stack , data wants to push
return  : void
*****************************************************************************/


void push(ST_stackInfo *info, sint32_t data){
    if(isFull(info)==full){
        printf("the stack is full\n");
    }
    else{
  info->data[++info->stack_pointer] = data;
    printf("%d pushed to stack\n", info->data[info->stack_pointer]);
}
}
/**************************************************************************
Function to remove an item from stack.  It decreases stack_pointer by 1
parameter : pointer to stack
return  : last item in the stack
*****************************************************************************/

sint32_t pop(ST_stackInfo *info){
    sint32_t ret=0;
if(isEmpty(info)==empty){
    printf("the stack is empty \n");
}else{
printf("%d pop from stack \n",info->data[info->stack_pointer]);
ret=info->data[info->stack_pointer--];
}
return ret;
}

/**************************************************************************
Function to decide if the stack is full or not
parameter : pointer to stack
return   : unsigned char 0=(not full) ,1=(full)
*****************************************************************************/


uint8_t isFull(ST_stackInfo* info){
uint8_t ret=notfull;
if(info->stack_pointer==(info->Size-1))
{

    ret=full;
}
return ret;
}

/**************************************************************************
Function to decide if the stack is empty or not
parameter : pointer to stack
return   : unsigned char 0=(not empty) ,1=(empty)
*****************************************************************************/


uint8_t isEmpty(ST_stackInfo* info){
uint8_t ret=notempty;
if(info->stack_pointer==init_stack_pointer){
    ret=empty;
}

return ret;
}

/**************************************************************************
Function to return the top from stack without removing it
parameter : pointer to stack
return   : top of stack sint32_t
*****************************************************************************/

sint32_t peek(ST_stackInfo* info)
{ sint32_t ret=0;
    if (isEmpty(info)){
        printf("the stack is empty \n");
        ret= -1;
        }
        else{
    ret=info->data[info->stack_pointer];
        }
    return ret;
}


