# -------------------------------------------------
# Project created by QtCreator 2011-07-19T19:54:05
# -------------------------------------------------
QT += core \
    network \
    xml
QT -= gui
TARGET = BACnet_KW
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app

INCLUDEPATH += gateway_common

INCLUDEPATH += internal \
    external \
    applayer \
    factories \
    datamodel \
    tests

SOURCES += main.cpp \
    bacnetvirtuallinklayer.cpp \
    bacnetnetworklayer.cpp \
    bacnetbbmdhandler.cpp \
    bacnetbipaddress.cpp \
    bacnetudptransportlayer.cpp \
    bacnetbiptransportlayer.cpp \
    bacnetaddress.cpp \
    bacnetrouter.cpp \
    bacnetapplicationlayer.cpp \
    bacnetnpci.cpp \
    helpercoder.cpp \
    bacnetbuffermanager.cpp \
    buffer.cpp \
    bacnetpci.cpp \
    bacnetcoder.cpp \
    bacnettagparser.cpp \
    datamodel/property.cpp \
    asynchowner.cpp \
    bacnettsm2.cpp \
    datamodel/cdm.cpp \
    bacnettsm.cpp \
    bacnetreadpropertyack.cpp \ # bacnetreadpropertyservice.cpp \
    bacnetcommon.cpp \
    bacnetobjectinternalsupport.cpp \
    #bacnetexternalobjects.cpp \
    analoginputobject.cpp \
    bacnetdeviceobject.cpp \
    bacnetobject.cpp \
    bacnetprimitivedata.cpp \ # bacneterrorack.cpp \
    servicefactory.cpp \
    asynchronousbacnettsmaction.cpp \
    bacnetservice.cpp \
    error.cpp \
    propertyvalue.cpp \
    bacnetdataabstract.cpp \
    bacnetconstructeddata.cpp \
    bacnetdefaultobject.cpp \
    bacnetsubscribecov.cpp \
    bacnetunconfirmedcov.cpp \
    bacnetconfirmedcov.cpp \
    sequenceof.cpp \
    bacnetdata.cpp \
    bacnetserviceack.cpp \
    propertyfactory.cpp \ # check.cpp \
    bacnetinternaladdresshelper.cpp \
    covsupport.cpp \
    covconfnotificationservicehandler.cpp \
    datavisitor.cpp \
    covincrementhandlers.cpp \
    bacnetcovsubscription.cpp \
    covsubscriptionstimehandler.cpp \
    discoverywrapper.cpp \
    invokeidgenerator.cpp \
    routingtable.cpp \
    \
    internal/internalsubscribecovrequesthandler.cpp \
    internal/internalwprequesthandler.cpp \
    internal/internalunconfirmedrequesthandler.cpp \
    internal/internalwhoisrequesthandler.cpp \
    internal/internalwhohasrequesthandler.cpp \
    internal/internalobjectshandler.cpp \
    internal/internalsubscribecovservicehandler.cpp \
    internal/internalrprequesthandler.cpp \
    internal/bacnetobject2.cpp \
    internal/deviceobject.cpp \
    internal/bacnetproperty.cpp \
    internal/internalconfirmedrequesthandler.cpp \
    internal/multipleasynchhelper.cpp \
    internal/internalihaveservicehandler.cpp \
    \
    external/externalservicehandler.cpp \
    external/bacnetwritepropertyservicehandler.cpp \
    external/bacnetreadpropertyservicehandler.cpp \
    external/externalobjectshandler.cpp \
    \
    applayer/writepropertyservicedata.cpp \
    applayer/whoisservicedata.cpp \
    applayer/whohasservicedata.cpp \
    applayer/subscribecovservicedata.cpp \
    applayer/readpropertyservicedata.cpp \
    applayer/ihaveservicedata.cpp \
    applayer/remoteobjectstodevicemapper.cpp \
    applayer/iamservicedata.cpp \
    applayer/covnotificationrequestdata.cpp \
    internal/internaliamservicehandler.cpp \
    externalconfirmedservicewrapper.cpp \
    external/externalpropertymapping.cpp \
    external/externalobjectreadstrategy.cpp \
    external/subscribecovservicehandler.cpp \
    tests/covanswerer.cpp \
    internal/internalconfirmedcovnotifhandler.cpp \
    applayer/bacnetarrayvisitor.cpp \
    internal/internaluncfrdmcovnotifhandler.cpp \
    tests/rpanswerer.cpp \
    external/externalobjectwritestrategy.cpp \
    external/externaltimedepjob.cpp \
    tests/wprequester.cpp \
    tests/wpacknowledger.cpp \
    factories/bacnetconfigurator.cpp \
    factories/networklayerconfigurator.cpp \
    factories/transportlayerconfigurator.cpp \
    factories/configuratorhelper.cpp \
    sng/sngsimplesensorproperty.cpp \
    sng/sngsimpleactorproperty.cpp \
    sng/sngcommon.cpp \
    datamodel/propertyconverter.cpp \
    datamodel/propertywithconversionobserver.cpp \
    datamodel/propertyobserver.cpp \
    datamodel/propertysubject.cpp \
    datamodel/propertyconvertersowner.cpp \
    tests/sngasynchvaluesetter.cpp \
    sng/sngdefinitions.cpp \
    factories/sngfactory.cpp \
    sng/snginternalsupport.cpp \
    datamodel/snginternaltypesmapper.cpp \
    gateway_common/bacnetprotocolinterface.cpp \
    gateway_common/sngprotocolinterface.cpp \
    gateway_common/protocolsmanager.cpp

