/**
*题目：最短且字典序最小的美丽子字符串
*日期：2026.4.17
*/
char* shortestBeautifulSubstring(char* s, int k) {
    char*ret=(char*)malloc(101*sizeof(char));
    char*tmp=(char*)malloc(101*sizeof(char));
    int len=INT_MAX,sum=0,left,right,i;
    for(left=right=0;right<strlen(s);right++){
        sum+=s[right]-'0';
        if(sum==k&&right-left+1<=len){
            if(right-left+1<len){
                for(i=left;i<=right;i++) ret[i-left]=s[i];
                if(len!=INT_MAX){
                    for(;i<=left+len-1;i++) ret[i-left]='\0';
                }
                ret[i-left]='\0';
                len=right-left+1;
            }
            else{
                for(i=left;i<=right;i++){
                    tmp[i-left]=s[i];
                }
                tmp[i-left]='\0';
                if(strcmp(tmp,ret)<0) strcpy(ret,tmp);
            }
        }
        while(sum>=k||s[left]=='0'){
            sum-=s[left]-'0';
            left++;
        }
    }
    if(len==INT_MAX) return "\0";
    return ret;
}
