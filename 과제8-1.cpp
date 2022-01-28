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

// 생성 함수
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}
// 초기화 함수
void init(HeapType* h)
{
	h->heap_size = 0;
}
// 삽입 함수
void insert_min_heap(HeapType* h, element item)
{
	int i;

	 i=++(h->heap_size);
	 h->heap[i] = item;              //새로넣은게 그 부모의 노드보다 작으면
	while ((i!=1) && (item.key <h->heap[i].key)) {
		h->heap[i] = h->heap[i/2]; // 부모에게 새로운 노드를 넣어준다
		i /= 2;
	}
	h->heap[i] = item;
}
// 삭제 함수
element delete_min_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1]; //minheap에서 가장 작은 값
	temp = h->heap[(h->heap_size)--];//minheap에서 가장 큰 값
	parent = 1;
	child = 2;
	while (child <= h->heap_size) //child의 값이 minheap의 범위내에 있을때까지
	{
		if ((child < h->heap_size) &&
			(h->heap[child].key) > h->heap[child + 1].key) //      현재 자식 노드 중에 작은 거 찾는다      
			child++;
		if (temp.key <= h->heap[child].key) break; //만약에 min heap에서 가장 큰 값이 

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
	
	while (child <= h->heap_size) //child의 값이 minheap의 범위내에 있을때까지
	{
		if ((child < h->heap_size) &&
			(h->heap[child].key) > h->heap[child + 1].key) //      현재 자식 노드 중에 작은 거 찾는다      
			child++;
		if (temp.key <= h->heap[child].key) break; //만약에 min heap에서 가장 큰 값이 

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

	while (child <= h->heap_size) //child의 값이 minheap의 범위내에 있을때까지
	{
		if ((child < h->heap_size) &&
			(h->heap[child].key) > h->heap[child + 1].key) //      현재 자식 노드 중에 작은 거 찾는다      
			child++;
		if (temp.key >= h->heap[child].key) break; //만약에 min heap에서 가장 큰 값이 

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