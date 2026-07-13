/**
*题目：图像渲染
*日期：2026.5.31
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int**image,int i,int j,int m,int n,int color,int origin){
    image[i][j]=color;
    if(i&&image[i-1][j]==origin) dfs(image,i-1,j,m,n,color,origin);
    if(i<m-1&&image[i+1][j]==origin) dfs(image,i+1,j,m,n,color,origin);
    if(j&&image[i][j-1]==origin) dfs(image,i,j-1,m,n,color,origin);
    if(j<n-1&&image[i][j+1]==origin) dfs(image,i,j+1,m,n,color,origin);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int m=imageSize,n=*imageColSize;
    *returnSize=m;
    *returnColumnSizes=(int*)malloc(m*sizeof(int));
    for(int i=0;i<m;i++){
        (*returnColumnSizes)[i]=n;
    }
    if(image[sr][sc]==color) return image;
    dfs(image,sr,sc,m,n,color,image[sr][sc]);
    return image;
}
