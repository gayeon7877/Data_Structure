#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TABLE_SIZE 13
#define KEY_SIZE 10

typedef struct element{
	
	char key[KEY_SIZE];

}element;

typedef struct ListNode{
	element item;
	ListNode* link;

}ListNode;
ListNode* hash_table[TABLE_SIZE];

int transform(char* key) {
	int number = 0;
	while (*key)
		number += *key++;
	return number;
}

int hash_function(char *key) {
	return transform(key) % TABLE_SIZE;  //key mod TABLE_SIZE
}

#define equal(e1,e2)(!strcmp(e1.key,e2.key))

void hash_chain_add(element item, ListNode* ht[]) {
	int hash_value = hash_function(item.key);
    ListNode* ptr;  
	ListNode* node_before = NULL;
	ListNode* node = ht[hash_value];

	for (; node; node_before=node,node = node->link) {
		if (equal(node->item,item)) {
			fprintf(stderr, "Duplicate search key ");
			return;
		}
	}
	ptr = (ListNode*)malloc(sizeof(ListNode));
	ptr->item = item;
	ptr->link = NULL;
	if (node_before)
		node_before->link = ptr;
	else
		ht[hash_value] = ptr;
}

void hash_chain_search(element item, ListNode* ht[]) {
	ListNode* node;
	int hash_value = hash_function(item.key);
	for (node = ht[hash_value]; node; node = node->link) {
		if (equal(node->item, item)) {
			printf("Search success\n");
			return;
		}
	}
	printf("Search failed\n");
}

void hash_chain_print(ListNode* ht[]) {
	ListNode* node;
	for (int i = 0; i < TABLE_SIZE; i++) {
		printf("[%d]", i);
		for (node = ht[i]; node; node = node->link)
			printf("-> %s", node->item.key);
		printf(" -> null\n");
	}
}

void init_table(ListNode* ht[]) {
	for (int i = 0; i < TABLE_SIZE; i++)
		ht[i] = NULL;
}
void hash_chain_delete(element item, ListNode *ht[])
{
	int hash_value = hash_function(item.key);
	if (ht[hash_value]==NULL)
		return;
	
	ListNode* node = ht[hash_value];
	ListNode* delNode = NULL;
	
	if (equal(node->item, item))
	{
		delNode = ht[hash_value];
		ht[hash_value] = ht[hash_value]->link;
	}
	else
	{
		
		ListNode* next = node->link;
		while (next)
		{
			if (equal(next->item , item))
			{
				node->link = next->link;
				delNode = next;
				break;
			}
			node = next;
			next = node->link;
		}
	}
	free(delNode);
}



void main() {
	element tmp;
	int op;
	init_table(hash_table);
	while (1) {
		printf("Enter the operation to do (0: insert, 1:delete, 2: search, 3:termination):");
		scanf_s("%d", &op);
		if (op == 3)  break;

		printf("Enter the search key:");
		scanf_s("%s", tmp.key, sizeof(tmp.key));
		if (op == 0)
			hash_chain_add(tmp, hash_table);
		else if (op == 1)
			hash_chain_delete(tmp, hash_table);
		else if (op == 2)
			hash_chain_search(tmp, hash_table);
		hash_chain_print(hash_table);
		printf("\n");
	}
}