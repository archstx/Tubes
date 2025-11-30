#include <iostream>
#include "composer.h"
#include "music.h"
using namespace std;

void menuAdmin(listComp&, listMusic&);
void menuUser(listComp, listMusic);

int main() {
    listComp LC;
    listMusic LM;
    int role = -1;

    createComposerList(LC);
    createMusicList(LM);

    while (role != 0) {
        cout << "\033[1;35m";                   //warna ungu
        cout << "=== PROGRAM MUSIK & KOMPOSER ===" << endl;
        cout << "\033[0m";                      //reset warna
        cout << "1. Login Admin" << endl;
        cout << "2. Login Pengguna" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> role;
        cout << endl;

        if (role == 1) menuAdmin(LC, LM);
        else if (role == 2) menuUser(LC, LM);
    }

    return 0;
}
