/**
*题目：长度为 3 的不同回文子序列
*日期：2026.5.5
*/
int countPalindromicSubsequence(char* s) {
    int strLeft[27]={0};
    int strRight[27]={0};
    for(int i=0;i<strlen(s);i++){
        if(strLeft[s[i]-'a'+1]==0) strLeft[s[i]-'a'+1]=i+1;
        strRight[s[i]-'a'+1]=i+1;
    }
    int ret=0;
    for(int i=1;i<=26;i++){
        if(strRight[i]-strLeft[i]){
            int tmp[27]={0};
            for(int j=strLeft[i];j<strRight[i]-1;j++){
                if(tmp[s[j]-'a'+1]==0) ret++;
                tmp[s[j]-'a'+1]++;
            }
        }
    }
    return ret;
}
