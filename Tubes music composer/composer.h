#ifndef COMPOSER_H_INCLUDED
#define COMPOSER_H_INCLUDED
#include <string>
#include "music.h"

using namespace std;

typedef struct Composer *adrComposer;

struct infotypeC {
    int id;
    string name;
};

struct Composer {
    infotypeC info;
    adrComposer next;
    adrComposer prev;
    adrMusic child;
};

struct listComp {
    adrComposer first;
    adrComposer last;
};

void createComposerList(listComp &L);
adrComposer createElmComposer(int id, string name);
void insertComposerFirst(listComp &L, adrComposer p);
void insertComposerLast(listComp &L, adrComposer p);
void insertComposerAfter(listComp &L, adrComposer prec, adrComposer p);
adrComposer findComposer(listComp L, int id);
void showComposer(listComp L);

void addMusicToComposer(adrComposer C, adrMusic M);

#endif // COMPOSER_H_INCLUDED
