// Question::1
// Create a class called Playlist with a default constructor that sets the playlist name to 'My Favourites' and prints a welcome message when an object is created.

// Answer::
#include <iostream>
#include <string>
using namespace std;

class Playlist {
public:
    string name;

    Playlist() {
        name = "My Favourites";
        cout << "Welcome to your playlist!" << endl;
    }
};

int main() {
    Playlist p1;

    cout << "Playlist Name: " << p1.name << endl;

    return 0;
}

// Question::2
// Build a class Product for a Flipkart-style app with a parameterized constructor that takes productName, price, and rating as arguments and displays all details using a displayInfo() method.

// Answer::
#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string productName;
    double price;
    double rating;

    Product(string n, double p, double r) {
        productName = n;
        price = p;
        rating = r;
    }

    void displayInfo() {
        cout << "Product: " << productName << endl;
        cout << "Price: " << price << endl;
        cout << "Rating: " << rating << endl;
    }
};

int main() {
    Product p1("Laptop", 45000, 4.5);

    p1.displayInfo();

    return 0;
}

// Question::3
// Create a class Movie with a parameterized constructor and then use a copy constructor to duplicate a Movie object. Print both the original and copied movie details to show they are identical.

// Answer::

#include <iostream>
#include <string>
using namespace std;

class Movie {
public:
    string name;
    int year;

    Movie(string n, int y) {
        name = n;
        year = y;
    }

    Movie(const Movie &m) {
        name = m.name;
        year = m.year;
    }

    void display() {
        cout << "Movie: " << name << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    Movie m1("Dangal", 2016);
    Movie m2(m1);

    cout << "Original Movie:" << endl;
    m1.display();

    cout << "\nCopied Movie:" << endl;
    m2.display();

    return 0;
}

// Question::4
// Simulate a BookMyShow ticket booking by creating a Ticket class that prints 'Saving your ticket...' in its destructor. Create and delete a Ticket object to demonstrate the destructor lifecycle.<br><br><em><strong>Hint:</strong> Use the __del__ method (Python) or ~Ticket() (C++) to define the destructor.</em>

// Answer::
#include <iostream>
using namespace std;

class Ticket {
public:
    Ticket() {
        cout << "Ticket booked!" << endl;
    }

    ~Ticket() {
        cout << "Saving your ticket..." << endl;
    }
};

int main() {
    Ticket *t1 = new Ticket();

    delete t1;

    return 0;
}

// Question::5
// Modify your Playlist class so that it auto-saves the playlist name to a file called autosave.txt when the object is destroyed, simulating an auto-save feature like Spotify.<br><br><em><strong>Hint:</strong> Write the file-saving code inside the destructor.</em>

// Answer::
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Playlist {
public:
    string name;

    Playlist(string n) {
        name = n;
    }

    ~Playlist() {
        ofstream file("autosave.txt");

        if (file.is_open()) {
            file << name;
            file.close();

            cout << "Playlist saved successfully!" << endl;
        }
    }
};

int main() {
    Playlist p1("My Favourites");

    cout << "Playlist: " << p1.name << endl;

    return 0;
}




