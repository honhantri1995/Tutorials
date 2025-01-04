#pragma once

#include <IHelloService.h>

using namespace android;

class BnHelloService : public BnInterface<IHelloService> {
public:
    virtual status_t onTransact(uint32_t code,
                                const Parcel &data,
                                Parcel* reply,
                                uint32_t flags = 0);
};
