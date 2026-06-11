// using extra String
class Solution {
public:
    string reverseWords(string s) {
      string ans = "";
      string word = "";

      for(char ch : s) {
        if(ch == ' ') {
            reverse(word.begin(), word.end());
            ans += word;
            ans += ' ';
            word = "";
        }
        else {
            word += ch;
        }
      }
      reverse(word.begin(), word.end());
      ans += word;
      return ans;
    }
};

//Using two pointers(Optimized Version)

class Solution {
public:
    string reverseWords(string s) {
        int i = 0;

        for (int j = 0; j <= s.size(); j++) {
            if (j == s.size() || s[j] == ' ') {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }

        return s;
    }
};
