

}
doubleBound(int i) {
    double surplusWeight = capacity - curWeight;
    double tmpValue = curValue;
    while (i <= n && weight[i] <= surplusWeight) {
        surplusWeight -= weight[i];
        tmpValue += value[i];
        i++;
    }
    说明物品没装完但背包容量装不下下⼀个物品了
        if (i <= n) {//
            tmpValue += (double)value[i] / (double)weight[i] * surplusWeight;
        }
    return tmpValue;
voidbackTracking(int i) {
    if (i > n) {
        if (curValue > bestValue) {
            bestValue = curValue;
        }
        return;
    }
    if (curWeight + weight[i] <= capacity) {
        x[i] = 1;
        curWeight += weight[i];
        curValue += value[i];
        backTracking(i + 1);
        输出叶节点后回溯，直到前⼀个
            祖先节点处，先恢复节点状态，再探索其右⼦树
            curWeight -= weight[i];//
        x[i] = 1
            curValue -= value[i];
    }
    if (Bound(i + 1) > bestValue) {
        x[i] = 0;
        右⼦树搜索完毕后回溯，直到前⼀个
            祖先结点处，搜索其右⼦树
            backTracking(i + 1);//
        x[i] = 1
    }
}