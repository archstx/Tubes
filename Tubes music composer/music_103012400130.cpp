#include "music.h"
#include <iostream>

using namespace std;

void deleteAfterMusic(adrMus prec, adrMus &M) {
    M = prec->next;
    prec->next = M->next;
    if (M->next != nullptr) {
        M->next->prev = prec;
    }
    M->next = nullptr;
    M->prev = nullptr;
    cout << "Data lagu berhasil dihapus!\n" << endl;
}

void deleteLastMusic(adrComp C, adrMus &M) {
    if (C->nextMusic == nullptr) {
        cout << "Tidak ada lagu yang dapat dihapus!\n" << endl;
    } else {
        adrMus q = (adrMus)C->nextMusic;
        while (q->next != nullptr) {
            q = q->next;
        }
        M = q;
        if (q->prev == nullptr) {
            C->nextMusic = nullptr;
        } else {
            q->prev->next = nullptr;
        }
        M->prev = nullptr;
        cout << "Data lagu berhasil dihapus!\n" << endl;
    }
}

adrMus findElemenMusic(adrComp C, string judul) {
    adrMus q = (adrMus)C->nextMusic;
    while (q != nullptr) {
        if (q->infoMus.judul == judul) {
            return q;
        }
        q = q->next;
    }
    return nullptr;
}
