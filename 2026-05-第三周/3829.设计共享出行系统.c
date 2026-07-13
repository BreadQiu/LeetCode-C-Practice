/**
*题目：设计共享出行系统
*日期：2026.5.17
*/
typedef struct {
    int rider[1000];
    int driver[1000];
    int irider;
    int idriver;
    int riderSize;
    int driverSize;
} RideSharingSystem;


RideSharingSystem* rideSharingSystemCreate() {
    RideSharingSystem*obj=(RideSharingSystem*)malloc(sizeof(RideSharingSystem));
    obj->irider=obj->idriver=obj->riderSize=obj->driverSize=0;
    return obj;
}

void rideSharingSystemAddRider(RideSharingSystem* obj, int riderId) {
    obj->rider[obj->riderSize++]=riderId;
}

void rideSharingSystemAddDriver(RideSharingSystem* obj, int driverId) {
    obj->driver[obj->driverSize++]=driverId;
}

int* rideSharingSystemMatchDriverWithRider(RideSharingSystem* obj, int* retSize) {
    int*ret=(int*)malloc(2*sizeof(int));
    ret[0]=ret[1]=-1;
    *retSize=2;
    for(;obj->irider<obj->riderSize&&obj->rider[obj->irider]==0;obj->irider++);
    if(obj->irider==obj->riderSize) return ret;
    for(;obj->idriver<obj->driverSize&&obj->driver[obj->idriver]==0;obj->idriver++);
    if(obj->idriver==obj->driverSize) return ret;
    ret[0]=obj->driver[obj->idriver];
    ret[1]=obj->rider[obj->irider];
    obj->rider[obj->irider++]=obj->driver[obj->idriver++]=0;
    return ret;
}

void rideSharingSystemCancelRider(RideSharingSystem* obj, int riderId) {
    int i;
    for(i=obj->irider;i<obj->riderSize&&obj->rider[i]!=riderId;i++);
    if(i<obj->riderSize) obj->rider[i]=0;
}

void rideSharingSystemFree(RideSharingSystem* obj) {
    free(obj);
}

/**
 * Your RideSharingSystem struct will be instantiated and called as such:
 * RideSharingSystem* obj = rideSharingSystemCreate();
 * rideSharingSystemAddRider(obj, riderId);

 * rideSharingSystemAddDriver(obj, driverId);

 * int* param_3 = rideSharingSystemMatchDriverWithRider(obj, retSize);

 * rideSharingSystemCancelRider(obj, riderId);

 * rideSharingSystemFree(obj);
*/
