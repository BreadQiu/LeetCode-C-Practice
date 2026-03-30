/**
*题目：每个字符最多出现两次的最长子字符串
*日期：2026.3.29
*/
int maximumLengthSubstring(char* s) {
    int i,j,k,max=2,num;
    if(strlen(s)==2) return 2;
    for(i=0,j=2,num=0;j<strlen(s);++j,num=0){
        for(k=j-1;k>=i;--k){
            if(s[k]==s[j]){
                if(num<1) num=1;
                else{
                    num=2;
                    break;
                }
            }
        }
        if(num==2) i=k+1;
        max=fmax(j-i+1,max);
    }
    return max;
}
