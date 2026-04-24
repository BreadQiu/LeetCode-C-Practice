/**
*题目：数组列表中的最大距离
*日期：2026.4.21
*/
int maxDistance(int** arrays, int arraysSize, int* arraysColSize) {
    int min=10000,max=-10000,i,ret=0;
    for(i=0;i<arraysSize;i++){
        ret=fmax(ret,max-arrays[i][0]);
        ret=fmax(ret,arrays[i][arraysColSize[i]-1]-min);
        min=fmin(min,arrays[i][0]);
        max=fmax(max,arrays[i][arraysColSize[i]-1]);
    }
    return ret;
}
