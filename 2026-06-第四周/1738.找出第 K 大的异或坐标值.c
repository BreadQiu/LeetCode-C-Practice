/**
*题目：找出第 K 大的异或坐标值
*日期：2026.6.25
*/
int cmp(const void*a,const void*b){
    return *(int*)b-*(int*)a;
}

int kthLargestValue(int** matrix, int matrixSize, int* matrixColSize, int k) {
    int m=matrixSize;
    int n=*matrixColSize;
    int cnt[m+1][n+1];
    memset(cnt[0],0,sizeof(cnt[0]));
    int ret[m*n];
    int iret=0;
    for(int i=0;i<m;i++){
        cnt[i+1][0]=0;
        for(int j=0;j<n;j++){
            cnt[i+1][j+1]=cnt[i][j+1]^cnt[i+1][j]^cnt[i][j]^matrix[i][j];
            ret[iret++]=cnt[i+1][j+1];
        }
    }
    qsort(ret,iret,sizeof(int),cmp);
    return ret[k-1];
}
