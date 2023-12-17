#include <bits/stdc++.h>
using namespace std;

int musicNo=1;
int favNo=1;
int music_count=0;
int fav_count=0;

struct node{
    string music_name;
    string music_artist;
    string music_length;
    int music_number;

    struct node *next;
    struct node *prev;
}; 
struct node *head = NULL, *tail = NULL;

struct favlist{
    string music_name;
    string music_artist;
    string music_length;
    int music_number;

    struct favlist *fnext;
    struct favlist *fprev;
}; 
struct favlist *fhead = NULL, *ftail = NULL;


void addMusic(){
    struct node *newnode = new node();

    cout << "Enter the name of the music : ";
    getline(cin, newnode->music_name);

    cout << "Enter the artist name of the music : ";
    getline(cin, newnode->music_artist);

    cout << "Enter the length of the music: ";
    getline(cin, newnode->music_length);

    newnode->music_number = musicNo++;
    newnode->next = NULL;
    newnode->prev = NULL;

    if(head==NULL){
        head = newnode;
        tail = newnode;
    }
    else{
        tail->next = newnode;
        tail = tail->next;
        tail->prev = newnode;
    }
    music_count++;
    cout << "Music Added to the Playlist!" << endl;
}

struct favlist *findfavMusic(string name){
    struct favlist *temp = fhead;
    while (temp!=NULL)
    {
        if(temp->music_name==name){
            return temp;
        }
        temp = temp->fnext;
    }
    return NULL;
}

void removeFavMusic(string name){
    struct favlist *temp = findfavMusic(name);
    if(temp==NULL){
        cout << "\nFavourite Playlist is empty!" << endl;
        return;
    }

    if(temp==fhead){
        fhead = fhead->fnext;
        if(fhead!=NULL) fhead->fprev = NULL;
        else ftail = NULL;
        delete temp;
        cout << "\nFavourite Music has been successfully removed!" << endl;
        fav_count--;
        return;
    }

    else if(temp==ftail){
        ftail = ftail->fprev;
        ftail->fnext = NULL;
        delete temp;
        cout << "\nFavourite Music has been successfully removed!" << endl;
        fav_count--;
        return;
    }

    temp->fprev->fnext = temp->fnext;
    temp->fnext->fprev = temp->fprev;
    delete temp;
    cout << "\nFavourite Music has been successfully removed!" << endl;
    fav_count--;

}

struct node *findMusic(string name){
    struct node *temp = head;
    while (temp!=NULL)
    {
        if(temp->music_name==name){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void removeMusic(string name){
    removeFavMusic(name);
    struct node *temp = findMusic(name);

    if(temp==NULL){
        cout << "\nMusic playlist is empty!" << endl;
        return;
    }

    if(temp==head){
        head = head->next;
        if(head!=NULL) head->prev = NULL;
        else tail = NULL;
        delete temp;
        cout << "\nMusic has been successfully removed!" << endl;
        music_count--;
        return;
    }

    else if(temp==tail){
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
        cout << "\nMusic has been successfully removed!" << endl;
        music_count--;
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    cout << "\nMusic has been successfully removed!" << endl;
    music_count--;

}

void showMusicList(){
    struct node *temp = head;
    if(temp==NULL){
        cout << "\nMusic PlayList is empty!" << endl;
        return;
    }
    while (temp != NULL){
        cout << endl << temp->music_number << endl;
        cout << "Music title: " << temp->music_name << endl;
        cout << "Music artist: " << temp->music_artist << endl;
        cout << "Music length: " << temp->music_length << endl;
        temp = temp->next;
    }
}

void addFav(string name){
    struct favlist *favnode = new favlist();
    struct node *temp = findMusic(name);

    if(temp==NULL){
        cout << "Music isn't avilable!" << endl;
        return;
    } 
    favnode->music_name = temp->music_name;
    favnode->music_artist = temp->music_artist;
    favnode->music_length = temp->music_length;
    favnode->music_number = temp->music_number;

    favnode->fnext = NULL;
    favnode->fprev = NULL;

    if(fhead==NULL){
        fhead = favnode;
        ftail = favnode;
    }
    else{
        ftail->fnext = favnode;
        ftail = ftail->fnext;
        ftail->fprev = favnode;
    }
    fav_count++;
    cout << "Music Added to the Favourite Playlist!" << endl;
}

void showFavList(){
    struct favlist *temp = fhead;

    if(temp==NULL){
        cout << "\nFavourite Music PlayList is empty!" << endl;
        return;
    }
    while (temp != NULL){
        cout << endl << temp->music_number << endl;
        cout << "Music title: " << temp->music_name << endl;
        cout << "Music artist: " << temp->music_artist << endl;
        cout << "Music length: " << temp->music_length << endl;
        temp = temp->fnext;
    }
}


int main(){
    musicNo = 1;

    cout << "\n\n                     Welcome to our Music Playlist\n";
    cout << "         You can add music, display music, and delete music from the playlist\n";
    cout << "                    Now do as you desire with the program\n";

    while(true){
        cout << "\n\n====================MENU=====================";
        cout << "\n1. Add a Music to the playlist." << endl;
        cout << "2. Display all Musics in the playlist." << endl;
        cout << "3. Find Music." << endl;
        cout << "4. Remove a Music from the playlist." << endl;
        cout << "5. Show Total Number of Music." << endl;
        cout << "6. Add a Music to the favourite playlist." << endl;
        cout << "7. Display all Favourite Musics in the playlist." << endl;
        cout << "8. Remove a Favourite Music from the playlist." << endl;
        cout << "0. Exit" << endl;

        cout << "\nChoose an option: ";
        int n; cin >> n; cin.ignore();
        cout << endl;

        if(n==1){
            addMusic();
        }

        else if(n==2){
            cout << "----------Music List----------" << endl;
            showMusicList();
        }

        else if(n==3){
            string name;
            cout << "Enter Name: ";
            getline(cin, name);
            struct node * toFind = findMusic(name);

            if(toFind!=NULL){
                cout <<"Music Found!" << endl;
                cout << "Music title: " << toFind->music_name << endl;
                cout << "Music artist: " << toFind->music_artist << endl;
                cout << "Music length: " << toFind->music_length << endl;
            }
            else cout << "Music Not Found!" << endl;
        }

        else if(n==4){
            string name;
            cout << "Enter Name: ";
            getline(cin, name);
            removeMusic(name);
        }

        else if(n==5){
            cout << "Number of Music avilabe in the playlist is: " << music_count << ".\n"; 
            cout << "Number of Favourite Music avilabe in the playlist is: " << fav_count << ".\n"; 
        }

        else if(n==6){
            string name;
            cout << "Enter the Music nmae: ";
            getline(cin,name);
            addFav(name);
        }

        else if(n==7){
            cout << "--------Favourite Music List--------" << endl;
            showFavList();
        }

        else if(n==8){
            string name;
            cout << "Enter Name: ";
            getline(cin, name);
            removeFavMusic(name);
        }

        else if(n==0){
            break;
        } 

        else{
            cout << "Invalid Action! Please Choose Carefully." << endl;
        } 
    }
    return 0;
}
