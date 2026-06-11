// Using backtracking
class Solution {
public:
    void backtrack(string &curr, int open, int close, int n, vector<string> &res){
          if(curr.length() == 2*n) {
            res.push_back(curr);
            return;
          } 
          if(open < n) {
            curr.push_back('(');
            backtrack(curr, open + 1, close, n, res);
            curr.pop_back();
          } 
          if(close < open) {
            curr.push_back(')');
            backtrack(curr, open, close + 1, n, res);
            curr.pop_back();
          }   
    }
    vector<string> generateParenthesis(int n) {
         vector<string> res;
         string curr;
         backtrack(curr, 0, 0, n, res); 
         return res;
    }
};

//Using DP
class Solution {
public:
    vector<string> generateParenthesis(int n) {

        vector<vector<string>> dp(n + 1);
        dp[0] = {""};

        for(int len = 1; len <= n; len++) {

            for(int i = 0; i < len; i++) {

                for(string left : dp[i]) {

                    for(string right : dp[len - 1 - i]) {

                        dp[len].push_back(
                            "(" + left + ")" + right
                        );
                    }
                }
            }
        }

        return dp[n];
    }
};
