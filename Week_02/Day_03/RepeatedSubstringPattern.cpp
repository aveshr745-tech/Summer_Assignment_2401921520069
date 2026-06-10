// Brute force Approach
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        for (int len = 1; len <= n / 2; len++) {
            if (n % len == 0) {
                string pattern = s.substr(0, len);
                string temp = "";

                int times = n / len;
                for (int i = 0; i < times; i++) {
                    temp += pattern;
                }

                if (temp == s) return true;
            }
        }

        return false;
    }
};

// Using KMP algorithm for optimization
class Solution {
private:
    bool solve(string& s) {
        int n = s.size();
        vector<int> lps(n, 0);
        int len = 0, i = 1;
        int maxlen = 0;
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
                maxlen = max(maxlen, len);
            } else {
                if (len != 0)
                    len = lps[len - 1];
                else
                    i++;
            }
        }

        len = lps[n - 1];
        return (len > 0 && n % (n - len) == 0);
    }

public:
    bool repeatedSubstringPattern(string s) {
         return solve(s); }
};
