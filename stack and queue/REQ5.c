
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int isListEmpty(ST_list *list){
	return (list->listSize == 0);
}

char createList(ST_list *list){
	list->head = NULL;
	list->listSize = 0;
	return list->listSize;
}

int insertToList(ST_list *list, unsigned char position, int data){
	ST_node *ptr, *q;
	int i;
	if((ptr = (ST_node *) malloc(sizeof(ST_node)))){
		ptr->data = data;
		ptr->nextNode = NULL;
		if(position == 0){
			ptr->nextNode = list->head;
			list->head = ptr;
		}
		else{
			for(q=list->head, i=0;i<position-1;i++)
				q=q->nextNode;
			ptr->nextNode = q->nextNode;
			q->nextNode = ptr;
		}
		list->listSize++;
		return 1;
	}
	else
		return 0;
}

int deleteFromList(ST_list *list, unsigned char position, int* data){
	ST_node *ptr, *q;
	int i;
	if(position >= list->listSize)
		return 0;
	else{
		if(position == 0){
			*data = list->head->data;
			q = list->head->nextNode;
			free(list->head);
			list->head = q;
		}
		else{
			for(q=list->head, i=0;i<position-1;i++)
				q = q->nextNode;
			*data = q->nextNode->data;
			ptr = q->nextNode->nextNode;
			free(q->nextNode);
			q->nextNode = ptr;
		}
	}
	list->listSize--;
	return 1;
}

ST_node* searchIntoList(ST_list *list, int data){
	ST_node *ptr;
	ptr = list->head;
	while(ptr != NULL){
		if(ptr->data == data)
			return ptr;
		ptr = ptr->nextNode;
	}
	return 0;
}
