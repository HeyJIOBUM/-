#include <iostream>
#include <cstring>
using namespace std;
struct patient{
    char name[20];
    int age;
    char disease[20];
    char gender[7];
    char prognosis[13];
};
void delete_element(patient*, int*);
void add_element(patient*, int);
void sort_name(patient*, int);
void display_elements(patient*, int);
void find_element(patient*, int);

int main() {
    patient list[256];
    int mode = 7; int count = 0;
    while (mode != 6){
        cout << "Add patient - 1" << "        " << "Delete patients - 2" << "   ";
        cout << "Sorting by patient name - 3" << endl << "Display patients - 4" << "   ";
        cout << "Find patient by prognosis - 5" << "     " << "End program - 6" << endl;
        cin >> mode;
        switch (mode) {
            case 1 : add_element(list, count); count++ ;break;
            case 2 : delete_element(list, &count);break;
            case 3 : sort_name(list, count);break;
            case 4 : display_elements(list, count);break;
            case 5 : find_element(list, count);break;
            case 6 : break;
            default: cout << "Invalid input" << endl; break;
        }
    }
    return 0;
}

void delete_element(patient* list, int* count) {
    int mode;
    int del_num;
    char del_part[40];
    cout << "Enter the method of deleting the element by :" << endl;
    cout << "Patient name - 1    " << "Patient age - 2    " << "Patient disease - 3" << endl;
    cout << "Patient gender - 4    " << "Patient prognosis - 5" << endl;
    cin >> mode;
    switch (mode){
        case 1:
            cout << "Enter the name of the patient to be deleted" << endl;
            cin >> del_part;
            for (int i = 0; i < *count; i++){
                if (strcmp(del_part, list[i].name) == 0){
                    list[i] = list[*count - 1];
                    *count = *count - 1;
                    i--;
                }
            }
            break;
        case 2:
            cout << "Enter the age of the patient to be deleted" << endl;
            cin >> del_num;
            for (int i = 0; i < *count; i++){
                if (del_num == list[i].age){
                    list[i] = list[*count - 1];
                    *count = *count - 1;
                    i--;
                }
            }
            break;
        case 3:
            cout << "Enter the disease of the patient to be deleted" << endl;
            cin >> del_part;
            for (int i = 0; i < *count; i++){
                if (strcmp(del_part, list[i].disease) == 0){
                    list[i] = list[*count - 1];
                    *count = *count - 1;
                    i--;
                }
            }
            break;
        case 4:
            cout << "Enter the gender of the patient to be deleted" << endl;
            cout << "male - 1, female - 2, other - 3" << endl;
            cin >> del_num;
            if (del_num == 1) strcpy(del_part, "male");
            else if (del_num == 2) strcpy(del_part, "female");
            else if (del_num == 3) strcpy(del_part, "other");
            else strcpy(del_part, "NONE");
            for (int i = 0; i < *count; i++){
                if (strcmp(del_part, list[i].gender) == 0){
                    list[i] = list[*count - 1];
                    *count = *count - 1;
                    i--;
                }
            }
            break;
        case 5:
            cout << "Enter the prognosis of the patient to be deleted" << endl;
            cout << "auspicious - 1, inauspicious - 2" << endl;
            cin >> del_num;
            if (del_num == 1) strcpy(del_part, "auspicious");
            else if (del_num == 2) strcpy(del_part, "inauspicious");
            else strcpy(del_part, "NONE");
            for (int i = 0; i < *count; i++){
                if (strcmp(del_part, list[i].prognosis) == 0){
                    list[i] = list[*count - 1];
                    *count = *count - 1;
                    i--;
                }
            }
            break;
        default: cout << "Invalid input" << endl;
    }
}
void add_element(patient* list, int count){
    int temp;
    if (count == 255) {cout << "Struct is overfilled"; exit;}
    cout << "Enter patient name" << endl;
    cin >> list[count].name;
    cout << "Enter patient age" << endl;
    cin >> list[count].age;
    cout << "Enter patient disease" << endl;
    cin >> list[count].disease;
    cout << "Enter patient gender: male - 1, female - 2, other - 3" << endl;
    cin >> temp;
    if (temp == 1) strcpy(list[count].gender,"male");
    else if (temp == 2) strcpy(list[count].gender,"female");
    else if (temp == 3) strcpy(list[count].gender,"other");
    else strcpy(list[count].gender,"NONE");
    cout << "Enter patient prognosis: auspicious - 1, inauspicious - 2" << endl;
    cin >> temp;
    if (temp == 1) strcpy(list[count].prognosis,"auspicious");
    else if (temp == 2) strcpy(list[count].prognosis,"inauspicious");
    else strcpy(list[count].prognosis,"NONE");
}
void sort_name(patient* list, int count) {
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
void display_elements(patient* list, int count) {
    for (int i = 0; i < count; i++){
        cout << list[i].name << "   "  << list[i].age;
        cout << "   " << list[i].disease << "   ";
        cout << list[i].gender << "   " << list[i].prognosis << endl;
        cout << "--------------------------------------" << endl;
    }
}
void find_element(patient* list, int count) {
    int state;
    char temp[13] = "NONE";
    cout << "To get diseases with auspicious prognosis enter - 1, inauspicious - 2" << endl;
    cin >> state;
    if (state == 1) strcpy(temp, "auspicious");
    else if (state == 2) strcpy(temp, "inauspicious");
    for (int i = 0; i < count; i++){
        if (strcmp(temp, list[i].prognosis) == 0){
            cout << list[i].name << "   "  << list[i].age;
            cout << "   " << list[i].disease << "   ";
            cout << list[i].gender << "   " << list[i].prognosis << endl;
            cout << "--------------------------------------" << endl;
        }
    }
}
