// linked_stack.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef int element;

typedef struct DlistNode {
	element data;
	struct DlistNode *llink;
	struct DlistNode* rlink;
	
} DlistNode;
void error(const char* message) {
	fprintf(stderr, "%s", message);
}
typedef struct {
	DlistNode *top;
	DlistNode* tail;
} DLinkedStackType;


void init(DLinkedStackType *s)
{
	s->top= NULL;
    s->tail=NULL;
	
}

int is_empty(DLinkedStackType *s)
{
	return (s->top == NULL);
}
DlistNode* create_Node(DlistNode* llink, element item, DlistNode* rlink) {
	DlistNode* node = (DlistNode*)malloc(sizeof(DlistNode));
	if (node == NULL)error("Memory allocation error");
	node->llink=llink;
	node->data = item;
	node->rlink = rlink;
	return node;
}
void push(DLinkedStackType *s, element item)
{
	DlistNode *temp = create_Node(s->tail,item,s->top);
	if (is_empty(s))
		s->tail = temp;
	else
		s->top->llink = temp;
	s->top = temp;
}

element pop(DLinkedStackType *s)
{
	element item; 
	DlistNode* removed_node;
	if (is_empty(s)) printf("DLinkedStack is empty\n");
	else {
		removed_node = s->top;
		item = removed_node->data;
		s->top = s->top->rlink;
		free(removed_node);
		if (s->top == NULL)
			s->tail = NULL;
		else
			s->tail->llink = NULL;
	}
	return item;
}

element peek(DLinkedStackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {		
		return s->top->data;
	}
}

void main()
{
	DLinkedStackType s;
	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
}




