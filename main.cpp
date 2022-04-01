#include <iostream>
#include <ctime>
#include "Employee.h"
#include "clone_encrypt_print.h"

using namespace std;

int main() {
    srand((unsigned)time(0));

    Plane plane0("Commercial","AirbusA310");

    SecurityEmployee SE("Eva");
    MaintenanceEmployee ME("Aris");
    CleaningEmployee CE("Nikos");

    plane0.process(SE);
    plane0.process(ME);
    plane0.process(CE);

    SE.report();
    ME.report();
    CE.report();

    plane0.ready_check();

    cout << "Plane ready to take off!" << endl;

    clone_encrypt_and_print(plane0);

    return 0;
}