HEADERS += bacnetvirtuallinklayer.h \
    bacnetnetworklayer.h \
    bacnetbbmdhandler.h \
    bacnetbipaddress.h \
    bacnetudptransportlayer.h \
    bacnetcommon.h \
    bacnettransportlayer.h \
    bacnetbiptransportlayer.h \
    bacnetaddress.h \
    bacnetrouter.h \
    bacnetapplicationlayer.h \
    bitfields.h \
    bacnetnpci.h \
    helpercoder.h \
    bacnetbuffermanager.h \
    buffer.h \
    bacnetpci.h \
    bacnetcoder.h \
    bacnettagparser.h \
    datamodel/property.h \
    bacnettsm2.h \ # asynchronousconfirmedhandler.h \
    asynchsetter.h \
    bacnettsm.h \
    bacnetreadpropertyack.h \
    datamodel/cdm.h \
    bacnetservice.h \ # bacneterrorack.h \
# bacnetreadpropertyservice.h \
    #bacnetexternalobjects.h \
    asynchowner.h \
    analoginputobject.h \
    bacnetobjectinternalsupport.h \
    bacnetdeviceobject.h \
    bacnetobject.h \
    servicefactory.h \
    asynchronousbacnettsmaction.h \
    error.h \
    bacnetprimitivedata.h \
    bacnetdefaultobject.h \
    bacnetdataabstract.h \
    bacnetconstructeddata.h \
    propertyvalue.h \
    bacnetsubscribecov.h \
    bacnetunconfirmedcov.h \
    sequenceof.h \
    bacnetconfirmedcov.h \
    bacnetdata.h \
    bacnetserviceack.h \
    datamodel/propertyowner.h \
    propertyfactory.h \ # check.h \
    cos.h \
    bacnetinternaladdresshelper.h \
    covsupport.h \
    covconfnotificationservicehandler.h \
    datavisitor.h \
    covincrementhandlers.h \
    bacnetcovsubscription.h \
    covsubscriptionstimehandler.h \
    discoverywrapper.h \
    invokeidgenerator.h \
    routingtable.h \
    \
    internal/internalconfirmedrequesthandler.h \
    internal/internalunconfirmedrequesthandler.h \
    internal/internalwhoisrequesthandler.h \
    internal/internalwhohasrequesthandler.h \
    internal/internalwprequesthandler.h \
    internal/internalsubscribecovrequesthandler.h \
    internal/internalsubscribecovservicehandler.h \
    internal/internalobjectshandler.h \
    internal/internalrprequesthandler.h \
    internal/bacnetobject2.h \
    internal/deviceobject.h \
    internal/bacnetproperty.h \
    internal/multipleasynchhelper.h \
    internal/internalpropertycontainersupport.h \
    internal/internalihaveservicehandler.h\
    \
    external/externalservicehandler.h \
    external/externalconfirmedservicehandler.h \
    external/bacnetwritepropertyservicehandler.h \
    external/externalobjectshandler.h \
    external/bacnetreadpropertyservicehandler.h \
    \
    applayer/writepropertyservicedata.h \
    applayer/whoisservicedata.h \
    applayer/whohasservicedata.h \
    applayer/subscribecovservicedata.h \
    applayer/readpropertyservicedata.h \
    applayer/ihaveservicedata.h \
    applayer/remoteobjectstodevicemapper.h \
    applayer/iamservicedata.h \
    applayer/covnotificationrequestdata.h \
    applayer/bacnetservicedata.h \
    internal/internaliamservicehandler.h \
    externalconfirmedservicewrapper.h \
    external/externalpropertymapping.h \
    external/externalobjectreadstrategy.h \
    external/subscribecovservicehandler.h \
    tests/covanswerer.h \
    internal/internalconfirmedcovnotifhandler.h \
    applayer/bacnetarrayvisitor.h \
    internal/internaluncfrdmcovnotifhandler.h \
    tests/rpanswerer.h \
    external/externalobjectwritestrategy.h \
    external/externaltimedepjob.h \
    tests/wprequester.h \
    tests/wpacknowledger.h \
    factories/bacnetconfigurator.h \
    factories/networklayerconfigurator.h \
    factories/transportlayerconfigurator.h \
    factories/configuratorhelper.h \
    sng/sngsimplesensorproperty.h \
    sng/sngsimpleactorproperty.h \
    sng/sngcommon.h \
    datamodel/propertyconverter.h \
    datamodel/propertywithconversionobserver.h \
    datamodel/propertyobserver.h \
    datamodel/propertysubject.h \
    datamodel/propertyconvertersowner.h \
    tests/sngasynchvaluesetter.h \
    sng/sngdefinitions.h \
    factories/sngfactory.h \
    sng/snginternalsupport.h \
    datamodel/snginternaltypesmapper.h \
    gateway_common/protocolinterface.h \
    gateway_common/bacnetprotocolinterface.h \
    gateway_common/sngprotocolinterface.h \
    gateway_common/protocolsmanager.h

OTHER_FILES +=

INCLUDEPATH += ./sng \
    ./sng/sng_include

HEADERS += sng/snghandler.h
SOURCES += sng/snghandler.cpp

LIBS += -lSNGConnectionManager
LIBS += -L./











































