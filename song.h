#ifndef SONG_H
#define SONG_H

#include <string>

// class Song: holds data for a song
// Four private member variables: the title, artist, genre, and year released of the song
// Public member functions: a constructor, destructor, and setters and getters for the private members
class Song {
private:
    std::string title;
    std::string artist;
    std::string genre;
    std::string year_released;
public:
    Song(std::string song_title, std::string song_artist, std::string song_genre, std::string song_year);
    ~Song();
    void setTitle(std::string song_title);
    void setArtist(std::string song_artist);
    void setGenre(std::string song_genre);
    void setYearReleased(std::string song_year);
    std::string getTitle() const;
    std::string getArtist() const;
    std::string getGenre() const;
    std::string getYearReleased() const;
};

// Constructor to initialize a song object
Song::Song(std::string song_title, std::string song_artist, std::string song_genre, std::string song_year) {
    title = song_title;
    artist = song_artist;
    genre = song_genre;
    year_released = song_year;
}

// Destructor to destroy objects
Song::~Song() {
    delete this;
}

// Setter function for the title of the song 
void Song::setTitle(std::string song_title) {
    title = song_title;
}

// Setter function for the artist of the song 
void Song::setArtist(std::string song_artist) {
    artist = song_artist;
}

// Setter function for the genre of the song
void Song::setGenre(std::string song_genre) {
    genre = song_genre;
}

// Setter function for the year the song was released
void Song::setYearReleased(std::string song_year) {
    year_released = song_year;
}

// Getter function for the title of the song
std::string Song::getTitle() const {
    return title;
}

// Getter function for the artist of the song
std::string Song::getArtist() const {
    return artist;
}

// Getter function for the genre of the song
std::string Song::getGenre() const {
    return genre;
}

// Getter function for the year the song was released
std::string Song::getYearReleased() const {
    return year_released;
}

#endif
