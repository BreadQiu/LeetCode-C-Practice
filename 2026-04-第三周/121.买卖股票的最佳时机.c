/**
*题目：买卖股票的最佳时机
*日期：2026.4.19
*/
int maxProfit(int* prices, int pricesSize) {
    int ret=0,minPrice=INT_MAX,right;
    for(right=0;right<pricesSize;right++){
        if(minPrice<prices[right]) ret=fmax(ret,prices[right]-minPrice);
        minPrice=fmin(minPrice,prices[right]);
    }
    return ret;
}
