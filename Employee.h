#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Plane.h"

class Employee: public Object {
private:
    String name;
public:
    Employee(const String&);
    Employee(const Employee&);
    virtual ~Employee();

    virtual void workOn(PassengerCompartment&)=0;
    virtual void workOn(EquipmentCompartment&)=0;
    virtual void workOn(CargoBay&)=0;

    virtual void worked()=0;

    virtual void report()=0;

    String toString();
    virtual Object* clone()= 0;
    virtual int equal(Object&);

    String get_name() const;

};

class SecurityEmployee: public Employee{
private:
    int hasWorked = 0;
public:
    SecurityEmployee(const String&);
    SecurityEmployee(const SecurityEmployee&);
    ~SecurityEmployee();

    void workOn(PassengerCompartment&);
    void workOn(EquipmentCompartment&);
    void workOn(CargoBay&);

    void worked();

    void report();

    String toString();
    Object* clone();
    int equal(Object&);
};

class MaintenanceEmployee: public Employee{
private:
    int hasWorked = 0;
public:
    MaintenanceEmployee(const String&);
    MaintenanceEmployee(const MaintenanceEmployee&);
    ~MaintenanceEmployee();

    void workOn(EquipmentCompartment&);
    void workOn(CargoBay&);

    void workOn(PassengerCompartment&) {};

    void worked();

    void report();

    String toString();
    Object* clone();
    int equal(Object&);
};

class CleaningEmployee: public Employee{
private:
    int hasWorked = 0;
public:
    CleaningEmployee(const String&);
    CleaningEmployee(const CleaningEmployee&);
    ~CleaningEmployee();

    void workOn(PassengerCompartment&);
    void workOn(CargoBay&);

    void workOn(EquipmentCompartment&) {};

    void worked();

    void report();

    String toString();
    Object* clone();
    int equal(Object&);
};

#endif
