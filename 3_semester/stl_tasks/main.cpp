//
// Created by aminjonshermatov on 11/27/2021.
//

#define __LOCAL__

#include "bus_routes.h"
#include "poples_queue.h"
#include "synonyms.h"

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
                cout << "Unknown command: " << command << '\n';
        }
    }
}

void TestPeoplesQueue() {
    /*
     * Input data
    8
    COME 5
    WORRY 1
    WORRY 4
    COME -2
    WORRY_COUNT
    COME 3
    WORRY 3
    WORRY_COUNT

    */
    PeoplesQueue pq;

    int q;
    cin >> q;

    while (q--) {
        PeoplesQueueCommands pqc;
        cin >> pqc;

        switch (pqc) {
            case WORRY: {
                int idx;
                cin >> idx;

                pq.worry(idx);
                break;
            }
            case QUIET: {
                int idx;
                cin >> idx;

                pq.quiet(idx);
                break;
            }
            case COME: {
                int k;
                cin >> k;

                if (k > 0) pq.come(k);
                else pq.leave(-k);

                break;
            }
            case WORRY_COUNT:
                pq.printWorryCount();
                break;
            default:
                cout << "Unknown command: " << pqc << '\n';
        }
    }
}

void TestSynonyms() {
    /*
     * Input data
    8
    ADD program code
    COUNT cipher
    ADD code cipher
    COUNT code
    COUNT program
    CHECK code program
    CHECK program cipher
    CHECK cpp java
    */
    Synonyms s;

    int q;
    cin >> q;

    while (q--) {
        SynonymsCommands sc;
        cin >> sc;

        switch (sc) {
            case ADD: {
                string word1, word2;
                cin >> word1 >> word2;

                s.add(word1, word2);
                break;
            }
            case COUNT: {
                string word;
                cin >> word;

                cout << s.synonymCount(word) << '\n';
                break;
            }
            case CHECK: {
                string word1, word2;
                cin >> word1 >> word2;

                cout << (s.check(word1, word2) ? "YES" : "NO") << '\n';
                break;
            }
            default:
                cout << "Unknown command: " << sc << '\n';
        }
    }
}

int main() {
#ifdef __LOCAL__
    freopen("../3_semester/stl_tasks/input.txt", "r", stdin);
    freopen("../3_semester/stl_tasks/output.txt", "w", stdout);
#endif

    TestBusRoutes();
    //TestPeoplesQueue();
    //TestSynonyms();
}