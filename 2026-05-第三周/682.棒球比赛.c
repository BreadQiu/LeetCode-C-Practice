/**
*题目：棒球比赛
*日期：2026.5.22
*/
int calPoints(char** operations, int operationsSize) {
    int*record=(int*)malloc(operationsSize*sizeof(int));
    int ret=0;
    for(int irecord=0,iop=0;iop<operationsSize;iop++){
        if(operations[iop][0]=='C'){
            ret-=record[--irecord];
        }else if(operations[iop][0]=='+'){
            ret+=record[irecord]=record[irecord-2]+record[irecord-1];
            irecord++;
        }else if(operations[iop][0]=='D'){
            ret+=record[irecord]=2*record[irecord-1];
            irecord++;
        }else{
            int num=0,tmp=1;
            for(int inum=strlen(operations[iop])-1;inum>0;inum--){
                num+=tmp*(operations[iop][inum]-'0');
                tmp*=10;
            }
            if(operations[iop][0]=='-'){
                num-=2*num;
            }else{
                num+=tmp*(operations[iop][0]-'0');
            }
            ret+=record[irecord]=num;
            irecord++;
        }
    }
    free(record);
    return ret;
}
