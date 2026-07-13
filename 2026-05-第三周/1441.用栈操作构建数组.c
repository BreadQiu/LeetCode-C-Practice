/**
*题目：用栈操作构建数组
*日期：2026.5.15
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    char**str=(char**)malloc(2*target[targetSize-1]*sizeof(char*));
    int istr=0;
    for(int itarget=0,in=1;itarget<targetSize;){
        str[istr]=(char*)malloc(5*sizeof(char));
        strcpy(str[istr++],"Push");
        if(target[itarget]>in){
            str[istr]=(char*)malloc(4*sizeof(char));
            strcpy(str[istr++],"Pop");
            in++;
        }else{
            itarget++;
            in++;
        }
    }
    *returnSize=istr;
    return str;
}
