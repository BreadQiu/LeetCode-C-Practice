/**
*题目：统计封闭岛屿的数目
*日期：2026.6.10
*/
int m;
int n;

void dfs(int**grid,int i,int j){
    grid[i][j]=1;
    if(i&&grid[i-1][j]==0){
        dfs(grid,i-1,j);
    }
    if(i<m-1&&grid[i+1][j]==0){
        dfs(grid,i+1,j);
    }
    if(j&&grid[i][j-1]==0){
        dfs(grid,i,j-1);
    }
    if(j<n-1&&grid[i][j+1]==0){
        dfs(grid,i,j+1);
    }
}

int closedIsland(int** grid, int gridSize, int* gridColSize) {
    m=gridSize;
    n=*gridColSize;
    int i,j;
    for(i=0,j=0;j<n;j++){
        if(grid[i][j]==0) dfs(grid,i,j);
    }
    for(i=m-1,j=0;j<n;j++){
        if(grid[i][j]==0) dfs(grid,i,j);
    }
    for(i=1,j=0;i<m-1;i++){
        if(grid[i][j]==0) dfs(grid,i,j);
    }
    for(i=1,j=n-1;i<m-1;i++){
        if(grid[i][j]==0) dfs(grid,i,j);
    }
    int ret=0;
    for(i=1;i<m-1;i++){
        for(j=1;j<n-1;j++){
            if(grid[i][j]==0){
                ret++;
                dfs(grid,i,j);
            }
        }
    }
    return ret;
}
