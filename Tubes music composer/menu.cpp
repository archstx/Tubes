#include "menu.h"
#include "composer.h"
#include "music.h"

using namespace std;

void menuAdmin(ListComposer &L){
    int option = -99;
    while (option != 0) {
        cout << "============ Menu Admin ============" << endl;
        cout << "|| 1. Composer                    ||" << endl;
        cout << "|| 2. Music                       ||" << endl;
        cout << "|| 0. back                        ||" << endl;
        cout << "====================================" << endl;
        cout << "Pilih opsi : ";
        cin >> option;
        switch(option) {
           case 1  :
              menuComposer(L);
              break;
           case 2  :
              menuMusic(L);
              break;
           case 0 :
              break;
           default :
               cout << "Pilihan tidak valid!\n" << endl;
        }
    }
}

void menuComposer(ListComposer &L){
    int option = -99;
    adrComp C = nullptr, precC;
    string nama, kode, namaPrec;
    int umur;
    while (option != 0) {
        cout << "============ Menu Composer ===========" << endl;
        cout << "|| 1. insert first                ||" << endl;
        cout << "|| 2. insert last                 ||" << endl;
        cout << "|| 3. insert after                ||" << endl;
        cout << "|| 4. delete first                ||" << endl;
        cout << "|| 5. delete last                 ||" << endl;
        cout << "|| 6. delete after                ||" << endl;
        cout << "|| 7. tampilkan composer          ||" << endl;
        cout << "|| 0. back                        ||" << endl;
        cout << "====================================" << endl;
        cout << "Pilih opsi : ";
        cin >> option;
        switch(option) {
           case 1  :
              cout << "Masukkan nama composer: ";
              cin >> nama;
              cout << "Masukkan kode composer: ";
              cin >> kode;
              cout << "Masukkan umur composer: ";
              cin >> umur;
              C = createElementComposer(nama, kode, umur);
              insertFirstComposer(L, C);
              cout << "Data composer berhasil ditambahkan!\n" << endl;
              break;
           case 2  :
              cout << "Masukkan nama composer: ";
              cin >> nama;
              cout << "Masukkan kode composer: ";
              cin >> kode;
              cout << "Masukkan umur composer: ";
              cin >> umur;
              C = createElementComposer(nama, kode, umur);
              insertLastComposer(L, C);
              cout << "Data composer berhasil ditambahkan!\n" << endl;
              break;
           case 3 :{
              viewComposer(L);
              cout << "Masukkan nama composer prec: ";
              cin >> namaPrec;
              precC = findElemenComposer(L, namaPrec);
              if (precC != nullptr){
                cout << "Masukkan nama composer: ";
                cin >> nama;
                cout << "Masukkan kode composer: ";
                cin >> kode;
                cout << "Masukkan umur composer: ";
                cin >> umur;
                C = createElementComposer(nama, kode, umur);
                insertAfterComposer(L, C, precC);
                cout << "Data composer berhasil ditambahkan!\n" << endl;
              } else {
                cout << "Composer dengan nama " << namaPrec << " tidak ditemukan!\n" << endl;
              }
              break;
           }
           case 4 :
              deleteFirstComposer(L, C);
              if (C != nullptr) {
                  cout << "Composer " << C->infoComposer.nama << " berhasil dihapus!\n" << endl;
              }
              break;
           case 5 :
              deleteLastComposer(L, C);
              if (C != nullptr) {
                  cout << "Composer " << C->infoComposer.nama << " berhasil dihapus!\n" << endl;
              }
              break;
           case 6 :
              viewComposer(L);
              cout << "Masukkan nama composer prec: ";
              cin >> namaPrec;
              precC = findElemenComposer(L, namaPrec);
              if (precC == nullptr){
                cout << "Composer dengan nama " << namaPrec << " tidak ditemukan!\n" << endl;
              } else if (precC->next == nullptr){
                cout << "Tidak ada data composer setelah nama " << namaPrec << "\n" << endl;
              } else {
                deleteAfterComposer(L, C, precC);
                if (C != nullptr) {
                    cout << "Composer " << C->infoComposer.nama << " berhasil dihapus!\n" << endl;
                }
              }
              break;
           case 7 :
              viewComposer(L);
              break;
           case 0 :
              break;
           default :
              cout << "Pilihan tidak valid!\n" << endl;
        }
    }
}

