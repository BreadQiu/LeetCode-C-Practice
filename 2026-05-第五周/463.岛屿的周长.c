/**
*题目：岛屿的周长
*日期：2026.5.30
*/
int dfs(int**grid,int i,int j,int m,int n,int C){
    C+=4;
    grid[i][j]=2;
    if(i){
        if(grid[i-1][j]==1) C=dfs(grid,i-1,j,m,n,C-1);
        else if(grid[i-1][j]==2) C--;
    }
    if(i<m-1){
        if(grid[i+1][j]==1) C=dfs(grid,i+1,j,m,n,C-1);
        else if(grid[i+1][j]==2) C--;
    }
    if(j){
        if(grid[i][j-1]==1) C=dfs(grid,i,j-1,m,n,C-1);
        else if(grid[i][j-1]==2) C--;
    }
    if(j<n-1){
        if(grid[i][j+1]==1) C=dfs(grid,i,j+1,m,n,C-1);
        else if(grid[i][j+1]==2) C--;
    }
    return C;
}

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int ret=0;
    for(int m=gridSize,n=*gridColSize,i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]) return dfs(grid,i,j,m,n,0);
        }
    }
    return 0;
}
