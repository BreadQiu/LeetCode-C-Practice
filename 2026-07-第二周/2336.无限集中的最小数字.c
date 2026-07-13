/**
*题目：无限集中的最小数字
*日期：2026.7.12
*/
int cmp(const void*a,const void*b){
    return *(int*)b-*(int*)a;
}


typedef struct {
    int*add;
    int addSize;
    int delete;
} SmallestInfiniteSet;


SmallestInfiniteSet* smallestInfiniteSetCreate() {
    SmallestInfiniteSet*obj=(SmallestInfiniteSet*)malloc(sizeof(SmallestInfiniteSet));
    obj->add=(int*)malloc(1000*sizeof(int));
    obj->addSize=0;
    obj->delete=0;
    return obj;
}

int smallestInfiniteSetPopSmallest(SmallestInfiniteSet* obj) {
    if(obj->addSize){
        int ret=obj->add[obj->addSize-1];
        obj->addSize--;
        return ret;
    }
    obj->delete++;
    return obj->delete;
}

void smallestInfiniteSetAddBack(SmallestInfiniteSet* obj, int num) {
    if(num<=obj->delete){
        int val=-1;
        for(int left=0,right=obj->addSize-1;left<=right;){
            int now=(left+right)/2;
            if(num>obj->add[now]){
                right=now-1;
            }else if(num<obj->add[now]){
                left=now+1;
            }else{
                val=now;
                break;
            }
        }
        if(val==-1){
            obj->add[obj->addSize++]=num;
            qsort(obj->add,obj->addSize,sizeof(int),cmp);
        }/*else{
            int tmp=obj->add[val];
            obj->add[val]=obj->add[obj->addSize-1];
            obj->add[obj->addSize-1]=tmp;
            obj->addSize--;
            qsort(obj->add,obj->addSize,sizeof(int),cmp);
        }*/
    }
}

void smallestInfiniteSetFree(SmallestInfiniteSet* obj) {
    free(obj->add);
    free(obj);
}

/**
 * Your SmallestInfiniteSet struct will be instantiated and called as such:
 * SmallestInfiniteSet* obj = smallestInfiniteSetCreate();
 * int param_1 = smallestInfiniteSetPopSmallest(obj);

 * smallestInfiniteSetAddBack(obj, num);

 * smallestInfiniteSetFree(obj);
*/
