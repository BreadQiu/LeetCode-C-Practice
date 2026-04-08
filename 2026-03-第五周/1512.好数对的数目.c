/**
*题目：好数对的数目
*日期：2026.3.30
*/
long long nCm(int n, int m){
    int i;
    long long plusn,plusm;
    for(plusn=1,i=n;i>=n-m+1;--i) plusn*=i;
    for(plusm=1,i=m;i>=1;--i) plusm*=i;
    return plusn/plusm;
}

int numIdenticalPairs(int* nums, int numsSize) {
    int i,hash[101];
    long long sum=0;
    memset(hash,0,sizeof(hash));
    for(i=0;i<numsSize;++i){
        ++hash[nums[i]];
    }
    for(i=1;i<=100;++i){
        if(hash[i]>1) sum+=nCm(hash[i],2);
    }
    return sum;
}
