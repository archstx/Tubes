#include <iostream>
#include "menu.h"
#include "composer.h"
#include "music.h"

using namespace std;

int main() {
    ListComposer L;
    createListComposer(L);

    int privilege = -1;

    while (privilege != 0) {
        cout << "\n=========================================" << endl;
        cout << "     SISTEM DATA COMPOSER & MUSIC        " << endl;
        cout << "=========================================" << endl;
        cout << "1. Admin" << endl;
        cout << "2. User" << endl;
        cout << "0. Keluar" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Pilih mode akses: ";
        cin >> privilege;

        switch (privilege) {
            case 1:
                menuAdmin(L);
                break;

            case 2:
                menuUser(L);
                break;

            case 0:
                cout << "\nTerima kasih telah menggunakan sistem ini!" << endl;
                break;

            default:
                cout << "\nPilihan tidak valid! Silakan coba lagi.\n" << endl;
        }
    }

    return 0;
}
