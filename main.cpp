#include "eventfactory.h"
#include "events/Event.h"
#include "Main.h"
#include <iostream>
int main() {
    Main main1 = {};
    std::cout << typeid(main1.getEvent()).name();
    return 0;
}