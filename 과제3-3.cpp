#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define TRUE 1
#define FALSE 0
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;
typedef struct {
	ListNode* head;// Head pointer
	ListNode* tail;// Tail pointer
	int length;// # of nodes

} ListType;
ListType list1;
int is_empty(ListType* list)
{
	if (list->head == NULL) return 1;
	else return 0;
}
int get_length(ListType* list)
{
	return list->length;
}

void init(ListType* list1) {
	list1->length = 0;
	list1->head = NULL;
	list1->tail = NULL;


}
ListNode* add_first(ListType* list1, element data) {
	ListNode* new_node;
	new_node = (ListNode*)malloc(sizeof(ListNode));
	
	new_node->data = data;
	new_node->link = list1->head;
	list1->head = new_node;
	return new_node;
	list1->length++;
}
void insert_last(ListNode** phead, ListNode* node)
{
	if (*phead == NULL) {
		*phead = node;
		node->link = node;
	}
	else {
		node->link = (*phead)->link;
		(*phead)->link = node;

	}
}

void add_last(ListType* list1, int data) {
	ListNode* new_node;
	new_node = (ListNode*)malloc(sizeof(ListNode));
	new_node->data = data;
	insert_last(&(list1->head), new_node);
	list1->length++;
	}
void error(char* str)
{
	printf("%s\n", str);
	exit(1);
}

int is_in_list(ListType* list1, element item)
{
	ListNode* p;
	p = list1->head;
	while ((p != NULL)) {
		if (p->data == item)
			break;
		p = p->link;
	}
	if (p == NULL) return FALSE;
	else return TRUE;
}
ListNode* get_node_at(ListType* list1, int pos)
{
	int i;
	ListNode* tmp_node = list1->head;
	if (pos < 0) return NULL;
	for (i = 0; i < pos; i++)
		tmp_node = tmp_node->link;
	return tmp_node;
}

element get_entry(ListType* list, int pos)
{
	ListNode* p;
	if (pos >= list->length) return 0;
		p = get_node_at(list, pos);
	return p->data;
}

void display(ListType* list1) {
	for (ListNode* p = list1->head; p != NULL; p = p->link)
		printf("%d->", p->data);
}
void remove_node(ListNode** phead, ListNode* p, ListNode* removed)
{
	if (p == NULL)
		*phead = (*phead)->link;
	else
		p->link = removed->link;
	free(removed);
}
void insert_node(ListNode** phead, ListNode* p, ListNode* new_node)
{
	if (*phead == NULL) { // 공백리스트인 경우
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) { // p가 NULL이면 첫번째 노드로 삽입
		new_node->link = *phead;
		*phead = new_node;
	}
	else {    // p 다음에 삽입
		new_node->link = p->link;
		p->link = new_node;
	}
}
void add(ListType* list, int position, element data)
{
	ListNode* p;
	if ((position >= 0) && (position <= list->length)) {
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		//if (node == NULL) error("메모리 할당에러");
		node->data = data;
		p = get_node_at(list, position - 1);
		insert_node(&(list->head), p, node);
		list->length++;
	}
}

void deletee(ListType* list1, int pos)
{
	if (!is_empty(list1) && (pos >= 0) && (pos < list1->length)) {
		ListNode* p = get_node_at(list1, pos - 1);
		ListNode* removed = get_node_at(list1, pos);
		remove_node(&(list1->head), p, removed);
		list1->length--;
	}
}
element delete_first(ListType* list1) {

	ListNode* temp = list1->head;
	element data;
	if (is_empty(list1)) {
		exit(1);
	}
	else {
		data = temp->data;
		list1->head = list1->head->link;
		if (list1->head == NULL)
			list1->tail = NULL;
		free(temp);
		return data;
	}
}
void delete_pos(ListType* list1, int pos) {
	ListNode* p = get_node_at(list1, pos - 1);
	remove_node(&(list1->head), p, (p != NULL) ? p->link : NULL);
	list1->length--;
}


void delete_last(ListType* list1) {
	delete_pos(list1, get_length(list1));


}
int main() {
	ListType list1;

	init(&list1);
	add_first(&list1, 20);
	add_last(&list1, 30);
	display(&list1);
	printf("\n");
	add_first(&list1, 10);
	add_last(&list1, 40);
	add(&list1, 2, 70);
	display(&list1);
	printf("\n");
	deletee(&list1, 2);
	delete_first(&list1);
	delete_last(&list1);
	display(&list1);
	printf("\n");
	printf("%s\n", is_in_list(&list1, 20) == TRUE ? "TRUE" : "FALSE");
	printf("%d\n", get_entry(&list1, 0));
}