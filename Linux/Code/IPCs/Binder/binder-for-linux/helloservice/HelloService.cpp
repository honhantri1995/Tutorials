#include <iostream>

#include <HelloService.h>
#include <binder/IServiceManager.h>

void HelloService::publish() {
    int ret = 100;
    ret = defaultServiceManager()->addService(String16("helloservice"), new HelloService());
    std::cout << "server: publish() returns " << ret << "\n";
}

void HelloService::joinThreadPool() {
    sp<ProcessState> ps(ProcessState::self());
    ps->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
}

void HelloService::publishAndJoinThreadPool() {
    publish();
    joinThreadPool();
}

HelloService::~HelloService() {

}


String8 HelloService::sayhello() {
    // do nothing here. Processing in function onTransact()
}


String8 HelloService::sayhello_to(String8 name) {
    // do nothing here. Processing in function onTransact()
}
