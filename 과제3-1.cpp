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
    struct DlistNode* curr =(*phead)->rlink;    // 연결 리스트 순회용 포인터에 첫 번째 노드의 주소 저장
    while (curr != NULL)               // 포인터가 NULL이 아닐 때 계속 반복
    {
        printf("%d->", curr->data);    // 현재 노드의 데이터 출력
        curr = curr->rlink;
      
    }
    printf("\n");// 포인터에 다음 노드의 주소 저장
    
    return 0;
}
