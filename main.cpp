#include <iostream>
#include <cstdio>
#include "singlylinkedlist.h"
#include "song.h"

int main() {
    
    // Declaring a new singly linked list that holds pointers to objects from the Song class
    SinglyLinkedList<Song*> song_list;
    
    char choice;
    
    std::cout << "Welcome to Playlist Maker! What would you like to do?" << std::endl;

    // Using a for loop to reprint the menu of options to the user when necessary
    for (;;) {
       
        std::cout << "1. Add a song to the playlist" << std::endl;
        std::cout << "2. Print the playlist" << std::endl;
        std::cout << "3. Search for a song in the playlist" << std::endl;
        std::cout << "4. Remove a song from the playlist" << std::endl;
        std::cout << "5. Quit" << std::endl;
        
        std::cout << "Enter choice: ";
        std::cin >> choice;
        while (getchar() != '\n'); // skips to the end of the line 
        std::cout << std::endl;
    
        if (choice == '1') { 
            
            // Declaring strings to hold the information for the song to be added to the list
            std::string title;
            std::string artist;
            std::string genre;
            std::string year;

            std::cout << "Enter the title of the song: ";
            std::getline(std::cin, title);
            std::cout << "Enter the artist of the song: ";
            std::getline(std::cin, artist);
            std::cout << "Enter the genre of the song: ";
            std::getline(std::cin, genre);
            std::cout << "Enter the year the song was released: ";
            std::getline(std::cin, year);

            // Creating a new Song object with the information the user entered
            Song* song = new Song(title, artist, genre, year);

            // Adding the song to the front of the linked list
            song_list.addFront(song);

            std::cout << std::endl << "Song added." << std::endl << std::endl;

            continue; // return to menu
        }

        else if (choice == '2') {
            
            int i;

            // If the size of the linked list is 1, prints the information of the only song in the list to the user
            if (song_list.getSizeList() == 1) {
                // Printing the song information if only one song in the list:
                // First accessing the element of the first node using song_list.getNthElem() from the SinglyLinkedList class
                // and passing in a position 0 to access the element at that position
                // The element we are accessing is a song object, so we then access the song object's title, artist, genre, 
                // and year released by using getTitle(), getArtist(), getGenre(), and getYearReleased() from the Song class
                std::cout << "Title: " << (song_list.getNthElem(song_list.getHead(), 0))->getTitle() << std::endl;
                std::cout << "Artist: " << (song_list.getNthElem(song_list.getHead(), 0))->getArtist() << std::endl;
                std::cout << "Genre: " << (song_list.getNthElem(song_list.getHead(), 0))->getGenre() << std::endl;
                std::cout << "Year Released: " << (song_list.getNthElem(song_list.getHead(), 0))->getYearReleased() << std::endl << std::endl;
            }
            // If multiple songs in the list, iterates through the list and prints all the songs to the user
            else {
                for (i = 0; i < song_list.getSizeList(); i++) {
                    
                    // If there is no song in a node for some reason, prints an error to the user and exits the program
                    if (song_list.getNthElem(song_list.getHead(), i) == NULL) {
                        std::cout << "Error: Node does not contain a song" << std::endl;
                        return 0;
                    }

                    // Printing the information of each song in the list to the user:
                    // First accessing the element of each node using song_list.getNthElem() from the SinglyLinkedList class 
                    // and passing in the position of each node by using the iterator i from the for loop
                    // The element we are accessing is a song object, so we then access the song object's title, artist, genre, 
                    // and year released by using getTitle(), getArtist(), getGenre(), and getYearReleased() from the Song class
                    std::cout << "Title: " << (song_list.getNthElem(song_list.getHead(), i))->getTitle() << std::endl;
                    std::cout << "Artist: " << (song_list.getNthElem(song_list.getHead(), i))->getArtist() << std::endl;
                    std::cout << "Genre: " << (song_list.getNthElem(song_list.getHead(), i))->getGenre() << std::endl;
                    std::cout << "Year Released: " << (song_list.getNthElem(song_list.getHead(), i))->getYearReleased() << std::endl << std::endl;

                } 
            }

            continue;
        }

        else if (choice == '3') {

            std::string search_title;
            int i, found = 0;

            // Asks the user for the title of the song to search for
            std::cout << "Enter the title of the song: ";
            std::getline(std::cin, search_title);
            std::cout << std::endl;

            // Searching through the linked list 
            for (i = 0; i < song_list.getSizeList(); i++) {

                // If the title of a song matches the title that the user gave, prints the song to the user
                if (song_list.getNthElem(song_list.getHead(), i)->getTitle() == search_title) {
                    // Printing the searched song to the user if it matches the given title:
                    // First accessing the element of the node using song_list.getNthElem() from the SinglyLinkedList class 
                    // and passing in the position found using the for loop 
                    // The element we are accessing is a song object, so we then access the song object's title, artist, genre, 
                    // and year released by using getTitle(), getArtist(), getGenre(), and getYearReleased() from the Song class
                    std::cout << "Title: " << (song_list.getNthElem(song_list.getHead(), i))->getTitle() << std::endl;
                    std::cout << "Artist: " << (song_list.getNthElem(song_list.getHead(), i))->getArtist() << std::endl;
                    std::cout << "Genre: " << (song_list.getNthElem(song_list.getHead(), i))->getGenre() << std::endl;
                    std::cout << "Year Released: " << (song_list.getNthElem(song_list.getHead(), i))->getYearReleased() << std::endl << std::endl;
                    found++;
                }

            }
            
            // If no songs matching the given title were found, prints a message to the user
            if (found == 0) {
                std::cout << "Song not found." << std::endl << std::endl;
            }

            continue;
        }

        else if (choice == '4') {
            
            std::string del_title, del_artist;
            int i, found = 0;

            // Asking the user for the title and artist of the song they want to remove from the list
            // Two songs could have the same title but different artists, so asking for both
            std::cout << "Enter the title of the song you want to delete: ";
            std::getline(std::cin, del_title);
            std::cout << "Enter the artist of the song you want to delete: ";
            std::getline(std::cin, del_artist);
            std::cout << std::endl;

            // Searching the list for the song matching the title and artist entered by the user
            for (i = 0; i < song_list.getSizeList(); i++) {

                // If a matching song is found, prints the information of the song deleted to the user and removes it from the list
                if (song_list.getNthElem(song_list.getHead(), i)->getTitle() == del_title && song_list.getNthElem(song_list.getHead(), i)->getArtist() == del_artist) {
                    
                    found++;

                    // Printing the deleted song to the user:
                    // First accessing the element of the node using song_list.getNthElem() from the SinglyLinkedList class 
                    // and passing in the position found using the for loop 
                    // The element we are accessing is a song object, so we then access the song object's title, artist, genre, 
                    // and year released by using getTitle(), getArtist(), getGenre(), and getYearReleased() from the Song class
                    std::cout << "Deleted:" << std::endl;
                    std::cout << "Title: " << (song_list.getNthElem(song_list.getHead(), i))->getTitle() << std::endl;
                    std::cout << "Artist: " << (song_list.getNthElem(song_list.getHead(), i))->getArtist() << std::endl;
                    std::cout << "Genre: " << (song_list.getNthElem(song_list.getHead(), i))->getGenre() << std::endl;
                    std::cout << "Year Released: " << (song_list.getNthElem(song_list.getHead(), i))->getYearReleased() << std::endl << std::endl;
                
                    song_list.deleteNthNode(song_list.getHead(), i);

                    // Deletes only one song, even if multiple songs in the list match the title and artist given
                    break;
                }

            }

            // If no song matching the title and artist given by the user was found, prints a message to the user
            if (found == 0) {
                std::cout << "Song not found." << std::endl << std::endl;
                continue;
            }

            continue;

        }

        else if (choice == '5') {

            // If user quits the program, prints a message and exits the program
            std::cout << "Bye!" << std::endl << std::endl;
            return 0;

        }

        else { 

            // If the user did not enter a valid choice of 1, 2, 3, 4, or 5, prints a message and goes back to the menu again
            std::cout << "Invalid choice entered. Please try again." << std::endl;
            continue;

        }

        std::cout << std::endl; // new line
    }
}
