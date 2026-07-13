/**
*题目：包含所有三种字符的子字符串数目
*日期：2026.4.26
*/
int numberOfSubstrings(char* s) {
    int ret=0;
    int left,right;
    int cnt[3]={0};
    for(left=right=0/*,cnt[s[right]-'a']++*/;true;){
        while(right<strlen(s)&&cnt[0]*cnt[1]*cnt[2]==0){
            cnt[s[right]-'a']++;
            right++;
        }
        if(cnt[0]*cnt[1]*cnt[2]) ret+=strlen(s)-right+1;
        else if(right>=strlen(s)) break;
        cnt[s[left]-'a']--;
        left++;
    }
    return ret;
}
