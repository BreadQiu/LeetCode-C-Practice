/**
*题目：主题空间
*日期：2026.5.29
*/
int dfs(char**grid,int i,int j,int m,int n,int area){
    char tmp=grid[i][j];
    grid[i][j]='6';
    if(area!=-1) area++;
    if(i){
        if(grid[i-1][j]==tmp) area=dfs(grid,i-1,j,m,n,area);
        else if(grid[i-1][j]=='0') area=-1;
    }else{
        area=-1;
    }
    if(i<m-1){
        if(grid[i+1][j]==tmp) area=dfs(grid,i+1,j,m,n,area);
        else if(grid[i+1][j]=='0') area=-1;
    }else{
        area=-1;
    }
    if(j){
        if(grid[i][j-1]==tmp) area=dfs(grid,i,j-1,m,n,area);
        else if(grid[i][j-1]=='0') area=-1;
    }else{
        area=-1;
    }
    if(j<n-1){
        if(grid[i][j+1]==tmp) area=dfs(grid,i,j+1,m,n,area);
        else if(grid[i][j+1]=='0') area=-1;
    }else{
        area=-1;
    }
    return area;
}

int largestArea(char** grid, int gridSize){
    int ret=0;
    for(int m=gridSize,n=strlen(grid[0]),i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]>='1'&&grid[i][j]<='5') ret=fmax(ret,dfs(grid,i,j,m,n,0));
        }
    }
    return ret;
}
