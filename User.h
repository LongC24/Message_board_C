#ifndef Message_board_USER_H
#define Message_board_USER_H


#include <string>

using namespace std;

class User {
private:
    string name;
    string comment;
    string commentTime;
public:
    User(string name, string comment, string commentTime);

    // validate the username that is not empty and not longer than 20 characters and not contain any special characters
    static bool nameValid(const string &name);

    // validate the comment that is not empty nd not longer than 500 characters not contain any special characters
    static bool commentValid(const string &comment);


    string getName();

    string getComment();

    string getCommentTime();

};

#endif 
