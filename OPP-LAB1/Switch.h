#ifndef SWITCH_H
#define SWITCH_H

#include "NetworkDevice.h"
#include <map>

class Switch : public NetworkDevice {
private:
    int numPorts;
    std::map<int, std::string> portStatus;
    std::string manufacturer;
public:
    Switch();
    Switch(const std::string& name, const std::string& ip, const std::string& mac, bool isOnline, const std::string& location,
        int ports, const std::string& manufacturer);

    void connectDevice(int port, const std::string& deviceName);
    void disconnectDevice(int port);
    void displayPortStatus() const;
    void displayInfo() const override;
};
#endif