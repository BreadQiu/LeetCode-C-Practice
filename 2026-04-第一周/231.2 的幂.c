/**
*题目：2 的幂
*日期：2026.4.2
*/
bool isPowerOfTwo(int n) {
    if(n<1||n&(n-1)) return false;
    return true;
}
