#pragma once
#define MAXSIZE 20
#include<stdio.h>
//线性表：是N个具有相同特性的数据元素的有限序列


////静态
//typedef struct {
//	int data[MAXSIZE];
//	int length;
//}SqList;

//动态
typedef struct {
	int *array;
	int capacity;//总容量
	int size;
}SqList;


void SqListInit(SqList *p);
void SqListdestroy(SqList *P);
void SqListPushBack(SqList *p, int data);
