#include<bits/stdc++.h>
class BST{
stack<BinaryTreeNode*>s;
bool rev=true;

public:
BST(BinaryTreeNode *root,bool reverse)
{
    rev=reverse; pushALL(root);
}

int next()
{
    BinaryTreeNode *root=s.top();s.pop();
    if(rev)pushALL(root->left);
    else pushALL(root->right);
    return root->data;
}
void pushALL(BinaryTreeNode *root)
{
    while(root)
    {
        s.push(root);
        if(rev)root=root->right;
        else root=root->left;
    }
}
};
bool pairSumBst(BinaryTreeNode *root, int k)
{
    BST l(root,false);
    BST r(root,true);

    int i=l.next();
    int j=r.next();

    while(i<j){
    if(i+j==k)return true;
    else if(i+j<k)i=l.next();
    else j=r.next();
    }
    return false;
}