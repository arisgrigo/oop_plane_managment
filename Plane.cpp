#include <ctime>
#include "Basic_Objects.h"
#include "Plane.h"
#include "Employee.h"

using namespace std;


PlaneComponent::PlaneComponent(const String& desc):description(desc){
    cout << "Plane Component just created!" << endl;
}

PlaneComponent::PlaneComponent(const PlaneComponent& clone_plc):Object(clone_plc), description(clone_plc.description){
    cout << "Copy of Plane Component just created!" << endl;
}

PlaneComponent::~PlaneComponent(){
    cout << "Plane Component to be destroyed!" <<endl;
}

String PlaneComponent::toString(){
    String return_str(Object::toString());
    return_str.concat("->PlaneComponent");

    return return_str;
}

int PlaneComponent::equal(Object& object) {
    PlaneComponent* ptr = (PlaneComponent*) &object;
    return ((this->get_id() == ptr->get_id()) && this->description.get_str() == ptr->description.get_str());
}

String* PlaneComponent::get_desc(){
    String* str_ptr = &description;
    return str_ptr;
}

PassengerCompartment::PassengerCompartment(const String& desc): PlaneComponent(desc) {
    int inner_exists = rand()%2;

    if(inner_exists){
        innerComp = new PassengerCompartment("Inner Passenger Compartment",1);      //uses constructor for Inner Compartment
    }else innerComp = nullptr;

    cout << "Passenger Compartment just created!"<< endl;
}

PassengerCompartment::PassengerCompartment(const String& desc, int isInner): PlaneComponent(desc){          //same as default constructor but for inner compartments
    innerComp = nullptr;
    cout << "Inner Passenger Compartment just created!" << endl;
}

PassengerCompartment::PassengerCompartment(const PassengerCompartment& clone_pc): PlaneComponent(clone_pc){
    if(clone_pc.innerComp){
        innerComp = new PassengerCompartment(*clone_pc.innerComp);
    }else innerComp = nullptr;

    cout << "Copy of Inner Passenger Compartment just created!" << endl;
}

PassengerCompartment::~PassengerCompartment(){
    if(innerComp != nullptr)
        delete innerComp;
    cout << "Passenger Compartment to be destroyed!" <<endl;
}

void PassengerCompartment::ready_check() {
    if(innerComp != nullptr)
        innerComp->ready_check(1);
    cout << "PassengerCompartment "<< get_desc()->get_str()<<" OK!" << endl;
}

void PassengerCompartment::ready_check(int isInner) {
    if(innerComp != nullptr)
        innerComp->ready_check(1);
    cout << "InnerPassengerCompartment " << get_desc()->get_str()<<" OK!" << endl;
}

void PassengerCompartment::process(Employee& employee) {
    employee.workOn(*this);
}

int PassengerCompartment::inner_exists() const {
    if(innerComp != nullptr)
        return 1;
    else return 0;
}

int PassengerCompartment::get_inner_id() const{
    if(innerComp != nullptr)
        return innerComp->get_id();
    else return -1;
}

PassengerCompartment& PassengerCompartment::get_inner() const {
    return *innerComp;
}

String PassengerCompartment::toString(){
    String return_str(PlaneComponent::toString());

    return_str.concat("->PassengerCompartment_");
    return_str.concat(get_desc()->get_str());

    if(innerComp != nullptr){
        return_str.concat("\n\t\tInnerPassengerCompartment: ");
        return_str.concat(innerComp->toString());
    }
    return return_str;
}

Object* PassengerCompartment::clone() {
    PassengerCompartment* passengerCompartment = new PassengerCompartment(*this);

    return passengerCompartment;
}

int PassengerCompartment::equal(Object& object) {
    PassengerCompartment* ptr = (PassengerCompartment*) &object;
    if(PlaneComponent::equal(*ptr)){
        if(this->innerComp && ptr->innerComp)
            if(this->innerComp->equal(*ptr->innerComp))                  //if both have inner compartments they must too be equal
               return 1;
            else return 0;
        else if(this->innerComp != nullptr && ptr->innerComp == nullptr)
                return 0;
            else if(this->innerComp == nullptr && ptr->innerComp != nullptr)
                    return 0;
                  else return 1;
    }else return 0;
}

