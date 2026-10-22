// Question::1
// Create a base class called SocialMediaUser with properties username and followers, and a method displayProfile() that prints the username and follower count.

// Answer::
#include <iostream>
#include <string>
using namespace std;

class SocialMediaUser {
public:
    string username;
    int followers;

    SocialMediaUser(string u, int f) {
        username = u;
        followers = f;
    }

    void displayProfile() {
        cout << "Username: " << username << endl;
        cout << "Followers: " << followers << endl;
    }
};

int main() {
    SocialMediaUser user1("Gaurav", 1000);

    user1.displayProfile();

    return 0;
}

// Question::2
// Build a YouTuber class that inherits from SocialMediaUser and adds a property channelName and a method uploadVideo(title) that prints 'Video [title] uploaded to [channelName]'.

// Answer::
#include <iostream>
#include <string>
using namespace std;

class SocialMediaUser {
public:
    string username;
    int followers;

    SocialMediaUser(string u, int f) {
        username = u;
        followers = f;
    }

    void displayProfile() {
        cout << "Username: " << username << endl;
        cout << "Followers: " << followers << endl;
    }
};

class YouTuber : public SocialMediaUser {
public:
    string channelName;

    YouTuber(string u, int f, string c)
        : SocialMediaUser(u, f) {
        channelName = c;
    }

    void uploadVideo(string title) {
        cout << "Video " << title
             << " uploaded to " << channelName << endl;
    }
};

int main() {
    YouTuber y1("Gaurav", 1000, "Gaurav Gaming");

    y1.displayProfile();
    y1.uploadVideo("My First Video");

    return 0;
}

// Question::3
// Create a Podcaster class that also inherits from SocialMediaUser and adds a property podcastName and a method publishEpisode(episodeTitle) that prints 'Episode [episodeTitle] published on [podcastName]'.

// Answer::
#include <iostream>
#include <string>
using namespace std;

class SocialMediaUser {
public:
    string username;
    int followers;

    SocialMediaUser(string u, int f) {
        username = u;
        followers = f;
    }

    void displayProfile() {
        cout << "Username: " << username << endl;
        cout << "Followers: " << followers << endl;
    }
};

class Podcaster : public SocialMediaUser {
public:
    string podcastName;

    Podcaster(string u, int f, string p)
        : SocialMediaUser(u, f) {
        podcastName = p;
    }

    void publishEpisode(string episodeTitle) {
        cout << "Episode " << episodeTitle
             << " published on " << podcastName << endl;
    }
};

int main() {
    Podcaster p1("Gaurav", 500, "Tech Talks");

    p1.displayProfile();
    p1.publishEpisode("Episode One");

    return 0;
}

// Question::4
// Demonstrate multilevel inheritance by creating a class GamingYouTuber that inherits from YouTuber and adds a method streamGame(gameName) which prints '[username] is now streaming [gameName] on [channelName]'.

// Answer::
#include <iostream>
#include <string>
using namespace std;

class SocialMediaUser {
public:
    string username;
    int followers;

    SocialMediaUser(string u, int f) {
        username = u;
        followers = f;
    }

    void displayProfile() {
        cout << "Username: " << username << endl;
        cout << "Followers: " << followers << endl;
    }
};

class YouTuber : public SocialMediaUser {
public:
    string channelName;

    YouTuber(string u, int f, string c)
        : SocialMediaUser(u, f) {
        channelName = c;
    }

    void uploadVideo(string title) {
        cout << "Video " << title
             << " uploaded to " << channelName << endl;
    }
};

class GamingYouTuber : public YouTuber {
public:
    GamingYouTuber(string u, int f, string c)
        : YouTuber(u, f, c) {}

    void streamGame(string gameName) {
        cout << username << " is now streaming "
             << gameName << " on " << channelName << endl;
    }
};

int main() {
    GamingYouTuber g1("Gaurav", 2000, "Gaurav Gaming");

    g1.displayProfile();
    g1.uploadVideo("GTA Gameplay");
    g1.streamGame("GTA V");

    return 0;
}

// Question::5
// Implement hierarchical inheritance by creating an InstagramInfluencer class that inherits from SocialMediaUser and adds a method postStory(storyTitle) which prints '[username] posted a new story: [storyTitle]'.<br><br><em><strong>Hint:</strong> Think about how SocialMediaUser is the parent for YouTuber, Podcaster, and InstagramInfluencer.</em>

// Answer::
#include <iostream>
#include <string>
using namespace std;

class SocialMediaUser {
public:
    string username;
    int followers;

    SocialMediaUser(string u, int f) {
        username = u;
        followers = f;
    }

    void displayProfile() {
        cout << "Username: " << username << endl;
        cout << "Followers: " << followers << endl;
    }
};

class InstagramInfluencer : public SocialMediaUser {
public:
    InstagramInfluencer(string u, int f)
        : SocialMediaUser(u, f) {}

    void postStory(string storyTitle) {
        cout << username << " posted a new story: "
             << storyTitle << endl;
    }
};

int main() {
    InstagramInfluencer i1("Gaurav", 3000);

    i1.displayProfile();
    i1.postStory("My Daily Life");

    return 0;
}
