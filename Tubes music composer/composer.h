#ifndef COMPOSER_H_INCLUDED
#define COMPOSER_H_INCLUDED

#include <string>

using namespace std;

struct ComposerInfo {
    string nama;
    string kode;
    int umur;
};

typedef ComposerInfo infotypeComp;
typedef struct elmenComposer *adrComp;
typedef struct elmenMus *adrMus;

struct elmenComposer {
    infotypeComp infoComposer;
    adrComp next;
    adrMus nextMusic;
};

struct ListComposer {
    adrComp first;
};

void createListComposer(ListComposer &L);
void insertFirstComposer(ListComposer &L, adrComp Comp);
void insertLastComposer(ListComposer &L, adrComp Comp);
void insertAfterComposer(ListComposer &L, adrComp Comp, adrComp prec);
void deleteFirstComposer(ListComposer &L, adrComp &Comp);
void deleteLastComposer(ListComposer &L, adrComp &Comp);
void deleteAfterComposer(ListComposer &L, adrComp &Comp, adrComp prec);
adrComp findElemenComposer(ListComposer L, string nama);
void menghitungJumlahComposer(ListComposer L);
adrComp createElementComposer(string nama, string kode, int umur);
void viewComposer(ListComposer L);

#endif
