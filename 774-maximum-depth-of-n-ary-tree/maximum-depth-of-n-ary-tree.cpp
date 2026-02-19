/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void bfs(Node*root,int&ans){
        if(root==NULL)
        return;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i<size;i++){
                Node*temp = q.front();
                q.pop();
                
                for(int j = 0;j<temp->children.size();j++){
                    q.push(temp->children[j]);

                }
            }
            ans++;
        }
    }
    int maxDepth(Node* root) {
        int ans = 0;
        bfs(root,ans);
        return ans;
    }
};