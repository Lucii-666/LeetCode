class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int freq = 0;
        int maxfreq = 0 , n = candidates.size();

        for(int j = 0; j < 32 ;j++){
            for(int i = 0 ; i < n ;i++){
                if(candidates[i] & (1 << j)){
                    freq++;
                }
            }
            maxfreq = max(freq , maxfreq);
            freq = 0;
        }

        return maxfreq;
    }
};