PrivateCompartment::PrivateCompartment(const String& desc): PlaneComponent(desc) {
    cout << "Private Compartment just created!" << endl;
}

PrivateCompartment::PrivateCompartment(const PrivateCompartment& clone_prc): PlaneComponent(clone_prc) {
    cout << "Copy of Private Compartment just created!" << endl;
}

PrivateCompartment::~PrivateCompartment() {
    cout << "Private Component to be destroyed!" <<endl;
}

String PrivateCompartment::toString() {
    String return_str(PlaneComponent::toString());
    return_str.concat("->PrivateCompartment->");

    return return_str;
}

EquipmentCompartment::EquipmentCompartment(const String& desc): PrivateCompartment(desc) {
    cout << "Equipment Compartment just created!" << endl;
}

EquipmentCompartment::EquipmentCompartment(const EquipmentCompartment& clone_ec): PrivateCompartment(clone_ec) {
    cout << "Copy of Equipment Compartment just created!" << endl;
}

EquipmentCompartment::~EquipmentCompartment() {
    cout << "Equipment Compartment to be destroyed!" << endl;
}

void EquipmentCompartment::ready_check() {
    cout <<"Equipment Compartment " << get_desc()->get_str() << " is OK!"<<endl;
}

void EquipmentCompartment::process(Employee& employee) {
    employee.workOn(*this);
}

String EquipmentCompartment::toString() {
    String return_str(PrivateCompartment::toString());

    return_str.concat("EquipmentCompartment_");
    return_str.concat(get_desc()->get_str());

    return return_str;
}

Object* EquipmentCompartment::clone() {
    EquipmentCompartment* equipmentCompartment = new EquipmentCompartment(*this);

    return equipmentCompartment;
}

int EquipmentCompartment::equal(Object& object) {
    EquipmentCompartment* ptr = (EquipmentCompartment*) &object;
    return(PlaneComponent::equal(*ptr));
}

CargoBay::CargoBay(const String& desc):PrivateCompartment(desc), equipment("CargoBayEquipment"){
    cout <<"Cargo Bay just created!";
}

CargoBay::CargoBay(const CargoBay& clone_cb):PrivateCompartment(clone_cb), equipment(clone_cb.equipment){
    cout <<"Copy of Cargo Bay just created!" << endl;
}

CargoBay::~CargoBay() {
    cout <<"Cargo Bay to be destroyed!" << endl;
}

void CargoBay::ready_check() {
	equipment.ready_check();
    cout <<"Cargo Bay " << get_desc()->get_str() << " is OK!"<<endl;
}

void CargoBay::process(Employee& employee) {
    employee.workOn(*this);
}

EquipmentCompartment& CargoBay::get_equipment() {
    return equipment;
}

String CargoBay::toString() {
    String return_str(PrivateCompartment::toString());

    return_str.concat("CargoBay_");
    return_str.concat(get_desc()->get_str());
    return_str.concat("\n\t\tCargoBayEquipment_");
    return_str.concat(equipment.get_desc()->get_str());

    return return_str;
}

Object* CargoBay::clone(){
    CargoBay* cargoBay = new CargoBay(*this);

    return cargoBay;
}

int CargoBay::equal(Object& object) {
    CargoBay* ptr = (CargoBay*) &object;
    return ((PlaneComponent::equal(object)) && equipment.equal((ptr->equipment)));
}

Plane::Plane(const String& desc,const String& title): description(desc), title(title), cargoBay("PlaneCargoBay") {
    srand((unsigned)time(0));


    for(int i = 0; i<=2; i++){
        equipmentCompartment[i]= new EquipmentCompartment("EquipmentCompartment"+to_string(i));
    }

    capacity = rand()%200 + 99;

    passengerC_capacity = (rand() % (capacity/40) + 1) + 2;

    passengerCompartment = new PassengerCompartment*[passengerC_capacity];

    for(int i=0; i<= passengerC_capacity - 1; i++){
        passengerCompartment[i] = new PassengerCompartment("PassengerCompartment"+to_string(i));
    }

    cout << "Plane just created!" << endl;
}

