/**
*题目：电话号码的字母组合
*日期：2026.5.26
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    char letter[8][5]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    char**ret=(char**)malloc(256*sizeof(char*));
    char tmp[5];
    for(int i=0;i<strlen(digits);i++){
        tmp[i]=letter[digits[i]-'2'][0];
    }
    *returnSize=0;
    int count[4]={0};
    for(int i=0;true;i++){
        ret[i]=(char*)malloc(5*sizeof(char));
        strcpy(ret[i],tmp);
        (*returnSize)++;
        int icount;
        for(icount=strlen(digits)-1;icount>=0;icount--){
            if(count[icount]==strlen(letter[digits[icount]-'2'])-1){
                count[icount]=0;
                tmp[icount]=letter[digits[icount]-'2'][0];
            }else{
                count[icount]++;
                break;
            }
        }
        if(icount<0){
            break;
        }
        tmp[icount]++;
    }
    return ret;
}
