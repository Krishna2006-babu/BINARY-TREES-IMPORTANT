class Solution {
public:
    TreeNode* dfs(TreeNode* root,int val,int depth,int curr){
        if(root == NULL){
            return NULL;
        }

        if(curr == depth-1){
            TreeNode* temp1 = root->left;
            TreeNode* temp2 = root->right;

            TreeNode* new1 = new TreeNode(val);
            TreeNode* new2 = new TreeNode(val);

            root->left = new1;
            root->right = new2;

            new1->left = temp1;
            new2->right = temp2;

            return root; 
        }

        root->left = dfs(root->left,val,depth,curr+1);
        root->right = dfs(root->right,val,depth,curr+1);

        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }

        return dfs(root,val,depth,1);
    }
};
