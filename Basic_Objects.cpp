#include <iostream>
#include <string>
#include "Basic_Objects.h"

using namespace std;

int Object:: id_count=0;

Object:: Object() {
    id = id_count++;
    cout << "Object just created!"<<endl;
}

Object:: Object(const Object& object) {
    id = object.id;
    id_count = object.id_count;
    cout << "Copy of Object just created!" <<endl;
}

Object:: ~Object() {
   cout << "Object to be destroyed!" <<endl;
}

int Object::identical(Object* object) {
    return this == object;
}

Object* Object::clone() {

    Object* new_object = new Object(*this);

    return new_object;
}

int Object:: equal(Object& object)
{
    return (this->id == object.id);
}

int Object::get_id() const {
    return id;
}

String Object::toString(){
    String str("Object_" + to_string(id));

    return str;
}

String::String(string given_str) {
    str = given_str;
    cout << "String just created!" <<endl;
}

String::String(const char* given_str) {
    str = given_str;
    cout << "String just created!" <<endl;
}

String::String(const String& copy_string): Object(copy_string){
    str = copy_string.str;
    cout << "Copy of String just created!" <<endl;
}

String:: ~String() {
   cout << "String to be destroyed!" <<endl;
}

int String::length() {
    return str.length();            //uses length function of string library
}

void String::clear() {
    str.clear();                    //uses clear function of string library
}

String String::concat(const String& sec_str) {
    String new_string(str.append(sec_str.str));         //uses append function of string library
    return new_string;
}

char String::at(int pos) {
    return str.at(pos);             //uses at function of string library
}

String String::updateAt(int pos, char new_char) {
    str[pos] = new_char;
    return *this;
}

void String::print() {
    cout << str << endl;
}

string String::get_str() const {
    return str;
}

Object* String::clone() {
    String* new_String = new String(*this);
    return new_String;
}

int String::equal(Object& object) {
    String* ptr = (String*) &object;
    return ((this->get_id() == ptr->get_id()) && (str == ptr->str));
}

String String::toString() {
    String return_str(Object::toString());

    return_str.concat("String_");
    return_str.concat(str);

    return return_str;
}