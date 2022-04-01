#ifndef BASIC_OBJECTS_H
#define BASIC_OBJECTS_H

#include <iostream>
#include <string>

class String;

class Object{
private:
    static int id_count;
    int id;

public:
    Object();
    Object(const Object&);
    virtual ~Object();

    int identical(Object*);
    virtual Object* clone();
    virtual int equal(Object&);

    int get_id() const;

    virtual String toString();
};

class String : public Object{
private:
    std::string str;
public:
    String(const char*);
    String(std::string);
    String(const String&);
    ~String();

    int length();
    void clear();
    String concat(const String&);
    char at(int);
    String updateAt(int, char);
    void print();

    std::string get_str() const;

    Object* clone();
    int equal(Object&);
    String toString();

};

#endif
