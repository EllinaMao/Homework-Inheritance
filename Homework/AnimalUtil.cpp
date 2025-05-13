#include "AnimalUtil.h"

void PrintAnimalInfo(Animal* animal) {
    animal->Show();
    animal->Type();
    animal->Sound();
    cout << "Can fly: " << (animal->CanFly() ? "Yes" : "No") << endl;
    cout << "Can swim: " << (animal->CanSwim() ? "Yes" : "No") << endl;
    cout << "Can climb: " << (animal->CanClimb() ? "Yes" : "No") << endl;
}
