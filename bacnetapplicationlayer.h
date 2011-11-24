#ifndef BACNETAPPLICATIONLAYERHANDLER_H
#define BACNETAPPLICATIONLAYERHANDLER_H

#include <QtCore>
#include <QList>
#include <QObject>

#include "bacnetpci.h"
#include "routingtable.h"

class BacnetAddress;
class BacnetNetworkLayerHandler;
class InternalObjectsHandler;

namespace Bacnet {
class ExternalObjectsHandler;
class ExternalConfirmedServiceHandler;
class BacnetTSM2;
class BacnetServiceData;
class BacnetDeviceObject;

class BacnetApplicationLayerHandler:
        public QObject
{
    Q_OBJECT
public:
    BacnetApplicationLayerHandler(BacnetNetworkLayerHandler *networkHndlr, QObject *parent = 0);
    virtual ~BacnetApplicationLayerHandler();

    /**
      Sets the the network layer handler, that will be invoked whenever new message is to be sent.
      */
    void setNetworkHandler(BacnetNetworkLayerHandler *networkHndlr);

    /**
      This is a method that should be invoked by Network Layer in order to pass data (starting at actualBytePtr*) of
      lenght length.
      \param - sourceAddr - is used by some requests/responses to localize the other device;
      \param - destAddr - not specified by BACnet but if application layer is supposed to act as a collection of
      devices we need to have information which device is being called.
      */
    void indication(quint8 *data, quint16 length, BacnetAddress &srcAddr, BacnetAddress &destAddr);

    void processConfirmedRequest(BacnetAddress &remoteSource, BacnetAddress &localDestination, quint8 *dataPtr, quint16 dataLength, BacnetConfirmedRequestData *crData);
    void processUnconfirmedRequest(BacnetAddress &remoteSource, BacnetAddress &localDestination, quint8 *dataPtr, quint16 dataLength, BacnetUnconfirmedRequestData &ucrData);
    void processAck(BacnetAddress &remoteSource, BacnetAddress &localDestination, quint8 *dataPtr, quint16 dataLength, ExternalConfirmedServiceHandler *serviceAct);
    void processError(BacnetAddress &remoteSource, BacnetAddress &localDestination, quint8 *dataPtr, quint16 dataLength, ExternalConfirmedServiceHandler *serviceAct);
    void processReject(BacnetAddress &remoteSource, BacnetAddress &localDestination, quint8 *dataPtr, quint16 dataLength, ExternalConfirmedServiceHandler *serviceAct);
    void processAbort(BacnetAddress &remoteSource, BacnetAddress &localDestination, quint8 *dataPtr, quint16 dataLength, ExternalConfirmedServiceHandler *serviceAct);
    void processTimeout(ExternalConfirmedServiceHandler *serviceAct);

    //! tries to send the data. When there is no translation entry obj id -> address, returns false. When discovery is to be used, when such case happens, use \sa sendUnconfirmedWithDiscovery()
    bool sendUnconfirmed(const ObjectIdStruct &destinedObject, BacnetAddress &source, BacnetServiceData &data, quint8 serviceChoice);
    //! sends unconfirmed data. When there is no translation entry objId -> address, first issues Who-has service. \note Takes ownership over BacnetServiceData.
    bool sendUnconfirmedWithDiscovery(const ObjectIdStruct &destinedObject, BacnetAddress &source, BacnetServiceData *data, quint8 serviceChoice);

    void sendUnconfirmed(const BacnetAddress &destination, BacnetAddress &source, BacnetServiceData &data, quint8 serviceChoice);
    bool send(const ObjectIdStruct &destinedObject, BacnetAddress &sourceAddress, BacnetServicesNS::BacnetConfirmedServiceChoice service, ExternalConfirmedServiceHandler *serviceToSend, quint32 timeout_ms = 1000);
    bool send(const BacnetAddress &destination, BacnetAddress &sourceAddress, BacnetServicesNS::BacnetConfirmedServiceChoice service, ExternalConfirmedServiceHandler *serviceToSend, quint32 timeout_ms = 1000);

    InternalObjectsHandler *internalHandler();
    ExternalObjectsHandler *externalHandler();
    QList<BacnetDeviceObject*> devices();

private:
    void discoverDevice(const ObjectIdStruct &deviceId);

protected:
    void timerEvent(QTimerEvent *);

protected:
    BacnetNetworkLayerHandler *_networkHndlr;

public:
    InternalObjectsHandler *_internalHandler;
    Bacnet::ExternalObjectsHandler *_externalHandler;
    Bacnet::BacnetTSM2 *_tsm;

private:
    static const int TimerInterval_ms = 1000;
    QBasicTimer _timer;
    static const int DefaultDynamicElementsSize = 100;
    RoutingTable _routingTable;
};

}

#endif // BACNETAPPLICATIONLAYERHANDLER_H
