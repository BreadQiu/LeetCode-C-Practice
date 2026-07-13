/**
*题目：直角三角形
*日期：2026.5.5
*/
long long numberOfRightTriangles(int** grid, int gridSize, int* gridColSize) {
    int*role=(int*)calloc(gridSize,sizeof(int));
    int*column=(int*)calloc(gridColSize[0],sizeof(int));
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[i];j++){
            role[i]+=grid[i][j];
            column[j]+=grid[i][j];
        }
    }
    long long ret=0;
    for(int i=0;i<gridSize;i++){
        if(role[i]<2) continue;
        for(int j=0;j<gridColSize[i];j++){
            if(grid[i][j]) ret+=(role[i]-1LL)*(column[j]-1LL);
        }
    }
    return ret;
}