void menuMusic(ListComposer &L){
    int option = -99;
    adrComp C = nullptr, tempC;
    adrMus M = nullptr, precM;
    string nama, namaPrec;
    int ID;
    string genre;
    bool laguSudahAda;
    while (option != 0) {
        cout << "============ Menu Music ============" << endl;
        cout << "|| 1. insert first                ||" << endl;
        cout << "|| 2. insert last                 ||" << endl;
        cout << "|| 3. insert after                ||" << endl;
        cout << "|| 4. delete first                ||" << endl;
        cout << "|| 5. delete last                 ||" << endl;
        cout << "|| 6. delete after                ||" << endl;
        cout << "|| 7. tampilkan lagu              ||" << endl;
        cout << "|| 0. back                        ||" << endl;
        cout << "====================================" << endl;
        cout << "Pilih opsi : ";
        cin >> option;
        switch(option) {
           case 1  :
              cout << "Masukkan nama composer yang akan menambah lagu: ";
              cin >> nama;
              C = findElemenComposer(L, nama);
              if (C == nullptr){
                  cout << "Nama composer tidak ditemukan!\n" << endl;
                  break;
              }
              cout << "Masukkan judul lagu: ";
              cin >> nama;
              if (findElemenMusic(C, nama) != nullptr){
                cout << "Composer ini sudah memiliki lagu tersebut!\n" << endl;
                break;
              }
              laguSudahAda = false;
              tempC = L.first;
              while (tempC != nullptr){
                if (findElemenMusic(tempC, nama) != nullptr){
                    cout << "Lagu ini sudah dimiliki oleh composer lain!" << endl;
                    laguSudahAda = true;
                    break;
                }
                tempC = tempC->next;
              }
              if (!laguSudahAda){
                cout << "Masukkan ID lagu: ";
                cin >> ID;
                cout << "Masukkan genre lagu: ";
                cin >> genre;
                M = createElemenMusic(nama, ID, genre);
                insertFirstMusic(C, M);
                cout << "Data lagu berhasil ditambahkan!\n" << endl;
              }
              break;
           case 2  :
              cout << "Masukkan nama composer yang akan menambah lagu: ";
              cin >> nama;
              C = findElemenComposer(L, nama);
              if (C == nullptr){
                  cout << "Nama composer tidak ditemukan!\n" << endl;
                  break;
              }
              cout << "Masukkan judul lagu: ";
              cin >> nama;
              if (findElemenMusic(C, nama) != nullptr){
                cout << "Composer ini sudah memiliki lagu tersebut!\n" << endl;
                break;
              }
              laguSudahAda = false;
              tempC = L.first;
              while (tempC != nullptr){
                if (findElemenMusic(tempC, nama) != nullptr){
                    cout << "Lagu ini sudah dimiliki oleh composer lain!" << endl;
                    laguSudahAda = true;
                    break;
                }
                tempC = tempC->next;
              }
              if (!laguSudahAda){
                cout << "Masukkan ID lagu: ";
                cin >> ID;
                cout << "Masukkan genre lagu: ";
                cin >> genre;
                M = createElemenMusic(nama, ID, genre);
                insertLastMusic(C, M);
                cout << "Data lagu berhasil ditambahkan!\n" << endl;
              }
              break;
           case 3 :
              cout << "Masukkan nama composer yang akan menambah lagu: ";
              cin >> nama;
              C = findElemenComposer(L, nama);
              if (C == nullptr){
                  cout << "Nama composer tidak ditemukan!\n" << endl;
                  break;
              }
              viewMusic(C);
              cout << "Masukkan judul lagu prec: ";
              cin >> namaPrec;
              precM = findElemenMusic(C, namaPrec);
              if (precM != nullptr){
                cout << "Masukkan judul lagu baru: ";
                cin >> nama;
                if (findElemenMusic(C, nama) != nullptr){
                    cout << "Composer ini sudah memiliki lagu tersebut!\n" << endl;
                    break;
                }
                laguSudahAda = false;
                tempC = L.first;
                while (tempC != nullptr){
                    if (findElemenMusic(tempC, nama) != nullptr){
                        cout << "Lagu ini sudah dimiliki oleh composer lain!" << endl;
                        laguSudahAda = true;
                        break;
                    }
                    tempC = tempC->next;
                }
                if (!laguSudahAda){
                    cout << "Masukkan ID lagu: ";
                    cin >> ID;
                    cout << "Masukkan genre lagu: ";
                    cin >> genre;
                    M = createElemenMusic(nama, ID, genre);
                    insertAfterMusic(precM, M);
                    cout << "Data lagu berhasil ditambahkan!\n" << endl;
                }
              } else {
                cout << "Lagu " << namaPrec << " tidak ditemukan!\n" << endl;
              }
              break;
           case 4 :
              cout << "Masukkan nama composer yang akan menghapus lagu: ";
              cin >> nama;
              C = findElemenComposer(L, nama);
              if (C == nullptr){
                  cout << "Nama composer tidak ditemukan!\n" << endl;
                  break;
              }
              if (C->nextMusic == nullptr){
                cout << "Tidak ada lagu yang dapat dihapus!\n" << endl;
                break;
              } else {
                adrMus deleted = nullptr;
                deleteFirstMusic(C, deleted);
                if (deleted != nullptr) {
                    cout << "Lagu " << deleted->infoMus.judul << " berhasil dihapus!\n" << endl;
                }
              }
              break;
           case 5 :
              cout << "Masukkan nama composer yang akan menghapus lagu: ";
              cin >> nama;
              C = findElemenComposer(L, nama);
              if (C == nullptr){
                  cout << "Nama composer tidak ditemukan!\n" << endl;
                  break;
              }
              if (C->nextMusic == nullptr){
                cout << "Tidak ada lagu yang dapat dihapus!\n" << endl;
                break;
              } else {
                adrMus deleted = nullptr;
                deleteLastMusic(C, deleted);
                if (deleted != nullptr) {
                    cout << "Lagu " << deleted->infoMus.judul << " berhasil dihapus!\n" << endl;
                }
              }
              break;
           case 6 :
              cout << "Masukkan nama composer yang akan menghapus lagu: ";
              cin >> nama;
              C = findElemenComposer(L, nama);
              if (C == nullptr){
                  cout << "Nama composer tidak ditemukan!\n" << endl;
                  break;
              }
              if (C->nextMusic == nullptr){
                cout << "Composer belum memiliki lagu\n" << endl;
                break;
              }
              viewMusic(C);
              cout << "Masukkan judul lagu prec: ";
              cin >> namaPrec;
              precM = findElemenMusic(C, namaPrec);
              if (precM == nullptr){
                cout << "Lagu " << namaPrec << " tidak ditemukan!\n" << endl;
                break;
              } else if (precM->next == nullptr){
                cout << "Tidak ada data lagu setelah lagu " << namaPrec << "\n" << endl;
                break;
              } else {
                adrMus deleted = nullptr;
                deleteAfterMusic(precM, deleted);
                if (deleted != nullptr) {
                    cout << "Lagu " << deleted->infoMus.judul << " berhasil dihapus!\n" << endl;
                }
              }
              break;
           case 7 :
              viewComposer(L);
              cout << "Masukkan nama composer: ";
              cin >> nama;
              C = findElemenComposer(L, nama);
              if (C == nullptr){
                cout << "Composer tidak ditemukan!\n" << endl;
              } else if (C->nextMusic == nullptr){
                cout << "Composer belum memiliki lagu!\n" << endl;
              } else {
                viewMusic(C);
              }
              break;
           case 0 :
              break;
           default :
              cout << "Pilihan tidak valid!\n" << endl;
        }
    }
}

