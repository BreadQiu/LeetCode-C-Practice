/**
*题目：Dota2 参议院
*日期：2026.5.17
*/
char* predictPartyVictory(char* senate) {
    for(int killR=0,killD=0;true;){
        bool hasR=false,hasD=false;
        for(int i=0;i<strlen(senate);i++){
            if(senate[i]=='R'){
                if(killR){
                    senate[i]='N';
                    killR--;
                }else{
                    hasR=true;
                    killD++;
                }
            }
            else if(senate[i]=='D'){
                if(killD){
                    senate[i]='N';
                    killD--;
                }else{
                    hasD=true;
                    killR++;
                }
            }
        }
        if(hasD==false) return "Radiant";
        if(hasR==false) return "Dire";
    }
}
