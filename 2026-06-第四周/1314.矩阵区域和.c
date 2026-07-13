/**
*题目：矩阵区域和
*日期：2026.6.25
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixBlockSum(int** mat, int matSize, int* matColSize, int k, int* returnSize, int** returnColumnSizes) {
    int m=matSize;
    int n=*matColSize;
    *returnSize=m;
    int**ret=(int**)malloc(sizeof(int*)*m);
    returnColumnSizes[0]=(int*)malloc(sizeof(int)*m);
    int sum[m+1][n+1];
    for(int j=0;j<=n;j++){
        sum[0][j]=0;
    }
    for(int i=0;i<m;i++){
        ret[i]=(int*)malloc(sizeof(int)*n);
        returnColumnSizes[0][i]=n;
        sum[i+1][0]=0;
        for(int j=0;j<n;j++){
            sum[i+1][j+1]=sum[i+1][j]+sum[i][j+1]-sum[i][j]+mat[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int row1=fmax(0,i-k);
            int col1=fmax(0,j-k);
            int row2=fmin(m-1,i+k);
            int col2=fmin(n-1,j+k);
            ret[i][j]=sum[row2+1][col2+1]-sum[row1][col2+1]-sum[row2+1][col1]+sum[row1][col1];
        }
    }
    return ret;
}
