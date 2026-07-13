/**
*题目：被围绕的区域
*日期：2026.6.12
*/
int m,n;

void dfs(char**board,int i,int j){
    if(board[i][j]!='O') return;
    board[i][j]='B';
    if(i) dfs(board,i-1,j);
    if(i<m-1) dfs(board,i+1,j);
    if(j) dfs(board,i,j-1);
    if(j<n-1) dfs(board,i,j+1);
}

void solve(char** board, int boardSize, int* boardColSize) {
    m=boardSize;
    n=*boardColSize;
    int i,j;
    for(i=0,j=0;j<n;j++){
        dfs(board,i,j);
    }
    for(i=m-1,j=0;j<n;j++){
        dfs(board,i,j);
    }
    for(i=1,j=0;i<m-1;i++){
        dfs(board,i,j);
    }
    for(i=1,j=n-1;i<m-1;i++){
        dfs(board,i,j);
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(board[i][j]=='O') board[i][j]='X';
            else if(board[i][j]=='B') board[i][j]='O';
        }
    }
}
