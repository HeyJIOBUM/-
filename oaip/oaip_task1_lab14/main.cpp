#include <iostream>
#include "list.h"
#include "balancedTree.h"
using namespace std;

balancedTreeNode* fillTreeFromList(listNode* list);

int main() {
    listNode* head;
    int numberOfElements;
    int value;
    cout << "Number of elements in list:\n";
    cin >> numberOfElements;
    for (int i = 0; i < numberOfElements; ++i) {
        cin >> value;
        if (i == 0) head = createList(value);
        else addListElement(head, value);
    }
    cout << "List length = " << findListLength(head) << "\n";
    cout << "Max element = " << findMaxElement(head)->listInfo << "\n";

    balancedTreeNode* root;
    root = fillTreeFromList(head);
    deleteList(head);
    deleteTree(root);

    cout << "Number of elements in balanced tree:\n";
    cin >> numberOfElements;
    for (int i = 0; i < numberOfElements; ++i) {
        cin >> value;
        if (i == 0) root = createBalancedTree(value);
        else addTreeElement(root, value);
    }
    cout << "Tree depth = " << findDepthOfTree(root) << "\n";
    deleteTree(root);
    return 0;
}

balancedTreeNode* fillTreeFromList(listNode* list){
    balancedTreeNode* root = createBalancedTree(list->listInfo);
    list = list->next;
    while (list != nullptr) {
        addTreeElement(root, list->listInfo);
        list = list->next;
    }
    cout << "Arithmetic mean of numbers in a tree = " << findAverage(root) << "\n";
    cout << "Tree depth = " << findDepthOfTree(root) << "\n";
    return root;
}