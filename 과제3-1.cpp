#include <stdio.h>
#include <stdlib.h>    

typedef int element;
typedef struct DlistNode {
    element data;
    struct DlistNode* llink;
    struct DlistNode* rlink;
}DlistNode;

void dinsert_first_node(DlistNode** phead, element data) {
    DlistNode* new_node;
    new_node = (DlistNode*)malloc(sizeof(DlistNode));
    new_node->data = data;
    new_node->rlink = (*phead)->rlink;
    (*phead)->rlink = new_node;

}
void dinsert_last_node(DlistNode** phead, element data) {
    DlistNode* new_node;
    new_node = (DlistNode*)malloc(sizeof(DlistNode));
    new_node->data = data;
    
    new_node->rlink = (*phead)->rlink;
    (*phead)->rlink = new_node;
    (*phead) = new_node;

  
}
void init(DlistNode* phead) {
    phead->llink = phead;
    phead->rlink = phead;
}
int main()
{
    DlistNode** phead;
    DlistNode* head;
    head = (DlistNode*)malloc(sizeof(struct DlistNode));
    init(head);
    phead = &head;
    head->data = NULL;
    //30->25->20->5->head->10
    dinsert_first_node(phead,5);
    dinsert_last_node(phead,10);
    dinsert_first_node(phead,20);
    dinsert_first_node(phead, 25);
    dinsert_first_node(phead, 30);
    struct DlistNode* curr =(*phead)->rlink;    // ���� ����Ʈ ��ȸ�� �����Ϳ� ù ��° ����� �ּ� ����
    while (curr != NULL)               // �����Ͱ� NULL�� �ƴ� �� ��� �ݺ�
    {
        printf("%d->", curr->data);    // ���� ����� ������ ���
        curr = curr->rlink;
      
    }
    printf("\n");// �����Ϳ� ���� ����� �ּ� ����
    
    return 0;
}
