#include "Router.h"
#include "Switch.h"
#include "Protocol.h"
#include "Graph.h"
#include "TemplateUtility.h"
#include <algorithm>

int main() {
    Router r("R1", "192.168.1.1", "AA:BB:CC:DD:EE:FF", true, "ServerRoom", 4, "RTX1000", "v2.1");
    Switch s("S1", "192.168.1.2", "11:22:33:44:55:66", true, "Lab", 8, "NetMaker");
    TCP tcp;
    UDP udp;
    AdjacencyListGraph graph;

    int choice;
    do {
        std::cout << "\nMenu:\n"
            << "1. Show Router Info\n"
            << "2. Add Route\n"
            << "3. Show Switch Info\n"
            << "4. Connect Device to Switch\n"
            << "5. Send TCP\n"
            << "6. Send UDP\n"
            << "7. Graph Add Edge\n"
            << "8. Graph Display\n"
            << "0. Exit\n"
            << "Choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            r.displayInfo();
            break;

        case 2: {
            std::string dest, gw;
            std::cout << "Destination: "; std::cin >> dest;
            std::cout << "Gateway: "; std::cin >> gw;
            r.addRoute(dest, gw);
            std::cout << "Route added.\n";
            break;
        }

        case 3:
            s.displayInfo();
            break;

        case 4: {
            int port;
            std::string dev;
            std::cout << "Port: "; std::cin >> port;
            std::cout << "Device Name: "; std::cin >> dev;
            s.connectDevice(port, dev);
            std::cout << "Device connected.\n";
            break;
        }

        case 5: {
            std::string msg;
            std::cout << "Message: "; std::cin >> msg;
            tcp.send(msg);
            break;
        }

        case 6: {
            std::string msg;
            std::cout << "Message: "; std::cin >> msg;
            udp.send(msg);
            break;
        }

        case 7: {
            int from, to;
            std::cout << "From: "; std::cin >> from;
            std::cout << "To: "; std::cin >> to;

            graph.addNode(std::max(from, to));

            sendPacketTemplate(graph, from, to);
            break;
        }

        case 8:
            std::cout << "Graph:\n";
            graph.displayGraph();
            break;

        case 0:
            std::cout << "Exiting...\n";
            break;

        default:
            std::cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}