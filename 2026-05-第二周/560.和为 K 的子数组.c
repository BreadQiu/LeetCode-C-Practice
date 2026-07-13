/**
*题目：和为 K 的子数组
*日期：2026.5.12
*/
typedef struct{
    int key;
    int val;
    UT_hash_handle hh
}Hashtable;

Hashtable*hashtable=NULL;

Hashtable*find(int key){
    Hashtable*tmp=NULL;
    HASH_FIND_INT(hashtable,&key,tmp);
    return tmp;
}

void deleteall(){
    Hashtable*cur=NULL,*tmp=NULL;
    HASH_ITER(hh,hashtable,cur,tmp){
        HASH_DEL(hashtable,cur);
        free(cur);
    }
}

int function(int key){
    Hashtable*it=find(key);
    if(it==NULL) return 0;
    else return it->val;
}

void add(int key){
    Hashtable*it=find(key);
    if(it==NULL){
        Hashtable*tmp=(Hashtable*)malloc(sizeof(Hashtable));
        tmp->key=key;
        tmp->val=1;
        HASH_ADD_INT(hashtable,key,tmp);
    }
    else{
        it->val++;
    }
}

int subarraySum(int* nums, int numsSize, int k) {
    int s=0;
    int ret=0;
    add(0);
    for(int i=1;i<=numsSize;i++){
        s+=nums[i-1];
        ret+=function(s-k);
        add(s);
    }
    deleteall();
    return ret;
}
