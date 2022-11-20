#include "Network.h"
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

// If the network is not connected, return false. Otherwise, return true.
bool Network::isConnected() {

    cout << "Checking network connection..." << endl;

    string command = "ping w3.uvm.edu -c 2  >netlog_temp.log";
    system(command.c_str());
    sleep(2);

    ifstream infile;
    infile.open("netlog_temp.log");
    string s;
    vector<string> v;
    while (infile) {
        getline(infile, s);
        if (infile.fail())
            break;
        v.push_back(s);
    }
    infile.close();

    system("rm netlog_temp.log");


    if (v.size() > 1) {
        string data = v[v.size() - 2];
        int iPos = data.find("received,");
        if (iPos != -1) {
            data = data.substr(iPos + 10, 3);
            int n = atoi(data.c_str());
            if (n == 0) {
                cout << "Network is connected." << endl;
                return true;
            } else {
                cout << "Network is not connected." << endl;
                cout << "Please check your network connection." << endl;
                return false;
            }
        }

    } else {
        cout << "Network is not connected." << endl;
        cout << "Please check your network connection." << endl;
        return false;
    }
    return false;
}
