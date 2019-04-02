//
// Created by caleb on 3/26/19.
//

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H

#endif //UTPOD_SONG_H

#include <string>
#include <iostream>


using namespace std;


class Song {
private:
    string title;
    string artist;
    int size;


    static const int MAX_SIZE = 512;
public:
    //Constructors
    Song();
    Song(string title);
    Song(string artist, string title, int size);

    //Sets and gets
    string getTitle() const{
        return title;
    }
    void setTitle(string _title){
        title = _title;
    }
    string getArtist() const;
    void setArtist(string _artist);
    int getSize() const;
    void setSize(int _size);


    //Operator overloading
    bool operator >(Song const &rhs);
    bool operator <(Song const &rhs);
    bool operator ==(Song const &rhs);

    //Default constructor used (no allocated memory associated with the song class)
    ~Song();
};



