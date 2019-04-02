//
// Created by caleb on 3/26/19.
//

#include "Song.h"

using namespace std;

    Song::Song(){
        title = "";
        artist = "";
        size = 0; //Should this change to 0?
    }

    Song::Song(string _title){
        title = _title;
        artist = "";
        size = 0; //Should this change to 0?
    }

    Song::Song(string _artist, string _title, int _size){
        title = _title;
        artist = _artist;
        size = _size;
    }

    string Song::getArtist() const {
        return artist;
    }

    void Song::setArtist(string _artist) {
        artist = _artist;
    }

    int Song::getSize() const {
        return size;
    }

    void Song::setSize(int _size) {
        this->size = _size;
    }

    bool Song::operator <(Song const &rhs){
        if(artist < rhs.artist) {
            return true;
        }
        if(artist == rhs.artist){
            if(title < rhs.title) {
                return true;
            }
            if(title == rhs.title){
                if(size <= rhs.size){
                    return true;
                }
            }
        }
        return false;
    }

    bool Song::operator >(Song const &rhs){
        if(artist > rhs.artist) {
            return true;
        }
        if(artist == rhs.artist){
            if(title > rhs.title) {
                return true;
            }
            if(title == rhs.title){
                if(size >= rhs.size){
                    return true;
                }
            }
        }
        return false;
    }

    bool Song::operator ==(Song const &rhs){
        return(
                title == rhs.title &&
                artist == rhs.artist &&
                size == rhs.size);
    }

    Song::~Song() = default;







