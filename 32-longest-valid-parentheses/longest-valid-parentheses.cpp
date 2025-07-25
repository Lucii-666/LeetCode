class Solution {
public:
    int longestValidParentheses(string s) {
        // With opp scan technique
        int l = 0, r = 0, n = s.length(), maxi = 0;
        for(int i=0;i<n;i++){
            l += (s[i] == '(') ? 1 : 0;
            r += (s[i] == ')') ? 1 : 0;

            if(l == r) maxi = max(maxi, 2*l);

            if(r > l) l = r = 0;
        }

        l = r = 0;
        for(int i=n-1;i>=0;i--){
            l += (s[i] == '(') ? 1 : 0;
            r += (s[i] == ')') ? 1 : 0;

            if(l == r) maxi = max(maxi, 2*l);

            if(l > r) l = r = 0;
        }

        return maxi;
    }
};