void menuUser(ListComposer &L){
    int option = -99;
    while (option != 0) {
        cout << "====== Menu Studi Kasus =======================================" << endl;
        cout << "|| 1. Menampilkan composer dan lagu                          ||" << endl;
        cout << "|| 2. Input data composer (NAMA / KODE harus berbeda)        ||" << endl;
        cout << "|| 3. Menghapus composer yang tidak memiliki lagu            ||" << endl;
        cout << "|| 4. Menghapus lagu dari composer tertentu                  ||" << endl;
        cout << "|| 5. Menghitung lagu yang dimiliki setiap composer          ||" << endl;
        cout << "|| 6. Menyisipkan lagu kepada composer pilihan               ||" << endl;
        cout << "|| 7. Menghitung total lagu yang sudah ada                   ||" << endl;
        cout << "|| 0. back                                                   ||" << endl;
        cout << "===============================================================" << endl;
        cout << "Pilih opsi : ";
        cin >> option;
        switch(option) {
           case 1  :
              printComposerMusic(L);
              break;
           case 2  :
              studiKasus1(L);
              break;
            case 3 :
                studiKasus2(L);
                break;
            case 4 :
                studiKasus3(L);
                break;
            case 5 :
                studiKasus4(L);
                break;
            case 6 :
                studiKasus5(L);
                break;
            case 7 :
                studiKasus6(L);
                break;
           case 0  :
              cout << "Kembali ke menu admin..." << endl;
              break;
           default:
              cout << "Pilihan tidak valid" << endl;
        }
    }
}

