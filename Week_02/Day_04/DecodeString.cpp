// Using Stack
class Solution {
public:
    string decodeString(string s) {
       stack<int> cntStack;
       stack<string> stringStack;

       string curr = "";
       int k  = 0;

       for(char c : s) {
        if(isdigit(c)) {
            k = k * 10 + (c - '0');
        }
        else if (c == '[') {
            cntStack.push(k);
            stringStack.push(curr);
            k = 0;
            curr = "";
        }
        else if (c == ']') {
            int repeat = cntStack.top();
            cntStack.pop();
            string prev = stringStack.top();
            stringStack.pop();

            for(int i = 0; i < repeat; i++) {
                prev += curr;
            }
            curr =  prev;
        }
        else {
            curr += c;
        }
       } 
       return curr;
    }
};

// using recursion
class Solution {
public:
    string decodeString(string s) {
       int i = 0;
       return decode(s, i);  
    }

    string decode(string& s, int& i) {
        string res = "";
        int num = 0;
        while(i < s.size()) {
            if(isdigit(s[i])) {
                num = num* 10 + (s[i] - '0');
                i++;
            }
            else if(s[i] == '[') {
                i++;
                string inner = decode(s, i);
                for(int k = 0; k < num; k++) {
                    res += inner;
                }
                num = 0;
            }
            else if(s[i] == ']') {
                i++;
                return res;
            }
            else {
                res += s[i]; // now, normal char
                i++;
            }
        }
        return res;
    }
};
