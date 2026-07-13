/**
*题目：存在重复元素 II
*日期：2026.4.24
*/
typedef struct{
    int key;
    int val;
    UT_hash_handle hh;
}hashTable;

hashTable*hashtable=NULL;

hashTable*find(int key){
    hashTable*tmp=NULL;
    HASH_FIND_INT(hashtable,&key,tmp);
    return tmp;
}

void delete(){
    hashTable*cur=NULL,*tmp=NULL;
    HASH_ITER(hh,hashtable,cur,tmp){
        HASH_DEL(hashtable,cur);
        free(cur);
    }
}

bool test(int key,int val,int k){
    hashTable*it=find(key);
    if(it!=NULL&&val-it->val<=k) return true;
    return false;
}

void update(int key,int val){
    hashTable*it=find(key);
    if(it==NULL){
        hashTable*tmp=(hashTable*)malloc(sizeof(hashTable));
        tmp->key=key;
        tmp->val=val;
        HASH_ADD_INT(hashtable,key,tmp);
    }else{
        it->val=val;
    }
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    int right;
    for(right=0;right<numsSize;right++){
        if(test(nums[right],right,k)){
            delete();
            return true;
        }
        update(nums[right],right);
    }
    delete();
    return false;
}
