// Using Hashmap
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;

        for(char c : magazine) {
            mp[c]++; 
        }

        for(char c : ransomNote) {
            if(mp[c]-- <= 0) {
                return false;
            }
        }

        return true;
    }
};

// using Frequency Array
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26] = {0};

        for(char c : magazine) {
            freq[c - 'a']++;
        }

        for(char c : ransomNote) {
            if(freq[c - 'a']-- <= 0) {
                return false;
            }
        }

        return true;
    }
};
