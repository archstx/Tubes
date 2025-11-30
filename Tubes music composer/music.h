#ifndef MUSIC_H_INCLUDED
#define MUSIC_H_INCLUDED
#include <string>
using namespace std;

typedef struct Music *adrMusic;

struct infotypeM {
    int release;
    float rating;
    string title;
};

struct Music {
    infotypeM info;
    adrMusic next;
};

struct listMusic {
    adrMusic first;
};

void createMusicList(listMusic &L);
adrMusic createElmMusic(int release, float rating, string title);
void insertMusicFirst(listMusic &L, adrMusic p);
void insertMusicLast(listMusic &L, adrMusic p);
void insertMusicAfter(listMusic &L, adrMusic prec, adrMusic p);
void showMusic(listMusic L);

void deleteMusicFirst(listMusic &L);
void deleteMusicLast(listMusic &L);
void deleteMusicAfter(listMusic &L, adrMusic prec);

void sortMusicByRelease(listMusic &L, bool ascending);
void sortMusicByRating(listMusic &L, bool ascending);

#endif // MUSIC_H_INCLUDED

