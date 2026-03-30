/**
*题目：无重复字符的最长子串
*日期：2026.3.29
*/
int lengthOfLongestSubstring(char* s) {
    int i,j,k,max;
    if(strlen(s)<=1) return strlen(s);
    for(i=0,j=1;j<strlen(s);++j){
        for(k=i;k<j;++k){
            if(s[k]==s[j]) break;
        }
        if(k<j) i=k+1;
        max=fmax(j-i+1,max);
    }
    return max;
}
