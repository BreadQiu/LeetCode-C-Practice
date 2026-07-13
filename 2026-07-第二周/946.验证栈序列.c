/**
*题目：验证栈序列
*日期：2026.7.10
*/
bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) {
    int n=pushedSize;
    int cnt[n];
    int cntSize=0;
    int ipushed=0;
    int ipopped=0;
    while(ipushed<n){
        cnt[cntSize++]=pushed[ipushed++];
        while(cntSize>0&&ipopped<n&&cnt[cntSize-1]==popped[ipopped]){
            cntSize--;
            ipopped++;
        }
    }
    if(ipopped==n) return true;
    return false;
}
