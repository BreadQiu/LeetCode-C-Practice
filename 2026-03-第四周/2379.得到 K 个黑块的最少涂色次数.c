/**
*题目：得到 K 个黑块的最少涂色次数
*日期：2026.3.25
*/
int minimumRecolors(char* blocks, int k) {
    int i,tp=0,num=0;
    for(i=0;i<k;++i) if(blocks[i]=='B') ++tp;
    for(;i<=strlen(blocks);++i){
        num=fmax(num,tp);
        if(num==k) return 0;
        if(blocks[i]=='B') ++tp;
        if(blocks[i-k]=='B') --tp;
    }
    return k-num;
}
