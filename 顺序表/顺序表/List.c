#include "Sqlist.h"
#include <assert.h>


//初始化顺序表

void SeqListInit(SqList *ps)
{
	//多多使用assert断言，以防程序出现不可测得问题
	assert(ps != NULL);
	//将顺序表中的数组进行赋值
	memset(ps->data, 0x00, MAXSIZE * sizeof(int));
	// 顺序表中的有效元素初始为0
		ps->size = 0;
}
	
void SeqListPrint(SeqList *ps)
{
	assert(ps != NULL);
	//使用for循环依次打印所有的有效元素的个数
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d->", ps->data[i]);
	}
	printf("NULL\n");




////初始化顺序表
//void SqListInit(SqList *p) {
//	assert(p!=NULL);
//	p->array = (int *)malloc(sizeof(int)*p->capacity);
//	p->capacity = 10;
//	p->size = 0;
//}
//
////销毁顺序表
//void SqListdestroy(SqList *p) {
//	assert(p != NULL);
//	assert(p->capacity != NULL);
//	free(p->capacity);
//}
//

//尾插
//void SqListPushBack(SqList *p, int data) {
//	assert(p!=NULL);
//	assert(p->array!=NULL);
//
//	p->array[p->size] = data;
//	p->size++;
//}
////头插
//void SqListPopPush(SqList *p, int data) {
//	assert(p != NULL);
//	assert(p->array != NULL);
//
//	for (int i = p->size; i >= 1;i--) {
//		p->array[i] = p->array[i-1];
//	}
//	p->array[0] = data;
//	p->size++;
//}
//
////头删
//void SqListPopFront(SqList *p) {
//	assert(p != NULL);
//	assert(p->array != NULL);
//
//	for (int i = 0; i < p->size;i++) {
//		p->array[i] = p->array[i + 1];
//	}
//	p->size--;
//}
////尾删
//void SqListPopBack(SqList *p) {
//	assert(p != NULL);
//	assert(p->array != NULL);
//
//	p->size--;
//
//}
////任意位置的插入
//void SeqListInsert(SqList *p, int pos, int data) {
//	assert(p != NULL);
//	assert(p->array != NULL);
//
//	if (pos>p->capacity) {
//		return;
//	}
//	for (int i = pos ; i <= p->size;i++) {
//		p->array[i] = p->array[i-1];
//	}
//	p->array[pos - 1] = data;
//	p->size++;
//
//}
