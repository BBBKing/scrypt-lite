// commons.cpp / scrypt-lite

/*
    MIT License

    Copyright (c) 2019 Leon Latsch
*/

#include <string>
#include <iostream>
#include <sys/stat.h>
#include <iostream>
#include <termios.h>
#include <unistd.h>

using namespace std;

void info(std::string const message) {
    std::cout << "[" << "\033[1;36mINFO\033[0m" << "] " << message << std::endl;
}

void error(std::string const &message) {
    std::cerr << "[" << "\033[1;31mERROR\033[0m"  <<"] " << message << std::endl;
}

bool exists(const std::string& file) {
    struct stat buffer;
    return (stat (file.c_str(), &buffer) == 0);
}


void setStdinEcho(bool enable = true) {
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    if( !enable )
        tty.c_lflag &= ~ECHO;
    else
        tty.c_lflag |= ECHO;

    (void) tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

string read(string message, bool withEcho = true) {
    cout << "[" << "\033[1;32mREAD\033[0m" << "] " << message;
    setStdinEcho(false);
    string content;
    cin >> content;
    setStdinEcho(true);
    cout << endl;
    return content;
}