class Solution {
public:
    string toHex(int num) {
        if(num==0){
            return "0";
        }
        string s="";
        int n;
        char c;
        for(int i=0; i<8; i++){
            n=(num&15);
            if(n<10){
                c=char(n+48);
            }
            else{
                c=char(n+87);
            }
            s=c+s;
            num=num>>4;
        }
        while(s[0]=='0'){
            s.erase(s.begin());
        }
        return s;
    }
};