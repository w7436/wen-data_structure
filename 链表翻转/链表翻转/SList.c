#include "SList.h"
#include <assert.h>
//返回值的作用：报错

//创建一个结点
SListNode *BuySListNode(int x) {

	SListNode *res = (SListNode *)malloc(sizeof(SListNode));
	res->data = x;
	res->next = NULL;
	return res;
}

//初始化
void SListInit(SListNode **pphead) {
	*pphead =NULL;

	//*pphead = (SListNode*)malloc(sizeof(SListNode));
	//(*pphead)->data = 0;
	//(*pphead)->next = NULL;
	
}

void SlistDestory(SListNode *phead) {

}

//头插
void SListPushFront(SListNode **pphead,int x) {

	SListNode * tmp;
	tmp = BuySListNode(x);
	tmp->next = *pphead;
	*pphead = tmp;

}
//头删
void SListPopFront(SListNode **pphead) {
	SListNode * tmp;
	tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;



}
