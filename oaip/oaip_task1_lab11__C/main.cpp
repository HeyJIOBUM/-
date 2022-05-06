#include <iostream>
#include <cstring>
using namespace std;
struct receipt{
    char* name;
    char receipt_date[12];
    int order_status;
};
void rewrite_file(receipt*&, int, char*);
void fill_struct_from_file(receipt*&, int*, char*);
void delete_element(receipt*&, int*, char*);
void add_element(receipt*&, int*, char*);
void sort(receipt*& list, int count, char*);
void display_elements(receipt*&, int);
void find_element(receipt*&, int);
int main() {
    int mode; int count = 0;
    char file_name[80];
    receipt* list = new receipt[1];
    cout << "Enter file name:";
    cin >> file_name;
    FILE *my_file = fopen (file_name,"r");
    if (my_file != nullptr) {
            fclose(my_file);
            fill_struct_from_file(list, &count, file_name);
        }
    else {
        my_file = fopen (file_name,"w");
        fclose(my_file);
    }
    do {
        cout << "Add element - 1" << "        " << "Delete element - 2" << "   ";
        cout << "Sorting by product name - 3" << endl << "Display elements - 4" << "   ";
        cout << "Find element - 5" << "     " << "End program - 6" << endl;
        cin >> mode;
        switch (mode) {
            case 1 : add_element(list, &count, file_name);break;
            case 2 : delete_element(list, &count, file_name);break;
            case 3 : sort(list, count, file_name);break;
            case 4 : display_elements(list, count);break;
            case 5 : find_element(list, count);break;
            case 6 : break;
            default: cout << "Invalid input" << endl; break;
        }
    } while (mode != 6);
    return 0;
}

void fill_struct_from_file(receipt*& list, int* count, char* file_name){
    FILE *my_file = fopen (file_name,"r");
    while (feof(my_file) == 0){
        char temp_str[20];
        receipt* temp = new receipt[*count + 1];
        for (int i = 0; i < *count; i++){
            temp[i] = list[i];
        }
        delete[] list;
        list = temp;
        fscanf(my_file,"%s%s%i", &temp_str, &list[*count].receipt_date, &list[*count].order_status);
        list[*count].name = new char[strlen(temp_str) + 1];
        strcpy(list[*count].name, temp_str);
        if ((int)temp_str[0] <= 0 || (int)list[*count].receipt_date[0] <= 0) continue;
        (*count)++;
    }
    fclose(my_file);
}
void rewrite_file(receipt*& list, int count, char* file_name){
    FILE *my_file = fopen (file_name,"w");
    for (int i = 0; i < count; ++i) {
        fprintf(my_file, "%c%s", ' ', list[i].name);
        fprintf(my_file, "%c%s", ' ', list[i].receipt_date);
        fprintf(my_file, "%c%i", ' ', list[i].order_status);
    }
    fclose(my_file);
}
void delete_element(receipt*& list, int* count, char* file_name) {
    int mode;
    int del_state;
    char del_part[40];
    cout << "Enter the method of deleting the element by :" << endl;
    cout << "Product name - 1    " << "Date of receipt - 2    " << "Status of order - 3" << endl;
    cin >> mode;
    switch (mode){
        case 1:
            cout << "Enter the name of the order to be deleted" << endl;
            cin >> del_part;
            for (int i = 0; i < *count; i++){
                if(strcmp(del_part, list[i].name) == 0){
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
                if (strcmp(del_part, list[i].receipt_date) == 0){
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
}
void add_element(receipt*& list, int* count, char* file_name){
    receipt* temp = new receipt[*count + 1];
    for (int i = 0; i < *count; i++){
        temp[i] = list[i];
    }
    delete[] list;
    list = temp;
    char temp_str[50];
    cout << "Enter product name" << endl;
    cin >> temp_str;
    list[*count].name = new char[strlen(temp_str) + 1];
    strcpy(list[*count].name, temp_str);
    cout << "Enter the date of receipt of the product" << endl;
    cin >> list[*count].receipt_date;
    cout << "Enter the state of the order: repaired - '1' , not repaired - '0'" << endl;
    cin >> list[*count].order_status;
    (*count)++;
    rewrite_file(list, *count, file_name);
}
void sort(receipt*& list, int count, char* file_name) {
    int min;
    for (int i = 0; i < count; i++){
        min = i;
        for (int j = i + 1; j < count; j++){
            if (strcmp(list[j].name,list[min].name) < 0){
                min = j;
            }
        }
        if (min != i){
            swap(list[i].name,list[min].name);
            swap(list[i].receipt_date,list[min].receipt_date);
            swap(list[i].order_status,list[min].order_status);
        }
    }
    rewrite_file(list, count, file_name);
}
void display_elements(receipt*& list, int count) {
    for (int i = 0; i < count; i++){
        cout << list[i].name << "   "  << list[i].receipt_date;
        cout << "   " << list[i].order_status << endl;
    }
}
void find_element(receipt*& list, int count) {
    int state;
    cout << "To get repaired orders enter - 1, unrepaired - 0" << endl;
    cin >> state;
    for (int i = 0; i < count; i++){
        if (state == list[i].order_status){
            cout << list[i].name << "   "  << list[i].receipt_date;
            cout << "   " << list[i].order_status << endl;
        }
    }
}
