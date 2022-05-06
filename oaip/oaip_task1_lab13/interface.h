#ifndef OAIP_TASK1_LAB13_INTERFACE_H
#define OAIP_TASK1_LAB13_INTERFACE_H
#include "structure.h"
#include "workingWithFiles.h"
void delete_element(receipt*&, int*, const string&);
void add_element(receipt*&, int*, const string&);
void get_sorted_elements(receipt*& list, int count, const string& file_name);
void display_elements(receipt*&, int);
void find_element(receipt*&, int);
#endif //OAIP_TASK1_LAB13_INTERFACE_H
