/**
*题目：转置矩阵
*日期：2026.4.1
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int i,j,m,n;
    *returnSize=n=*matrixColSize;
    *returnColumnSizes=(int*)malloc(n*sizeof(int));
    m=matrixSize;
    int** new=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;++i){
        (*returnColumnSizes)[i]=m;
        new[i]=(int*)malloc(m*sizeof(int));
        for(j=0;j<m;++j){
            new[i][j]=matrix[j][i];
        }
    }
    return new;
}
