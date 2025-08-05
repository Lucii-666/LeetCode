class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        int i=0;
        if(n==1){
            return 0;
        }
        long long total =0;
        for(int i=0;i<chalk.size();i++){
            total+=chalk[i];
        }
        total=k%total;
        if(total==0){
            return 0;
        }
        while(total>=chalk[i]){
            total=total-chalk[i%n];
            i=(i+1)%n;
        }
        return i;

    }
};