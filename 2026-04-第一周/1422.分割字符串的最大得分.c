/**
*题目：分割字符串的最大得分
*日期：2026.4.1
*/
int maxScore(char* s) {
    int i,j,temp,max=0;
    int*score=(int*)malloc(strlen(s)*sizeof(int));
    for(i=0,temp=0;i<=strlen(s)-2;++i){
        if(s[i]=='0') ++temp;
        score[i]=temp;
    }
    for(j=strlen(s)-2,temp=0;j>=0;--j){
        if(s[j+1]=='1') ++temp;
        score[j]+=temp;
        max=fmax(score[j],max);
    }
    return max;
}
