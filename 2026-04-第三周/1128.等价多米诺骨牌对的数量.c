/**
*题目：等价多米诺骨牌对的数量
*日期：2026.4.21
*/
int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize) {
    int cnt[100]={0};
    int i,tmp;
    long long ret=0;
    for(i=0;i<dominoesSize;i++){
        if(dominoes[i][0]>dominoes[i][1]){
            tmp=dominoes[i][0];
            dominoes[i][0]=dominoes[i][1];
            dominoes[i][1]=tmp;
        }
        ret+=cnt[10*dominoes[i][0]+dominoes[i][1]];
        cnt[10*dominoes[i][0]+dominoes[i][1]]++;
    }
    return ret;
}
