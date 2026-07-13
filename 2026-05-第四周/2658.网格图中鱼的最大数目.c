/**
*题目：网格图中鱼的最大数目
*日期：2026.5.27
*/
int dfs(int**grid,int i,int j,int m,int n,int value){
    value+=grid[i][j];
    grid[i][j]=0;
    if(i&&grid[i-1][j]){//up
        value=dfs(grid,i-1,j,m,n,value);
    }
    if(i<m-1&&grid[i+1][j]){//down
        value=dfs(grid,i+1,j,m,n,value);
    }
    if(j&&grid[i][j-1]){//left
        value=dfs(grid,i,j-1,m,n,value);
    }
    if(j<n-1&&grid[i][j+1]){//right
        value=dfs(grid,i,j+1,m,n,value);
    }
    return value;
}

int findMaxFish(int** grid, int gridSize, int* gridColSize) {
    int ret=0;
    for(int m=gridSize,i=0;i<m;i++){
        for(int n=*gridColSize,j=0;j<n;j++){
            if(grid[i][j]){
                ret=fmax(ret,dfs(grid,i,j,m,n,0));
            }
        }
    }
    return ret;
}
