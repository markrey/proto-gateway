#ifndef BACNETREADPROPERTYACK_H
#define BACNETREADPROPERTYACK_H

#include "bacnetservice.h"
#include "bacnetcommon.h"
#include "bacnetservicedata.h"
#include "readpropertyservicedata.h"
#include "bacnetdata.h"

namespace Bacnet {

    class BacnetReadPropertyAck:
            public BacnetServiceData
    {
    public:
        BacnetReadPropertyAck();
        BacnetReadPropertyAck(ReadPropertyServiceData &ackReadPrptyData, BacnetDataInterfaceShared &data);
        ~BacnetReadPropertyAck();


    public://overridden BacnetServiceData methods.
        virtual qint32 fromRaw(quint8 *serviceData, quint16 bufferLength);
        virtual qint32 toRaw(quint8 *startPtr, quint16 bufferLength);

    public:
        ReadPropertyServiceData _readData;
        BacnetDataInterfaceShared _data;
    };

}

#endif // BACNETREADPROPERTYACK_H
