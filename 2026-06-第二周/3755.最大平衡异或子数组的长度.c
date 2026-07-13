/**
*题目：最大平衡异或子数组的长度
*日期：2026.6.14
*/
typedef struct{
    long long key;
    int val;
    UT_hash_handle hh;
}Hashtable;

Hashtable*hashtable=NULL;

Hashtable*find(long long key){
    Hashtable*tmp=NULL;
    HASH_FIND(hh,hashtable,&key,sizeof(long long),tmp);
    return tmp;
}

void deleteall(){
    Hashtable*cur=NULL,*tmp=NULL;
    HASH_ITER(hh,hashtable,cur,tmp){
        HASH_DEL(hashtable,cur);
        free(cur);
    }
}

int get(long long key){
    Hashtable*tmp=find(key);
    if(tmp==NULL){
        return -2;
    }
    return tmp->val;
}

void add(long long key,int val){
    Hashtable*tmp=(Hashtable*)malloc(sizeof(Hashtable));
    tmp->key=key;
    tmp->val=val;
    HASH_ADD(hh,hashtable,key,sizeof(long long),tmp);
}

int maxBalancedSubarray(int* nums, int numsSize) {
    int ret=0;
    add(100000,-1);
   long long sum=0;
    for(int odevity=100000,i=0;i<numsSize;i++){
        sum=sum^nums[i];
        odevity+=nums[i]%2?1:-1;
        long long key=sum<<18|odevity;
        int val=get(key);
        if(val!=-2){
            ret=fmax(ret,i-val);
        }else{
            add(key,i);
        }
    }
    deleteall();
    return ret;
}
