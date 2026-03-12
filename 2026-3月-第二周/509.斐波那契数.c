/**
*题目：斐波那契数
*日期：2026.3.11
*/
int fib(int n) {
    int a=0,b=1,c,i;
    if(n<2) return n;
    for(i=2;i<=n;i++)
    {
        c=a+b;a=b;b=c;
    }
    return c;
}
