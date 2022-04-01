#ifndef PLANE_H
#define PLANE_H

#include "Basic_Objects.h"

class Employee;

class PlaneComponent: public Object{
private:
    String description;
public:
    PlaneComponent(const String&);
    PlaneComponent(const PlaneComponent&);
    virtual ~PlaneComponent();

    virtual void ready_check()=0;
    virtual void process(Employee&)=0;

    String toString();
    Object* clone() = 0;
    virtual int equal(Object&);

    String* get_desc();
};

class PassengerCompartment: public PlaneComponent{
private:
    PassengerCompartment* innerComp;                //50% it exists
public:
    PassengerCompartment(const String&);
    PassengerCompartment(const String&, int);       //used for creating the inner compartment
    PassengerCompartment(const PassengerCompartment&);
    ~PassengerCompartment();

    void ready_check();
    void ready_check(int);                  //used for inner compartment
    void process(Employee&);

    int inner_exists() const;
    int get_inner_id() const;
    PassengerCompartment& get_inner() const;

    String toString();
    Object* clone();
    int equal(Object&);
};

class PrivateCompartment: public PlaneComponent{
private:

public:
    PrivateCompartment(const String&);
    PrivateCompartment(const PrivateCompartment&);
    virtual ~PrivateCompartment();

    String toString();

};

class EquipmentCompartment: public PrivateCompartment{
private:
public:
    EquipmentCompartment(const String&);
    EquipmentCompartment(const EquipmentCompartment&);
    ~EquipmentCompartment();

    void ready_check();
    void process(Employee&);

    String toString();
    Object* clone();
    int equal(Object&);
};

class CargoBay: public PrivateCompartment{
private:
    EquipmentCompartment equipment;
public:
    CargoBay(const String&);
    CargoBay(const CargoBay&);
    ~CargoBay();

    void ready_check();
    void process(Employee&);

    EquipmentCompartment& get_equipment();

    String toString();
    Object* clone();
    int equal(Object&);
};

class Plane: public Object{
private:
    String description;
    String title;
    unsigned int capacity;
    unsigned int passengerC_capacity;            //used for the Passenger Compartments
    CargoBay cargoBay;
    EquipmentCompartment* equipmentCompartment[3];
    PassengerCompartment** passengerCompartment;
public:
    Plane(const String&,const String&);
    Plane(const Plane&);
    ~Plane();

    void ready_check();
    void process(Employee&);

    String toString();
    Object* clone();
    int equal(Object&);

    String get_desc();
    String get_title();
    unsigned int get_capacity();
    unsigned int get_pcapacity();
    CargoBay* get_cargoBay();
    EquipmentCompartment* get_equipmentCompartment(int);
    PassengerCompartment* get_passengerCompartment(int);
};

#endif
