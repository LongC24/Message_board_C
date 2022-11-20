#include <iostream>
#include <string>
#include <vector>
#include "Network.h"
#include "User.h"

using namespace std;
// Different OSs use different CLI commands to run Python
#ifdef _WIN32
const string python = "py";
#else
const string python = "python3";
#endif

void showMenu();

// ask the user want to continue or not by Y/N and validate the input
char getUserChoice();

// get the current time by YYYY-mm-DD:HH-MM and return it as a string and format it
string getCurrentTime();

// get the user name and comment and validate it
User getUserNameComment();


int main() {


    static bool debug = false;
    static bool skipNetworkCheck = false;

    if (skipNetworkCheck) {
        cout << "Skip the NetworkCheck" << endl;
    } else {
        // if the network is not connected, the program will not run
        if (!Network::isConnected()) {
            cout << "Exit the program please try again later after check the internet is Ok" << endl;
            return 0;
        }
    }

    // Shoe the menu
    showMenu();


    // creat a vector of to store the user's name and comment
    vector<User> userNameComment;

    // get the user's name and comment and validate it
    char userChoice;
    do {
        //push the user's name and comment to the vector
        cin.ignore();
        userNameComment.push_back(getUserNameComment());
        userChoice = getUserChoice();
    } while (userChoice == 'Y' || userChoice == 'y');


    //if debug print the user's name and comment
    if (debug) {
        for (auto &i: userNameComment) {
            cout << "User name: " << i.getName() << endl;
            cout << "User comment: " << i.getComment() << endl;
        }
    }


    // send the user's name and comment to the python
    for (auto &i: userNameComment) {
        string command;
        command = python + " ../sentToDB.py " + i.getName() + " " + i.getComment() + " " + i.getCommentTime();
        system(command.c_str());
    }

    cout << "Thank you for your comments" << endl;

    return 0;
}

void showMenu() {
    string junk;
    cout << "This is a simple message board program can write  message to the web page" << endl;
    cout << "After you don't want keep going, the comment will be sent to web page automatically " << endl;
    cout << "Press enter to continue" << endl;
}

char getUserChoice() {
    // ask the user want to continue or not by Y/N and validate the input
    char userChoice;
    do {
        cout << "Do you want to continue? (Y/N): ";
        cin >> userChoice;
        if (userChoice != 'Y' && userChoice != 'N' && userChoice != 'y' && userChoice != 'n') {
            cout << "Invalid input, please try again" << endl;
        }
    } while (userChoice != 'Y' && userChoice != 'N' && userChoice != 'y' && userChoice != 'n');

    return userChoice;

}

string getCurrentTime() {
    // get the current time by YYYY-MM-DD:HH-MM and return it as a string and format it
    time_t now = time(0);
    struct tm *tm = localtime(&now);
    char buf[80];
    strftime(buf, sizeof(buf), "%Y/%m/%d-%H:%M", tm);
    string currentTime(buf);
    return currentTime;


}

User getUserNameComment() {
    // get the user input username that can't contain space and special characters
    string userName;
    cout << "Please enter your name: ";
    getline(cin, userName);
    while (!User::nameValid(userName)) {
        cout << "Invalid input, please try again" << endl;
        cout << "Please enter your name: ";
        getline(cin, userName);
    }

    cout << "Welcome " << userName << "!" << endl;
    cout << "Please leave a comment Thanks!" << endl;


    // get the user comment by getline and valid the input by User::commentValid
    string userComment;
    do {
        cout << "Please enter your comment: ";
        getline(cin, userComment);
        if (!User::commentValid(userComment)) {
            cout << "Invalid input, please try again" << endl;
        }
    } while (!User::commentValid(userComment));



    //replace the space to '^'
    for (auto &i: userComment) {
        if (i == ' ') {
            i = '^';
        }
    }

    return User(userName, userComment, getCurrentTime());


}


