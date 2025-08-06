#include <iostream>
#include <string>
#include <fstream>// access file opertor
#include <cstdlib> // For exit()

using namespace std;

string username, password, password2;
int choice;
int confirmation;

void writetofile(string username) {
    ofstream writefile;
    string filename = username + ".txt";
    writefile.open(filename.c_str());
    if (writefile.is_open()) {
        writefile << password;
        writefile.close();
        cout << " Registration successful!\n";
    } else {
        cout << " Error opening file.\n";
    }
}

void login() {
    cout << " Enter your username: ";
    cin >> username;
    cout << " Enter your password: ";
    cin >> password;

    string filename = username + ".txt";
    ifstream readfile(filename.c_str());

    if (!readfile.is_open()) {
        cout << " No such user found.\n";
        return;
    }

    string stored_password;
    getline(readfile, stored_password);
    readfile.close();

    if (stored_password == password) {
        cout << " Login successful!\n";
    } else {
        cout << " Incorrect password.\n";
    }
}

void registerpassword();

void registerme() {
    cout << " Please enter your username: ";
    cin.ignore(); // To clear newline
    getline(cin, username);
    cout << "\nYou entered \"" << username << "\". Is this correct?\n[1] Yes\n[2] No\n";
    cin >> confirmation;

    if (confirmation == 1) {
        registerpassword();
    } else {
        cout << " Let's try again.\n";
        registerme();
    }
}

void registerpassword() {
    cout << " Enter your password: ";
    cin >> password;
    cout << " Re-enter your password: ";
    cin >> password2;

    if (password == password2) {
        writetofile(username); 
    } else {
        cout << " Passwords do not match. Try again.\n";
        registerpassword();
    }
}

void exitprogram() {
    cout << "Exiting program. Goodbye!\n";
    exit(0);
}

void mainmenu() {
    cout << "\n Main Menu\n";
    cout << "[1] Login\n";
    cout << "[2] Register\n";
    cout << "[3] Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << " Invalid input. Try again: ";
        cin >> choice;
    }

    switch (choice) {
        case 1:
            login();
            break;
        case 2:
            registerme();
            break;
        case 3:
            exitprogram();
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            mainmenu();
            break;
    }
}

int main() {
    cout << "Hello, Welcome to the Login/Register System \n";
    mainmenu();
    return 0;
}
