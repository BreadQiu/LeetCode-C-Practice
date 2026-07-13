/**
*题目：K 次乘运算后的最终数组 I
*日期：2026.5.24
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct{
    int key;
    int*val;
    int num;
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

int cmp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}

void add(int key,int val){
    Hashtable*it=find(key);
    if(it==NULL){
        Hashtable*tmp=(Hashtable*)malloc(sizeof(Hashtable));
        tmp->key=key;
        tmp->val=(int*)malloc(sizeof(int)*100);
        tmp->val[0]=val;
        tmp->num=1;
        HASH_ADD_INT(hashtable,key,tmp);
    }else{
        it->val[it->num++]=val;
        qsort(it->val,it->num,sizeof(int),cmp);
    }
}

void function(int*nums,int numsSize,int*ret,int multiplier){
    Hashtable*tmp=find(nums[0]);
    nums[0]*=multiplier;
    qsort(nums,numsSize,sizeof(int),cmp);//nums

    ret[tmp->val[0]]*=multiplier;//ret

    add(tmp->key*multiplier,tmp->val[0]);//tmp->key*multiplier

    tmp->val[0]=INT_MAX;
    qsort(tmp->val,tmp->num,sizeof(int),cmp);
    tmp->num--;//tmp->key
}

int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize) {
    int*ret=(int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++){
        ret[i]=nums[i];
        add(nums[i],i);
    }
    qsort(nums,numsSize,sizeof(int),cmp);
    for(int i=0;i<k;i++){
        function(nums,numsSize,ret,multiplier);
    }
    deleteall();
    *returnSize=numsSize;
    return ret;
}
