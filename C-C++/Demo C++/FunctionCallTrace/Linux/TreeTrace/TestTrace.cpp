#include <iostream>
#include "DebugHook.h"

class Vehicle
{
private:
    int m_seatNum;
    double m_maxWeight;

public:
    void car(int seatNum = 4)
    {
        TRACE_FUNC_1("(%d)", seatNum);
        std::cout << "This is a car\n";
        m_seatNum = seatNum;
    }

    void truck(int seatNum = 2, double maxWeight = 10)
    {
        TRACE_FUNC_2("(%d, %lf)", seatNum, maxWeight);
        std::cout << "This is a truck\n";
        m_maxWeight = maxWeight;

        car(seatNum);
    }

    void roadster()
    {
        TRACE_FUNC();
        std::cout << "This is a roadster\n";

        truck();
    }
};

int main()
{
    TRACE_FILE("./trace.log");
    TRACE_FUNC();

    Vehicle vehicle;
    vehicle.car(6);
    vehicle.roadster();

    return 0;
}