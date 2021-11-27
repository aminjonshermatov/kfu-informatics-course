//
// Created by aminjonshermatov on 11/27/2021.
//
#include "bus_routes.h"

void TestBusRoutes() {
    /*
     * Input data
     10
    ALL_BUSES
    BUSES_FOR_STOP Marushkino
    STOPS_FOR_BUS 32K
    NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
    NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
    BUSES_FOR_STOP Vnukovo
    NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
    NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
    STOPS_FOR_BUS 272
    ALL_BUSES
    */
    BusRoutes br;

    int q;
    cin >> q;

    while (q--) {
        BusRoutesCommands command;
        cin >> command;

        switch (command) {
            case NEW_BUS: {
                string bus;
                cin >> bus;

                int k;
                cin >> k;
                vector<string> stops(k);

                for (auto& stop : stops) cin >> stop;

                br.addBus(bus, stops);
                break;
            }
            case BUSES_FOR_STOP: {
                string stop;
                cin >> stop;

                br.printBusesForStop(stop);
                break;
            }
            case STOPS_FOR_BUS: {
                string bus;
                cin >> bus;

                br.printStopsForBus(bus);
                break;
            }
            case ALL_BUSES:

                br.printAllBuses();
                break;
            default:
                cout << "Unknown command: " << command;
        }
    }
}

int main() {
    TestBusRoutes();
}