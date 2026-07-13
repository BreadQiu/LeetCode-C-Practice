/**
*题目：回旋镖的数量
*日期：2026.5.6
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

int function(int i,int j,int distance){
    int add=0;
    Hashtable*itj=find(1LL*j<<30|distance);
    if(itj==NULL){
        Hashtable*tmpj=(Hashtable*)malloc(sizeof(Hashtable));
        tmpj->key=1LL*j<<30|distance;
        tmpj->val=1;
        HASH_ADD(hh,hashtable,key,sizeof(long long),tmpj);
    }else{
        add+=2*itj->val;
        itj->val++;
    }
    Hashtable*iti=find(1LL*i<<30|distance);
    if(iti==NULL){
        Hashtable*tmpi=(Hashtable*)malloc(sizeof(Hashtable));
        tmpi->key=1LL*i<<30|distance;
        tmpi->val=1;
        HASH_ADD(hh,hashtable,key,sizeof(long long),tmpi);
    }else{
        add+=2*iti->val;
        iti->val++;
    }
    return add;
}

int numberOfBoomerangs(int** points, int pointsSize, int* pointsColSize) {
    int ret=0;
    for(int i=0;i<pointsSize-1;i++){
        for(int j=i+1;j<pointsSize;j++){
            ret+=function(i,j,(points[j][0]-points[i][0])*(points[j][0]-points[i][0])+(points[j][1]-points[i][1])*(points[j][1]-points[i][1]));
        }
    }
    deleteall();
    return ret;
}
