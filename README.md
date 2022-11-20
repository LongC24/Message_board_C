- Coder:
    - Lichao Yang

- Date:
    - 2022-10-29

- Requirements
    - Python:
        - pip install requests
    - PHP
    - MySQL
    - Web Server

- Description:
    - This is a simple message board program.
    - Composed using C++ Python PHP HTML and SQL
- Run
    - First compile and run main.cpp according to CMakeLists, then it will detect the network connection and exit the
      program if the connection fails. Otherwise, it will continue to run. The user is asked to enter a name and a
      comment. Then call sentToDB.py to send data to InsertToDB.php. Finally, index.php is used to display the comments
      to the user.
    -
- Summary：
    - This is a simple message board program. Composed using C++ Python PHP HTML and SQL


- File:
    - C++:
        - main.cpp
            - showMenu()
                - Show Menu
            - getUserChoice()
                - Get the user's input and validate it(Y/N)
            - getCurrentTime()
                - Get the current comment time and format it
            - getUserNameComment()
                - Get the user's name and comment, and validate it. Then call getCurrentTim() to get the time and date
                  and return it via the User class.
        - Network.h
            - Network.cpp
                - Contains a method for check the networks
        - User.h
            - User.cpp
                - A Class contains the name Comment and the comment time
                - Data validation function for names and comments
    - Python:
        - sentToDB.py
    - PHP:
        - InsertToDB.php
        - index.php
        - lib/constants.php
        - lib/Database.php
        - lib/pass.php
            - lib/pass_demo.php(After chang the password, please rename this file to pass.php)
            - Contains write and read passwords for the database Future work

- Future work
    - Add delete user comment function
    - Add the web comment space
    - Add more CSS to make it look better
    - If possible add a GUI interface
    - If possible add a login system
- Know Bugs
    - If the network detection passes and then disconnects, the data may not be sent.
