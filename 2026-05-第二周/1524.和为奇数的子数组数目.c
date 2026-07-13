/**
*题目：和为奇数的子数组数目
*日期：2026.5.13
*/
int numOfSubarrays(int* arr, int arrSize) {
    long long ret=0,odd=0,even=0;
    for(int i=0;i<arrSize;i++){
        if(arr[i]%2){
            int tmp=odd;
            odd=even;
            even=tmp;
            odd++;
        }
        else{
            even++;
        }
        ret+=odd;
    }
    return ret%1000000007;
}