void studiKasus1(ListComposer &L){
    string nama, kode;
    int umur;
    adrComp q;
    cout << "Pada studi kasus ini kita akan memasukkan data composer baru\n";
    cout << "Inputkan data composer baru :\n";
    cout << "Nama : ";
    cin >> nama;
    cout << "Kode : ";
    cin >> kode;
    cout << "Umur : ";
    cin >> umur;

    q = L.first;
    while (q != nullptr){
        if (q->infoComposer.nama == nama || q->infoComposer.kode == kode){
           cout << "KODE / NAMA composer sama! Data ditolak.\n" << endl;
           return;
        }
        q = q->next;
    }
    adrComp C = createElementComposer(nama, kode, umur);
    insertLastComposer(L, C);
    cout << "DATA COMPOSER BERHASIL DIMASUKAN!\n" << endl;
}

void studiKasus2(ListComposer &L){
    int hapus = 0;
    cout << "Pada studi kasus ini kita akan menghapus composer yang tidak memiliki lagu sama sekali" << endl;
    cout << "Menghapus composer yang tidak memiliki lagu..." << endl;

    adrComp Q = L.first;
    adrComp nextQ;

    while (Q != nullptr){
        nextQ = Q->next;

        if (Q->nextMusic == nullptr){
            hapus++;
            if (Q == L.first){
                adrComp deleted = nullptr;
                deleteFirstComposer(L, deleted);
                if (deleted != nullptr) {
                    cout << "Composer " << deleted->infoComposer.nama << " dihapus.\n";
                }
            } else if (Q->next == nullptr){
                adrComp deleted = nullptr;
                deleteLastComposer(L, deleted);
                if (deleted != nullptr) {
                    cout << "Composer " << deleted->infoComposer.nama << " dihapus.\n";
                }
            } else {
                adrComp C = L.first;
                while (C->next != Q){
                    C = C->next;
                }
                adrComp deleted = nullptr;
                deleteAfterComposer(L, deleted, C);
                if (deleted != nullptr) {
                    cout << "Composer " << deleted->infoComposer.nama << " dihapus.\n";
                }
            }
        }
        Q = nextQ;
    }

    if (hapus == 0){
        cout << "Tidak ada composer yang tidak memiliki lagu.\n" << endl;
    } else {
        cout << "Semua composer tanpa lagu telah dihapus (" << hapus << " data).\n" << endl;
    }
}

