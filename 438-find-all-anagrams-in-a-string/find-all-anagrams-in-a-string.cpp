class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        int n = s.length();
        int m = p.length();

        if (m > n) return ans;

        vector<int> freqP(26, 0), freqS(26, 0);

        // p ka freq
        for (char c : p) {
            freqP[c - 'a']++;
        }

        int i = 0;

        for (int j = 0; j < n; j++) {

            // add char
            freqS[s[j] - 'a']++;

            // window size bada ho gaya
            if (j - i + 1 > m) {
                freqS[s[i] - 'a']--;
                i++;
            }

            // match mila
            if (freqS == freqP) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};