Plane::Plane(const Plane& clone_plane)
: Object(clone_plane), description(clone_plane.description), title(clone_plane.title), cargoBay(clone_plane.cargoBay), capacity(clone_plane.capacity) {
    passengerC_capacity = clone_plane.passengerC_capacity;
    for(int i = 0; i<=2; i++){
        equipmentCompartment[i]= new EquipmentCompartment(*clone_plane.equipmentCompartment[i]);
    }

    passengerCompartment = new PassengerCompartment*[passengerC_capacity];

    for(int i=0; i<= passengerC_capacity - 1; i++){
        passengerCompartment[i] = new PassengerCompartment(*clone_plane.passengerCompartment[i]);
    }

    cout << "Copy of Plane just created!" << endl;

}

Plane::~Plane() {
    for(int i=0; i<=2; i++){
        delete equipmentCompartment[i];
    }

    for(int i=0; i< passengerC_capacity; i++){
        delete passengerCompartment[i];
    }
    delete[] passengerCompartment;

    cout << "Plane to be destroyed!" <<endl;
}

void Plane::ready_check() {
    cargoBay.ready_check();
    for(int i=0; i<=2; i++){
        equipmentCompartment[i]->ready_check();
    }
    for(int i=0; i<=passengerC_capacity-1; i++){
        passengerCompartment[i]->ready_check();
    }
    cout <<"Plane " << title.get_str() <<  " is OK!"<< endl;
}

void Plane::process(Employee& employee) {
    employee.workOn(cargoBay);
    for(int i=0; i<=2; i++){
        employee.workOn(*equipmentCompartment[i]);
    }
    for(int i=0; i<=passengerC_capacity-1; i++){
        employee.workOn(*passengerCompartment[i]);
    }

    employee.worked();
}

String Plane::toString() {
    String return_str(Object::toString());

    return_str.concat("->Plane_");
    return_str.concat(description);
    return_str.concat(", title_");
    return_str.concat(title);
    return_str.concat(", capacity_" + to_string(capacity));
    return_str.concat(", passenger_compartment_capacity_" + to_string(passengerC_capacity));

    return_str.concat("\n\n\tPlaneCargoBay: \n\t");
    return_str.concat(cargoBay.toString());

    return_str.concat("\n\n\tPlaneEquipmentCompartment: ");
    for(int i=0; i<=2; i++){
        return_str.concat("\n\t");
        return_str.concat(equipmentCompartment[i]->toString());
    }

    return_str.concat("\n\n\tPlanePassengerCompartment: ");
    for(int i=0; i<passengerC_capacity; i++){
        return_str.concat("\n\t");
        return_str.concat(passengerCompartment[i]->toString());
    }

    return return_str;
}

Object* Plane::clone() {
    Plane* plane = new Plane(*this);

    return plane;
}

int Plane::equal(Object& object) {
    int isEqual = 0;

    Plane* ptr = (Plane*) &object;
    if(description.get_str() == ptr->description.get_str() && title.get_str() == ptr->title.get_str() && this->get_id() == ptr->get_id())
        if(capacity == ptr->capacity && passengerC_capacity == ptr->passengerC_capacity)
            if(cargoBay.equal(ptr->cargoBay)){
                for(int i = 0; i<=2; i++){
                    isEqual = equipmentCompartment[i]->equal(*ptr->equipmentCompartment[i]);
                    if(isEqual != 1)
                        return 0;
                }
                for(int i = 0; i<=passengerC_capacity - 1; i++){
                    isEqual = passengerCompartment[i]->equal(*ptr->passengerCompartment[i]);
                    if(isEqual != 1)
                        return 0;
                }
                if(isEqual)
                    return 1;
                else return 0;

            }else return 0;
        else return 0;
    else return 0;
}

String Plane::get_desc() {
    return description;
}

String Plane::get_title() {
    return title;
}

unsigned int Plane::get_capacity(){
    return capacity;
}

unsigned int Plane::get_pcapacity(){
    return passengerC_capacity;
}

CargoBay* Plane::get_cargoBay() {
    CargoBay* ptr = &cargoBay;
    return ptr;
}

EquipmentCompartment* Plane::get_equipmentCompartment(int i) {
    EquipmentCompartment* ptr = equipmentCompartment[i];
    return ptr;
}

PassengerCompartment* Plane::get_passengerCompartment(int i){
    PassengerCompartment* ptr = passengerCompartment[i];
    return ptr;
}