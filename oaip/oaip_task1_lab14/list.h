#ifndef OAIP_TASK1_LAB14_LIST_H
#define OAIP_TASK1_LAB14_LIST_H
struct listNode {
    listNode* next;
    int listInfo;
};

listNode* createList(int value);
void addListElement(listNode* list, int value);
int findListLength(listNode* list);
listNode* findMaxElement(listNode* list);
void deleteList(listNode* list);
#endif //OAIP_TASK1_LAB14_LIST_H
