/**
*题目：寻找比目标字母大的最小字母
*日期：2026.4.13
*/
char nextGreatestLetter(char* letters, int lettersSize, char target) {
    int left,right,now;
    for(left=0,right=lettersSize-1;1;){
        now=(left+right)/2;
        if(now==left){
            if(letters[now]<=target&&letters[right]>target) return letters[right];
            else return letters[0];
        }
        else if(letters[now]<=target) now=((left=now)+right)/2;
        else{
            if(letters[now-1]>target) now=(left+(right=now))/2;
            else return letters[now];
            }
    }
}
