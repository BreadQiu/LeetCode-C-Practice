/**
*题目：边界着色
*日期：2026.6.3
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int**grid,int i,int j,int m,int n,int origin){
    bool border=false;
    grid[i][j]=-1;
    if(i&&grid[i-1][j]==origin) dfs(grid,i-1,j,m,n,origin);
    else if(i==0||grid[i-1][j]>0) border=true;
    if(i<m-1&&grid[i+1][j]==origin) dfs(grid,i+1,j,m,n,origin);
    else if(i==m-1||grid[i+1][j]>0) border=true;
    if(j&&grid[i][j-1]==origin) dfs(grid,i,j-1,m,n,origin);
    else if(j==0||grid[i][j-1]>0) border=true;
    if(j<n-1&&grid[i][j+1]==origin) dfs(grid,i,j+1,m,n,origin);
    else if(j==n-1||grid[i][j+1]>0) border=true;
    if(border) grid[i][j]=-2;
}

int** colorBorder(int** grid, int gridSize, int* gridColSize, int row, int col, int color, int* returnSize, int** returnColumnSizes) {
    int m=gridSize,n=*gridColSize;
    *returnSize=m;
    *returnColumnSizes=(int*)malloc(m*sizeof(int));
    int origin=grid[row][col];
    if(grid[row][col]!=color) dfs(grid,row,col,m,n,origin);
    for(int i=0;i<m;i++){
        (*returnColumnSizes)[i]=n;
        for(int j=0;j<n;j++){
            if(grid[i][j]==-1) grid[i][j]=origin;
            else if(grid[i][j]==-2) grid[i][j]=color;
        }
    }
    return grid;
}
