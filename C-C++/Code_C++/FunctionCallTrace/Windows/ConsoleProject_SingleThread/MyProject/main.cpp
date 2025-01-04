#include <iostream>

class Vehicle
{
public:
    void car()
    {
        std::cout << "This is a car\n";
    }

    void truck()
    {
        std::cout << "This is a truck\n";
    }
};

int main()
{
    Vehicle vehicle;
    vehicle.car();
    vehicle.truck();

    return 0;
}