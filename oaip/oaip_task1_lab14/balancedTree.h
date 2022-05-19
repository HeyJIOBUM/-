#ifndef OAIP_TASK1_LAB14_BALANCEDTREE_H
#define OAIP_TASK1_LAB14_BALANCEDTREE_H


struct balancedTreeNode {
    int treeInfo;
    int numberOfRightChildren;
    int numberOfLeftChildren;
    balancedTreeNode* left;
    balancedTreeNode* right;
};

balancedTreeNode* createBalancedTree(int value);
void addTreeElement(balancedTreeNode* root, int value);
int findDepthOfTree(balancedTreeNode* root);
double findAverage(balancedTreeNode* root);
int findSumOfAllElements(balancedTreeNode* root);
void deleteTree(balancedTreeNode* root);
#endif //OAIP_TASK1_LAB14_BALANCEDTREE_H
