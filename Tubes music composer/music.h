#ifndef MUSIC_H_INCLUDED
#define MUSIC_H_INCLUDED

#include <iostream>
#include "composer.h"
using namespace std;

struct Music {
    string judul;
    int ID;
    string genre;
};

typedef Music infotypeMus;
typedef struct elmenMus *adrMus;

struct elmenMus {
    infotypeMus infoMus;
    adrMus next;
    adrMus prev;
};

adrMus createElemenMusic(string judul, int ID, string genre);
void insertFirstMusic(adrComp C, adrMus M);
void insertLastMusic(adrComp C, adrMus M);
void insertAfterMusic(adrMus prec, adrMus M);
void deleteFirstMusic(adrComp, adrMus &M);
void deleteLastMusic(adrComp, adrMus &M);
void deleteAfterMusic(adrMus prec, adrMus &M);
adrMus findElemenMusic(adrComp C, string judul);
void viewMusic(adrComp C);

#endif
