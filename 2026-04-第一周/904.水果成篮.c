/**
*题目：水果成篮
*日期：2026.4.7
*/
int totalFruit(int* fruits, int fruitsSize) {
    int left,right,middle,lefttemp,max;
    for(left=0,right=0;right<fruitsSize&&fruits[right]==fruits[left];++right);
    lefttemp=middle=right;
    max=right-left;
    if(right==fruitsSize) return max;
    for(++right;right<fruitsSize;++right){
        if(fruits[right]!=fruits[left]&&fruits[right]!=fruits[middle]){
            max=fmax(right-left,max);
            left=lefttemp;
            middle=right;
        }
        if(fruits[right]!=fruits[right-1]) lefttemp=right;
    }
    return fmax(right-left,max);
}
