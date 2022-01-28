#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENT 200

typedef struct TreeNode {
	int weight;
	char ch;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

typedef struct {
	TreeNode* ptree;
	char ch;
	int key;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}
void init(HeapType* h) {
	h->heap_size = 0;
}
void insert_min_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}
element delete_min_heap(HeapType* h) {
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child <= h->heap_size) && ((h->heap[child].key) > h->heap[child + 1].key))
			child++;
		if (temp.key < h->heap[child].key)break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
TreeNode* make_tree(TreeNode* left, TreeNode* right) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->left = left;
	node->right = right;
	return node;
}
void destroy_tree(TreeNode* root) {
	if (root == NULL)return;
	destroy_tree(root->left);
	destroy_tree(root->right);
	free(root);
}
int is_leaf(TreeNode* root) {
	return !(root->left) && !(root->right);
}
void print_array(int codes[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d", codes[i]);
	printf("\n");
}
void print_codes(TreeNode*root,int codes[], int top) {
	
	if (root->left) {
		codes[top] = 0;
		print_codes(root->left, codes, top + 1);
	}
	if (root->right) {
		codes[top] = 1;
		print_codes(root->right, codes, top + 1);
	}

	if (is_leaf(root)) {
	
		printf("%c: ", root->ch);
		print_array(codes, top);

	}

}
int** m_LUT;
TreeNode* huffman_traversal(TreeNode*node){
	if (node->right != NULL) {
		node = node->right;
		while (node->right != NULL)
			node = node->left;
		    
		return node;
	}
}

void huffman_encoding(char* str,TreeNode* root, int codes[], int top)
{
	
		

	printf("\n* Huffman encoding\n");
	printf("bits stream: ");
	int interval = 0;
	for (int i = 0; i < MAX_ELEMENT; i++)
	{
	
		switch (str[i]) {
		case 'a':
		    
			printf("0");
			interval = interval + 1;
			break;
		case 'b':
		
	
			printf("101");
			interval = interval + 3;
			break;
		case 'c':
		
			printf("1100");
			interval = interval + 3;
			break;
		case 'd':
		
			printf("111");
			interval = interval + 3;
			break;
		case 'e':
		
		
			printf("1101");
			interval = interval + 4;
			break;
		case 'f':
		
			printf("1100");
			interval = interval + 4;
			break;
		default:
			
			break;


		}
	}
	
	printf("total length of bits stream: %d\n", interval);
	



}
//void huffman_decoding(char* str, TreeNode* root, int codes[], int top)
//{

//	char ori[MAX_ELEMENT];

//}
void huffman_tree(int freq[], char ch_list[], int n) {
	int i;
	TreeNode* node, * x;
	HeapType* heap;
	element e, e1, e2;
	int codes[100];
	int top = 0;

	heap = create();
	init(heap);
	for (i = 0; i < n; i++) {
		node = make_tree(NULL, NULL);
		e.ch = node->ch = ch_list[i];
		e.key = node->weight = freq[i];
		e.ptree = node;
		insert_min_heap(heap, e);
	}
	for (i = 1; i < n; i++) {
		e1 = delete_min_heap(heap);
		e2 = delete_min_heap(heap);
		x = make_tree(e1.ptree, e2.ptree);
		e.key = x->weight = e1.key + e2.key;
		e.ptree = x;
		printf("%d+%d->%d\n", e1.key, e2.key,e.key);
		insert_min_heap(heap, e);
	}
	e = delete_min_heap(heap);
	print_codes(e.ptree, codes, top);
	char str[MAX_ELEMENT] = { "abacdebaf" };
	huffman_encoding(str, e.ptree, codes, top);

	destroy_tree(e.ptree);
	free(heap);
}
int main(void) {
	char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int freq[] = { 45, 13, 12, 16, 9, 5 };
	huffman_tree(freq, data, 6);
	char str[MAX_ELEMENT] = { "abacdebaf" };
	
	return 0;

}