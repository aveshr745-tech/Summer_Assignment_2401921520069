class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int idx = 0;

        while (i < n) {
            char curr = chars[i];
            int count = 0;

            while (i < n && chars[i] == curr) {
                count++;
                i++;
            }
            chars[idx++] = curr;

            if (count > 1) {
                string freq = to_string(count);
                for (char c : freq) {
                    chars[idx++] = c;
                }
            }
        }

        return idx;
    }
};

// More in-place approach → extract digits manually and reverse them
class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();

        int i = 0;
        int j = 0;

        while (i < n) {

            char curr = chars[i];
            int start = i;
            while (i < n && chars[i] == curr) {
                i++;
            }

            int count = i - start;

            chars[j] = curr;
            j++;
            if (count > 1) {
                int digitsStart = j;
                while (count > 0) {
                    chars[j++] = (count % 10) + '0';
                    count /= 10;
                }
                reverse(chars.begin() + digitsStart,
                        chars.begin() + j);
            }
        }
        return j;
    }
};
