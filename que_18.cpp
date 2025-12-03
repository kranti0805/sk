#include <iostream>
using namespace std;

// ------------------- NODE STRUCTURE -------------------
struct Node {
    char name[50];     // song name (char array, no string library)
    Node* next;
};

// ------------------- PLAYLIST CLASS -------------------
class Playlist {
public:
    Node* head;
    Node* current;

    Playlist() {
        head = NULL;
        current = NULL;
    }

    // ---------- ADD SONG ----------
    void addSong() {
        Node* newNode = new Node;

        cout << "Enter Song Name: ";
        cin >> newNode->name;   // since no string library
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            current = newNode;
            cout << "Song added as first song.\n";
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        cout << "Song added to playlist.\n";
    }

    // ---------- DELETE SONG ----------
    void deleteSong() {
        if (head == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }

        char song[50];
        cout << "Enter Song Name to Delete: ";
        cin >> song;

        Node* temp = head;
        Node* prev = NULL;

        while (temp != NULL) {
            // compare song name manually
            int match = 1;
            for (int i = 0; song[i] != '\0' || temp->name[i] != '\0'; i++) {
                if (song[i] != temp->name[i]) {
                    match = 0;
                    break;
                }
            }

            if (match) break;

            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Song not found.\n";
            return;
        }

        if (temp == head) {
            head = head->next;
            if (current == temp)
                current = head;
        } else {
            prev->next = temp->next;
            if (current == temp)
                current = prev;
        }

        delete temp;
        cout << "Song deleted.\n";
    }

    // ---------- NEXT SONG ----------
    void nextSong() {
        if (current == NULL) {
            cout << "Playlist empty.\n";
            return;
        }
        if (current->next != NULL) {
            current = current->next;
            cout << "Now Playing: " << current->name << endl;
        } else {
            cout << "You are at the last song.\n";
        }
    }

    // ---------- PREVIOUS SONG ----------
    void previousSong() {
        if (current == head || current == NULL) {
            cout << "You are at the first song.\n";
            return;
        }

        Node* temp = head;
        while (temp->next != current)
            temp = temp->next;

        current = temp;
        cout << "Now Playing: " << current->name << endl;
    }

    // ---------- DISPLAY PLAYLIST ----------
    void display() {
        if (head == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "\n--- PLAYLIST ---\n";
        while (temp != NULL) {
            if (temp == current)
                cout << temp->name << "   <-- CURRENT SONG\n";
            else
                cout << temp->name << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

// ------------------- MAIN MENU -------------------
int main() {
    Playlist p;
    int choice;

    while (1) {
        cout << "\n--- MUSIC PLAYLIST MANAGER ---\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Next Song\n";
        cout << "4. Previous Song\n";
        cout << "5. Display Playlist\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: p.addSong(); break;
            case 2: p.deleteSong(); break;
            case 3: p.nextSong(); break;
            case 4: p.previousSong(); break;
            case 5: p.display(); break;
            case 6: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}
