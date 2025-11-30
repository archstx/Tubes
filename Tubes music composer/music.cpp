#include <iostream>
#include "music.h"

using namespace std;

void createMusicList(listMusic &L){
    L.first = nullptr;
}

adrMusic createElmMusic(int release, float rating, string title){
    adrMusic p = new Music;

    p->info.release = release;
    p->info.rating = rating;
    p->info.title = title;
    p->next = nullptr;

    return p;
}

void insertMusicFirst(listMusic &L, adrMusic p){
    if (L.first == nullptr){ // kosong
        L.first = p;
        p->next = nullptr;
    } else {
        p->next = L.first;
        L.first = p;
    }

    cout << "\033[1;32m" << endl;                           //warna hijau
    cout << "Music berhasil ditambahkan!" << endl;
    cout << "\033[0m" << endl;                              //reset warna
}

void insertMusicLast(listMusic &L, adrMusic p){
    adrMusic Q = L.first;

    if(L.first == nullptr){
        insertMusicFirst(L, p);
    } else {
        while(Q->next != nullptr){
            Q = Q->next;
        }
        Q->next = p;
        p->next = nullptr;
    }

    cout << "\033[1;32m" << endl;                           //warna hijau
    cout << "Composer berhasil ditambahkan!" << endl;
    cout << "\033[0m" << endl;                              //reset warna
}

void insertMusicAfter(listMusic &L, adrMusic prec, adrMusic p){
    p->next = prec->next;
    prec->next = p;

    cout << "\033[1;32m" << endl;                           //warna hijau
    cout << "Composer berhasil ditambahkan!" << endl;
    cout << "\033[0m" << endl;                              //reset warna
}


void showMusic(listMusic L) {
    adrMusic p = L.first;
    if (p == nullptr) {
        cout << "(Belum ada musik)" << endl;
        cout << endl;
        return;
    }

    while (p != nullptr) {
        cout << "Title: " << p->info.title
             << " | Release: " << p->info.release
             << " | Rating: " << p->info.rating << endl;
        p = p->next;
    }
}
