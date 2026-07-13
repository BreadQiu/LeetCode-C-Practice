/**
*题目：有效数字整数
*日期：2026.4.25
*/
bool validDigit(int n, int x) {
    bool tmp=false;
    while(n>=10){
        if(x==n%10) tmp=true;
        n/=10;
    }
    if(tmp&&n!=x) return true;
    return false;
}
