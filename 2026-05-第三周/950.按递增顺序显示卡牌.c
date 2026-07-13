/**
*题目：按递增顺序显示卡牌
*日期：2026.5.19
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int cmp(const void*a,const void*b){
     return *(int*)a-*(int*)b;
 }

int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize) {
    int*cnt=(int*)malloc(((deckSize+1)*(deckSize/2+1)/2+2)*sizeof(int));
    int*turn=(int*)malloc(deckSize*sizeof(int));
    for(int cntSize=deckSize,turnSize=0,i=0;i<cntSize;i++){
        if(i<deckSize) cnt[i]=i;
        if(i%2==0){
            turn[turnSize++]=cnt[i];
        }else{
            cnt[cntSize++]=cnt[i];
        }
    }
    qsort(deck,deckSize,sizeof(int),cmp);
    int*ret=(int*)malloc(deckSize*sizeof(int));
    for(int i=0;i<deckSize;i++){
        ret[turn[i]]=deck[i];
    }
    *returnSize=deckSize;
    free(cnt);
    free(turn);
    return ret;
}
