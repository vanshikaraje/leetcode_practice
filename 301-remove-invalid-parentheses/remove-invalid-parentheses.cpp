class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while(!q.empty()) {
            string curr = q.front();
            q.pop();

            // Check valid hai ya nahi
            int count = 0;
            bool valid = true;

            for(char c : curr) {
                if(c == '(') {
                    count++;
                }
                else if(c == ')') {
                    count--;

                    if(count < 0) {
                        valid = false;
                        break;
                    }
                }
            }

            if(count != 0)
                valid = false;

            if(valid) {
                ans.push_back(curr);
                found = true;
            }

            // Agar current level par valid mil gaya,
            // toh aur brackets remove nahi karne
            if(found)
                continue;

            // Ek-ek bracket remove karke next strings banao
            for(int i = 0; i < curr.size(); i++) {
                if(curr[i] != '(' && curr[i] != ')')
                    continue;

                string next = curr.substr(0, i) + curr.substr(i + 1);

                if(visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return ans;
    }
};