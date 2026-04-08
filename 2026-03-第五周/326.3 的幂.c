/**
*题目：3 的幂
*日期：2026.3.31
*/
bool isPowerOfThree(int n) {
    if(n<=0) return false;
    while(n%3==0) n/=3;
    if(n==1) return true;
    return false;
}
