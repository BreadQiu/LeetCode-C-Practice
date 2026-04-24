/**
*题目：考试的最大困扰度
*日期：2026.4.17
*/
int maxConsecutiveAnswers(char* answerKey, int k) {
    int sumF=0,sumT=0,max=0,left,right;
    for(left=0,right=0;right<strlen(answerKey);right++){
        if(answerKey[right]=='T') sumT++;
        else sumF++;
        max=fmax(max,right-left);
        while(sumT>k){
            if(answerKey[left]=='T') sumT--;
            else sumF--;
            left++;
        }
    }
    max=fmax(max,right-left);
    sumF=sumT=0;
    for(left=0,right=0;right<strlen(answerKey);right++){
        if(answerKey[right]=='T') sumT++;
        else sumF++;
        max=fmax(max,right-left);
        while(sumF>k){
            if(answerKey[left]=='T') sumT--;
            else sumF--;
            left++;
        }
    }
    return fmax(max,right-left);
}
