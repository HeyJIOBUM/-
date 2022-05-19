#include "list.h"
listNode* createList(int value){
    listNode* node = new listNode;
    node->listInfo = value;
    node->next = nullptr;
    return node;
}
void addListElement(listNode* list, int value){
    while (list->next != nullptr) list = list->next;
    listNode* node = new listNode;
    node->listInfo = value;
    node->next = nullptr;
    list->next = node;
}
int findListLength(listNode* list){
    int length = 1;
    while (list->next != nullptr){
        list = list->next;
        length++;
    }
    return length;
}
listNode* findMaxElement(listNode* list){
    listNode* maxElement = list;
    int max = list->listInfo;
    while (list != nullptr){
        if (list->listInfo > max){
            max = list->listInfo;
            maxElement = list;
        }
        list = list->next;
    }
    return maxElement;
}
void deleteList(listNode* list){
    listNode* tempPtr;
    while (list->next != nullptr){
        tempPtr = list->next;
        delete list;
        list = tempPtr;
    }
    delete list;
}