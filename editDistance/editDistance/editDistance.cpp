#define _CRT_SECURE_NO_WARNINGS 1

// ######################################################################## //
//
//  ������ʹ�ö�̬�滮����� '�༭����' ����.
//
//  ��������: 2016-04-03
//
//  �޸ļ�¼:
//  ( 1 ) 2016-04-03 �����˳�ʼ�汾( v0.10 )
//
//  �� �� ��: v0.10
//
//  ��    ע: ʹ�ñ�׼ C ����ʵ��
//
//  ��    ��: ��ΰ
//
// ######################################################################## //

// EditDistance.cpp : �������̨Ӧ�ó������ڵ㡣
//

// #include "stdafx.h"

// ʹ�õĿⶨ��
#include < stdio.h >
#include < stdlib.h >
#include < string.h >
#include < iostream >
#include < vector >
#include < algorithm >

// ######################################################################## //
//                                                                          // 
//                              ���������ݶ�����                               // 
//                                                                          // 
// ######################################################################## //

#define STR_LEN           100
#define TRUE              1
#define FALSE             0

//////////////////////////////////////////////////////////////////////////////


// ######################################################################## //
//                                                                          // 
//                           �����Ǹ����Ӻ�������                               // 
//                                                                          // 
// ######################################################################## //

int  FindTripleMin(int a, int b, int c);
int  CalcEditDistance(char* StrA, char* StrB, int** d);
void PrintEditDistanceMatrix(int** d, int RowNum, int ColNum);

// ######################################################################## //
//                                                                          // 
//                          �����Ǹ����Ӻ�����ʵ��                             // 
//                                                                          // 
// ######################################################################## //

// ȡ 3 �������е���Сֵ ...
int FindTripleMin(int a, int b, int c)
{
	int t = (a < b) ? a : b;

	return ((t < c) ? t : c);
}

// ʹ�ö�̬�滮�����������ַ���֮��ı༭���뼰��ʾ 'A -> B' �����Ĳ������� ...
//
// ������������ :
// ( 1 ) A = fxpimu  B = xwrs  d( A, B ) = 5
// ( 2 ) A = abc     B = cba   d( A, B ) = 2
// ( 3 ) A = stot    B = stop  d( A, B ) = 1
// ( 4 ) A = cd      B = abcb  d( A, B ) = 3
int CalcEditDistance(char* StrA, char* StrB, int** D)
{
	// ��ʼ��������� ...
	for (int i = 0; i <= strlen(StrA); i++)
		D[i][0] = i;

	for (int j = 0; j <= strlen(StrB); j++)
		D[0][j] = j;

	// �뽫����Ĵ��벹�����, ʹ���������ȷ���� ...
	// ......
	for (int i = 1; i <= strlen(StrA); ++i)
	{
		for (int j = 1; j <= strlen(StrB); ++j)
		{
			if (StrA[i - 1] == StrB[j - 1])
				D[i][j] = D[i - 1][j - 1];
			else
				D[i][j] = FindTripleMin( D[i - 1][j], D[i][j - 1], D[i - 1][j - 1]) + 1;
		}
	}

	// ���ر༭����ֵ ...
	return D[strlen(StrA)][strlen(StrB)];
}

// ��ӡ�༭������� ...
void PrintEditDistanceMatrix(int** d, int RowNum, int ColNum)
{
	int i, j;

	printf("\t���ɵı༭�������Ϊ : \n");
	for (i = 0; i <= RowNum - 1; i++)
	{
		printf("\t");
		for (j = 0; j <= ColNum - 1; j++)
			printf("%d ", d[i][j]);
		printf("\n");
	}
	printf("\n\n");
}

//////////////////////////////////////////////////////////////////////////////

// ######################################################################## //
//                                                                          // 
//                             �������������ʵ��                              // 
//                                                                          // 
// ######################################################################## //

void main(void)
{
	char StrA[STR_LEN];
	char StrB[STR_LEN];
	int** d;
	int  i, m, n, dAB;
	int  IsStop;

	IsStop = FALSE;
	while (!IsStop)
	{
		// ���� ...
		system("cls");

		// �����ַ��� 'A' ...
		printf("\n\n\t������ < �ַ��� A > �� ���� < q / Q > ��ʾ���� : ");
		scanf("%s", StrA);
		m = strlen(StrA);
		if (m > 0)
			IsStop = ((StrA[0] == 'q') || (StrA[0] == 'Q'));
		else
			printf("\t������ַ��� A ����Ϊ�� !\n\n");

		if (!IsStop)
		{
			// �����ַ��� 'B' ...
			printf("\n\t������ < �ַ��� B > �� ���� < q / Q > ��ʾ���� : ");
			scanf("%s", StrB);
			n = strlen(StrB);
			if (n > 0)
				IsStop = ((StrB[0] == 'q') || (StrB[0] == 'Q'));
			else
				printf("\t������ַ��� B ����Ϊ�� !\n\n");

			// ������ַ��� 'A' �� 'B' ����Ϊ��, �������༭���� ...
			if (!IsStop)
			{
				// ��̬�����ά���� ...
				d = (int**)malloc((m + 1) * sizeof(int));
				for (i = 0; i <= m; i++)
					d[i] = (int*)malloc((n + 1) * sizeof(int));

				// ����༭���� ...
				dAB = CalcEditDistance(StrA, StrB, d);

				// ��ʾ������ ...
				printf("\n\t< �ַ��� A �� B ֮��ı༭����Ϊ��%d > \n\n", dAB);

				// ��ӡ�༭������� ...
				PrintEditDistanceMatrix(d, (m + 1), (n + 1));

				// �ͷſռ� ...
				for (i = 0; i <= m; i++)
					free(d[i]);
				free(d);

				// �ȴ��û���������һ������ ...
				printf("\n\n");
				system("PAUSE");
			}
		}
	}

	// �ȴ��û���������һ������ ...
	printf("\n\n");
	system("PAUSE");
}

//////////////////////////////////////////////////////////////////////////////