void printComposerMusic(ListComposer L){
    adrComp C = L.first;
    if (C == nullptr){
        cout << "Tidak ada data composer." << endl;
        return;
    }
    cout << "Daftar Composer dan Lagu:" << endl;
    while (C != nullptr){
        cout << "==============================" << endl;
        cout << "Nama Composer: " << C->infoComposer.nama << "\nKode: " << C->infoComposer.kode << "\nUmur: " << C->infoComposer.umur << endl;
        cout << "------------------------------" << endl;
        adrMus M = (adrMus)C->nextMusic;
        if (M == nullptr){
            cout << "  Tidak ada lagu." << endl;
        } else {
            cout << "  Lagu: ";
            while (M != nullptr){
                cout << M->infoMus.judul << " (" << M->infoMus.ID << "), ";
                M = M->next;
            }
            cout << endl;
        }
        C = C->next;
    }
    cout << "==============================" << endl;
}

void studiKasus3(ListComposer &L){
    cout << "Pada studi kasus ini kita akan menghapus lagu tertentu dari composer tertentu\n";
    string kodeComposer;
    int idLagu;
    cout << "Masukkan kode composer: ";
    cin >> kodeComposer;
    cout << "Masukkan ID lagu yang akan dihapus: ";
    cin >> idLagu;

    adrComp C = L.first;
    while (C != nullptr && C->infoComposer.kode != kodeComposer){
        C = C->next;
    }
    if (C == nullptr){
        cout << "Composer dengan kode tersebut tidak ditemukan." << endl;
        return;
    }

    adrMus M = (adrMus)C->nextMusic;
    while (M != nullptr && M->infoMus.ID != idLagu){
        M = M->next;
    }

    if (M == nullptr){
        cout << "Lagu dengan ID tersebut tidak ditemukan pada composer ini." << endl;
    } else {
        adrMus deleted = nullptr;
        if (M == (adrMus)C->nextMusic){
            deleteFirstMusic(C, deleted);
        } else if (M->next == nullptr){
            deleteLastMusic(C, deleted);
        } else {
            adrMus Z = (adrMus)C->nextMusic;
            while (Z->next != M){
                Z = Z->next;
            }
            deleteAfterMusic(Z, deleted);
        }
        if (deleted != nullptr) {
            cout << "Lagu " << deleted->infoMus.judul << " berhasil dihapus." << endl;
        }
    }
}

void studiKasus4(ListComposer L){
    cout << "Pada studi kasus ini kita akan menghitung jumlah lagu yang dimiliki oleh setiap composer\n";
    adrComp C = L.first;
    while (C != nullptr){
        int jumlah = 0;
        adrMus M = C->nextMusic;
        while (M != nullptr){
            jumlah++;
            M = M->next;
        }
        cout << "Composer " << C->infoComposer.nama << " memiliki " << jumlah << " lagu." << endl;
        C = C->next;
    }
}

void studiKasus5(ListComposer &L){
    cout << "Pada studi kasus ini kita akan menyisipkan lagu baru ke composer tertentu\n";
    string kodeComposer, judulLagu, genre;
    int idLagu;
    cout << "Masukkan kode composer tujuan: ";
    cin >> kodeComposer;
    cout << "Masukkan judul lagu: ";
    cin >> judulLagu;
    cout << "Masukkan ID lagu: ";
    cin >> idLagu;
    cout << "Masukkan genre: ";
    cin >> genre;

    adrComp C = L.first;
    while (C != nullptr){
        if(findElemenMusic(C, judulLagu) != nullptr){
            cout << "Gagal: Lagu sudah dimiliki oleh composer " << C->infoComposer.nama << endl;
            return;
        }
        C = C->next;
    }

    C = L.first;
    while (C != nullptr && C->infoComposer.kode != kodeComposer){
        C = C->next;
    }

    if (C == nullptr){
        cout << "Composer tujuan tidak ditemukan." << endl;
    } else {
        adrMus M = createElemenMusic(judulLagu, idLagu, genre);
        insertLastMusic(C, M);
        cout << "Lagu berhasil disisipkan." << endl;
    }
}

void studiKasus6(ListComposer L){
    cout << "Pada studi kasus ini kita akan menghitung jumlah lagu yang sudah ada" << endl;
    int total = 0;
    adrComp C = L.first;
    while (C != nullptr){
        adrMus M = C->nextMusic;
        while (M != nullptr){
            total = total + 1;
            M = M->next;
        }
        C = C->next;
    }
    cout << "Total lagu yang sudah ada dalam database: " << total << endl;
}
