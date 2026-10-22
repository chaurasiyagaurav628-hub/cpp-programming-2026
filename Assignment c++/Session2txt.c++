// Question::1
// Create a class called Playlist with properties: name (string), createdOn (date), and isPublic (boolean). Instantiate an object of Playlist and print all its properties.

// Answer::
#include <iostream>
#include <string>
using namespace std;

class Playlist {
public:
    string name;
    string createdOn;
    bool isPublic;

    Playlist(string n, string date, bool p) {
        name = n;
        createdOn = date;
        isPublic = p;
    }
};

int main() {
    Playlist p1("My Songs", "22-10-2026", true);

    cout << "Name: " << p1.name << endl;
    cout << "Created On: " << p1.createdOn << endl;
    cout << "Is Public: " << boolalpha << p1.isPublic << endl;

    return 0;
}

// Question :: 2
// Add a member function to your Playlist class named togglePublic() that switches isPublic between true and false each time it is called. Demonstrate by toggling the value twice and printing the result each time.

// Answer::
#include <iostream>
#include <string>
using namespace std;

class Playlist {
public:
    string name;
    bool isPublic;

    Playlist(string n, bool p) {
        name = n;
        isPublic = p;
    }

    void togglePublic() {
        isPublic = !isPublic;
    }
};

int main() {
    Playlist p1("My Songs", true);

    cout << boolalpha << p1.isPublic << endl;

    p1.togglePublic();
    cout << p1.isPublic << endl;

    p1.togglePublic();
    cout << p1.isPublic << endl;

    return 0;
}

// Question::3
// Create a class called FoodOrder with properties: orderId (number), restaurantName (string), and isDelivered (boolean). Write a member function markDelivered() that sets isDelivered to true and prints a message. Instantiate FoodOrder and call markDelivered().

// Answer::
#include <iostream>
#include <string>
using namespace std;

class FoodOrder {
public:
    int orderId;
    string restaurantName;
    bool isDelivered;

    FoodOrder(int id, string restaurant, bool delivered) {
        orderId = id;
        restaurantName = restaurant;
        isDelivered = delivered;
    }

    void markDelivered() {
        isDelivered = true;
        cout << "Order delivered successfully!" << endl;
    }
};

int main() {
    FoodOrder order1(101, "Pizza House", false);

    order1.markDelivered();

    cout << "Order ID: " << order1.orderId << endl;
    cout << "Restaurant: " << order1.restaurantName << endl;
    cout << "Delivered: " << boolalpha << order1.isDelivered << endl;

    return 0;
}

// Question::4
// Extend your Playlist class to include a member function addSong(songTitle) that adds the song title to an array property called songs. Demonstrate by adding three song titles and displaying the updated songs list.<br><br><em><strong>Hint:</strong> Initialize songs as an empty array inside the constructor.</em>

// Answer::
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Playlist {
public:
    string name;
    vector<string> songs;

    Playlist(string n) {
        name = n;
    }

    void addSong(string songTitle) {
        songs.push_back(songTitle);
    }

    void displaySongs() {
        cout << "Playlist: " << name << endl;

        for (string song : songs) {
            cout << song << endl;
        }
    }
};

int main() {
    Playlist p1("My Favorite Songs");

    p1.addSong("Kesariya");
    p1.addSong("Apna Bana Le");
    p1.addSong("Heeriye");

    p1.displaySongs();

    return 0;
}

// Question::5
// Refactor your FoodOrder class so that the constructor takes an object as a parameter (with keys orderId, restaurantName, isDelivered) instead of separate arguments. Update your instantiation code to use this new constructor signature.

// Answer::

#include <iostream>
#include <string>
using namespace std;

struct OrderData {
    int orderId;
    string restaurantName;
    bool isDelivered;
};

class FoodOrder {
public:
    int orderId;
    string restaurantName;
    bool isDelivered;

    FoodOrder(OrderData data) {
        orderId = data.orderId;
        restaurantName = data.restaurantName;
        isDelivered = data.isDelivered;
    }

    void display() {
        cout << "Order ID: " << orderId << endl;
        cout << "Restaurant: " << restaurantName << endl;
        cout << "Delivered: " << boolalpha << isDelivered << endl;
    }
};

int main() {
    OrderData data = {101, "Pizza House", false};

    FoodOrder order1(data);

    order1.display();

    return 0;
}



