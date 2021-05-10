#include <iostream>
#include <fstream>
#include "Car2.h"
#include <sstream>
#include "Station2.h"

using namespace std;

int main(int argc, char* argv[]) {

    if (argc < 3) {
        cerr << "Please provide name of input and output files";
        return 1;
    }
    cout << "Input file: " << argv[1] << endl;
    ifstream in(argv[1]);
    if (!in) {
        cerr << "Unable to open " << argv[1] << " for input";
        return 2;
    }
    cout << "Output file: " << argv[2] << endl;
    ofstream out(argv[2]);
    if (!out) {
        in.close();
        cerr << "Unable to open " << argv[2] << " for output";
        return 3;
    }

    unsigned int carNum;


    Station<Car> stationHolder;
    string command;
    for(string line; getline(in,line);) {
        stringstream input(line);
        if(line == "") {
            continue;
        }
        input >> command;
        try {
            if (command == "Add:station") {
                input >> carNum;
                Car add;
                cout << add.id << endl;
                string error = "Error";
                if(stationHolder.GetCar().id == 0) {
                    add.SetCar(carNum);
                    stationHolder.AddCar(add);
                    out << line << " OK" << endl;
                }
                else {
                    throw error;
                }
            }
            if (command == "Add:queue") {
                string error = command + "Turntable empty!";
                if(stationHolder.GetCar().id == 0) {
                    throw error;
                }
                else {
                    stationHolder.AddQueue();
                    out << command << " OK" << endl;
                }


            }
            if (command == "Add:stack") {
                string error = command + " Turntable empty!";
                if (stationHolder.GetCar().id == 0 ) {
                    throw error;
                }
                else {
                    stationHolder.AddStack();
                    out << command <<  " OK" << endl;
                }
            }
            if (command == "Remove:station") {
               string error = command + " Turntable empty!";
               if(stationHolder.GetCar().id == 0) {
                   throw error;
               }
               else {
                   stationHolder.RemoveStation();
                   out << command << " " << "OK" << endl;
               }
            }
            if (command == "Remove:queue") {
                  stationHolder.RemoveQueue();
                  out << command << " OK" << endl;
            }
            if (command == "Remove:stack") {
                  stationHolder.RemoveStack();
                  out << command << " OK" << endl;
            }
            if (command == "Top:station") {
                string error = "Error";
                if(stationHolder.GetCar().id == 0) {
                    throw error;
                }
                else {
                    out << stationHolder.GetCar().id;
                }

            }
            if (command == "Top:queue") {
                string error = "Error";
                if(stationHolder.QueueEmpty()) {
                    throw error;
                }
                else {
                    out << command << " " << stationHolder.TopQueue().id << endl;
                }

            }
            if (command == "Top:stack") {
                string error = "Error";
                if(stationHolder.StackEmpty()) {
                    throw error;
                }
                else {
                    out << command << " " << stationHolder.TopStack().id << endl;
                }

            }
            if (command == "Size:queue") {
                out << command << " " << stationHolder.SizeQueue() << endl;

            }
            if (command == "Size:stack") {
                out << command << " " << stationHolder.SizeStack() << endl;

            }
            if (command == "Size:train") {
                 out << command << " " << stationHolder.SizeTrain() << endl;
            }
            if (command == "Queue") {
                 out << command << stationHolder.PrintQueue() << endl;
            }
            if (command == "Stack") {
                out << command << stationHolder.PrintStack() << endl;
            }
            if (command == "Train") {
              out << command << " " << stationHolder.PrintTrain() << endl;
            }
            if (command == "Find") {
                unsigned int findValue;
                input >> findValue;
               out << stationHolder.FindCar(findValue) << endl;
            }
        } catch(string error) {
            out << error << endl;
        }

    }





    return 0;


}


