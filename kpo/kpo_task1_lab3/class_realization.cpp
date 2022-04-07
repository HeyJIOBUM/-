#include "class determination.h"
    //конструктор по умолчанию
animal::animal(){
    this->name = new char[20];
    this->type = new char[20];
    strcpy(this->name,"NONE");
    strcpy(this->type,"NONE");
    average_weight = 0;
}
    //конструктор с параметрами
animal::animal(char* nm, char* tp, int av_we){
    this->name = new char[20];
    this->type = new char[20];
    strcpy(this->name,nm);
    strcpy(this->type,tp);
    this->average_weight = av_we;
}
    //конструктор копирования
animal::animal(const animal &anim){
    this->name = new char[20];
    strcpy(this->name, anim.name);
    this->type = new char[20];
    strcpy(this->type, anim.type);
    this->average_weight = anim.average_weight;
}
    //деструктор
animal::~animal(){
    delete name;
    delete type;
}
    //сетер для поля name
void animal::setName(char* nm){
    strcpy(this->name,nm);
}
    //сетер для поля type
void animal::setType(char* tp){
    strcpy(this->type,tp);
}
    //сетер для поля average_weight
void animal::setAv_we(int av_we){
    if (av_we > 0){
        this->average_weight = av_we;
    }
}
    //сетер для полей объекта через параметры
void animal::set(char* nm, char* tp, int av_we){
    strcpy(this->name,nm);
    strcpy(this->type,tp);
    this->average_weight = av_we;
}
    //сетер для полей объекта через другой объект
void animal::set(const animal& anima){
    this->name = anima.name;
    this->type = anima.type;
    this->average_weight = anima.average_weight;
}
    //гетер для поля name
char* animal::getName(){
    return this->name;
}
    //гетер для поля type
char* animal::getType(){
    return this->type;
}
    //гетер для поля average_weight
int animal::getAv_we(){
    return this->average_weight;
}
    //показ полей объекта
void animal::show(){
    std::cout << "Name - " << this->name << std::endl;
    std::cout << "Type - " << this->type << std::endl;
    std::cout << "Weight - " << this->average_weight << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;
}