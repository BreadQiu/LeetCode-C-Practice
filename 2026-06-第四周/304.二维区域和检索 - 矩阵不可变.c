/**
*题目：二维区域和检索 - 矩阵不可变
*日期：2026.6.22
*/
typedef struct {
    int**matrixcnt;
    int m;
    int n;
} NumMatrix;


NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    int m=matrixSize;
    int n=*matrixColSize;
    NumMatrix*obj=(NumMatrix*)malloc(sizeof(NumMatrix));
    obj->matrixcnt=(int**)malloc((m+1)*sizeof(int*));
    for(int i=0;i<m;i++){
        obj->matrixcnt[i]=(int*)malloc((n+1)*sizeof(int));
        obj->matrixcnt[i][0]=0;
        for(int j=1;j<=n;j++){
            obj->matrixcnt[i][j]=obj->matrixcnt[i][j-1]+matrix[i][j-1];
        }
    }
    obj->m=m;
    obj->n=n;
    return obj;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    int ret=0;
    for(int i=row1;i<=row2;i++){
        ret+=obj->matrixcnt[i][col2+1]-obj->matrixcnt[i][col1];
    }
    return ret;
}

void numMatrixFree(NumMatrix* obj) {
    free(obj);
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);

 * numMatrixFree(obj);
*/
