#include <iostream>
#include "composer.h"
using namespace std;

void createComposerList(listComp &L){
    L.first = nullptr;
    L.last = nullptr;
}

adrComposer createElmComposer(int id, string name){
    adrComposer p = new Composer;
    p->info.id = id;
    p->info.name = name;
    p->next = nullptr;
    p->prev = nullptr;
    p->child = nullptr;
    return p;
}


void insertComposerFirst(listComp &L, adrComposer p){
    if (L.first == nullptr){ // kosong
        L.first = p;
        L.last = p;
        p->prev = nullptr;
        p->next = nullptr;
    } else {
        p->next = L.first;
        L.first->prev = p;
        p->prev = nullptr;
        L.first = p;
    }

    cout << "\033[1;32m" << endl;                           //warna hijau
    cout << "Composer berhasil ditambahkan!" << endl;
    cout << "\033[0m" << endl;                              //reset warna
}

void insertComposerLast(listComp &L, adrComposer p){
    if(L.first == nullptr){
        insertComposerFirst(L, p);
    } else {
        L.last->next = p;
        p->prev = L.last;
        p->next = nullptr;
        L.last = p;
    }

    cout << "\033[1;32m" << endl;                           //warna hijau
    cout << "Composer berhasil ditambahkan!" << endl;
    cout << "\033[0m" << endl;                              //reset warna
}

void insertComposerAfter(listComp &L, adrComposer Prec, adrComposer P){
    if(P == nullptr || Prec == nullptr) return;
    P->next = Prec->next;
    P->prev = Prec;
    if(Prec->next != nullptr) Prec->next->prev = P;
    else L.last = P; // jika Prec adalah last
    Prec->next = P;

    cout << "\033[1;32m" << endl;                           //warna hijau
    cout << "Composer berhasil ditambahkan!" << endl;
    cout << "\033[0m" << endl;                              //reset warna
}


// cari berdasarkan id
adrComposer findComposer(listComp L, int id){
    adrComposer p = L.first;
    while (p != nullptr){
        if(p->info.id == id) return p;
        p = p->next;
    }
    return nullptr;
}

void showComposer(listComp L){
    adrComposer p = L.first;
    if (p == nullptr) {
        cout << "(Belum ada composer)" << endl;
        cout << endl;
        return;
    }

    while (p != nullptr) {
        cout << "ID Composer : " << p->info.id << endl;
        cout << "Nama        : " << p->info.name << endl;
        cout << "Music List  : ";

        adrMusic C = p->child;
        if (C == nullptr) {
            cout << "(Kosong)";
        } else {
            while (C != nullptr) {
                cout << "[" << C->info.title << "] ";
                C = C->next;
            }
        }
        cout << endl << endl;
        p = p->next;
    }
}

void addMusicToComposer(adrComposer C, adrMusic M) {
    if (C == nullptr || M == nullptr) return;
    if (C->child == nullptr) {
        C->child = M;
        M->next = nullptr;
    } else {
        adrMusic p = C->child;
        while (p->next != nullptr){
            p = p->next;
        }
        p->next = M;
        M->next = nullptr;
    }
}


// hapus semua child music milik satu composer
void deleteAllChildMusic(adrMusic &child) {
    while (child != nullptr) {
        adrMusic p = child;
        child = child->next;
        delete p;
    }
}

void deleteComposerFirst(listComp &L) {
    if (L.first == nullptr) {
        cout << "List composer kosong.\n";
        return;
    }

    adrComposer p = L.first;

    // hapus semua music milik composer ini
    deleteAllChildMusic(p->child);

    if (L.first == L.last) { // cuma 1 elemen
        L.first = nullptr;
        L.last = nullptr;
    } else {
        L.first = p->next;
        L.first->prev = nullptr;
    }

    delete p;

    cout << "\033[1;32m"
         << "Composer pertama berhasil dihapus!"
         << "\033[0m" << endl;
}

void deleteComposerLast(listComp &L) {
    if (L.first == nullptr) {
        cout << "List composer kosong.\n";
        return;
    }

    adrComposer p = L.last;

    // hapus semua music milik composer ini
    deleteAllChildMusic(p->child);

    if (L.first == L.last) { // cuma 1 elemen
        L.first = nullptr;
        L.last = nullptr;
    } else {
        L.last = p->prev;
        L.last->next = nullptr;
    }

    delete p;

    cout << "\033[1;32m"
         << "Composer terakhir berhasil dihapus!"
         << "\033[0m" << endl;
}

void deleteComposerAfter(listComp &L, adrComposer prec) {
    if (prec == nullptr || prec->next == nullptr) {
        cout << "Tidak ada composer setelah posisi tersebut.\n";
        return;
    }

    adrComposer p = prec->next;

    // hapus semua music milik composer ini
    deleteAllChildMusic(p->child);

    prec->next = p->next;
    if (p->next != nullptr) {
        p->next->prev = prec;
    } else {
        // kalau yang dihapus adalah last
        L.last = prec;
    }

    delete p;

    cout << "\033[1;32m"
         << "Composer setelah elemen tersebut berhasil dihapus!"
         << "\033[0m" << endl;
}

