
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) 
    {
        return true;
    } 
    else if (p == NULL || q == NULL) 
    {
        return false;
    } 
    else if (p->val != q->val) 
    {
        return false;
    } 
    else 
    {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot){
    if(root == NULL)
    {
        return false;
    }

    if(isSameTree(root,subRoot))
    {
        return true;
    }

    return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
}