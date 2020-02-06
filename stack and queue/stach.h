#ifndef stack_H__
#define  stack_H__
#include "std_types.h"
#define init_stack_pointer (-1)
#define empty   1
#define notempty 0
#define full  0
#define notfull 1
typedef struct Stack {
    sint32_t stack_pointer;
    uint16_t  Size;
    sint32_t* data;
}ST_stackInfo;



void createStack(ST_stackInfo *info, uint16_t capicity);
void push(ST_stackInfo *info, sint32_t data);
sint32_t  pop(ST_stackInfo *info);
uint8_t isFull(ST_stackInfo* info);
uint8_t isEmpty(ST_stackInfo* info);





#endif // stack_H__
