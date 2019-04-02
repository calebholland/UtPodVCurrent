//
// Created by caleb on 3/26/19.
//

#include <iostream>
#include <string>
#include "UtPod.h"
//#include "Song.h"

using namespace std;

int main() {


    cout << "UtPod constructor tests:--------------------------------- " <<endl <<endl;
    cout << "1. No parameters: " <<endl;

    UtPod def;

    cout << "remaining memory: " << def.getRemainingMemory() <<endl;
    cout << "Total memory: " << def.getTotalMemory() <<endl<<endl;

    cout << "2. Passing in size: 128MB: " <<endl;

    UtPod small(128);

    cout << "remaining memory: " << small.getRemainingMemory() <<endl;
    cout << "Total memory: " <<small.getTotalMemory() <<endl <<endl;

    cout << "3. Passing in invalid size: 2000: " <<endl;

    UtPod xl(2000);

    cout << "remaining memory: " << xl.getRemainingMemory() <<endl;
    cout << "Total memory: " <<xl.getTotalMemory() <<endl <<endl;

    cout << "4. Passing in invalid size: -35: " <<endl;

    UtPod xs(-35);

    cout << "remaining memory: " << xs.getRemainingMemory() <<endl;
    cout << "Total memory: " <<xs.getTotalMemory() <<endl <<endl;


    cout << "Adding a list of normal (valid, not exceptionally large or designed to throw errors) songs:" <<endl;

    Song s1("Air", "Kelly Watch the Stars", 12);
    int result = def.addSong(s1);
    cout << "Printing the result of adding the first song: " <<result <<endl <<endl;

    Song s2("Bread", "Guitar Man", 7);
    def.addSong(s2);

    Song s3("Oingo Boingo", "Dead Man's Party", 6);
    def.addSong(s3);

    Song s4("Har Mar Superstar", "Prisoner", 21);
    def.addSong(s4);

    Song s5("Wings", "London Town", 3);
    def.addSong(s5);

    Song s6("King Crimson", "Red", 46);
    def.addSong(s6);

    Song s7("King Crimson", "Three of a Perfect Pair", 18);
    def.addSong(s7);

    Song s8("King Gizzard and the Lizard Wizard", "People Vultures", 13);
    def.addSong(s8);

    Song s9("King Crimson", "Red", 10);
    def.addSong(s9);


    cout << "All song list: ------------------------------------" << endl;
    def.showSongList();


    cout << "remaining memory: " << def.getRemainingMemory() << endl;
    cout << "total memory: " << def.getTotalMemory() << endl <<endl;

    cout << "sorted list: --------------------------------------" << endl;
    def.sortSongList();
    def.showSongList();
    cout << endl;

    cout << "shuffled list: ---------------------------------------" << endl;
    def.shuffle();
    def.showSongList();
    cout << endl;

    cout << "shuffled again list (to demonstrate randomness): ---------------------------------------" << endl;
    def.shuffle();
    def.showSongList();
    cout << endl<<endl;

    cout << "Testing to ensure shuffle does nothing to list with less than 2 songs, using small UtPod: " <<endl;
    small.addSong(s3);
    cout << "Unshuffled song list: " <<endl;
    small.showSongList();
    small.shuffle();
    cout<< "Shuffled song list: " <<endl;
    small.showSongList();
    cout <<endl;

    //Test all Song set and gets:

    cout << "Song gets and sets testing: ------------------------------" << endl;
    cout << "default declaration: ";
    Song s10;
    cout << "artist: " << s10.getArtist() << "title: " << s10.getTitle() << "size: " << s10.getSize() <<endl <<endl;
    cout << "can we add this song? " <<def.addSong(s10) << endl;
    cout << "using sets: " <<endl;
    s10.setArtist("Bay City Rollers");
    s10.setTitle("Don't Worry Baby");
    s10.setSize(4);


    cout << "Song get functions used to print song list as well as directly to show the following: " <<endl;
    cout << "artist: " << s10.getArtist() << " title: " << s10.getTitle() << " size: " << s10.getSize() <<endl <<endl;
    cout << "Can we add this song now? " <<endl << def.addSong(s10) <<endl;
    cout << "If song is invalid (artist or title are blank or size 0 or negative), can we add? Setting title to blank" << endl;
    s10.setTitle("");
    cout << "result of addSong: " << def.addSong(s10) <<endl<<endl;
    cout << "Reset title to Don't Worry Baby, setting size to 0: " <<endl;
    s10.setTitle("Don't Worry Baby");
    s10.setSize(0);
    cout << "result of addSong: " << def.addSong(s10) <<endl<<endl;
    cout << "settings size to -3: " <<endl;
    s10.setSize(-3);
    cout << "result of addSong: " << def.addSong(s10) <<endl<<endl;


    cout << "Song class Operator overloading was tested by removing the song (== operator used), and Sort List ( <  used)" <<endl;
    cout << "Test of Song > operator overloading: which is greater, "
            "    Song s2(\"Bread\", \"Guitar Man\", 7);\n or "
            "    Song s3(\"Oingo Boingo\", \"Dead Man's Party\", 6); ? " <<endl;
    if(s2 > s3){
        cout << s2.getArtist() << " " << s2.getTitle() << " " << s2.getSize() << endl<<endl;
    }
    else if(s3 > s2){
        cout << s3.getArtist() << " " << s3.getTitle() << " " << s3.getSize() << endl<<endl;
    }



    cout << "Test removing song: --------------------------------------------" <<endl;
    cout << "Before removing: remaining size: " << def.getRemainingMemory()<<endl;
    def.showSongList();
    cout <<endl;
    cout << "remove Wings' London Town: " <<endl;
    def.removeSong(s5);
    cout << "New remaining size: " << def.getRemainingMemory() << endl;
    cout << "New song list: " <<endl;
    def.showSongList();
    cout << endl;
    cout << "Can we add London Town back if its size is 500 MB, exceeding the Ipod's size?" <<endl;
    cout << "Remaining memory: " << def.getRemainingMemory() << endl;
    s5.setSize(500);
    cout << "Lond town size is: " << s5.getSize() << endl;
    cout << "result of attempted add is: " <<def.addSong(s5) <<endl<<endl;
    cout << "Since London Town is no longer in the UtPod, can we remove it? " <<endl;
    cout << def.removeSong(s5) <<endl<<endl;

    cout << "If a song is in the UtPod twice, will the sort function still work? "
            "Adding another copy of Guitar Man, then shuffling: " <<endl;
    def.addSong(s2);
    def.shuffle();
    def.showSongList();
    cout <<endl;
    cout << "Sorted: " << endl;
    def.sortSongList();
    def.showSongList();
    cout <<endl<<endl;

    cout << "If we remove a song that appears twice, will it only remove the first instance? " <<endl;
    cout << "Shuffled list: " <<endl;
    def.shuffle();
    def.shuffle();
    def.showSongList();
    cout << endl;
    def.removeSong(s2);
    cout << "With first instance of Guitar Man removed: " <<endl;
    def.showSongList();
    cout <<endl;


    cout << "Clearing memory test: ----------------------------------------" <<endl;
    cout << "Current song list: " <<endl;
    def.showSongList();
    cout << "Current available memory: " <<def.getRemainingMemory() <<endl<<endl;
    def.clearMemory();
    cout << "Cleared song list: " <<endl;
    def.showSongList();
    cout <<endl;
    cout << "Current available memory (after clearing): " <<def.getTotalMemory() << endl<<endl;

    cout << "Can we now add songs back to the utPod without issue? Re-adding s1 through s9" <<endl<<endl;
    def.addSong(s1);
    def.addSong(s2);
    def.addSong(s3);
    def.addSong(s4);
    def.addSong(s5);
    def.addSong(s6);
    def.addSong(s7);
    def.addSong(s8);
    def.addSong(s9);
    cout << "New song list: " <<endl;
    def.showSongList();
    cout <<endl;
    cout << "Note that Wings' London Town was skipped because its size (set to 500) was too large for the UtPod "
            "by the time it was added, but the rest after it were added correctly." <<endl<<endl;

    cout << "Can we clear an empty UtPod without issue? " <<endl;
    cout << "small UtPod song list: " <<endl;
    small.showSongList();
    cout << "small UtPod song list after clearing: " <<endl;
    small.clearMemory();
    small.showSongList();
    cout << endl;
    cout << "Clearing small UtPod (now empty) again. New small song list: " <<endl;
    small.clearMemory();
    small.showSongList();
    cout <<endl<<endl;

    cout << "The destructor for UtPod calls the clear memory function, which deletes all of the song nodes. "
            "This prevents memory leaks." <<endl<<endl;

    return 0;
}