/**
*题目：统计梯形的数目 I
*日期：2026.5.3
*/
int countTrapezoids(int** points, int pointsSize, int* pointsColSize) {
    //int cnt[200000001]={0};
    long long*cnt=(long long*)calloc(200000001,sizeof(long long));
    int legal[50000];
    int i,legali;
    for(i=legali=0;i<pointsSize;i++){
        if(++cnt[points[i][1]+100000000]==2) legal[legali++]=points[i][1]+100000000;
    }
    long long sum=0;
    for(i=0;i<legali;i++){
        cnt[legal[i]]=cnt[legal[i]]*(cnt[legal[i]]-1)/2;
        sum+=cnt[legal[i]];
    }
    long long ret=0;
    for(i=0;i<legali-1;i++){
        sum-=cnt[legal[i]];
        ret+=cnt[legal[i]]*sum;
    }
    return ret%1000000007;
}
