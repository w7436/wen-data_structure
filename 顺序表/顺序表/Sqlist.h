#pragma once
#define MAXSIZE 20
#include<stdio.h>
//���Ա���N��������ͬ���Ե�����Ԫ�ص���������


////��̬
//typedef struct {
//	int data[MAXSIZE];
//	int length;
//}SqList;

//��̬
typedef struct {
	int *array;
	int capacity;//������
	int size;
}SqList;


void SqListInit(SqList *p);
void SqListdestroy(SqList *P);
void SqListPushBack(SqList *p, int data);
