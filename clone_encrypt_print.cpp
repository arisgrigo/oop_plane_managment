#include <iostream>
#include <ctime>
#include "Employee.h"

using namespace std;

void clone_encrypt_and_print(Object& object){
    srand((unsigned)time(0));

    Object* new_obj;
    new_obj = object.clone();
    int isEqual = new_obj->equal(object);

    if(isEqual)
        cout << "Objects are equal" << endl;
    else cout << "Objects not equal" << endl;

    String str0(object.toString());
    String str1(new_obj->toString());

    int random_num = rand() % str1.length() / (3/2);            //at most 2/3 of characters will change
    if(random_num < 4)
        random_num += 4;                //at least 4 characters will change
    char new_char;

    for(int i = 0; i<= random_num; i++){
        new_char = 'a' + rand() % 26;
        random_num = rand()%str1.length();

        while(str0.at(random_num) == '\n' || str0.at(random_num) == '\t')               //character must not be tab or next line
            random_num = rand()%str1.length();

        str1.updateAt(random_num, new_char);
    }

    str0.print();
    cout << endl << "Encrypted: " << endl << endl;
    str1.print();

    String str2(str0.concat(str1));

    cout << "Length of concatenation: " << str2.length() << endl << endl;

    if(str2.length() % 2 == 0){
        cout << "Concatenation's Middle characters are: " << str2.at((str2.length() / 2) - 1) << " and: " << str2.at(str2.length() / 2) << endl << endl;
    }else cout << "Concatenation's Middle character is: " << str2.at(str2.length() / 2) << endl << endl;

    str2.clear();

    cout << "Length of concatenation after clear: " << str2.length() << endl << endl;

    delete new_obj;
}
