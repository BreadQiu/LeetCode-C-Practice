/**
*题目：必须拿起的最小连续卡牌数
*日期：2026.4.24
*/
int minimumCardPickup(int* cards, int cardsSize) {
    int cnt[1000001]={0};
    int left,right,min=INT_MAX;
    for(left=right=0;right<cardsSize;right++){
        cnt[cards[right]]++;
        while(cnt[cards[right]]>1){
            min=fmin(min,right-left+1);
            cnt[cards[left]]--;
            left++;
        }
    }
    if(min==INT_MAX) return -1;
    return min;
}
