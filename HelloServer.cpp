#define LOG_TAG "helloserver"
#include <log/log.h>

#include <unistd.h>
#include <stdlib.h>
#include <utils/RefBase.h>
#include <utils/Log.h>
#include <binder/TextOutput.h>
#include <binder/IInterface.h>
#include <binder/IBinder.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "com/yuandaima/IHello.h"
#include "com/yuandaima/BnHello.h"

using namespace android;

class MyHelloService : public com::yuandaima::BnHello
{
    public:
    binder::Status hello() 
    {
        ALOGI("server hello function is running");
        return binder::Status();
    }


    binder::Status sum(int32_t x, int32_t y, int32_t* _aidl_return) 
    {
         ALOGI("server sum function is running");
         *_aidl_return = x + y;
         return binder::Status();
    }
    
};

int main(int argc, char const *argv[])
{
    
    ALOGD("Hello Server is runing");
    
    defaultServiceManager()->addService(String16("MyHelloService"), new MyHelloService());
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
    
    return 0;
}
