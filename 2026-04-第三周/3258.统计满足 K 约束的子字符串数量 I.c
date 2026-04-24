/**
*题目：统计满足 K 约束的子字符串数量 I
*日期：2026.4.17
*/
int countKConstraintSubstrings(char* s, int k) {
    int left,right,sum0=0,sum1=0,ret=0;
    for(left=right=0;right<strlen(s);right++){
        if(s[right]=='0') sum0++;
        else sum1++;
        while(sum0>k&&sum1>k){
            if(s[left]=='0') sum0--;
            else sum1--;
            left++;
        }
        ret+=right-left+1;
    }
    return ret;
}
