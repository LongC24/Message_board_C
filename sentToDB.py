import sys
import requests

# get the user's name and comment from the command line


userName = sys.argv[1]
userComment = sys.argv[2]
commentTime = sys.argv[3]

# replase the ^ with space
userComment = userComment.replace("^", " ")

PASSWORD = 'Some_PW'

print()
print("Name: " + userName)
print("Comment: " + userComment)
print("CommentTime: " + commentTime)
print()


def connection(name, comment, time, password):
    URL = 'https://example.com/xxxx/insertToDB.php'
    PARAMS = {'password': password, 'UserName': name, 'UserComment': comment, 'Time': time}
    try:
        requests.get(url=URL, params=PARAMS)
    except:
        print("Error")


connection(userName, userComment, commentTime, PASSWORD)
print("Send Success")


