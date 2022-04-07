#ifndef MAIN_CPP_CLASS_DETERMINATION_H
#define MAIN_CPP_CLASS_DETERMINATION_H
#include <iostream>
#include <cstring>
class animal{
private:
    char* name;
    char* type;
    int average_weight;
public:
    animal();
    animal(char* nm, char* tp, int av_we);
    animal(const animal&);
    ~animal();
    void setName(char*);
    void setType(char*);
    void setAv_we(int);
    void set(char*, char*, int);
    void set(const animal&);
    char* getName();
    char* getType();
    int getAv_we();
    void show();
};
#endif //MAIN_CPP_CLASS_DETERMINATION_H
