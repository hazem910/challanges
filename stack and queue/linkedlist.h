#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef int listkey;

typedef struct ST_node{
	listkey data;
	struct ST_node *nextNode;
}ST_node;

typedef struct ST_list{
	ST_node *head;
	int listSize;
}ST_list;

int isListEmpty(ST_list *List);
char createList(ST_list *List);
int insertToList(ST_list *List, unsigned char position, int data);
int deleteFromList(ST_list *List, unsigned char position, int* data);
ST_node* searchIntoList(ST_list *List, int data);

#endif
