#include "workingWithFiles.h"
#include <fstream>
#include <iostream>
using namespace std;
void update_index_files(receipt*& list, int count, const string& file_name){
    string nameArray[count];
    int shadowNameArray[count];
    bool boolArray[count];
    int shadowBoolArray[count];
    for (int i = 0; i < count; ++i) {
        nameArray[i] = list[i].name;
        boolArray[i] = list[i].order_status;
        shadowNameArray[i] = i;
        shadowBoolArray[i] = i;
    }
    int min;
    for (int i = 0; i < count; i++) {
        min = i;
        for (int j = i + 1; j < count; j++) {
            if (nameArray[j] < nameArray[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(nameArray[i], nameArray[min]);
            swap(shadowNameArray[i], shadowNameArray[min]);
        }
    }
    for (int i = 0, j = 0; i < count && j < count; ++i) {
        if (boolArray[i] == 1) continue;
        else {
            j = i + 1;
            while (boolArray[j] != 1 && j < count)j++;
            if (j < count){
                swap(boolArray[i], boolArray[j]);
                swap(shadowBoolArray[i], shadowBoolArray[j]);
            }
        }
    }
    ofstream index1("nameIndex" + file_name), index2("statusIndex" + file_name);
    for (int i = 0; i < count; ++i) {
        index1 << shadowNameArray[i] << ' ';
        index2 << shadowBoolArray[i] << ' ';
    }
    index1.close();
    index2.close();
}

void fill_struct_from_file(receipt*& list, int* count, const string& file_name){
    ifstream fin (file_name);
    while (!fin.eof()){
        receipt* temp = new receipt[*count + 1];
        for (int i = 0; i < *count; i++){
            temp[i] = list[i];
        }
        delete[] list;
        list = temp;
        fin >> list[*count].name;
        fin >> list[*count].receipt_date;
        fin >> list[*count].order_status;
        if ((int)list[*count].name[0] <= 0  || (int)list[*count].receipt_date[0] <= 0) continue;
        (*count)++;
    }
    fin.close();
    update_index_files(list, *count, file_name);
}

void rewrite_file(receipt*& list, int count, const string& file_name){
    ofstream fout (file_name);
    for (int i = 0; i < count; ++i) {
        fout << " " << list[i].name << " " << list[i].receipt_date << " " << list[i].order_status;
    }
    fout.close();
}