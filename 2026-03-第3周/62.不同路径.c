/**
*题目：不同路径
*日期：2026.3.18
*/
int uniquePaths(int m, int n) {
    int i,j,nums[100][100];
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    {
        if(i==0||j==0) nums[i][j]=1;
        else nums[i][j]=nums[i-1][j]+nums[i][j-1];
    }
    return nums[i-1][j-1];
}
