#include "Sqlist.h"
#include <assert.h>


//��ʼ��˳���
void SqListInit(SqList *p) {
	assert(p!=NULL);
	p->array = (int *)malloc(sizeof(int)*p->capacity);
	p->capacity = 10;
	p->size = 0;
}

//����˳���
void SqListdestroy(SqList *p) {
	assert(p != NULL);
	assert(p->capacity != NULL);
	free(p->capacity);
}

//β��
void SqListPushBack(SqList *p, int data) {
	assert(p!=NULL);
	assert(p->array!=NULL);

	p->array[p->size] = data;
	p->size++;
}
//ͷ��
void SqListPopPush(SqList *p, int data) {
	assert(p != NULL);
	assert(p->array != NULL);

	for (int i = p->size; i >= 1;i--) {
		p->array[i] = p->array[i-1];
	}
	p->array[0] = data;
	p->size++;
}

//ͷɾ
void SqListPopFront(SqList *p) {
	assert(p != NULL);
	assert(p->array != NULL);

	for (int i = 0; i < p->size;i++) {
		p->array[i] = p->array[i + 1];
	}
	p->size--;
}
//βɾ
void SqListPopBack(SqList *p) {
	assert(p != NULL);
	assert(p->array != NULL);

	p->size--;

}
//����λ�õĲ���
void SeqListInsert(SqList *p, int pos, int data) {
	assert(p != NULL);
	assert(p->array != NULL);

	if (pos>p->capacity) {
		return;
	}
	for (int i = pos ; i <= p->size;i++) {
		p->array[i] = p->array[i-1];
	}
	p->array[pos - 1] = data;
	p->size++;

}
