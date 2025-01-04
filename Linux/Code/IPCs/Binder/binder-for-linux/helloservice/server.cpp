#include <iostream>
#include <binder/ProcessState.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <binder/IInterface.h>
#include <HelloService.h>



using namespace std;
using namespace android;

int main(int argc, char *argv[]) {
    std::cout << "Hello Server started" << std::endl;
    
    HelloService::publishAndJoinThreadPool();
}

