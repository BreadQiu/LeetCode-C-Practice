/**
*题目：按策略买卖股票的最佳时机
*日期：2026.5.11
*/
long long maxProfit(int* prices, int pricesSize, int* strategy, int strategySize, int k) {
    long long tmp=0;
    int i;
    for(i=0;i<pricesSize;i++){
        tmp+=strategy[i]*prices[i];
    }
    long long ret=tmp;
    for(i=0;i<k/2;i++){
        tmp+=(0-strategy[i])*prices[i];
    }
    for(;i<k;i++){
        tmp+=(1-strategy[i])*prices[i];
    }
    ret=fmax(ret,tmp);
    for(;i<pricesSize;i++){
        tmp+=(strategy[i-k]-0)*prices[i-k];
        tmp+=(0-1)*prices[i-k/2];
        tmp+=(1-strategy[i])*prices[i];
        ret=fmax(ret,tmp);
    }
    return ret;
}
