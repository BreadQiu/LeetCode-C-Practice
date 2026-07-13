/**
*题目：统计子岛屿
*日期：2026.6.12
*/
int m,n;

bool dfs(int**grid1,int**grid2,int i,int j,bool include){
    if(!grid2[i][j]){
        return include;
    }
    grid2[i][j]=0;
    if(!grid1[i][j]){
        include=false;
    }
    if(i){
        include=dfs(grid1,grid2,i-1,j,include)&&include;
    }
    if(i<m-1){
        include=dfs(grid1,grid2,i+1,j,include)&&include;
    }
    if(j){
        include=dfs(grid1,grid2,i,j-1,include)&&include;
    }
    if(j<n-1){
        include=dfs(grid1,grid2,i,j+1,include)&&include;
    }
    return include;
}

int countSubIslands(int** grid1, int grid1Size, int* grid1ColSize, int** grid2, int grid2Size, int* grid2ColSize) {
   m=grid1Size;
   n=*grid1ColSize;
   int ret=0;
   for(int i=0;i<m;i++){
       for(int j=0;j<n;j++){
           if(grid2[i][j]){
               ret+=dfs(grid1,grid2,i,j,true);
           }
       }
   }
   return ret;
}
