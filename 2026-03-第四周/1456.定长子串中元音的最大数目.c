/**
*题目：定长子串中元音的最大数目
*日期：2026.3.24
*/
bool Ifaeiou(char* s,int i){
    if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') return true;
    return false;
}
int maxVowels(char* s, int k) {
    int i,tp=0,num=0;
    for(i=0;i<k;i++) if(Ifaeiou(s,i)) tp++;
    for(;i<=strlen(s);i++)
    {
        num=fmax(num,tp);
        if(tp==k) return k;
        if(Ifaeiou(s,i-k)) tp--;
        if(Ifaeiou(s,i)) tp++;
    }
    return num;
}
