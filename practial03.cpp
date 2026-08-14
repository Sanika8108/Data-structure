#include <iostream>
#include <cstring>
using namespace std;

struct Song
{
    char title[50];
    char artist[50];
    Song *prev;
    Song *next;
};

Song *head = NULL;
Song *current = NULL;

void addSong()
{
    Song *newSong = new Song;

    cout << "\nEnter song title: ";
    cin.ignore();
    cin.getline(newSong->title, 50);

    cout << "Enter artist name: ";
    cin.getline(newSong->artist, 50);

    newSong->prev = NULL;
    newSong->next = NULL;

    if (head == NULL)
    {
        head = newSong;
        current = newSong;
    }
    else
    {
        Song *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newSong;
        newSong->prev = temp;
    }

    cout << "Song added successfully!\n";
}

void currentSong()
{
    if (current == NULL)
    {
        cout << "\nPlaylist is empty!\n";
        return;
    }

    cout << "\nCurrent Song\n";
    cout << "Title  : " << current->title << endl;
    cout << "Artist : " << current->artist << endl;
}

void nextSong()
{
    if (current == NULL)
    {
        cout << "\nPlaylist is empty!\n";
    }
    else if (current->next == NULL)
    {
        cout << "\nYou are at the last song.\n";
    }
    else
    {
        current = current->next;
        currentSong();
    }
}

void previousSong()
{
    if (current == NULL)
    {
        cout << "\nPlaylist is empty!\n";
    }
    else if (current->prev == NULL)
    {
        cout << "\nYou are at the first song.\n";
    }
    else
    {
        current = current->prev;
        currentSong();
    }
}

void displayPlaylist()
{
    Song *temp = head;

    if (head == NULL)
    {
        cout << "\nPlaylist is empty!\n";
        return;
    }

    cout << "\n----- Music Playlist -----\n";

    while (temp != NULL)
    {
        cout << "Title: " << temp->title
             << " | Artist: " << temp->artist << endl;

        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== MUSIC PLAYLIST =====\n";
        cout << "1. Add Song\n";
        cout << "2. Next Song\n";
        cout << "3. Previous Song\n";
        cout << "4. Current Song\n";
        cout << "5. Display Playlist\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addSong();
                break;

            case 2:
                nextSong();
                break;

            case 3:
                previousSong();
                break;

            case 4:
                currentSong();
                break;

            case 5:
                displayPlaylist();
                break;

            case 6:
                cout << "\nProgram ended.\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}