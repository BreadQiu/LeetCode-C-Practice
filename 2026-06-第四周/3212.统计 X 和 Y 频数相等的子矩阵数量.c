/**
*题目：统计 X 和 Y 频数相等的子矩阵数量
*日期：2026.6.28
*/
int numberOfSubmatrices(char** grid, int gridSize, int* gridColSize) {
    int m=gridSize;
    int n=*gridColSize;
    int cnt[n];
    memset(cnt,0,sizeof(cnt));
    int start=n;
    int ret=0;
    for(int i=0;i<m;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if(grid[i][j]=='X'){
                sum++;
                start=fmin(start,j);
            }else if(grid[i][j]=='Y'){
                sum--;
            }
            cnt[j]+=sum;
            if(cnt[j]==0&&start<=j){
                ret++;
            }
        }
    }
    return ret;
}
