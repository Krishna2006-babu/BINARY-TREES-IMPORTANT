class Solution {
public:
    int func(TreeNode* root, int curr){
        curr = curr*10 + root->val;

        if(root->left == NULL && root->right == NULL){
            return curr;
        }

        int left = 0, right = 0;

        if(root->left)
            left = func(root->left, curr);

        if(root->right)
            right = func(root->right, curr);

        return left + right;
    }

    int sumNumbers(TreeNode* root) {
        return func(root, 0);
    }
};
