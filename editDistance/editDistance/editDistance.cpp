#define _CRT_SECURE_NO_WARNINGS 1

// ######################################################################## //
//
//  本程序使用动态规划法解决 '编辑距离' 问题.
//
//  创建日期: 2016-04-03
//
//  修改记录:
//  ( 1 ) 2016-04-03 创建了初始版本( v0.10 )
//
//  版 本 号: v0.10
//
//  备    注: 使用标准 C 代码实现
//
//  作    者: 刘伟
//
// ######################################################################## //

// EditDistance.cpp : 定义控制台应用程序的入口点。
//

// #include "stdafx.h"

// 使用的库定义
#include < stdio.h >
#include < stdlib.h >
#include < string.h >
#include < iostream >
#include < vector >
#include < algorithm >

// ######################################################################## //
//                                                                          // 
//                              下面是数据定义区                               // 
//                                                                          // 
// ######################################################################## //

#define STR_LEN           100
#define TRUE              1
#define FALSE             0

//////////////////////////////////////////////////////////////////////////////


// ######################################################################## //
//                                                                          // 
//                           下面是各个子函数定义                               // 
//                                                                          // 
// ######################################################################## //

int  FindTripleMin(int a, int b, int c);
int  CalcEditDistance(char* StrA, char* StrB, int** d);
void PrintEditDistanceMatrix(int** d, int RowNum, int ColNum);

// ######################################################################## //
//                                                                          // 
//                          下面是各个子函数的实现                             // 
//                                                                          // 
// ######################################################################## //

// 取 3 个整数中的最小值 ...
int FindTripleMin(int a, int b, int c)
{
	int t = (a < b) ? a : b;

	return ((t < c) ? t : c);
}

// 使用动态规划法计算两个字符串之间的编辑距离及显示 'A -> B' 经过的操作步骤 ...
//
// 测试数据如下 :
// ( 1 ) A = fxpimu  B = xwrs  d( A, B ) = 5
// ( 2 ) A = abc     B = cba   d( A, B ) = 2
// ( 3 ) A = stot    B = stop  d( A, B ) = 1
// ( 4 ) A = cd      B = abcb  d( A, B ) = 3
int CalcEditDistance(char* StrA, char* StrB, int** D)
{
	// 初始化距离矩阵 ...
	for (int i = 0; i <= strlen(StrA); i++)
		D[i][0] = i;

	for (int j = 0; j <= strlen(StrB); j++)
		D[0][j] = j;

	// 请将下面的代码补充完毕, 使程序可以正确运行 ...
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

	// 返回编辑距离值 ...
	return D[strlen(StrA)][strlen(StrB)];
}

// 打印编辑距离矩阵 ...
void PrintEditDistanceMatrix(int** d, int RowNum, int ColNum)
{
	int i, j;

	printf("\t生成的编辑距离矩阵为 : \n");
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
//                             下面是主程序的实现                              // 
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
		// 清屏 ...
		system("cls");

		// 输入字符串 'A' ...
		printf("\n\n\t请输入 < 字符串 A > ， 输入 < q / Q > 表示结束 : ");
		scanf("%s", StrA);
		m = strlen(StrA);
		if (m > 0)
			IsStop = ((StrA[0] == 'q') || (StrA[0] == 'Q'));
		else
			printf("\t输入的字符串 A 不能为空 !\n\n");

		if (!IsStop)
		{
			// 输入字符串 'B' ...
			printf("\n\t请输入 < 字符串 B > ， 输入 < q / Q > 表示结束 : ");
			scanf("%s", StrB);
			n = strlen(StrB);
			if (n > 0)
				IsStop = ((StrB[0] == 'q') || (StrB[0] == 'Q'));
			else
				printf("\t输入的字符串 B 不能为空 !\n\n");

			// 输入的字符串 'A' 和 'B' 均不为空, 则计算其编辑距离 ...
			if (!IsStop)
			{
				// 动态申请二维数组 ...
				d = (int**)malloc((m + 1) * sizeof(int));
				for (i = 0; i <= m; i++)
					d[i] = (int*)malloc((n + 1) * sizeof(int));

				// 计算编辑距离 ...
				dAB = CalcEditDistance(StrA, StrB, d);

				// 显示计算结果 ...
				printf("\n\t< 字符串 A 和 B 之间的编辑距离为：%d > \n\n", dAB);

				// 打印编辑距离矩阵 ...
				PrintEditDistanceMatrix(d, (m + 1), (n + 1));

				// 释放空间 ...
				for (i = 0; i <= m; i++)
					free(d[i]);
				free(d);

				// 等待用户输入任意一键返回 ...
				printf("\n\n");
				system("PAUSE");
			}
		}
	}

	// 等待用户输入任意一键返回 ...
	printf("\n\n");
	system("PAUSE");
}

//////////////////////////////////////////////////////////////////////////////
