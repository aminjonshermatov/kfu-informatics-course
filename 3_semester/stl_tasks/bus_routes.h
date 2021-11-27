//
// Created by aminjonshermatov on 11/27/2021.
//

#ifndef INFORMATICS_BUS_ROUTES_H
#define INFORMATICS_BUS_ROUTES_H

#include "bits/stdc++.h"

using namespace std;

enum BusRoutesCommands {
    NEW_BUS,
    BUSES_FOR_STOP,
    STOPS_FOR_BUS,
    ALL_BUSES
};

istream& operator>>(istream& in, BusRoutesCommands& brc) {
    string cmd;
    in >> cmd;

    if (cmd == "NEW_BUS") brc = NEW_BUS;
    else if (cmd == "BUSES_FOR_STOP") brc = BUSES_FOR_STOP;
    else if (cmd == "STOPS_FOR_BUS") brc = STOPS_FOR_BUS;
    else if (cmd == "ALL_BUSES") brc = ALL_BUSES;

    return in;
}

class BusRoutes {
public:
    BusRoutes() = default;

    void addBus(const string& busName, const vector<string>& _stops) {
        buses[busName] = _stops;

        for (const auto& stop : _stops) stops[stop].push_back(busName);
    }

    void printBusesForStop(const string& stop) const {
        if (stops.count(stop) == 0) {
            cout << "No stop";
        } else {
            for (const auto& bus : stops.at(stop)) cout << bus << ' ';
        }
        cout << '\n';
    }

    void printStopsForBus(const string& bus) const {
        if (buses.count(bus) == 0) {
            cout << "No bus";
        } else {
            for (const auto& stop : buses.at(bus)) {
                cout << "Stop " << stop << ": ";
                if (stops.at(stop).size() == 1 && stops.at(stop)[0] == bus) cout << "no interchange" << '\n';
                else {
                    for (const auto& _bus : stops.at(stop)) {
                        if (_bus == bus) continue;

                        cout << _bus << ' ';
                    }
                    cout << '\n';
                }
            }
        }
        cout << '\n';
    }

    void printAllBuses() const {
        if (buses.empty()) {
            cout << "No buses" << '\n';
        } else {
            for (const auto& [bus, _stops] : buses) {
                cout << "Bus " << bus << ": ";

                for (const auto& stop : _stops) cout << stop << ' ';
                cout << '\n';
            }
        }
    }

private:
    map<string, vector<string>> stops;
    map<string, vector<string>> buses;
};

#endif //INFORMATICS_BUS_ROUTES_H
