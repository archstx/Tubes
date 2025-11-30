#include <iostream>
#include "composer.h"
#include "music.h"
using namespace std;

void menuAdmin(listComp &LC, listMusic &LM) {
    int pilihan = -1;
    while (pilihan != 0) {
        cout << "\033[1;34m";                   //warna biru
        cout << "=== MENU ADMIN ===" << endl;
        cout << "\033[0m";                      //reset warna
        cout << "1. Tambah Composer" << endl;
        cout << "2. Tambah Music" << endl;
        cout << "3. Hubungkan Composer - Music" << endl;
        cout << "4. Tampilkan Composer" << endl;
        cout << "5. Tampilkan Music" << endl;
        cout << "0. Logout" << endl;
        cout << "Pilih: ";
        cin >> pilihan;
        cout << endl;

        if (pilihan == 1) {             //opsi 1
            int id;
            string nama;
            cout << "ID: ";
            cin >> id;
            cout << "Nama: ";
            cin >> nama;

            int position;
            cout << "Insert Composer di posisi: \n1. First\n2. Last\n3. After ID tertentu\nPilih: ";
            cin >> position;

            if (position == 1){
                    insertComposerFirst(LC, createElmComposer(id, nama));
            } else if (position == 2){
                insertComposerLast(LC, createElmComposer(id, nama));
            } else if (position == 3){
                int afterID;
                cout << endl;
                cout << "Masukkan ID setelah composer: ";
                cin >> afterID;
                adrComposer prec = findComposer(LC, afterID);
                if (prec != nullptr){
                        insertComposerAfter(LC, prec, createElmComposer(id, nama));
                } else {
                    cout << endl;
                    cout << "\033[1;31m";                           // warna merah
                    cout << "Composer ID tidak ditemukan." << endl;
                    cout << "\033[0m" << endl;                      // Reset warna
                }
            }
        }

        else if (pilihan == 2) {                //opsi 2
            string title, afterTitle;
            int tahun;
            float rating;

            cout << "Title: ";
            cin >> title;
            cout << "Release: ";
            cin >> tahun;
            cout << "Rating: ";
            cin >> rating;

            int position;
            cout << "Insert Music di posisi: \n1. First\n2. Last\n3. After Title tertentu\nPilih: ";
            cin >> position;

            if (position == 1){
                    insertMusicFirst(LM, createElmMusic(tahun, rating, title));
            } else if (position == 2){
                insertMusicLast(LM, createElmMusic(tahun, rating, title));
            } else if (position == 3){
                int afterID;
                cout << endl;
                cout << "Masukkan Title setelah musik: ";
                cin >> afterTitle;

                adrMusic prec = LM.first;
                while(prec != nullptr && prec->info.title != afterTitle){
                        prec = prec->next;
                }
                if(prec != nullptr) {
                        insertMusicAfter(LM, prec, createElmMusic(tahun, rating, title));
                } else {
                    cout << endl;
                    cout << "\033[1;31m";                           // warna merah
                    cout << "Music title tidak ditemukan." << endl;
                    cout << "\033[0m" << endl;                      // Reset warna
                }
            }
        }

        else if (pilihan == 3) {                //opsi 3
            int id;
            string judul;

            cout << "ID Composer: ";
            cin >> id;
            cout << "Judul Musik: ";
            cin >> judul;

            adrComposer C = findComposer(LC, id);
            adrMusic M = LM.first;
            while (M != nullptr && M->info.title != judul) {
                M = M->next;
            }

            if (C != nullptr && M != nullptr) {
                addMusicToComposer(C, createElmMusic(M->info.release, M->info.rating, M->info.title));
                cout << "Data berhasil disambungkan!" << endl;
            } else {
                cout << endl;
                cout << "\033[1;31m";                           // warna merah
                cout << "Composer ID tidak ditemukan." << endl;
                cout << "\033[0m" << endl;                      // reset warna
            }
            cout << endl;
        }

        else if (pilihan == 4) {                //opsi 4
            showComposer(LC);
        }

        else if (pilihan == 5) {                //opsi 5
            showMusic(LM);
            cout << endl;
        }
    }
}

void menuUser(listComp LC, listMusic LM) {
    int pilihan = -1;
    while (pilihan != 0) {
        cout << "\033[1;32m";                   //warna hijau
        cout << "=== MENU USER ===" << endl;
        cout << "\033[0m";                      //reset warna
        cout << "1. Lihat Composer" << endl;
        cout << "2. Lihat Music" << endl;
        cout << "0. Logout" << endl;
        cout << "Pilih: ";
        cin >> pilihan;
        cout << endl;

        if (pilihan == 1){
            showComposer(LC);
        } else if (pilihan == 2){
            showMusic(LM);
        }
    }
}
