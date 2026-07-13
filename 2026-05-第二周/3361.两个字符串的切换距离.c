/**
*题目：两个字符串的切换距离
*日期：2026.5.11
*/
long long shiftDistance(char* s, char* t, int* nextCost, int nextCostSize, int* previousCost, int previousCostSize) {
    long long nexts[27];
    nexts[0]=0;
    for(int i=1;i<=26;i++){
        nexts[i]=nexts[i-1]+nextCost[i-1];
    }
    long long pres[27];
    pres[26]=0;
    for(int i=25;i>=0;i--){
        pres[i]=pres[i+1]+previousCost[i];
    }
    long long ret=0;
    for(int i=0;i<strlen(s);i++){
        long long nexttmp=t[i]>=s[i]?(nexts[t[i]-'a']-nexts[s[i]-'a']):(nexts[26]-nexts[s[i]-'a']+nexts[t[i]-'a']);
        long long pretmp=t[i]<=s[i]?(pres[t[i]-'a'+1]-pres[s[i]-'a'+1]):(pres[0]-pres[s[i]-'a'+1]+pres[t[i]-'a'+1]);
        ret+=fmin(nexttmp,pretmp);
    }
    return ret;
}
