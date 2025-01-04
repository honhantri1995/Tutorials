#include <iostream> 

int main()
{
    int captureMe = 10;

    // Capture of the variable "captureMe", which can now be used as a copy
    // inside the lambda expression
    auto f1 = [captureMe]()
    {
        std::cout << captureMe << std::endl;
    };

    // Now, "captureMe" is captured as a reference
    auto f2 = [&captureMe]()
    {
        captureMe++;
        std::cout << captureMe << std::endl;
    };

    int x = 0, y = 1, z = 2;

    // Capture *all* local variables as a copy
    auto f3 = [=]()
    {
        std::cout << "x: " << x << ", y: " << y << std::endl;
    };

    // Capture *all* local variables as reference
    auto f4 = [&]()
    {
        x++;
        y++;
        z++;
        std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
    };

    std::cout << "calling f1()..." << std::endl;
    f1();

    std::cout << "calling f2()..." << std::endl;
    f2();

    std::cout << "calling f3()..." << std::endl;
    f3();

    std::cout << "calling f4()..." << std::endl;
    f4();

    return 0;
}
