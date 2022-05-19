#include "balancedTree.h"
balancedTreeNode* createBalancedTree(int value){
    balancedTreeNode* root = new balancedTreeNode;
    root->right = nullptr;
    root->left = nullptr;
    root->numberOfLeftChildren = 0;
    root->numberOfRightChildren = 0;
    root->treeInfo = value;
    return root;
}
void addTreeElement(balancedTreeNode* root, int value){
    while (root->left != nullptr && root->right != nullptr){
        if (root->numberOfLeftChildren - root->numberOfRightChildren == 1){
            root->numberOfRightChildren++;
            root = root->right;

        } else {
            root->numberOfLeftChildren++;
            root = root->left;
        }
    }
    balancedTreeNode* newNode = new balancedTreeNode;
    newNode->right = nullptr;
    newNode->left = nullptr;
    newNode->numberOfLeftChildren = 0;
    newNode->numberOfRightChildren = 0;
    newNode->treeInfo = value;
    if (root->left == nullptr){
        root->left = newNode;
        root->numberOfLeftChildren++;
    }
    else {
        root->right = newNode;
        root->numberOfRightChildren++;
    }
}
int findDepthOfTree(balancedTreeNode* root){
    int depth = 0;
    while (root->left != nullptr){
        root = root->left;
        depth++;
    }
    return depth;
}
double findAverage(balancedTreeNode* root){
    int sum = findSumOfAllElements(root);
    return (double)sum / (root->numberOfRightChildren + root->numberOfLeftChildren + 1);
}
int findSumOfAllElements(balancedTreeNode* root){
    if (root == nullptr) return 0;
    return root->treeInfo + findSumOfAllElements(root->left) + findSumOfAllElements(root->right);
}
void deleteTree(balancedTreeNode* root){
    if (root->left != nullptr) deleteTree(root->left);
    else if (root->right != nullptr) deleteTree(root->right);
    delete root;
}