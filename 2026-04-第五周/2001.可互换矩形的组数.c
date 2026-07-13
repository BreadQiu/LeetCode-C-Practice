/**
*题目：可互换矩形的组数
*日期：2026.4.30
*/
typedef struct{
    long long key;
    int val;
    UT_hash_handle hh;
}hashTable;

hashTable*hashtable=NULL;

hashTable*find(long long key){
    hashTable*tmp=NULL;
    HASH_FIND(hh,hashtable,&key,sizeof(long long),tmp);
    return tmp;
}

void delete(){
    hashTable*cur=NULL,*tmp=NULL;
    HASH_ITER(hh,hashtable,cur,tmp){
        HASH_DEL(hashtable,cur);
        free(cur);
    }
}

int function(long long key){
    hashTable*it=find(key);
    if(it==NULL){
        hashTable*tmp=(hashTable*)malloc(sizeof(hashTable));
        tmp->key=key;
        tmp->val=1;
        HASH_ADD(hh,hashtable,key,sizeof(long long),tmp);
        return 0;
    }else{
        it->val++;
        return it->val-1;
    }
}

long long interchangeableRectangles(int** rectangles, int rectanglesSize, int* rectanglesColSize) {
    int i,tmp;
    long long ret=0;
    for(i=0;i<rectanglesSize;i++){
        int a=rectangles[i][0];
        int b=rectangles[i][1];
        int t=a%b;
        while(t>0){
            a=b;
            b=t;
            t=a%b;
        }
        ret+=function((long long)rectangles[i][0]/b<<17|(long long)rectangles[i][1]/b);
    }
    delete();
    return ret;
}
