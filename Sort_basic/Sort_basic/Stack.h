#pragma once
typedef int SDataType;


/*
��̬ջ
#define  MAXSIZE 100
typedef struct Stack
{
	SDataType array[MAXSIZE];
	int top;   // ���ջ��
}Stack;

����ڱ���ʱ��Ҫ�õ�ջ���Լ����Կ��ٶ���һ����̬ջ�����ÿ�������
*/


typedef struct Stack
{
	SDataType* array;
	int capacity;
	int size;  // ջ��Ԫ�صĸ��� ջ��
}Stack;


// ע�⣺ջ��û������λ�õĲ����ɾ������
//      ջ����Ҫ����--����

void StackInit(Stack* ps);

// ��ջ��β��
void StackPush(Stack* ps, SDataType data);

// ��ջ��βɾ
void StackPop(Stack* ps);

// ��ȡջ��Ԫ��
SDataType StackTop(Stack* ps);

// ��ȡջ����ЧԪ�صĸ���
int StackSize(Stack* ps);

// ���ջ�Ƿ�Ϊ��
int StackEmpty(Stack* ps);

// ����ջ
void StackDestroy(Stack* ps);