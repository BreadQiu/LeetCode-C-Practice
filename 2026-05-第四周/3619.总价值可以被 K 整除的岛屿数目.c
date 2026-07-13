/**
*题目：总价值可以被 K 整除的岛屿数目
*日期：2026.5.27
*/
int dfs(int**grid,int i,int j,int m,int n,int k,int value){
    value+=grid[i][j]%k;
    grid[i][j]=0;
    if(i&&grid[i-1][j]){//up
        value=dfs(grid,i-1,j,m,n,k,value%k);
    }
    if(i<m-1&&grid[i+1][j]){//down
        value=dfs(grid,i+1,j,m,n,k,value%k);
    }
    if(j&&grid[i][j-1]){//left
        value=dfs(grid,i,j-1,m,n,k,value%k);
    }
    if(j<n-1&&grid[i][j+1]){//right
        value=dfs(grid,i,j+1,m,n,k,value%k);
    }
    return value%k;
}

int countIslands(int** grid, int gridSize, int* gridColSize, int k) {
    int ret=0;
    for(int m=gridSize,i=0;i<m;i++){
        for(int n=*gridColSize,j=0;j<n;j++){
            if(grid[i][j]){
                ret+=dfs(grid,i,j,m,n,k,0)%k==0;
            }
        }
    }
    return ret;
}
