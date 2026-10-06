class Solution {
public:
    int maxDepth(string s) {
        int res = 0 ,cur = 0;
      for(int i = 0;i<s.length();i++){
        char ch = s[i];
        if(ch=='('){
            cur++;
            res = max(res,cur);
        }
        else if(ch==')'){
            cur--;
        }

      }
      return res;
    }
};