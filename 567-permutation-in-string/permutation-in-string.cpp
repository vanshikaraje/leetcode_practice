class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n1 = s1.length();
        int n2 = s2.length();

        if (n1 > n2) return false;

        vector<int> freq1(26, 0), freq2(26, 0);

        // s1 ka freq
        for (char c : s1) {
            freq1[c - 'a']++;
        }

        int i = 0;

        for (int j = 0; j < n2; j++) {

            // window me add karo
            freq2[s2[j] - 'a']++;

            // window size > n1 → shrink karo
            if (j - i + 1 > n1) {
                freq2[s2[i] - 'a']--;
                i++;
            }

            // compare
            if (freq1 == freq2) return true;
        }

        return false;
    }
};