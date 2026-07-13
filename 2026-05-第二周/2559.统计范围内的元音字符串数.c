/**
*题目：统计范围内的元音字符串数
*日期：2026.5.10
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int vowel(char letter){
     if(letter=='a'||letter=='e'||letter=='i'||letter=='o'||letter=='u') return 1;
     return 0;
 }

int* vowelStrings(char** words, int wordsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int*s=(int*)malloc((wordsSize+1)*sizeof(int));
    s[0]=0;
    for(int i=1;i<=wordsSize;i++){
        s[i]=s[i-1]+vowel(words[i-1][0])*vowel(words[i-1][strlen(words[i-1])-1]);
    }
    int*ret=(int*)malloc(queriesSize*sizeof(int));
    for(int i=0;i<queriesSize;i++){
        ret[i]=s[queries[i][1]+1]-s[queries[i][0]];
    }
    *returnSize=queriesSize;
    return ret;
}
