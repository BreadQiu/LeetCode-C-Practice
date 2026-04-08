/**
*题目：统计好三元组
*日期：2026.3.30
*/
int countGoodTriplets(int* arr, int arrSize, int a, int b, int c) {
    int i,j,k;
   long long sum=0;
    for(i=0;i<arrSize-2;++i){
        for(j=i+1;j<arrSize-1;++j){
            if(abs(arr[i]-arr[j])<=a){
                for(k=j+1;k<arrSize;++k){
                    if(abs(arr[j] - arr[k])<=b&&abs(arr[i] - arr[k])<=c) ++sum;
                }
            }
        }
    }
    return sum;
}
