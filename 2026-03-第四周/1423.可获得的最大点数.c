/**
*题目：可获得的最大点数
*日期：2026.3.29
*/
int maxScore(int* cardPoints, int cardPointsSize, int k) {
    int i,j;
    long long max=0,sum=0;
    for(i=0;i<k;++i) sum+=cardPoints[i];
    max=sum;
    for(j=cardPointsSize-1,--i;j>=cardPointsSize-k;--j,--i){
        sum+=cardPoints[j];
        sum-=cardPoints[i];
        max=fmax(sum,max);
    }
    return max;
}
