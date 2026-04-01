class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i =0;
        while(i<n){
            int start = i;
            while(i<n&&s[i]!=' '){
                i++;
            }
            int end = i-1;
            while(start<end){
                char temp = s[start];
                s[start]=s[end];
                s[end]=temp;
                start++;
                end--;
            }
            i++;
        }
        return s;
    }
};