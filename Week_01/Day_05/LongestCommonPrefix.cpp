/*Using sorting logic*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs[strs.size()-1];
        int minlength = min(first.size(), last.size());
        string res = "";
        for(int i=0; i<minlength; i++){
            if(first[i] != last[i]){
                break;
            }
            res += first[i];
        }
        return res;
    }
};

/*Using Built-in function substr*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
