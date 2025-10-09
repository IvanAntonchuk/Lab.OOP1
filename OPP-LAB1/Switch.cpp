#include "Switch.h"

Switch::Switch() : NetworkDevice(), numPorts(0), manufacturer("Unknown") {}

Switch::Switch(const std::string& n, const std::string& i, const std::string& m, bool online, const std::string& loc,
    int ports, const std::string& manuf)
    : NetworkDevice(n, i, m, online, loc), numPorts(ports), manufacturer(manuf) {
}

void Switch::connectDevice(int port, const std::string& deviceName) {
    portStatus[port] = deviceName;
}

void Switch::disconnectDevice(int port) {
    portStatus.erase(port);
}

void Switch::displayPortStatus() const {
    for (const auto& p : portStatus)
        std::cout << "Port " << p.first << " -> " << p.second << "\n";
}

void Switch::displayInfo() const {
    NetworkDevice::displayInfo();
    std::cout << "Manufacturer: " << manufacturer << "\nPorts: " << numPorts << "\n";
    displayPortStatus();
}