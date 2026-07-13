/**
*题目：岛屿的最大面积
*日期：2026.5.27
*/
int dfs(int**grid,int i,int j,int m,int n,int area){
    grid[i][j]=0;
    if(i&&grid[i-1][j]){//up
        area=dfs(grid,i-1,j,m,n,area+1);
    }
    if(i<m-1&&grid[i+1][j]){//down
        area=dfs(grid,i+1,j,m,n,area+1);
    }
    if(j&&grid[i][j-1]){//left
        area=dfs(grid,i,j-1,m,n,area+1);
    }
    if(j<n-1&&grid[i][j+1]){//right
        area=dfs(grid,i,j+1,m,n,area+1);
    }
    return area;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int m=gridSize,n=*gridColSize;
    int ret=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]){
                ret=fmax(ret,dfs(grid,i,j,m,n,1));
            }
        }
    }
    return ret;
}
