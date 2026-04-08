/**
*题目：统计范围内的元音字符串数
*日期：2026.4.1
*/
int vowelStrings(char** words, int wordsSize, int left, int right) {
    int i,sum=0;
    for(i=left;i<=right;++i){
        if((words[i][0]=='a'||words[i][0]=='e'||words[i][0]=='i'||words[i][0]=='o'||words[i][0]=='u')&&(words[i][strlen(words[i])-1]=='a'||words[i][strlen(words[i])-1]=='e'||words[i][strlen(words[i])-1]=='i'||words[i][strlen(words[i])-1]=='o'||words[i][strlen(words[i])-1]=='u')) ++sum;
    }
    return sum;
}
