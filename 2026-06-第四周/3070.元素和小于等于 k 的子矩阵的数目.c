/**
*题目：元素和小于等于 k 的子矩阵的数目
*日期：2026.6.25
*/
int countSubmatrices(int** grid, int gridSize, int* gridColSize, int k) {
    int m=gridSize;
    int n=*gridColSize;
    int cnt[n];
    int ret=0;
    for(int sum=0,j=0;j<n;j++){
        sum+=grid[0][j];
        cnt[j]=sum;
        if(cnt[j]<=k) ret++;
        else break;
    }
    for(int i=1;i<m;i++){
        if(cnt[0]>k) return ret;
        for(int sum=0,j=0;j<n;j++){
            sum+=grid[i][j];
            cnt[j]+=sum;
            if(cnt[j]>k) break;
            else ret++;
        }
    }
    return ret;
}
