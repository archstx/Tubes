#include "composer.h"
#include <iostream>
using namespace std;

void deleteFirstComposer(ListComposer &L, adrComp &C) {
    if (L.first == nullptr) {
        cout << "List kosong, tidak dapat dihapus!\n" << endl;
    } else if (L.first->next == nullptr) {
        C = L.first;
        L.first = nullptr;
        cout << "Data composer berhasil dihapus!" << endl;
    } else {
        C = L.first;
        L.first = C->next;
        C->next = nullptr;
        cout << "Data composer berhasil dihapus!" << endl;
    }
}

void deleteAfterComposer(ListComposer &L, adrComp &C, adrComp prec) {
    C = prec->next;
    prec->next = C->next;
    C->next = nullptr;
    cout << "Data composer berhasil dihapus!" << endl;
}

void deleteLastComposer(ListComposer &L, adrComp &C) {
    if (L.first == nullptr) {
        cout << "List kosong, tidak dapat dihapus!\n" << endl;
    } else if (L.first->next == nullptr) {
        C = L.first;
        L.first = nullptr;
        cout << "Composer berhasil dihapus!\n" << endl;
    } else {
        adrComp q = L.first;
        while (q->next->next != nullptr) {
            q = q->next;
        }
        C = q->next;
        q->next = nullptr;
        cout << "Composer berhasil dihapus!\n" << endl;
    }
}

void menghitungJumlahComposer(ListComposer L) {
    adrComp C = L.first;
    int jumlah = 0;
    while (C != nullptr) {
        jumlah++;
        C = C->next;
    }
    cout << "Jumlah Composer: " << jumlah << endl;
}
