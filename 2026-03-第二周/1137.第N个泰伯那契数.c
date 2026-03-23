/**
*题目：第N个泰伯那契数
*日期：2026.3.11
*/
int tribonacci(int n) {
    int a=0,b=1,c=1,d,i;
    if(n<2) return n;
    if(n==3) return 2;
    for(i=3;i<=n;i++)
    {
        d=a+b+c;a=b;b=c;c=d;
    }
    return c;
}
