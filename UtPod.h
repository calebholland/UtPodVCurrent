
//

#ifndef UTPOD_UTPOD_H
#define UTPOD_UTPOD_H

#endif //UTPOD_UTPOD_H

#ifndef UTPOD_H
#define UTPOD_H
#include "Song.h"
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

//UtPod class declaration
class UtPod
{
private:
    static const int MAX_MEMORY = 512;
    static const int SUCCESS = 0;
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;

    struct SongNode
    {
        Song s;
        SongNode *next;
    };

    SongNode *songs;  //the head pointer

    int podMemSize;  //the total amount of memory available on the UtPod

    //Swap is a private function used to swap the contents (but not the addresses) of two song nodes.
    //Since the == operator for Song is overwritten, it is a very simple function that just includes one extra temp pointer.
    //Input parameters: two song nodes that need to be swapped (order doesn't matter)
    //Output parameters: void (songs swapped in pass by reference)
    void swap(SongNode* &s1, SongNode* &s2);

    //getNumberSongs is a private function used in shuffle, etc to know how many songs are in the UtPod. It just traverses the LL and counts the songs.
    //Input parameters: None
    //Output parameters: int: number of songs in UtPod
    int getNumberSongs();

public:
    //Default constructor
    //set the memory size to MAX_MEMORY
    UtPod();

    //Constructor with size parameter
    //The user of the class will pass in a size.
    //If the size is greater than MAX_MEMORY or less than or equal to 0,
    //set the size to MAX_MEMORY.
    UtPod(int size);

    /* FUNCTION - int addSong
     * attempts to add a new song to the UtPod
         o returns a 0 if successful
         o returns -1 if not enough memory to add the song

     precondition: s is a valid Song

     input parms - song s

     output parms - 0 if successful, -1 if not
    */

    int addSong(Song const &s);


    /* FUNCTION - int removeSong
     * attempts to remove a song from the UtPod
     * removes the first instance of a song that is in the the UtPod multiple times
         o returns 0 if successful
         o returns -1 if nothing is removed


       input parms - song s

       output parms - 0 if song removed, -1 if not
    */

    int removeSong(Song const &s);


    /* FUNCTION - void shuffle
     *  shuffles the songs into random order
        o will do nothing if there are less than two songs in the current list

       input parms - None

       output parms - None, shuffled in place
    */

    void shuffle();


    /* FUNCTION - void showSongList
     * prints the current list of songs in order from first to last to standard output
     * format - Title, Artist, size in MB (one song per line)

       input parms - None

       output parms - None, prints out the list of songs
    */

    void showSongList();


    /* FUNCTION - void sortSongList
     *  sorts the songs in ascending order
        o will do nothing if there are less than two songs in the current list

       input parms - None

       output parms - None, sorted in place
    */

    void sortSongList();


    /* FUNCTION - void clearMemory
     * clears all the songs from memory

       input parms - None

       output parms - None, deletes all song nodes and resets songs pointer to null
    */
    void clearMemory();


    /* FUNCTION - int getTotalMemory
     *  returns the total amount of memory in the UtPod
        o will do nothing if there are less than two songs in the current list

       input parms - None

       output parms - total memory as an int, stored in a simple int variable as podMemSize
    */

    int getTotalMemory() {
        return podMemSize;
    }



    /* FUNCTION - int getRemainingMemory
     *  returns the amount of memory available for adding new songs

       input parms - None

       output parms - An int with the available, free memory left in the UtPod
    */

    int getRemainingMemory();


    //UtPod destructor:
    //Deletes all of the song nodes pointed to, which frees all of the allocated memory to avoid memory leaks
    ~UtPod();

};



#endif
