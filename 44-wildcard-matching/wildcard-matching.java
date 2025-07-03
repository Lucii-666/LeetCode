class Solution {
    public boolean isMatch(String s, String p) {
        // int m = p.length();
        // int n = s.length();
        // boolean[][] memo = new boolean[m][n];
        // int[][] dp = new int[m][n];
        // return f(0, 0, p, s, memo, dp);
        // return tabulation(p, s);


        return SO(p,s);
    }

    static boolean f(int i, int j, String s1, String s2, boolean[][] memo, int[][] dp) {
        int m = s1.length();
        int n = s2.length();

        if (i == m && j == n)
            return true;
        if (i == m && j < n)
            return false;
        if (i < m && j == n) {
            for (int k = i; k < m; k++) {
                if (s1.charAt(k) != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != 0)
            return memo[i][j];
        dp[i][j] = 1;
        if (s1.charAt(i) == s2.charAt(j) || s1.charAt(i) == '?')
            return memo[i][j] = f(i + 1, j + 1, s1, s2, memo, dp);
        else if (s1.charAt(i) == '*') {
            return memo[i][j] = f(i + 1, j, s1, s2, memo, dp) || f(i, j + 1, s1, s2, memo, dp);
        }
        return memo[i][j] = false;
    }

    static boolean tabulation(String s1, String s2) {
        int m = s1.length();
        int n = s2.length();

        boolean dp[][] = new boolean[m + 1][n + 1];
        dp[m][n] = true;

        for (int j = 0; j < n; j++) {
            dp[m][j] = false;
        }
        for (int i = 0; i < m; i++) {
            for (int k = i; k < m; k++) {
                if (s1.charAt(k) != '*') {
                    dp[i][n] = false;
                    break;
                } else {
                    dp[i][n] = true;
                }
            }
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s1.charAt(i) == s2.charAt(j) || s1.charAt(i) == '?')
                    dp[i][j] = dp[i + 1][j + 1];
                else if (s1.charAt(i) == '*') {
                    dp[i][j] = dp[i + 1][j] || dp[i][j + 1];
                } else
                    dp[i][j] = false;
            }
        }

        return dp[0][0];
    }

    static boolean SO(String s1, String s2) {
        int m = s1.length();
        int n = s2.length();

        boolean prev[] = new boolean[n + 1];
        prev[n] = true;

        for (int j = 0; j < n; j++) {
            prev[j] = false;
        }

        for (int i = m - 1; i >= 0; i--) {

            boolean[] curr = new boolean[n + 1];
            for (int k = i; k < m; k++) {
                if (s1.charAt(k) != '*') {
                    curr[n] = false;
                    break;
                } else {
                    curr[n] = true;
                }
            }
            for (int j = n - 1; j >= 0; j--) {
                if (s1.charAt(i) == s2.charAt(j) || s1.charAt(i) == '?')
                    curr[j] = prev[j + 1];
                else if (s1.charAt(i) == '*') {
                    curr[j] = prev[j] || curr[j + 1];
                } else
                    curr[j] = false;
            }
            prev = curr;
        }

        return prev[0];
    }
}