
#include "User.h"
#include <iostream>

using namespace std;

User::User(string name, string comment, string commentTime) {
    this->name = name;
    this->comment = comment;
    this->commentTime = commentTime;

}

string User::getName() {
    return name;
}

string User::getComment() {
    return comment;
}

string User::getCommentTime() {
    return commentTime;
}

bool User::nameValid(const string& name) {
    if (name.length() > 20) {
        cout << "Cant longer than 20 characters" << endl;
        return false;
    }
    //not contain any special characters and the space
    for (int i = 0; i < name.length(); i++) {
        if (name[i] == ' ' || name[i] == '!' || name[i] == '@' || name[i] == '#' || name[i] == '$' || name[i] == '%' ||
            name[i] == '^' || name[i] == '&' || name[i] == '*' || name[i] == '(' || name[i] == ')' || name[i] == '-' ||
            name[i] == '_' || name[i] == '+' || name[i] == '=' || name[i] == '[' || name[i] == ']' || name[i] == '{' ||
            name[i] == '}' || name[i] == '|' || name[i] == '\\' || name[i] == ':' || name[i] == ';' ||
            name[i] == '\'' || name[i] == '\"' || name[i] == ',' || name[i] == '.' || name[i] == '/' ||
            name[i] == '<' || name[i] == '>' || name[i] == '?' || name[i] == '~' || name[i] == '`' || name[i] == '!') {
            cout << "Cant contain any special characters and the space" << endl;
            return false;
        }
    }

    return true;
}

bool User::commentValid(const string& comment) {
    if (comment.length() > 500) {
        return false;
    }

    //not contain any special characters except ' " . ? , ! : ; - _ @      (not sure)
    for (char i: comment) {
        if (!((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') ||
              (i >= '0' && i <= '9') || i == ' ' || i == '"' || i == '.' || i == '?' || i == ',' || i == '!' ||
              i == ':' || i == ';' || i == '-' || i == '_' || i == '@')) {
            cout << "Comment can only contain letters, numbers, space, '\"', . ? , ! : ; - _ @ " << endl;
            return false;
        }
    }


    return true;
}
