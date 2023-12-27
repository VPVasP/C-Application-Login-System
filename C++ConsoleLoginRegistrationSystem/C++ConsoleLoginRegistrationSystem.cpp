#include <iostream>
#include <fstream>
#include <string>


bool doesUserExist(const std::string& username) {
    std::ifstream infile("UserInfo.txt");
    std::string storedUsername, storedPassword;

    while (infile >> storedUsername >> storedPassword) {
        if (storedUsername == username) {

            return true;
        }
    }

    return false;
}

void clearUserCredentials() {
    std::ofstream outfile("UserInfo.txt", std::ofstream::trunc);
    outfile.close();
}
void registerUser() {
    std::string username, password;

    std::cout << "Enter a username: ";
    std::cin >> username;


    if (doesUserExist(username)) {

        std::cout << "Error: This username already exists. Please choose a different username.\n";

        return;
    }

    std::cout << "Enter a password: ";
    std::cin >> password;


    std::ofstream outfile("UserInfo.txt", std::ios::app);

    if (outfile.is_open()) {

        outfile << username << " " << password << "\n";
        std::cout << "Registration successful!\n";
        outfile.close();
    }
    else {

        std::cerr << "Error: Unable to open file for registration.\n";

    }
}


bool loginUser(const std::string& username, const std::string& password) {
    std::ifstream infile("UserInfo.txt");
    std::string storedUsername, storedPassword;

    while (infile >> storedUsername >> storedPassword) {
        if (storedUsername == username && storedPassword == password) {

            return true;

        }
    }

    return false;
}

int main() {
    int choice;

    do {
        std::cout << "Welcome to the VP Login System\n";
        std::cout << "1. Login\n";
        std::cout << "2. Register\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string username, password;

            std::cout << "Enter your username: ";
            std::cin >> username;

            std::cout << "Enter your password: ";
            std::cin >> password;

            if (loginUser(username, password)) {
                std::cout << "Hello, " << username << "!You are now logged in.\n";
            }
            else {
                std::cout << "Login failed. Incorrect username or password.\n";
            }

            break;
        }

        case 2:
            registerUser();
            break;

        case 0:
            std::cout << "Exiting the application\n";
            break;

        default:
            std::cout << "You pressed the wrong number,please choose on of the above.\n";
        }
    } while (choice != 0);

    return 0;
}