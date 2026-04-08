/**
*题目：整数的各位积和之差
*日期：2026.3.30
*/
int subtractProductAndSum(int n) {
    int temp=0,add=0,plus=1;
    for(;n>0;n/=10){
        temp=n%10;
        add+=temp;
        plus*=temp;
    }
    return plus-add;
}
