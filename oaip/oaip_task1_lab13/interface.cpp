#include "interface.h"
#include <iostream>
#include <fstream>
using namespace std;
void get_sorted_elements(receipt*& list, int count, const string& file_name) {
    int mode, temp;
    string indexType[2] = {"nameIndex" + file_name, "statusIndex" + file_name};
    cout << "Get elements sorted by: names - 1, order status - 2\n";
    cin >> mode;
    if (mode > 2 || mode < 1) return;
    ifstream fin (indexType[mode - 1]);
    for (int i = 0; i < count; ++i) {
        fin >> temp;
        cout << list[temp].name << "   "  << list[temp].receipt_date;
        cout << "   " << list[temp].order_status << endl;
    }
    fin.close();
}
void delete_element(receipt*& list, int* count, const string& file_name) {
    int mode;
    bool del_state;
    string del_part;
    cout << "Enter the method of deleting the element by :" << endl;
    cout << "Product name - 1    " << "Date of receipt - 2    " << "Status of order - 3" << endl;
    cin >> mode;
    switch (mode){
        case 1:
            cout << "Enter the name of the order to be deleted" << endl;
            cin >> del_part;
            for (int i = 0; i < *count; i++){
                if(del_part == list[i].name){
                    list[i] = list[*count - 1];
                    *count = *count - 1;
                    i--;
                }
            }
            break;
        case 2:
            cout << "Enter the date of receipt of the order to be deleted" << endl;
            cin >> del_part;
            for (int i = 0; i < *count; i++){
                if (del_part == list[i].receipt_date){
                    list[i] = list[*count - 1];
                    *count = *count - 1;
                    i--;
                }
            }
            break;
        case 3:
            cout << "Enter the repair status of the deleting products" << endl;
            cout << "Repaired - 1, not repaired - 0" << endl;
            cin >> del_state;
            for (int i = 0; i < *count; i++){
                if(del_state == list[i].order_status){
                    list[i] = list[*count - 1];
                    *count = *count - 1;
                    i--;
                }
            }
            break;
        default: cout << "Invalid input";
    }
    receipt* temp = new receipt[*count];
    for (int i = 0; i < *count; i++){
        temp[i] = list[i];
    }
    delete[] list;
    list = temp;
    rewrite_file(list, *count, file_name);
    update_index_files(list, *count, file_name);
}
void add_element(receipt*& list, int* count, const string& file_name){
    receipt* temp = new receipt[*count + 1];
    for (int i = 0; i < *count; i++){
        temp[i] = list[i];
    }
    delete[] list;
    list = temp;
    cout << "Enter product name" << endl;
    cin >> list[*count].name;
    cout << "Enter the date of receipt of the product" << endl;
    cin >> list[*count].receipt_date;
    cout << "Enter the state of the order: repaired - '1' , not repaired - '0'" << endl;
    cin >> list[*count].order_status;
    (*count)++;
    rewrite_file(list, *count, file_name);
    update_index_files(list, *count, file_name);
}
void display_elements(receipt*& list, int count) {
    for (int i = 0; i < count; i++){
        cout << list[i].name << "   "  << list[i].receipt_date;
        cout << "   " << list[i].order_status << endl;
    }
}
void find_element(receipt*& list, int count) {
    bool state;
    cout << "To get repaired orders enter - 1, unrepaired - 0" << endl;
    cin >> state;
    for (int i = 0; i < count; i++){
        if (state == list[i].order_status){
            cout << list[i].name << "   "  << list[i].receipt_date;
            cout << "   " << list[i].order_status << endl;
        }
    }
}