/**
*题目：最小路径和
*日期：2026.3.21
*/
int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int i,j,m,n,point[200][200];
    m=gridSize;
    n=gridColSize[0];
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    {
        if(i==0&&j==0) point[i][j]=grid[i][j];
        else if(i==0) point[i][j]=point[i][j-1]+grid[i][j];
        else if(j==0) point[i][j]=point[i-1][j]+grid[i][j];
        else point[i][j]=fmin(point[i-1][j],point[i][j-1])+grid[i][j];
    }
    return point[i-1][j-1];
}
