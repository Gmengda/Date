void preorder(struct TreeNode* root, int* res, int* resSize) {
    if (root == NULL) {
        return;
    }
    
    preorder(root->left, res, resSize);
    res[(*resSize)++] = root->val;
    preorder(root->right, res, resSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = malloc(sizeof(int) * 2000);
    *returnSize = 0;
    preorder(root, res, returnSize);
    return res;
}