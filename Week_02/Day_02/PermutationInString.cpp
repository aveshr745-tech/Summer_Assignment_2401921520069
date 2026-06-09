// Using HashMap
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (n > m) return false;

        unordered_map<char, int> mp1, mp2;

        for (char ch : s1)
            mp1[ch]++;

        for (int i = 0; i < n; i++)
            mp2[s2[i]]++;

        if (mp1 == mp2)
            return true;

        for (int i = n; i < m; i++) {
            mp2[s2[i]]++;

            mp2[s2[i - n]]--;
            if (mp2[s2[i - n]] == 0)
                mp2.erase(s2[i - n]);

            if (mp1 == mp2)
                return true;
        }

        return false;
    }
};


/*As there are only lowercase letters we can use frequency array of size 26 (Slightly Optimized Version)*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (n > m) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (char ch : s1)
            freq1[ch - 'a']++;

        for (int i = 0; i < n; i++)
            freq2[s2[i] - 'a']++;

        if (freq1 == freq2)
            return true;

        for (int i = n; i < m; i++) {
            freq2[s2[i] - 'a']++;

            freq2[s2[i - n] - 'a']--;

            if (freq1 == freq2)
                return true;
        }

        return false;
    }
};
