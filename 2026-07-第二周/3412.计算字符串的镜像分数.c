/**
*题目：计算字符串的镜像分数
*日期：2026.7.10
*/
long long calculateScore(char* s) {
    int cnt[26][100000];
    int cntSize[26]={0};
    long long ret=0;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        int reverseval='a'+25-s[i];
        int val=s[i]-'a';
        if(cntSize[reverseval]){
            ret+=i-cnt[reverseval][--cntSize[reverseval]];
        }else{
            //cnt[val]=(int*)realloc(cnt[val],(cntSize[val]+1)*sizeof(int));
            cnt[val][cntSize[val]++]=i;
        }
    }
    return ret;
}
