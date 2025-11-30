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

void deleteMusicFirst(listMusic &L) {
    if (L.first == nullptr) {
        cout << "List music kosong.\n";
        return;
    }

    adrMusic p = L.first;
    L.first = p->next;
    delete p;

    cout << "\033[1;32m"
         << "Music pertama berhasil dihapus!"
         << "\033[0m" << endl;
}

void deleteMusicLast(listMusic &L) {
    if (L.first == nullptr) {
        cout << "List music kosong.\n";
        return;
    }

    // hanya satu elemen
    if (L.first->next == nullptr) {
        delete L.first;
        L.first = nullptr;
        cout << "\033[1;32m"
             << "Music terakhir berhasil dihapus!"
             << "\033[0m" << endl;
        return;
    }

    adrMusic prev = nullptr;
    adrMusic p = L.first;

    while (p->next != nullptr) {
        prev = p;
        p = p->next;
    }

    prev->next = nullptr;
    delete p;

    cout << "\033[1;32m"
         << "Music terakhir berhasil dihapus!"
         << "\033[0m" << endl;
}

void deleteMusicAfter(listMusic &L, adrMusic prec) {
    if (prec == nullptr || prec->next == nullptr) {
        cout << "Tidak ada elemen setelah posisi tersebut.\n";
        return;
    }

    adrMusic p = prec->next;
    prec->next = p->next;
    delete p;

    cout << "\033[1;32m"
         << "Music setelah elemen tersebut berhasil dihapus!"
         << "\033[0m" << endl;
}

static void swapMusicInfo(adrMusic a, adrMusic b) {
    std::swap(a->info.title, b->info.title);
    std::swap(a->info.release, b->info.release);
    std::swap(a->info.rating, b->info.rating);
}

void sortMusicByRelease(listMusic &L, bool ascending) {
    adrMusic i = L.first;
    while (i != nullptr) {
        adrMusic best = i;
        adrMusic j = i->next;
        while (j != nullptr) {
            bool better = ascending
                ? (j->info.release < best->info.release)
                : (j->info.release > best->info.release);

            if (better) best = j;
            j = j->next;
        }
        if (best != i) swapMusicInfo(i, best);
        i = i->next;
    }
}

void sortMusicByRating(listMusic &L, bool ascending) {
    adrMusic i = L.first;
    while (i != nullptr) {
        adrMusic best = i;
        adrMusic j = i->next;
        while (j != nullptr) {
            bool better = ascending
                ? (j->info.rating < best->info.rating)
                : (j->info.rating > best->info.rating);

            if (better) best = j;
            j = j->next;
        }
        if (best != i) swapMusicInfo(i, best);
        i = i->next;
    }
}

