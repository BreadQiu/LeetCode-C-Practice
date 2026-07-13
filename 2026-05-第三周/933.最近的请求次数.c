/**
*题目：最近的请求次数
*日期：2026.5.16
*/
typedef struct {
    int arr[10000];
    int iping;
    int iobj;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter*obj=(RecentCounter*)malloc(sizeof(RecentCounter));
    //int*(obj->arr)=(int*)malloc(10000*sizeof(int));
    obj->iping=obj->iobj=0;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->arr[obj->iobj++]=t;
    while(obj->arr[obj->iping]<t-3000) obj->iping++;
    return obj->iobj-obj->iping;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);

 * recentCounterFree(obj);
*/
