
/*
 * queue.c
 *
 *  Created on: feb 6, 2020
 *      Author: hazem ebrahim
 */
#include "qeue.h"

/**************************************************************************
function to create a Queue of given capacity. It initializes size of Queue
parameter : pointer to Queue , size of Queue
return  : void
*****************************************************************************/

 void createQueue(ST_queueInfo* info, uint16_t maxSize){

 info-> capacity = maxSize;
    info->Front = info->Size = 0;
    info->rear = maxSize - 1;
    info->Arr = (sint32_t*) malloc(info->capacity * sizeof(sint32_t));
 }
/**************************************************************************
Function to decide if the Queue is full or not
parameter : pointer to Queue
return   : unsigned char
*****************************************************************************/

uint8_t queueisFull(ST_queueInfo *info){
uint8_t ret=notfull;
if(info->Size == info->capacity){

    ret=full;

}

return ret;
}

/**************************************************************************
Function to decide if the Queue is empty or not
parameter : pointer to stack
return   : unsigned char
*****************************************************************************/


uint8_t queueisEmpty(ST_queueInfo *info){
uint8_t ret=notempty;
if(info->Size==0){

    ret=empty;
}
return ret;
}

/**************************************************************************
Function to add an item to Queue.
parameter : pointer to Queue , data wants to enqueue
return  : void
*****************************************************************************/


void enqueue(ST_queueInfo *info, sint32_t data){
    if(queueisFull(info)==full){
     printf("the queue is full \n");
    }
    else{
 info->rear = (info->rear + 1)%info->capacity;
    info->Arr[info->rear] = data;
    info->Size = info->Size + 1;
    printf("%d enqueued to queue\n", data);
    }
}
/**************************************************************************
Function to remove an item from Queue.
parameter : pointer to Queue
return  : first item enqueued sint32
*****************************************************************************/

sint32_t dequeue(ST_queueInfo *info){
    sint32_t ret=empty;
if(queueisEmpty(info)==empty){
           printf("the queue is empty ");

}
else{
    ret = info->Arr[info->Front];
    info->Front = (info->Front + 1)%info->capacity;
    info->Size = info->Size - 1;

}

return ret;
}


/**************************************************************************
Function to peak a front item from Queue.
parameter : pointer to Queue
return  : front element of queue
*****************************************************************************/



sint32_t front(ST_queueInfo *info)
{
    if (isEmpty(&info))
        {
        }
    return info->Arr[info->Front];
}

