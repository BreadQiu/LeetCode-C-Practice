/**
*题目：矩形区域不超过 K 的最大数值和
*日期：2026.6.22
*/
int max;

int cmp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}

int function(int*tmp,int itmp,int arr,int ret){
    int find=arr-max;
    int ileft;
    for(int left=0,right=itmp-1;left<=right;){
        int mid=(left+right)/2;
        if(tmp[mid]<find){
            left=mid+1;
        }else if(tmp[mid]>find){
            right=mid-1;
        }else{
            ileft=left;
            break;
        }
        ileft=left;
    }
    for(;ileft<itmp&&tmp[ileft]<find;ileft++);
    if(ileft<itmp){
        ret=fmax(ret,arr-tmp[ileft]);
    }
    return ret;
}

int maxSumSubmatrix(int** matrix, int matrixSize, int* matrixColSize, int k) {
    max=k;
    int m=matrixSize;
    int n=*matrixColSize;
    int cnt[m+1][n+1];
    int ret=INT_MIN;
    for(int i=0;i<m;i++){
        int tmp[n+1];
        int itmp=0;
        tmp[itmp++]=cnt[i][0]=0;
        for(int j=0;j<n;j++){
            cnt[i][j+1]=matrix[i][j]+cnt[i][j];
            ret=function(tmp,itmp,cnt[i][j+1],ret);
            if(ret==k){
                return k;
            }
            tmp[itmp++]=cnt[i][j+1];
            qsort(tmp,itmp,sizeof(int),cmp);
        }
    }
    for(int i1=0;i1<m-1;i1++){
        int cntlong[n+1];
        memcpy(cntlong,cnt[i1],(n+1)*sizeof(int));
        for(int i2=i1+1;i2<m;i2++){
            int tmp[n+1];
            int itmp=0;
            tmp[itmp++]=0;
            for(int j=0;j<n;j++){
                cntlong[j+1]+=cnt[i2][j+1];
                ret=function(tmp,itmp,cntlong[j+1],ret);
                if(ret==k){
                    return k;
                }
                tmp[itmp++]=cntlong[j+1];
                qsort(tmp,itmp,sizeof(int),cmp);
            }
        }
    }
    return ret;
}
