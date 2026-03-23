/**
*题目：不同路径II
*日期：2026.3.19
*/
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int i,j,nums[100][100];
    for(i=0;i<obstacleGridSize;i++)
    for(j=0;j<obstacleGridColSize[0];j++)
    {
        if(obstacleGrid[i][j]==1) nums[i][j]=0;
        else if(i==0&&j==0) nums[i][j]=1;
        else if(i==0) nums[i][j]=nums[i][j-1];
        else if(j==0) nums[i][j]=nums[i-1][j];
        else nums[i][j]=nums[i-1][j]+nums[i][j-1];
    }
    return nums[i-1][j-1];
}
