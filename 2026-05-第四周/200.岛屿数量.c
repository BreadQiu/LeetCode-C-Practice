/**
*题目：岛屿数量
*日期：2026.5.25
*/
typedef struct{
    int key;
    int val;
    UT_hash_handle hh;
}Hashtable;

Hashtable*hashtable=NULL;

Hashtable*find(int key){
    Hashtable*tmp=NULL;
    HASH_FIND_INT(hashtable,&key,tmp);
    return tmp;
}

void deleteall(){
    Hashtable*cur=NULL,*tmp=NULL;
    HASH_ITER(hh,hashtable,cur,tmp){
        HASH_DEL(hashtable,cur);
        free(cur);
    }
}

void add(int key,int val){
    Hashtable*tmp=(Hashtable*)malloc(sizeof(Hashtable));
    tmp->key=key;
    tmp->val=val;
    HASH_ADD_INT(hashtable,key,tmp);
}

void refresh(int i,int j,int val){
    if(i){
        Hashtable*up=find((i-1)<<9|j);
        if(up!=NULL&&up->val>val){
            up->val=val;
            refresh(i-1,j,val);
        }
    }
    Hashtable*down=find((i+1)<<9|j);
    if(down!=NULL&&down->val>val){
        down->val=val;
        refresh(i+1,j,val);
    }
    if(j){
        Hashtable*left=find(i<<9|(j-1));
        if(left!=NULL&&left->val>val){
            left->val=val;
            refresh(i,j-1,val);
        }
    }
    Hashtable*right=find(i<<9|(j+1));
    if(right!=NULL&&right->val>val){
        right->val=val;
        refresh(i,j+1,val);
    }
}

int function(int i,int j,int valmax){
    int valmin=INT_MAX;
    if(i){
        Hashtable*up=find((i-1)<<9|j);
        if(up!=NULL){
            valmin=up->val;
        }
    }
    if(j){
        Hashtable*left=find(i<<9|(j-1));
        if(left!=NULL){
            if(valmin!=INT_MAX&&valmin!=left->val){//up&left
                valmin=fmin(valmin,left->val);
                add(i<<9|j,valmin);
                refresh(i,j,valmin);
                return -1;
            }else{//left
                add(i<<9|j,left->val);
                return 0;
            }
        }
    }
    if(valmin==INT_MAX){//none
        add(i<<9|j,valmax+1);
        return 1;
    }else{//up
        add(i<<9|j,valmin);
        return 0;
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int ret=0;
    int valmax=0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<*gridColSize;j++){
            if(grid[i][j]=='1'){
                int tmp=function(i,j,valmax);
                if(tmp==-1){
                    ret--;
                }else if(tmp==1){
                    ret++;
                    valmax++;
                }
            }
        }
    }
    deleteall();
    return ret;
}
