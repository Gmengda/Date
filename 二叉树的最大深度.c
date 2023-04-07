int maxDepth(struct TreeNode* root){
    if(root == NULL)
    {
        return 0;
    }

    int x = maxDepth(root->left) + 1;
    int y = maxDepth(root->right) + 1;

    return x > y ? x : y;
}