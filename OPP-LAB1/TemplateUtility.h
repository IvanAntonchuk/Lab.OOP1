#ifndef TEMPLATEUTILITY_H
#define TEMPLATEUTILITY_H

#include <iostream>

template<typename GraphType>
void sendPacketTemplate(GraphType& g, int from, int to) {
    g.addEdge(from, to);
    std::cout << "Packet sent from " << from << " to " << to << "\n";
}

#endif