#include <iostream>
#include <fstream>
#include "interface.h"
using namespace std;
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
        ofstream file_ (file_name);1
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

