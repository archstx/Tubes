#include "music.h"
#include <iostream>

using namespace std;

adrMus createElemenMusic(string judul, int ID, string genre) {
    infotypeMus x;
    adrMus M = new elmenMus;

    x.judul = judul;
    x.ID = ID;
    x.genre = genre;

    M->infoMus = x;
    M->next = nullptr;
    M->prev = nullptr;

    return M;
}

void insertFirstMusic(adrComp C, adrMus M) {
    if (C->nextMusic == nullptr) {
        C->nextMusic = M;
    } else {
        M->next = (adrMus)C->nextMusic;
        ((adrMus)C->nextMusic)->prev = M;
        C->nextMusic = M;
    }
}

void insertAfterMusic(adrMus prec, adrMus M) {
    M->next = prec->next;
    M->prev = prec;
    prec->next = M;
    if (M->next != nullptr) {
        M->next->prev = M;
    }
}

void insertLastMusic(adrComp C, adrMus M) {
    if (C->nextMusic == nullptr) {
        C->nextMusic = M;
    } else {
        adrMus q = (adrMus)C->nextMusic;
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = M;
        M->prev = q;
    }
}

void deleteFirstMusic(adrComp C, adrMus &M) {
    if (C->nextMusic == nullptr) {
        cout << "Tidak ada lagu yang dapat dihapus!\n" << endl;
    } else {
        M = (adrMus)C->nextMusic;
        C->nextMusic = M->next;
        if (C->nextMusic != nullptr) {
            ((adrMus)C->nextMusic)->prev = nullptr;
        }
        M->next = nullptr;
        cout << "Data lagu berhasil dihapus!\n" << endl;
    }
}

void viewMusic(adrComp C) {
    adrMus M = (adrMus)C->nextMusic;
    cout << "==== Daftar Lagu Composer ====" << endl;
    if (M == nullptr) {
        cout << "(Belum ada lagu yang ditambahkan)" << endl;
    }
    while (M != nullptr) {
        cout << "Judul Lagu   : " << M->infoMus.judul << endl;
        cout << "ID Lagu      : " << M->infoMus.ID << endl;
        cout << "Genre Lagu   : " << M->infoMus.genre << endl;
        cout << "---------------------------------" << endl;
        M = M->next;
    }
    cout << endl;
}
