#include "SList.h"
#include <assert.h>
//����ֵ�����ã�����

//����һ�����
SListNode *BuySListNode(int x) {

	SListNode *res = (SListNode *)malloc(sizeof(SListNode));
	res->data = x;
	res->next = NULL;
	return res;
}

//��ʼ��
void SListInit(SListNode **pphead) {
	*pphead =NULL;

	//*pphead = (SListNode*)malloc(sizeof(SListNode));
	//(*pphead)->data = 0;
	//(*pphead)->next = NULL;
	
}

void SlistDestory(SListNode *phead) {

}

//ͷ��
void SListPushFront(SListNode **pphead,int x) {

	SListNode * tmp;
	tmp = BuySListNode(x);
	tmp->next = *pphead;
	*pphead = tmp;

}
//ͷɾ
void SListPopFront(SListNode **pphead) {
	SListNode * tmp;
	tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;



}
