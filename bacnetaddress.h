#ifndef BACNETADDRESS_H
#define BACNETADDRESS_H

#include <QtGlobal>

/**
  Bacnet address is a cocatenation of (6.1):
  # an optional network,
  # the MAC address appropriate to the underlying LAN technology,
  # the link service access point (what is it?)

  About broadcasts:
  - mac address equal to 0xffff means it's a global broadcast
  - mac address
  */

class   BacnetAddress
{
public:
    enum AddressConstants {
        MaxMacLength = 6,
        NetworkLength = 2
    };

    BacnetAddress();

    /**
      Sets address to be global broadcast
      and the MAC field gets zero'd.
      */
    void setGlobalBroadcast();
    /**
      Returns true, if address is a global broadcast.
      */
    bool isGlobalBroadcast() const;

    /**
      Sets the address to be a local broadcast and MAC fields get zero'd
      */
    void setLocalBroadcast();

    /**
      Returns true if address is local broadacst.
      */
    bool isLocalBraodacst() const;

    /**
      Sets address as a remote broadcast.
      \warning this is only preparation, you have to remember to set appropriate networknumber (earlier or later).
      */
    void setIsRemoteBroadcast();

    /**
      Depicts if address is a remote broadcast.
      */
    bool isRemoteBroadcast() const;

    /**
      Returns true, if the network number was set.
      */
    bool hasNetworkNumber() const;
    /**
      Returns network number, if present. Otherwise returns 0.
      */
    quint16 networkNumber() const;

    /**
      Returns true if address has been initialized (meaning the MAC part has been filled)
      */
    bool isAddrInitialized() const;
    /**
      Clears contents and sets it uninitialized.
      */
    void resetMacAddress();

    /**
      Sets actual network number at data pointer.
      \returns - number of bytes used to store the network number. It may be 0, if network number is invalid (internally less than 0)
      */
    quint8 networkNumToRaw(quint8 *data);

    /**
    Sets the network number according to the data passed.
    \param data - pointer to the data that is supposed to represent network number.
    \returns - number of bytes used to read network Number (currently it's 2)
      */
    quint8 setNetworkNumFromRaw(quint8 *data);

    //! Sets network number.
    void setNetworkNum(quint16 netNum);

    /**
      Reads lenght bytes *data and sets them as this address (in network byte orded,
      as there is no profit to do it in host byte orde)
      */
    void macAddressFromRaw(quint8 *data, quint8 length);

    /**
      Returns length of stored MAC address.
      */
    quint8 macAddrLength() const;

    /**
      Sets \sa length() bytes, starting from data pointer, to the value of MAC address in network byte order.
      */
    quint8 macAddressToRaw(quint8 *data);

    /**
      Compares two BacnetAddresses
      */
    bool operator ==(const BacnetAddress &other) const;

    /**
      The function returns pointer to _address table.
      \note probably you don't want to use this function.
      */
    const quint8 *macPtr() const;

public:
    /**
      Decodes mac address from string written in a following way xx:xx:..:xx, where xx is one byte
      encoded in hexadecimal.
      */
    bool macAddressFromString(QString &addressStr);

    bool networkNumFromString(QString &netStr);

    QString macAddressToString();
    QString netToString();

private:
    enum {
        GlobalBroadcastNet = 0xffff,
        UninitizlizedNet = -2
    };

    quint8 _macAddress[MaxMacLength];
    qint32 _networkNumber;
    qint8 _macAddrLength;
};

#endif // BACNETADDRESS_H
