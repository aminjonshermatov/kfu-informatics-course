//
// Created by aminjonshermatov on 11/27/2021.
//

#include "regex"

#include "Instrument.h"
// 2
#include "Trumpet.h"
#include "Clarinet.h"
#include "Saxophone.h"

// 1
#include "Guitar.h"
#include "Violin.h"
#include "Accordion.h"

// 0
#include "Piano.h"
#include "Drum.h"
#include "Xylophone.h"

int main() {
    const unsigned int SIZE = 3;

    array<array<Instrument*, SIZE>, SIZE> instruments{
            {
                    {
                            new Trumpet(100, "TrumpetSound"),
                            new Clarinet(70, "ClarinetSound"),
                            new Saxophone(99, "SaxophoneSound")
                    },
                    {
                            new Guitar(120, "GuitarSound"),
                            new Violin(89, "ViolinSound"),
                            new Accordion(79, "AccordionSound")
                    },
                    {
                            new Piano(300, "PianoSound"),
                            new Drum(200, "DrumSound"),
                            new Xylophone(159, "XylophoneSound")
                    }
            }
    };

    stringstream commands;
    commands << "Commands:" << '\n'
             << '\t' << "Enter '\\list' to to display instruments." << '\n'
             << '\t' << "Enter '\\target {lineNumber} {instrumentNumber}' to show the specific instrument." << '\n'
             << '\t' << "Enter '\\exit' to exit from program." << '\n';


    stringstream instrumentList;
    instrumentList << "Instruments:" << '\n';
    for (const auto& line : instruments) {
        for (const auto& ins : line) {
            instrumentList << '\t' << setw(8) << left << ins->getName();
        }
        instrumentList << '\n';
    }

    cout << "Hi friend. Welcome to the musical instruments shop." << '\n';
    cout << commands.str();
    while (true) {
        string command;
        getline(cin, command);

        smatch match;
        if (regex_search(command, match, regex{"^\\\\(list|target ([1-3]) ([1-3])|exit)$"})) {
            if (match[1] == "list") {
                cout << instrumentList.str();
            } else if (match[1] == "exit") {
                cout << "Bye!";
                break;
            } else {
                cout << (*instruments[stoi(match[2]) - 1][stoi(match[3]) - 1]);
            }
        } else {
            cout << "Unknown command" << '\n'
                 << commands.str();
        }
    }
}
