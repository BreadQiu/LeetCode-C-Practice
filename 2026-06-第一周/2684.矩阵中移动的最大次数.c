/**
*题目：矩阵中移动的最大次数
*日期：2026.6.6
*/
int maxMoves(int** grid, int gridSize, int* gridColSize) {
    int m=gridSize,n=*gridColSize;
    int ret=0;
    bool**use=(bool**)malloc(m*sizeof(bool*));
    for(int i=0;i<m;i++){
        use[i]=(bool*)calloc(n,sizeof(bool));
    }

    void dfs(int i,int j){
        ret=fmax(ret,j);
        if(ret==n-1) return;
        use[i][j]=true;
        if(i&&use[i-1][j+1]==false&&grid[i-1][j+1]>grid[i][j]){
            dfs(i-1,j+1);
        }
        if(use[i][j+1]==false&&grid[i][j+1]>grid[i][j]){
            dfs(i,j+1);
        }
        if(i<m-1&&grid[i+1][j+1]>grid[i][j]){
            dfs(i+1,j+1);
        }
    }

    for(int i=0;i<m;i++){
        dfs(i,0);
    }
    return ret;
}
