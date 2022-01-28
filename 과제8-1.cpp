#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
typedef struct
{
	int key;
} element;
typedef struct
{
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

// ���� �Լ�
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}
// �ʱ�ȭ �Լ�
void init(HeapType* h)
{
	h->heap_size = 0;
}
// ���� �Լ�
void insert_min_heap(HeapType* h, element item)
{
	int i;

	 i=++(h->heap_size);
	 h->heap[i] = item;              //���γ����� �� �θ��� ��庸�� ������
	while ((i!=1) && (item.key <h->heap[i].key)) {
		h->heap[i] = h->heap[i/2]; // �θ𿡰� ���ο� ��带 �־��ش�
		i /= 2;
	}
	h->heap[i] = item;
}
// ���� �Լ�
element delete_min_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1]; //minheap���� ���� ���� ��
	temp = h->heap[(h->heap_size)--];//minheap���� ���� ū ��
	parent = 1;
	child = 2;
	while (child <= h->heap_size) //child�� ���� minheap�� �������� ����������
	{
		if ((child < h->heap_size) &&
			(h->heap[child].key) > h->heap[child + 1].key) //      ���� �ڽ� ��� �߿� ���� �� ã�´�      
			child++;
		if (temp.key <= h->heap[child].key) break; //���࿡ min heap���� ���� ū ���� 

		h->heap[parent] = h->heap[child];
		parent = child;
		child*= 2;
	}
	h->heap[parent] = temp;
	return item;
}
void heap_increase(HeapType* h, element item) {
	
	int parent = 1;
	int child = 2;
	element temp;
	temp = h->heap[(h->heap_size)];
	if (item.key < h->heap[1].key)
		return;
	
	while (child <= h->heap_size) //child�� ���� minheap�� �������� ����������
	{
		if ((child < h->heap_size) &&
			(h->heap[child].key) > h->heap[child + 1].key) //      ���� �ڽ� ��� �߿� ���� �� ã�´�      
			child++;
		if (temp.key <= h->heap[child].key) break; //���࿡ min heap���� ���� ū ���� 

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = item;

	
}
void heap_decrease(HeapType* h, element item) {
	int i = 1;
	int parent = 1;
	int child = 2;
	element temp;
	temp = h->heap[(h->heap_size)];
	if (item.key > h->heap[h->heap_size].key)
		return;

	while (child <= h->heap_size) //child�� ���� minheap�� �������� ����������
	{
		if ((child < h->heap_size) &&
			(h->heap[child].key) > h->heap[child + 1].key) //      ���� �ڽ� ��� �߿� ���� �� ã�´�      
			child++;
		if (temp.key >= h->heap[child].key) break; //���࿡ min heap���� ���� ū ���� 

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = item;


}
int main(void)
{
	element e1 = { 1 }, e2 = { 2 }, e3 = { 3 }, e4 = { 4 }, e5 = { 5 }, e6 = { 6 }, e7 = { 7 }, e8 = { 8 }, e9 = { 9 };
	
	HeapType* heap;
	element e10 = {0};
	
	heap = create();
	init(heap);

	insert_min_heap(heap, e1);
	insert_min_heap(heap, e2);
	insert_min_heap(heap, e3);
	insert_min_heap(heap, e4);
	insert_min_heap(heap, e5);
	insert_min_heap(heap, e6);
	insert_min_heap(heap, e7);
	insert_min_heap(heap, e8);
	insert_min_heap(heap, e9);
	heap_decrease(heap, e10);
	element show = { 0 };
	for (int i = 0; i < 9; i++) {
		show = delete_min_heap(heap);
		printf("< %d > ", show.key);
	}
	
	free(heap);
	return 0;
}