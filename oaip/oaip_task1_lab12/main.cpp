#include <iostream>
#include <fstream>
using namespace std;
struct receipt{
    string name;
    string receipt_date;
    bool order_status;
};
void rewrite_file(receipt*&, int, const string&);
void fill_struct_from_file(receipt*&, int*, const string&);
void delete_element(receipt*&, int*, const string&);
void add_element(receipt*&, int*, const string&);
void get_sorted_elements(receipt*& list, int count, const string& file_name);
void display_elements(receipt*&, int);
void find_element(receipt*&, int);
void update_index_files(receipt*&, int, const string&);
int main() {
    int mode; int count = 0;
    string file_name;
    receipt* list = new receipt[1];
    cout << "Enter file name:";
    cin >> file_name;
    ifstream file (file_name);
    if (file.is_open()) {
        file.close();
        fill_struct_from_file(list, &count, file_name);
    }
    else {
        ofstream file_ (file_name);
        file_.close();
    }
    do {
        cout << "Add element - 1" << "        " << "Delete element - 2" << "   ";
        cout << "Get sorted elements - 3" << endl << "Display elements - 4" << "   ";
        cout << "Find element - 5" << "     " << "End program - 6" << endl;
        cin >> mode;
        switch (mode) {
            case 1 : add_element(list, &count, file_name);break;
            case 2 : delete_element(list, &count, file_name);break;
            case 3 : get_sorted_elements(list, count, file_name);break;
            case 4 : display_elements(list, count);break;
            case 5 : find_element(list, count);break;   
            case 6 : break;
            default: cout << "Invalid input" << endl; break;
        }
    } while (mode != 6);
    return 0;
}
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
        if ((int)list[*count].name[0] <= 0 || (int)list[*count].receipt_date[0] <= 0) continue;
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