class Solution {
public:
    string getPermutation(int n, int k) {
        int j=1,val=0;
        for(int i=1;i<n;i++){
            j*=i;
        }
        set<char>s;
        for(char i='1';i<=n+'0';i++){
            s.insert(i);
        }
        string ans;
        while(val<k && n>0){
            set<char>t=s;
            while(k>val+j){
                val+=j;
                t.erase(t.begin());
            }
            ans.push_back(*(t.begin()));
            s.erase(*(t.begin()));
            t.erase(t.begin());
            n--;
            if(n>0){
                j/=n;
            }
        }
        return ans;
    }
};