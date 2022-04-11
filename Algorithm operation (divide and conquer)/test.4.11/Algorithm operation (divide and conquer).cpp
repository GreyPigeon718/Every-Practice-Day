
/*******************************************************************************

  《 算法设计与分析 》课内上机实验题目 - 分治法求解 '找伪币' 问题

   < 作者 >     刘伟

   < 编写日期 >  2016-01-20

   < 版本号 >    v1.0

   < 备注 >     使用标准 C 代码实现

*******************************************************************************/

// 使用的库定义 ...
#include < stdio.h >
#include < stdlib.h >
#include < time.h >

#define ARRAY_SIZE 16
#define TRUE       1
#define FALSE      0

int CallTimes = 0;

// 生成包含 'N' 个硬币重量的数组( 含 1 枚伪币 ), 并返回伪币位置 ...
int CreateRandomCoinWeightArray(int* p, int N)
{
    int i, kt;
    int TrueCoinWeight, FakeCoinWeight;
    int IsStop;

    // 生成随机数种子 ...
    srand((unsigned)time(NULL));

    // 生成随机真币重量值( 在 50 至 100 之间 ) ...
    TrueCoinWeight = 50 + rand() % (100 - 50);

    // 生成随机伪币位置( 在 0 ~ N-1 之间 ) ...
    kt = rand() % N;

    // 设置真币重量 ...
    for (i = 0; i < N; i++)
        if (i != kt)
            *(p + i) = TrueCoinWeight;

    // 生成 1 个比真币略轻的伪币重量值 ...
    IsStop = FALSE;
    while (!IsStop)
    {
        FakeCoinWeight = 50 + rand() % (100 - 50);
        // 设置满足条件的伪币重量值 ...
        if ((TrueCoinWeight > FakeCoinWeight) && (TrueCoinWeight - FakeCoinWeight <= 5))
        {
            IsStop = TRUE;

            *(p + kt) = FakeCoinWeight;
        }
    }

    // 返回伪币位置 ...
    return kt;
}

// 计算数组中硬币重量和 ...
int CalcCoinTotalWeight(int ArrayData[], int kb, int ke)
{
    int i, TotalWeight = 0;

    for (i = kb; i <= ke; i++)
        TotalWeight += ArrayData[i];

    return TotalWeight;
}

// 采用分治法找到伪币( 假定伪币一定存在且只有 1 枚 ) ...
// kb - (子)数组左边界( begin )
// ke - (子)数组右边界( end )
int FindFakeCoin(int ArrayData[], int kb, int ke)
{
    
    int LWeight, RWeight;

    CallTimes++;
    printf("< 第 %d 次查找 > \n", CallTimes);

    // 请将下面的代码补充完毕, 使程序可以正确运行 ...
    // ......
    LWeight = 0;
    RWeight = 0;
    while (kb < ke)
    {
        int mid = (ke - kb) / 2 + kb;
        LWeight = CalcCoinTotalWeight(ArrayData, kb, mid);
        RWeight = CalcCoinTotalWeight(ArrayData, mid+1, ke);
        if (ke - kb == 1)
        {
            if (LWeight > RWeight)
                return kb;
            return ke;
        }

        if (LWeight < RWeight)
        {
            ke = mid;
            return FindFakeCoin(ArrayData, kb, ke);
        }
        if (LWeight > RWeight)
        {
            kb = mid+1;
            return FindFakeCoin(ArrayData, kb, ke);
        }
    }
    return kb;
}

// ####################################################################### //
//                                                                         // 
//                           下面是主程序开始                              // 
//                                                                         // 
// ####################################################################### //

void main(void)
{
    int ArrayData[ARRAY_SIZE];
    int i, k, FakeCoinPos;

    // 生成包含 'N' 个硬币重量的数组( 含 1 枚伪币 ), 并返回伪币位置 ...
    k = CreateRandomCoinWeightArray(ArrayData, ARRAY_SIZE);

    // 输出随机数组内容 ...
    printf("< 生成的硬币重量数组值为( 含 1 枚伪币 ) > : \n");
    for (i = 0; i < ARRAY_SIZE; i++)
        printf("%d\n", ArrayData[i]);
    printf("\n");
    printf("< 第 %d 枚为伪币 > \n", (k + 1));
    printf("\n");

    // 采用分治法找到伪币位置 ...
    FakeCoinPos = FindFakeCoin(ArrayData, 0, ARRAY_SIZE - 1);

    printf("< 找到第 %d 枚为伪币 > \n", (FakeCoinPos + 1));
    printf("\n");

    // 等待用户输入任意一键返回 ...
    system("PAUSE");
}
