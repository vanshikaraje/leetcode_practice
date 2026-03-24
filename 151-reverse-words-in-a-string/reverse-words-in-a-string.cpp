class Solution {
public:
    string reverseWords(string s) {
        
        int i = s.size() - 1;
        string ans = "";

        while(i >= 0){

            // skip spaces
            while(i >= 0 && s[i] == ' ') i--;

            if(i < 0) break;

            int j = i;

            // find word start
            while(i >= 0 && s[i] != ' ') i--;

            // add word
            if(!ans.empty()) ans += " ";
            ans += s.substr(i+1, j-i);
        }

        return ans;
    }
};