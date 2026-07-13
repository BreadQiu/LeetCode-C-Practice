/**
*题目：连续的子数组和
*日期：2026.6.12
*/
typedef struct{
    int key;
    int val;
    UT_hash_handle hh;
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

void add(int key){
    Hashtable*it=find(key);
    if(it==NULL){
        Hashtable*tmp=(Hashtable*)malloc(sizeof(Hashtable));
        tmp->key=key;
        tmp->val=1;
        HASH_ADD_INT(hashtable,key,tmp);
    }else{
        it->val++;
    }
}

bool get(int key){
    Hashtable*tmp=find(key);
    if(tmp==NULL){
        return false;
    }else{
        return true;
    }
}

bool checkSubarraySum(int* nums, int numsSize, int k) {
    if(numsSize==1) return false;
    int*cnt=(int*)malloc(sizeof(int)*(numsSize+1));
    cnt[0]=0;
    add(0);
    cnt[1]=nums[0]%k;
    for(int i=1;i<numsSize;i++){
        cnt[i+1]=(cnt[i]+nums[i])%k;
        if(get(cnt[i+1])){
            deleteall();
            return true;
        }
        add(cnt[i]);
    }
    deleteall();
    return false;
}
