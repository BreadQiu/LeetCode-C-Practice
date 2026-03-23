/**
*题目：爬楼梯
*日期：2026.3.11
*/
int climbStairs(int n) {
    int a=0,b=1,c,i;
    for(i=1;i<=n;i++)
    {
        c=a+b;a=b;b=c;
    }
    return c;
}
