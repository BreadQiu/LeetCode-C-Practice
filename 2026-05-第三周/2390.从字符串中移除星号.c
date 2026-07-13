/**
*题目：从字符串中移除星号
*日期：2026.5.24
*/
char* removeStars(char* s) {
    char*ret=(char*)malloc(sizeof(char)*(strlen(s)+1));
    int iret=strlen(s);
    ret[iret--]='\0';
    for(int kill=0,is=iret;is>=0;is--){
        if(s[is]=='*'){
            kill++;
        }else if(kill){
            kill--;
        }else{
            ret[iret--]=s[is];
        }
    }
    return ret+iret+1;
}
