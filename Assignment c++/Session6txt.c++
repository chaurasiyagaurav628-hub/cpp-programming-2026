// Question::1
// Create a class called Song in your preferred OOP language with private properties title and artist. Add public getter and setter methods to access and modify these properties, then create an object and update its title.

// Answer::
#include <iostream>
#include <string>
using namespace std;

class Song {
private:
    string title;
    string artist;

public:
    void setTitle(string t) {
        title = t;
    }

    string getTitle() {
        return title;
    }

    void setArtist(string a) {
        artist = a;
    }

    string getArtist() {
        return artist;
    }
};

int main() {
    Song s;

    s.setTitle("Kesariya");
    s.setArtist("Arijit Singh");

    cout << "Old Title: " << s.getTitle() << endl;

    s.setTitle("Apna Bana Le");

    cout << "Updated Title: " << s.getTitle() << endl;
    cout << "Artist: " << s.getArtist() << endl;

    return 0;
}

// Question::2
// Build a class called InstaStory with a protected property storyViews. Create a subclass called SponsoredStory that can access and display the storyViews value.

// Answer::
#include <iostream>
using namespace std;

class InstaStory {
protected:
    int storyViews;

public:
    InstaStory() {
        storyViews = 500;
    }
};

class SponsoredStory : public InstaStory {
public:
    void displayViews() {
        cout << "Story Views: " << storyViews << endl;
    }
};

int main() {
    SponsoredStory s;
    s.displayViews();

    return 0;
}

// Question::3
// Imagine a Flipkart-like app: create an abstract class Product with an abstract method upload(). Then, create two subclasses, Electronics and Clothing, that each implement the upload() method to print a different upload message.

// Answer::
#include <iostream>
using namespace std;

class Product {
public:
    virtual void upload() = 0;
};

class Electronics : public Product {
public:
    void upload() override {
        cout << "Electronics product uploaded" << endl;
    }
};

class Clothing : public Product {
public:
    void upload() override {
        cout << "Clothing product uploaded" << endl;
    }
};

int main() {
    Electronics e;
    Clothing c;

    e.upload();
    c.upload();

    return 0;
}

// Question::4
// Refactor the following code so that the user’s phone number in the UserProfile class is private and can only be set or retrieved using public methods.<br><br><em><strong>Hint:</strong> Add private access modifier to the phone number and create setPhoneNumber() and getPhoneNumber() methods.</em>

// Answer::
#include <iostream>
#include <string>
using namespace std;

class UserProfile {
private:
    string phoneNumber;

public:
    void setPhoneNumber(string number) {
        phoneNumber = number;
    }

    string getPhoneNumber() {
        return phoneNumber;
    }
};

int main() {
    UserProfile user;

    user.setPhoneNumber("9876543210");

    cout << "Phone Number: "
         << user.getPhoneNumber() << endl;

    return 0;
}

// Question::5
// Explain in your own words the difference between encapsulation and abstraction, using examples from any social media app you use daily (like Instagram or WhatsApp).

// Answer::
// Encapsulation:
// - Encapsulation means wrapping data and methods into a single class.
// - It protects data using access modifiers like private and public.
// - Example: In WhatsApp, a user's phone number can be kept private and accessed through getter and setter methods.



// Abstraction:
// - Abstraction means hiding internal implementation details and showing only essential features.
// - It makes a program easier to use.
// - Example: In WhatsApp, we press the Send button to send a message without knowing how the message is transmitted internally.







