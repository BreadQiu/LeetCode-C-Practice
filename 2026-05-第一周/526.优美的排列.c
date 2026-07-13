/**
*题目：优美的排列
*日期：2026.5.2
*/
int countArrangement(int n) {
    int**cnt=(int**)malloc(n*sizeof(int*));
    int*arr=(int*)calloc(n,sizeof(int));
    int*use=(int*)calloc(n,sizeof(int));
    int*cntSize=(int*)malloc(n*sizeof(int*));
    int ret=0;
    for(int right=0;right<n;right++){
        int i,tmp;
        cnt[right]=(int*)malloc(n*sizeof(int));
        for(tmp=1,i=0;tmp<=n;tmp++){
            if((tmp%(right+1))*((right+1)%tmp)==0){
                cnt[right][i++]=tmp;
            }
        }
        cntSize[right]=i;
    }
    int i,j;
    for(i=0,j=0;1;){
        for(;j<cntSize[i]&&use[cnt[i][j]-1]==1;j++);
        if(j==cntSize[i]){
            i--;
            if(i<0) break;
            j=arr[i];
            use[cnt[i][j]-1]--;
            j++;
        }else{
            if(i==n-1){
                ret++;
                j++;
            }else{
                use[cnt[i][j]-1]++;
                arr[i]=j;
                i++;
                j=0;
            }
        }
    }
    return ret;
}
