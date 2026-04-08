/**
*题目：尽可能使字符串相等
*日期：2026.4.7
*/
int equalSubstring(char* s, char* t, int maxCost) {
    int i,left=INT_MAX,right=INT_MAX,max=1,sum=0;
    int* arr=(int*)malloc((strlen(s)+1)*sizeof(int));
    for(i=0;i<strlen(s);++i){
        arr[i]=abs(s[i]-t[i]);
        if(left==INT_MAX&&arr[i]<=maxCost){
            left=right=i;
        }
    }
    if(left==INT_MAX) return 0;
    for(;right<=strlen(s);max=fmax(right-left-1,max)){
        for(;left<right&&sum>maxCost;++left){
            sum-=arr[left];
        }
        for(;right<=strlen(s)&&sum<=maxCost;++right){
            sum+=arr[right];
        }
    }
    return max;
}
