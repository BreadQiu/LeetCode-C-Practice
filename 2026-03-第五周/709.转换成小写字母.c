/**
*题目：转换成小写字母
*日期：2026.3.30
*/
char* toLowerCase(char* s) {
    int i;
    char* new=(char*)malloc((strlen(s)+1)*sizeof(char));
    for(i=0;i<=strlen(s);++i){
        if(s[i]>='A'&&s[i]<='Z') new[i]=s[i]-'A'+'a';
        else new[i]=s[i];
    }
    return new;
}
