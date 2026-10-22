// Question::1
// Create a text file called my_fav_songs.txt and write the names of your 5 favorite songs into it using ofstream.

// Answer::
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("my_fav_songs.txt");

    file << "Kesariya" << endl;
    file << "Apna Bana Le" << endl;
    file << "Tum Hi Ho" << endl;
    file << "Heeriye" << endl;
    file << "Chaleya" << endl;

    file.close();

    cout << "Songs saved successfully!" << endl;

    return 0;
}

// Question::2
// Read all song names from my_fav_songs.txt using ifstream and display each song on a new line in the console.

// Answer::
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("my_fav_songs.txt");
    string song;

    while (getline(file, song)) {
        cout << song << endl;
    }

    file.close();

    return 0;
}

// Question::3
// Modify your code to append a new song name entered by the user to my_fav_songs.txt without overwriting the existing list.<br><br><em><strong>Hint:</strong> Open the file in append mode using ofstream.</em>

// Answer::
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream file("my_fav_songs.txt", ios::app);
    string song;

    cout << "Enter a new song name: ";
    getline(cin, song);

    file << song << endl;

    file.close();

    cout << "New song added successfully!" << endl;

    return 0;
}

Question::4
Build a Flipkart-style wishlist tracker: ask the user to enter 3 product names and prices, save them to a file called wishlist.txt, then read the file and display each product with its price.

Answer::
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream file("wishlist.txt");

    string product;
    double price;

    for (int i = 1; i <= 3; i++) {
        cout << "Enter product name: ";
        getline(cin, product);

        cout << "Enter product price: ";
        cin >> price;
        cin.ignore();

        file << product << " - Rs. " << price << endl;
    }

    file.close();

    ifstream readFile("wishlist.txt");
    string line;

    cout << "\nYour Wishlist:\n";

    while (getline(readFile, line)) {
        cout << line << endl;
    }

    readFile.close();

    return 0;
}

// Question::5
// Given a file called insta_followers.txt containing Instagram usernames (one per line), write a program to count and display the total number of followers listed in the file.<br><br><em><strong>Constraint:</strong> Do not use any array or vector to store the names—just count as you read.</em>

// Answer::
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("insta_followers.txt");

    string username;
    int count = 0;

    while (getline(file, username)) {
        count++;
    }

    cout << "Total Followers: " << count << endl;

    file.close();

    return 0;
}

