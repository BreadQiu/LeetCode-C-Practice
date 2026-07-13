/**
*题目：设计浏览器历史记录
*日期：2026.7.1
*/



typedef struct {
    char**record;
    int recordSize;
    int now;
    } BrowserHistory;

BrowserHistory* browserHistoryCreate(char* homepage) {
    BrowserHistory*obj=(BrowserHistory*)malloc(sizeof(BrowserHistory));
    obj->record=(char**)malloc(5000*sizeof(char*));
    obj->recordSize=1;
    obj->record[0]=(char*)malloc(21*sizeof(char));
    strcpy(obj->record[0],homepage);
    obj->now=0;
    return obj;
}

void browserHistoryVisit(BrowserHistory* obj, char* url) {
    obj->recordSize=obj->now+2;
    obj->record[obj->recordSize-1]=(char*)malloc(21*sizeof(char));
    strcpy(obj->record[obj->recordSize-1],url);
    obj->now++;
}

char* browserHistoryBack(BrowserHistory* obj, int steps) {
    obj->now-=fmin(steps,obj->now);
    return obj->record[obj->now];
}

char* browserHistoryForward(BrowserHistory* obj, int steps) {
    obj->now+=fmin(steps,obj->recordSize-1-obj->now);
    return obj->record[obj->now];
}

void browserHistoryFree(BrowserHistory* obj) {
    free(obj->record);
    free(obj);
}

/**
 * Your BrowserHistory struct will be instantiated and called as such:
 * BrowserHistory* obj = browserHistoryCreate(homepage);
 * browserHistoryVisit(obj, url);

 * char* param_2 = browserHistoryBack(obj, steps);

 * char* param_3 = browserHistoryForward(obj, steps);

 * browserHistoryFree(obj);
*/
