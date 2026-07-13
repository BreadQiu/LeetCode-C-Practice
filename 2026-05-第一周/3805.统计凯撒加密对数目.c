/**
*题目：统计凯撒加密对数目
*日期：2026.5.4
*/
typedef struct{
    char*str;
    int val;
    UT_hash_handle hh;
}Hashtable;

Hashtable*hashtable=NULL;

Hashtable*find(char str[]){
    Hashtable*tmp=NULL;
    HASH_FIND_STR(hashtable,str,tmp);
    return tmp;
}

void delete(){
    Hashtable*cur=NULL,*tmp=NULL;
    HASH_ITER(hh,hashtable,cur,tmp){
        HASH_DEL(hashtable,cur);
        free(cur->str);
        free(cur);
    }
}

long long function(char str[]){
    Hashtable*it=find(str);
    if(it==NULL){
        Hashtable*tmp=(Hashtable*)malloc(sizeof(Hashtable));
        tmp->str=strdup(str);
        tmp->val=1;
        HASH_ADD_STR(hashtable,str,tmp);
        return 0;
    }else{
        it->val++;
        return it->val-1;
    }
}

long long countPairs(char** words, int wordsSize) {
    long long ret=0;
    for(int i=0;i<wordsSize;i++){
        int sub=words[i][0]-'a';
        for(int j=0;j<strlen(words[i]);j++){
            words[i][j]-=sub;
            if(words[i][j]<'a') words[i][j]+=26;
        }
        ret+=function(words[i]);
    }
    delete();
    return ret;
}
