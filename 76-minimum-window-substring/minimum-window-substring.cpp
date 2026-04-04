class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> freqT(128, 0), freqS(128, 0);

        for (char c : t) freqT[c]++;

        int i = 0, count = 0;
        int minLen = INT_MAX, start = 0;

        for (int j = 0; j < s.length(); j++) {

            freqS[s[j]]++;

            if (freqS[s[j]] <= freqT[s[j]]) {
                count++;
            }

            // valid window
            while (count == t.length()) {

                // update answer
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                // shrink
                freqS[s[i]]--;

                if (freqS[s[i]] < freqT[s[i]]) {
                    count--;
                }

                i++;
            }
        }

        if (minLen == INT_MAX) return "";
        return s.substr(start, minLen);
    }
};