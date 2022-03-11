#include <iostream>
#include <cstring>
using namespace std;
struct receipt{
    char name[20];
    char receipt_date[12];
    bool order_status;
    /*unsigned short available : 1;
    union check{
        int value1;
        int value2;
    };
    enum state{good, medium, bad};*/
};
void delete_element(receipt*, int*);
void add_element(receipt*, int);
void sort(receipt*, int);
void display_elements(receipt*, int);
void find_element(receipt*, int);
int main() {
    receipt list[256];
    int mode = 7; int count = 0;
    while (mode != 6){
        cout << "Add element - 1" << "        " << "Delete element - 2" << "   ";
        cout << "Sorting by product name - 3" << endl << "Display elements - 4" << "   ";
        cout << "Find element - 5" << "     " << "End program - 6" << endl;
        cin >> mode;
        switch (mode) {
            case 1 : add_element(list, count); count++ ;break;
            case 2 : delete_element(list, &count);break;
            case 3 : sort(list, count);break;
            case 4 : display_elements(list, count);break;
            case 5 : find_element(list, count);break;
            case 6 : break;
            default: cout << "Invalid input" << endl; break;
        }
    }
    return 0;
}
void delete_element(receipt* list, int* count) {
    int mode;
    bool del_state;
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
}
void add_element(receipt* list, int count){
    if (count == 255) cout << "Struct is overfilled";
    cout << "Enter product name" << endl;
    cin >> list[count].name;
    cout << "Enter the date of receipt of the product" << endl;
    cin >> list[count].receipt_date;
    cout << "Enter the state of the order: repaired - '1' , not repaired - '0'" << endl;
    cin >> list[count].order_status;
}
void sort(receipt* list, int count) {
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
        }
    }
}
void display_elements(receipt* list, int count) {
    for (int i = 0; i < count; i++){
        cout << list[i].name << "   "  << list[i].receipt_date;
        cout << "   " << list[i].order_status << endl;
    }
}
void find_element(receipt* list, int count) {
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
