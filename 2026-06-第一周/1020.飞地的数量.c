/**
*题目：飞地的数量
*日期：2026.6.3
*/
void dfs(int**grid,int i,int j,int m,int n){
    grid[i][j]=0;
    if(i&&grid[i-1][j]) dfs(grid,i-1,j,m,n);
    if(i<m-1&&grid[i+1][j]) dfs(grid,i+1,j,m,n);
    if(j&&grid[i][j-1]) dfs(grid,i,j-1,m,n);
    if(j<n-1&&grid[i][j+1]) dfs(grid,i,j+1,m,n);
}

int numEnclaves(int** grid, int gridSize, int* gridColSize) {
    int m=gridSize,n=*gridColSize;
    for(int j=0;j<n;j++){
        if(grid[0][j]) dfs(grid,0,j,m,n);
    }
    if(m>1){
        for(int j=0;j<n;j++){
            if(grid[m-1][j]) dfs(grid,m-1,j,m,n);
        }
    }
    for(int i=1;i<m-1;i++){
        if(grid[i][0]) dfs(grid,i,0,m,n);
    }
    if(n>1){
        for(int i=1;i<m-1;i++){
        if(grid[i][n-1]) dfs(grid,i,n-1,m,n);
    }
    }
    int ret=0;
    for(int i=1;i<m-1;i++){
        for(int j=1;j<n-1;j++){
            ret+=grid[i][j];
        }
    }
    return ret;
}
