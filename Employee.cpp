#include <string>
#include "Employee.h"

using namespace std;

Employee::Employee(const String& given_name): name(given_name) {
    cout << "Employee just created!" << endl;
}

Employee::Employee(const Employee& clone_employee): Object(clone_employee), name(clone_employee.name) {
    cout << "Copy of Employee just created!" << endl;
}

Employee::~Employee() {
    cout << "Employee to be destroyed!" << endl;
}

String Employee::toString() {
    String return_str(Object::toString());

    return_str.concat("->Employee_");
    return_str.concat(name);

    return return_str;
}

int Employee::equal(Object& object) {
    Employee* ptr = (Employee*) &object;
    return ((this->get_id() == ptr->get_id()) && name.get_str() == ptr->name.get_str());
}

String Employee::get_name() const {
    return name;
}

SecurityEmployee::SecurityEmployee(const String& name): Employee(name){
    cout << "Security Employee just created!" << endl;
}

SecurityEmployee::SecurityEmployee(const SecurityEmployee& clone_se): Employee(clone_se){
    hasWorked = clone_se.hasWorked;
    cout << "Copy of Security Employee just created!" << endl;
}

SecurityEmployee::~SecurityEmployee() {
    cout << "Security Employee to be destroyed!" << endl;
}

void SecurityEmployee::workOn(PassengerCompartment& PC) {
    if(PC.inner_exists())
        workOn(PC.get_inner());
    cout << PC.get_desc()->get_str() << " is secure!" << endl;
}

void SecurityEmployee::workOn(EquipmentCompartment& EC) {
    cout << EC.get_desc()->get_str() <<" is secure!" << endl;
}

void SecurityEmployee::workOn(CargoBay& CB) {
    cout << CB.get_desc()->get_str() <<" is secure!" << endl;
    workOn(CB.get_equipment());
}

void SecurityEmployee::worked() {
    hasWorked = 1;
}

void SecurityEmployee::report() {
    if(hasWorked)
        cout << "Security Employee " << get_name().get_str() << " checked the passenger compartments, cargo bay, and equipment compartments! OK!" << endl;
    else cout << "Security Employee has not yet worked!" << endl;
}

String SecurityEmployee::toString() {
    String return_str(Employee::toString());

    return_str.concat("->SecurityEmployee");

    return return_str;
}

Object* SecurityEmployee::clone() {
    SecurityEmployee* securityEmployee = new SecurityEmployee(*this);

    return securityEmployee;
}

int SecurityEmployee::equal(Object& object) {
    SecurityEmployee* ptr = (SecurityEmployee*) &object;
    return((Employee::equal(*ptr)) && hasWorked == ptr->hasWorked);
}

MaintenanceEmployee::MaintenanceEmployee(const String& name): Employee(name){
    cout << "Maintenance Employee just created!" << endl;
}

MaintenanceEmployee::MaintenanceEmployee(const MaintenanceEmployee& clone_me): Employee(clone_me){
    hasWorked = clone_me.hasWorked;
    cout << "Copy of Maintenance Employee just created!" << endl;
}

MaintenanceEmployee::~MaintenanceEmployee() {
    cout << "Maintenance Employee to be destroyed!" << endl;
}

void MaintenanceEmployee::workOn(EquipmentCompartment& EC) {
    cout << EC.get_desc()->get_str() << " is maintained!" << endl;
}

void MaintenanceEmployee::workOn(CargoBay& CB) {
    cout << CB.get_desc()->get_str() << " is maintained!" << endl;
    workOn(CB.get_equipment());
}

void MaintenanceEmployee::worked() {
    hasWorked = 1;
}

void MaintenanceEmployee::report() {
    if(hasWorked)
        cout << "Maintenance Employee " << get_name().get_str() << " checked the cargo bay and equipment compartments! OK!" << endl;
    else cout << "Maintenance Employee has not yet worked!" << endl;
}

String MaintenanceEmployee::toString() {
    String return_str(Employee::toString());

    return_str.concat("->MaintenanceEmployee");

    return return_str;
}

Object* MaintenanceEmployee::clone(){
    MaintenanceEmployee* maintenanceEmployee = new MaintenanceEmployee(*this);
    return maintenanceEmployee;
}

int MaintenanceEmployee::equal(Object& object) {
    MaintenanceEmployee* ptr = (MaintenanceEmployee*) &object;
    return((Employee::equal(*ptr)) && hasWorked == ptr->hasWorked);
}

CleaningEmployee::CleaningEmployee(const String& name): Employee(name){
    cout << "Cleaning Employee just created!" << endl;
}

CleaningEmployee::CleaningEmployee(const CleaningEmployee& clone_ce): Employee(clone_ce){
    hasWorked = clone_ce.hasWorked;
    cout << "Copy of Cleaning Employee just created!" << endl;
}

CleaningEmployee::~CleaningEmployee() {
    cout << "Cleaning Employee to be destroyed!" << endl;
}

void CleaningEmployee::workOn(PassengerCompartment& PC) {
    if(PC.inner_exists())
        workOn(PC.get_inner());
    cout << PC.get_desc()->get_str() << " is cleaned!" << endl;
}

void CleaningEmployee::workOn(CargoBay& CB) {
    cout << CB.get_desc()->get_str() << " is cleaned!" << endl;
}

void CleaningEmployee::worked() {
    hasWorked = 1;
}

void CleaningEmployee::report() {
    if(hasWorked)
        cout << "Cleaning Employee " << get_name().get_str() << " checked the cargo bay and passenger compartments! OK!" << endl;
    else cout << "Cleaning Employee has not yet worked!" << endl;
}

String CleaningEmployee::toString() {
    String return_str(Employee::toString());

    return_str.concat("->CleaningEmployee");

    return return_str;
}

Object* CleaningEmployee::clone() {
    CleaningEmployee* cleaningEmployee = new CleaningEmployee(*this);

    return cleaningEmployee;
}

int CleaningEmployee::equal(Object& object) {
    CleaningEmployee* ptr = (CleaningEmployee*) &object;
    return((Employee::equal(*ptr)) && hasWorked == ptr->hasWorked);
}