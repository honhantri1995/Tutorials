#include <iostream>
#include <BnHelloService.h>

status_t BnHelloService::onTransact(uint32_t code, const Parcel &data, Parcel* reply, uint32_t flags) {
    switch(code) { 
        case SAYHELLO:
        {
            std::cout << "server: Processing SAYHELLO command\n";
	    
            reply->writeString8(String8("Hello world!"));
            break;
        }
        case SAYHELLO_TO:
        {
            std::cout << "server: Processing SAYHELLO_TO command\n";
            
            String8 name = data.readString8();

            reply->writeString8(String8("Greeting to ") + name);
            break;
        }
        default:
            return BBinder::onTransact(code, data, reply, flags);
    }
    return 0;
}
