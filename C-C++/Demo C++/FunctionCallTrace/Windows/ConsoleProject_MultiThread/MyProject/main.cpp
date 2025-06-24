#include <windows.h>
#include <iostream>

class Vehicle
{
public:
    void car()
    {
        std::cout << "[" << ::GetCurrentThreadId() << "] ";
        std::cout << "This is a car\n";
    }

    void truck()
    {
        std::cout << "[" << ::GetCurrentThreadId() << "] ";
        std::cout << "This is a truck\n";
    }
};

DWORD WINAPI ThreadHanlder_1(void* p)
{
    Vehicle vehicle;
    vehicle.car();
    vehicle.truck();

    return 0;
}

DWORD WINAPI ThreadHanlder_2(void* p)
{
    Vehicle vehicle;
    vehicle.car();
    vehicle.truck();

    return 0;
}

int main()
{
    // Create thread 1
    DWORD threadId_1 = 0;
    HANDLE threadHandle_1 = ::CreateThread(NULL, 0, ThreadHanlder_1, NULL, 0, &threadId_1);
    ::Sleep(20);

    DWORD threadId_2 = 0;
    HANDLE threadHandle_2 = ::CreateThread(NULL, 0, ThreadHanlder_2, NULL, 0, &threadId_2);
    ::Sleep(20);

    return 0;
}