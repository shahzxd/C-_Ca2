#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Crawler.h"
#include "Hopper.h"

using namespace std;

int main() {
    vector<Bug *> bugs;
    int choice = 0;

    while (choice != 9) {
        cout << "\nWelcome to Bug Board\n"
             << "1. Load Bugs from File\n"
             << "2. Display All Bugs\n"
             << "3. Find Bug by ID\n"
             << "4. Simulate Bug Movement\n"
             << "5. Display Life History of Bugs\n"
             << "6. Display Bugs by Cell\n"
             << "7. Run Simulation\n"
             << "8. Run Simulation with GUI\n"
             << "9. Exit and Save Bug History\n"
             << "Select an option: ";

        cin >> choice;

        switch (choice) {
            case 1: {
                ifstream file("bugs.txt");
                if (!file.is_open()) {
                    cout << "Error: Unable to open file." << endl;
                    break;
                }

                string line;
                while (getline(file, line)) {
                    stringstream ss(line);
                    string value;
                    vector<string> values;
                    while (getline(ss, value, ';')) {
                        values.push_back(value);
                    }

                    char type = values[0][0];
                    int id = stoi(values[1]);
                    int x = stoi(values[2]);
                    int y = stoi(values[3]);
                    int direction = stoi(values[4]);
                    int size = stoi(values[5]);

                    pair<int, int> position = make_pair(x, y);

                    if (type == 'H') {
                        int hopLength = stoi(values[6]);
                        bugs.push_back(new Hopper(id, position, direction, size, true, {}, hopLength));
                    } else {
                        bugs.push_back(new Crawler(id, position, direction, size, true, {}));
                    }
                }
                file.close();
                cout << "Bugs loaded successfully." << endl;
                break;
            }
            case 2: {
                cout << "Displaying All Bugs:\n";
                for (const auto &bug : bugs) {
                    bug->display();
                }
                break;
            }
            case 3: {
                int id;
                cout << "Enter Bug ID: ";
                cin >> id;
                bool found = false;
                for (const auto &bug : bugs) {
                    if (bug->getID() == id) {
                        found = true;
                        bug->display();
                        break;
                    }
                }
                if (!found) {
                    cout << "Bug with ID " << id << " not found." << endl;
                }
                break;
            }
            case 4: {
                cout << "Simulating Bug Movement...\n";
                for (const auto &bug : bugs) {
                    bug->move();
                }
                cout << "Simulation complete." << endl;
                break;
            }
            case 5: {
                cout << "Displaying Life History of Bugs:\n";
                for (const auto &bug : bugs) {
                    bug->displayHistory();
                }
                break;
            }
            case 6: {
                cout << "Displaying Bugs by Cell:\n";
                // Implement displaying bugs by cell
                break;
            }
            case 7: {
                cout << "Running Simulation...\n";
                // Implement simulation
                cout << "Simulation complete." << endl;
                break;
            }
            case 8: {
                cout << "Running Simulation with GUI...\n";
                // Implement simulation with GUI
                cout << "Simulation with GUI complete." << endl;
                break;
            }
            case 9: {
                ofstream historyFile("BugHistory.txt");
                if (!historyFile.is_open()) {
                    cout << "Error: Unable to open file for writing." << endl;
                    break;
                }
                cout << "Saving Bug History to file...\n";
                for (const auto &bug : bugs) {
                    historyFile << bug->getHistory() << endl;
                }
                historyFile.close();
                cout << "Bug History saved successfully." << endl;
                break;
            }
            default: {
                cout << "Invalid option. Please select again." << endl;
                break;
            }
        }
    }

    // Clean up memory
    for (auto bug : bugs) {
        delete bug;
    }
    return 0;
}
