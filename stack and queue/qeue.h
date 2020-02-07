/*
 * queue.h
 *
 *  Created on: feb 6, 2020
 *      Author: hazem ebrahim
 */



#include "std_types.h"


typedef struct Queue
{
     uint16_t Front, rear, Size;
    uint16_t capacity;
    sint32_t* Arr;
}ST_queueInfo;

    void createQueue(ST_queueInfo* info, uint16_t maxSize);
	void enqueue(ST_queueInfo *info, sint32_t data);
	sint32_t dequeue(ST_queueInfo *info);
    uint8_t queueisFull(ST_queueInfo *info);
    uint8_t queueisEmpty(ST_queueInfo *info);
    sint32_t Front(ST_queueInfo *info);

