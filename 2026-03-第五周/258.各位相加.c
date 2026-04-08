/**
*题目：各位相加
*日期：2026.3.30
*/
int addDigits(int num) {
    int temp=0;
    for(;num>=10;num=temp,temp=0){
        for(;num>0;num/=10){
            temp+=num%10;
        }
    }
    return num;
}
