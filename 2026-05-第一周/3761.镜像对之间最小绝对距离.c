/**
*题目：镜像对之间最小绝对距离
*日期：2026.5.4
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

int function(int reverse,int origin,int val,int ret){
    Hashtable*it=find(origin);
    Hashtable*tmp=(Hashtable*)malloc(sizeof(Hashtable));
        tmp->key=reverse;
        tmp->val=val;
        HASH_ADD_INT(hashtable,key,tmp);
    if(it==NULL){
        return ret;
    }else{
        return fmin(ret,val-it->val);
    }
}

int minMirrorPairDistance(int* nums, int numsSize) {
    int ret=INT_MAX;
    for(int i=0;i<numsSize;i++){
        int origin=nums[i];
        while(nums[i]%10==0) nums[i]/=10;
        int reverse=0;
        while(nums[i]){
            reverse+=nums[i]%10;
            nums[i]/=10;
            if(nums[i]) reverse*=10;
        }
        ret=function(reverse,origin,i,ret);
    }
    deleteall();
    if(ret==INT_MAX) return -1;
    return ret;
}
