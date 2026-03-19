/**
*题目：使用最小花费爬楼梯
*日期：2026.3.12
*/
int minCostClimbingStairs(int* cost, int costSize) {
    int i,record[costSize+1];
    record[0]=cost[0];record[1]=cost[1];
    for(i=2;i<costSize;i++)
    record[i]=record[i-2]>record[i-1]?record[i-1]+cost[i]:record[i-2]+cost[i];
    return record[i-1]>record[i-2]?record[i-2]:record[i-1];
}
