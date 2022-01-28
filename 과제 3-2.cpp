#include<stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;
ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;

}
void print_list(ListNode* p) {
	while (p->link!= NULL) {
		printf("%d ", p->link->data);
		p = p->link;
	}
	printf("\n");
}
ListNode*concat_list(ListNode*A, ListNode* B) {
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	
	ListNode* C= head;

	A = A->link;
	B = B->link;

	while (A != NULL && B != NULL) {
		if (A->data <= B->data) {
			C->link = A;
			A = A->link;
		}
		else {
			C->link = B;
			B = B->link;
		}
		C = C->link;
	}
	if (A!= NULL)
		C->link = A;
	if (B!= NULL)
		C->link = B;
	return head;
}
int main(void) {
	ListNode* A = NULL;
	ListNode* B = NULL;
	A= insert_first(A, 25);
	A= insert_first(A, 20);
	A = insert_first(A, 15);
	A = insert_first(A, 10);
	A = insert_first(A, 5);
	A = insert_first(A, 2);
	A = insert_first(A, 1);
	print_list(A);

	B = insert_first(B, 30);
	B = insert_first(B, 18);
	B = insert_first(B, 15);
	B = insert_first(B, 8);
	B = insert_first(B, 7);
	B = insert_first(B, 3);
	print_list(B);
	ListNode* C= concat_list(A, B);
	print_list(C);
	return 0;
}