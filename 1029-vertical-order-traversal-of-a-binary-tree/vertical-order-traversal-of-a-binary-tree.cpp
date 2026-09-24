class Solution {
public:

    void solve(TreeNode* root, int row, int col,
               vector<vector<int>>& nodes) {
        
        if(root == NULL)
            return;

        // store: col, row, value
        nodes.push_back({col, row, root->val});

        solve(root->left, row+1, col-1, nodes);
        solve(root->right, row+1, col+1, nodes);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> nodes;   // will store {col,row,value}
        vector<vector<int>> ans;

        solve(root, 0, 0, nodes);

        // sort by col, then row, then value
        sort(nodes.begin(), nodes.end());

        int prevCol = nodes[0][0];
        vector<int> column;

        for(int i = 0; i < nodes.size(); i++) {

            int col = nodes[i][0];
            int value = nodes[i][2];

            if(col != prevCol) {
                ans.push_back(column);
                column.clear();
                prevCol = col;
            }

            column.push_back(value);
        }

        ans.push_back(column);

        return ans;
    }
};