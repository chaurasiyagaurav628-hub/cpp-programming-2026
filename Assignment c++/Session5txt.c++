// Question::1
// Create a Java class called PaymentProcessor with two overloaded methods processPayment(): one that takes only an amount, and one that takes amount and a coupon code. Print which version is called and the final amount in each case.

// Answer::
#include <iostream>
using namespace std;

class PaymentProcessor {
public:
    void processPayment(double amount) {
        cout << "Payment without coupon" << endl;
        cout << "Final Amount: " << amount << endl;
    }

    void processPayment(double amount, string couponCode) {
        double finalAmount = amount - 100;

        cout << "Payment with coupon: " << couponCode << endl;
        cout << "Final Amount: " << finalAmount << endl;
    }
};

int main() {
    PaymentProcessor p;

    p.processPayment(1000);
    p.processPayment(1000, "SAVE100");

    return 0;
}

// Question::2
// Build two classes, InstagramUploader and YouTubeUploader, each with a method uploadContent(). Both should extend a base class SocialMediaUploader and override uploadContent() to print a message showing how uploading works differently for Instagram and YouTube.

// Answer::
#include <iostream>
using namespace std;

class SocialMediaUploader {
public:
    virtual void uploadContent() {
        cout << "Uploading social media content" << endl;
    }
};

class InstagramUploader : public SocialMediaUploader {
public:
    void uploadContent() override {
        cout << "Uploading photos and reels on Instagram" << endl;
    }
};

class YouTubeUploader : public SocialMediaUploader {
public:
    void uploadContent() override {
        cout << "Uploading videos on YouTube" << endl;
    }
};

int main() {
    InstagramUploader instagram;
    YouTubeUploader youtube;

    instagram.uploadContent();
    youtube.uploadContent();

    return 0;
}

// Question::3
// Write a function in Java or Python that simulates a Flipkart-style search: overload a method searchProduct() to allow searching by product name or by product name and category. Demonstrate both usages with sample data.

// Answer::

#include <iostream>
#include <string>
using namespace std;

class ProductSearch {
public:
    string products[4] = {
        "iPhone", "Samsung", "Laptop", "Headphones"
    };

    void searchProduct(string name) {
        cout << "Searching by product name: " << name << endl;

        for (int i = 0; i < 4; i++) {
            if (products[i] == name) {
                cout << "Product found: " << products[i] << endl;
                return;
            }
        }

        cout << "Product not found" << endl;
    }

    void searchProduct(string name, string category) {
        cout << "Searching by name and category" << endl;
        cout << "Product: " << name << endl;
        cout << "Category: " << category << endl;
    }
};

int main() {
    ProductSearch search;

    search.searchProduct("iPhone");
    search.searchProduct("Samsung", "Mobile");

    return 0;
}

// Question::4
// Given this code: class MusicPlayer { void play(String song) { System.out.println("Playing: " + song); } } class SpotifyPlayer extends MusicPlayer { void play(String song) { System.out.println("Streaming on Spotify: " + song); } } — Create an object of type MusicPlayer but assign it a SpotifyPlayer instance, then call play(). Explain the output.<br><br><em><strong>Hint:</strong> This tests runtime polymorphism (overriding) and dynamic method dispatch.</em>

// Answer::
#include <iostream>
#include <string>
using namespace std;

class MusicPlayer {
public:
    virtual void play(string song) {
        cout << "Playing: " << song << endl;
    }
};

class SpotifyPlayer : public MusicPlayer {
public:
    void play(string song) override {
        cout << "Streaming on Spotify: " << song << endl;
    }
};

int main() {
    MusicPlayer* player = new SpotifyPlayer();

    player->play("Kesariya");

    delete player;
    return 0;
}
