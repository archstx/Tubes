#include "composer.h"
#include <iostream>
using namespace std;

void createListComposer(ListComposer &L) {
    L.first = nullptr;
}

adrComp createElementComposer(string nama, string kode, int umur) {
    infotypeComp x;
    adrComp C = new elmenComposer;

    x.nama = nama;
    x.kode = kode;
    x.umur = umur;

    C->infoComposer = x;
    C->next = nullptr;
    C->nextMusic = nullptr;

    return C;
}

void insertFirstComposer(ListComposer &L, adrComp C) {
    if (L.first == nullptr) {
        L.first = C;
    } else {
        C->next = L.first;
        L.first = C;
    }
}

void insertAfterComposer(ListComposer &L, adrComp C, adrComp prec) {
    C->next = prec->next;
    prec->next = C;
}

void insertLastComposer(ListComposer &L, adrComp C) {
    if (L.first == nullptr) {
        L.first = C;
    } else {
        adrComp q = L.first;
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = C;
    }
}

adrComp findElemenComposer(ListComposer L, string nama) {
    adrComp C = L.first;
    while (C != nullptr) {
        if (C->infoComposer.nama == nama) {
            return C;
        }
        C = C->next;
    }
    return nullptr;
}

void viewComposer(ListComposer L) {
    adrComp C;
    cout << "=== Daftar Composer Musik ===" << endl;
    C = L.first;
    while (C != nullptr) {
        cout << "Nama Composer: " << C->infoComposer.nama << endl;
        cout << "Kode Composer: " << C->infoComposer.kode << endl;
        cout << "Umur Composer: " << C->infoComposer.umur << endl;
        cout << "-------------------------------" << endl;
        C = C->next;
    }
    cout << endl;
}
