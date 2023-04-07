bool same(struct TreeNode* l,struct TreeNode* r)
{
    if(l == NULL && r == NULL)
    {
        return true;
    }
    if(l == NULL || r == NULL)
    {
        return false;
    }
    if(l->val != r->val)
    {
        return false;
    }

    return same(l->left,r->right) && same(l->right,r->left);

}

bool isSymmetric(struct TreeNode* root){
    if(same(root->left,root->right))
    {
        return true;
    }
    return false;
}