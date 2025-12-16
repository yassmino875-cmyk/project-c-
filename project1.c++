#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

string titles[MAX];
string authors[MAX];
string status[MAX];

int countBooks = 0;

void addBook() {
    if (countBooks >= MAX) {
        cout << "Library is full\n";
        return;
    }

    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, titles[countBooks]);

    cout << "Enter author name: ";
    getline(cin, authors[countBooks]);

    status[countBooks] = "Available";

    countBooks++;
    cout << "Book added successfully\n";
}

void searchBook() {
    string name;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, name);

    for (int i = 0; i < countBooks; i++) {
        if (titles[i] == name) {
            cout << "Book Found\n";
            cout << "Title: " << titles[i] << endl;
            cout << "Author: " << authors[i] << endl;
            cout << "Status: " << status[i] << endl;
            return;
        }
    }
    cout << "Book not found\n";
}

void borrowBook() {
    string name;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, name);

    for (int i = 0; i < countBooks; i++) {
        if (titles[i] == name) {
            if (status[i] == "Available") {
                status[i] = "Borrowed";
                cout << "Book borrowed successfully\n";
            } else {
                cout << "Book is already borrowed\n";
            }
            return;
        }
    }
    cout << "Book not found\n";
}

void returnBook() {
    string name;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, name);

    for (int i = 0; i < countBooks; i++) {
        if (titles[i] == name) {
            if (status[i] == "Borrowed") {
                status[i] = "Available";
                cout << "Book returned successfully\n";
            } else {
                cout << "Book is already available\n";
            }
            return;
        }
    }
    cout << "Book not found\n";
}

void displayBooks() {
    if (countBooks == 0) {
        cout << "No books in library\n";
        return;
    }

    for (int i = 0; i < countBooks; i++) {
        cout << i + 1 << "- ";
        cout << titles[i] << " | ";
        cout << authors[i] << " | ";
        cout << status[i] << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\n==== Library Menu ====\n";
        cout << "1- Add New Book\n";
        cout << "2- Search Book\n";
        cout << "3- Borrow Book\n";
        cout << "4- Return Book\n";
        cout << "5- Display All Books\n";
        cout << "6- Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: searchBook(); break;
            case 3: borrowBook(); break;
            case 4: returnBook(); break;
            case 5: displayBooks(); break;
            case 6: cout << "Good Bye\n"; break;
            default: cout << "Invalid choice\n";
        }

    } while (choice != 6);
    system("pause");

    return 0;
}
