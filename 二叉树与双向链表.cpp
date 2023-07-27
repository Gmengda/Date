/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 * };
 */
 
/**
 *
 * @param pRootOfTree TreeNode类
 * @return TreeNode类
 */
struct TreeNode* Convert(struct TreeNode* pRootOfTree ) {
    if(!pRootOfTree)
        return pRootOfTree;
    struct TreeNode* p=pRootOfTree;
    if(pRootOfTree->left)
    {
        Convert(pRootOfTree->left);
        p=pRootOfTree->left;
        while(p->right)
            p=p->right;
        pRootOfTree->left=p;
        p->right=pRootOfTree;
    }
    if(pRootOfTree->right)
    {
        Convert(pRootOfTree->right);
        p=pRootOfTree->right;
        while(p->left)
            p=p->left;
        pRootOfTree->right=p;
        p->left=pRootOfTree;
    } 
    while(p->left)
        p=p->left;
    return p;
}