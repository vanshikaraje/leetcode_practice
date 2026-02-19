class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;

        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            // check left child
            if(temp->left){
                // if left child is a leaf
                if(temp->left->left == NULL && temp->left->right == NULL){
                    sum += temp->left->val;
                }
                else{
                    q.push(temp->left);
                }
            }

            // push right child normally
            if(temp->right){
                q.push(temp->right);
            }
        }

        return sum;
    }
};