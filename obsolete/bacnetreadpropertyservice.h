#ifndef BACNETREADPROPERTYSERVICE_H
#define BACNETREADPROPERTYSERVICE_H

#include <QtCore>

#include "readpropertyservicedata.h"
#include "bacnetservice.h"
#include "bacnetcommon.h"
#include "error.h"

class BacnetObject;
class BacnetDeviceObject;
class BacnetTagParser;
class BacnetAck;
namespace Bacnet {class BacnetReadPropertyAck;}
class ReadPropertyServiceHandler:
        public BacnetService
{
public:
    qint32 fromRaw(quint8 *serviceData, quint8 buffLength);
    qint32 toRaw(quint8 *startPtr, quint8 buffLength);

public:
    QList<int> asynchIds();
    //! \Takes actions associated with asynchronous event and returns true, if the response is ready now.
    bool asynchActionFinished(int asynchId, int result, BacnetDeviceObject *device, BacnetObject *object);

public://derived from BacnetService
    virtual qint32 execute(BacnetDeviceObject *device);
    //! \warning The response is created only once. Caller takes ownership over the response.
    virtual BacnetService *takeResponse();
    virtual bool hasError();
    virtual Bacnet::Error &error();
    virtual bool isReady();


public:


private:
    /** Function is specific to this class.
      */
//    BacnetReject::RejectReason checkForError_helper(BacnetTagParser &bParser, qint16 parseRet, quint8 expectedTag, bool convertedOk);
    bool finishReading_helper(BacnetObject *device, int resultCode = 0);

public:
    ReadPropertyServiceHandler();
    ReadPropertyServiceHandler(Bacnet::ObjectIdStruct objId, BacnetProperty::Identifier propertyId,
                              quint32 arrayIndex = Bacnet::ArrayIndexNotPresent);

    ~ReadPropertyServiceHandler();

//private:
    Bacnet::ReadPropertyServiceData _rpData;
    Bacnet::Error _error;

    //! \todo Turn it into some asynch object.
    quint32 _asynchId;

    //! ReadPropertyServiceHandlerAck
    Bacnet::BacnetReadPropertyAck *_response;
};

#endif // BACNETREADPROPERTYSERVICE_H
