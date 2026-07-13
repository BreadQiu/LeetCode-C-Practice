/**
*题目：水域大小
*日期：2026.5.27
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int dfs(int**grid,int i,int j,int m,int n,int num){
    num++;
    grid[i][j]=1;
    if(i){
        if(grid[i-1][j]==0){//up
            num=dfs(grid,i-1,j,m,n,num);
        }
        if(j&&grid[i-1][j-1]==0){//up-left
            num=dfs(grid,i-1,j-1,m,n,num);
        }
        if(j<n-1&&grid[i-1][j+1]==0){//up-right
            num=dfs(grid,i-1,j+1,m,n,num);
        }
    }
    if(i<m-1){
        if(grid[i+1][j]==0){//down
            num=dfs(grid,i+1,j,m,n,num);
        }
        if(j&&grid[i+1][j-1]==0){//down-left
            num=dfs(grid,i+1,j-1,m,n,num);
        }
        if(j<n-1&&grid[i+1][j+1]==0){//down-right
            num=dfs(grid,i+1,j+1,m,n,num);
        }
    }
    if(j&&grid[i][j-1]==0){//left
        num=dfs(grid,i,j-1,m,n,num);
    }
    if(j<n-1&&grid[i][j+1]==0){//right
        num=dfs(grid,i,j+1,m,n,num);
    }
    return num;
}

 int cmp(const void*a,const void*b){
     return *(int*)a-*(int*)b;
 }

int* pondSizes(int** land, int landSize, int* landColSize, int* returnSize) {
    int*ret=(int*)malloc(40000*sizeof(int));
    *returnSize=0;
    for(int m=landSize,n=*landColSize,i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(land[i][j]==0){
                ret[(*returnSize)++]=dfs(land,i,j,m,n,0);
                j++;
            }
        }
    }
    qsort(ret,*returnSize,sizeof(int),cmp);
    return ret;
}
