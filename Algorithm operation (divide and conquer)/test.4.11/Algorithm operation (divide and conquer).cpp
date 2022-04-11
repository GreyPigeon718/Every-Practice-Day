
/*******************************************************************************

  �� �㷨�������� �������ϻ�ʵ����Ŀ - ���η���� '��α��' ����

   < ���� >     ��ΰ

   < ��д���� >  2016-01-20

   < �汾�� >    v1.0

   < ��ע >     ʹ�ñ�׼ C ����ʵ��

*******************************************************************************/

// ʹ�õĿⶨ�� ...
#include < stdio.h >
#include < stdlib.h >
#include < time.h >

#define ARRAY_SIZE 16
#define TRUE       1
#define FALSE      0

int CallTimes = 0;

// ���ɰ��� 'N' ��Ӳ������������( �� 1 öα�� ), ������α��λ�� ...
int CreateRandomCoinWeightArray(int* p, int N)
{
    int i, kt;
    int TrueCoinWeight, FakeCoinWeight;
    int IsStop;

    // ������������� ...
    srand((unsigned)time(NULL));

    // ��������������ֵ( �� 50 �� 100 ֮�� ) ...
    TrueCoinWeight = 50 + rand() % (100 - 50);

    // �������α��λ��( �� 0 ~ N-1 ֮�� ) ...
    kt = rand() % N;

    // ����������� ...
    for (i = 0; i < N; i++)
        if (i != kt)
            *(p + i) = TrueCoinWeight;

    // ���� 1 ������������α������ֵ ...
    IsStop = FALSE;
    while (!IsStop)
    {
        FakeCoinWeight = 50 + rand() % (100 - 50);
        // ��������������α������ֵ ...
        if ((TrueCoinWeight > FakeCoinWeight) && (TrueCoinWeight - FakeCoinWeight <= 5))
        {
            IsStop = TRUE;

            *(p + kt) = FakeCoinWeight;
        }
    }

    // ����α��λ�� ...
    return kt;
}

// ����������Ӳ�������� ...
int CalcCoinTotalWeight(int ArrayData[], int kb, int ke)
{
    int i, TotalWeight = 0;

    for (i = kb; i <= ke; i++)
        TotalWeight += ArrayData[i];

    return TotalWeight;
}

// ���÷��η��ҵ�α��( �ٶ�α��һ��������ֻ�� 1 ö ) ...
// kb - (��)������߽�( begin )
// ke - (��)�����ұ߽�( end )
int FindFakeCoin(int ArrayData[], int kb, int ke)
{
    
    int LWeight, RWeight;

    CallTimes++;
    printf("< �� %d �β��� > \n", CallTimes);

    // �뽫����Ĵ��벹�����, ʹ���������ȷ���� ...
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
//                           ������������ʼ                              // 
//                                                                         // 
// ####################################################################### //

void main(void)
{
    int ArrayData[ARRAY_SIZE];
    int i, k, FakeCoinPos;

    // ���ɰ��� 'N' ��Ӳ������������( �� 1 öα�� ), ������α��λ�� ...
    k = CreateRandomCoinWeightArray(ArrayData, ARRAY_SIZE);

    // �������������� ...
    printf("< ���ɵ�Ӳ����������ֵΪ( �� 1 öα�� ) > : \n");
    for (i = 0; i < ARRAY_SIZE; i++)
        printf("%d\n", ArrayData[i]);
    printf("\n");
    printf("< �� %d öΪα�� > \n", (k + 1));
    printf("\n");

    // ���÷��η��ҵ�α��λ�� ...
    FakeCoinPos = FindFakeCoin(ArrayData, 0, ARRAY_SIZE - 1);

    printf("< �ҵ��� %d öΪα�� > \n", (FakeCoinPos + 1));
    printf("\n");

    // �ȴ��û���������һ������ ...
    system("PAUSE");
}
