/**
*题目：数组异或操作
*日期：2026.3.30
*/
int xorOperation(int n, int start) {
    int i,output=start;
    for(i=2;i<=n;++i){
        start+=2;
        output^=start;
    }
    return output;
}
