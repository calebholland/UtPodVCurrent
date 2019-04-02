#include <iostream>
//#include "Song.h"
#include "UtPod.h"
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;


    UtPod::UtPod() {
        podMemSize = MAX_MEMORY;
        songs = nullptr;
        unsigned int nowTime = (unsigned)time(0);
        srand(nowTime);
        //cout << "nowTime is " << nowTime << endl;
    }

    UtPod::UtPod(int size){
        if((size > 0) && (size < 512)){
            podMemSize = size;
        }
        else{
            podMemSize = 512;
        }
        songs = nullptr;
        unsigned int nowTime = (unsigned)time(0);
        srand(nowTime);
        //cout << "nowTime is " << nowTime << endl;
    }

    int UtPod::addSong(Song const &s) {
        if( ((UtPod::getRemainingMemory() - s.getSize()) < 0) || (s.getSize() <= 0) || (s.getArtist() == "") || (s.getTitle() == "")){
            return -1;
        }
        else{
            auto *temp = new(SongNode);
            temp->s = s;
            temp->next = songs;
            songs = temp;
        }
        return 0;
    }

    int UtPod::removeSong(Song const &s){
        SongNode* ptr = songs->next;
        SongNode* prevPtr = songs;
        if(prevPtr->s == s){
            songs = prevPtr->next;
            delete(prevPtr);
            return 0;
        }
        while(ptr != nullptr){
            if(ptr->s == s){
                prevPtr->next = ptr->next;
                delete(ptr);
                return 0;
            }
            else{
                prevPtr = ptr;
                ptr = ptr->next;
            }
        }
        return -1;
    }

    int UtPod::getRemainingMemory(){
        SongNode *ptr = songs;
        SongNode *nextPtr;
        int memAvail = podMemSize;
        while (ptr != nullptr) {
            nextPtr = ptr->next;
            memAvail -= ptr->s.getSize();
            ptr = nextPtr;
        }
        return(memAvail);
    }

    void UtPod::clearMemory() {
        SongNode *ptr = songs;
        SongNode *nextPtr;
        while (ptr != nullptr) {
            nextPtr = ptr->next;
            delete (ptr);
            //cout << "deleted a pointer" << endl;
            ptr = nextPtr;
        }
        songs = nullptr;
    }

    int UtPod::getNumberSongs() {
        SongNode *ptr = songs;
        int numberSongs = 0;
        while (ptr != nullptr) {
            numberSongs++;
            ptr = ptr->next;
        }
        return numberSongs;
    }

    void UtPod::shuffle(){

        for(int i = 0; i < (2 * getNumberSongs()); i++){
            int ptr1Times = rand() % getNumberSongs();
            SongNode* ptr1 = songs;
            int ptr2Times = rand() % getNumberSongs();
            SongNode* ptr2 = songs;
            for(int j = 0; j < ptr1Times; j++){
                ptr1 = ptr1->next;
            }
            for(int j = 0; j < ptr2Times; j++){
                ptr2 = ptr2->next;
            }
            swap(ptr1, ptr2);
        }
    }

    void UtPod::showSongList(){
        SongNode* ptr = songs;
        while(ptr != nullptr){
            cout << ptr->s.getArtist() << ", " << ptr->s.getTitle() << ", " << ptr->s.getSize()
            << "MB " << endl;
            ptr = ptr->next;
        }
    }

    void UtPod::swap(SongNode* &s1, SongNode* &s2) {
        Song tempS1;
        tempS1 = s1->s;
        s1->s = s2->s;
        s2->s = tempS1;
    }

    void UtPod::sortSongList() {

        for (SongNode *ptr1 = songs; ptr1 != nullptr; ptr1 = ptr1->next) {
            SongNode *smallest = ptr1;
            for (SongNode *ptr2 = ptr1->next; ptr2 != nullptr; ptr2 = ptr2->next) {
                if (ptr2->s < smallest->s) {
                    smallest = ptr2;
                }
            }
            if (ptr1 != smallest) {
                swap(ptr1, smallest);
            }
        }
    }



    UtPod::~UtPod(){
        UtPod::clearMemory();
    }





/* Pointer changing version of sort (abandoned, much more complicated and clunky/non functional):
SongNode* rightPtr = songs->next;
SongNode* rightPtr2 = songs->next;
SongNode* leftPtr = songs;
SongNode* lowest = songs;
SongNode* prevLowest = songs;
SongNode* prevRightPtr = songs;
SongNode* prevLeftPtr = songs;
if( (leftPtr == nullptr) || (rightPtr == nullptr)){
    return;
}
while(leftPtr != nullptr){
    lowest = leftPtr;
    while(rightPtr2 != nullptr) {
        prevRightPtr = rightPtr;
        rightPtr = rightPtr2;
        if(rightPtr != prevRightPtr) {
            if (rightPtr->s < lowest->s) {
                lowest = rightPtr;
                prevLowest = prevRightPtr;
            }
        }
        else {
            if (rightPtr->s < lowest->s) {
                lowest = rightPtr;
                //prevLowest = leftPtr;
                prevLowest = prevRightPtr;
            }
        }
        rightPtr2 = rightPtr->next;
    }
    if(lowest != leftPtr) {
        if (leftPtr != songs) {
            prevLowest->next = lowest->next;
            prevLeftPtr->next = lowest;
            lowest->next = leftPtr;
        }
        else {
            songs = lowest;
            prevLowest->next = lowest->next;
            lowest->next = leftPtr;
        }
    }
    prevLeftPtr = lowest;
    leftPtr = prevLeftPtr->next;
    rightPtr2 = leftPtr->next;
    rightPtr = leftPtr->next;
}
 */
