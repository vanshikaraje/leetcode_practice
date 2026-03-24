class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for(int i = 0; i < s.length(); i++) {

            char c1 = s[i];
            char c2 = t[i];

            // check s -> t
            if(mp1.find(c1) != mp1.end()) {
                if(mp1[c1] != c2) {
                    return false;
                }
            } else {
                mp1[c1] = c2;
            }

            // check t -> s
            if(mp2.find(c2) != mp2.end()) {
                if(mp2[c2] != c1) {
                    return false;
                }
            } else {
                mp2[c2] = c1;
            }
        }

        return true;
    }
};