/**
*题目：比较含退格的字符串
*日期：2026.5.21
*/
bool backspaceCompare(char* s, char* t) {
    for(int l=strlen(s)-1,i=0;i<=l;i++){
        if(s[i]=='#'){
            if(i==0){
                memmove(s,s+1,l);
                s[l--]='\0';
                i-=1;
            }else if(l==1){
                s="";
                break;
            }else if(i==l){
                s[i]='\0';
                s[i-1]='\0';
                break;
            }else{
                memmove(s+i-1,s+i+1,l-i+1);
                s[l--]='\0';
                s[l--]='\0';
                i-=2;
            }
        }
    }
    for(int l=strlen(t)-1,i=0;i<=l;i++){
        if(t[i]=='#'){
            if(i==0){
                memmove(t,t+1,l);
                t[l--]='\0';
                i-=1;
            }else if(l==1){
                t="";
                break;
            }else if(i==l){
                t[i]='\0';
                t[i-1]='\0';
                break;
            }else{
                memmove(t+i-1,t+i+1,l-i+1);
                t[l--]='\0';
                t[l--]='\0';
                i-=2;
            }
        }
    }
    if(strcmp(s,"#")==0) s="";
    if(strcmp(t,"#")==0) t="";
    puts(s);
    puts(t);
    if(strcmp(s,t)) return false;
    return true;
}
