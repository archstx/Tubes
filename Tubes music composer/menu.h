#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "composer.h"
#include "music.h"

void adminMenu(listComp &LC);
void userMenu(listComp LC);

// composer
void menuInsertComposer(listComp &LC);
void menuDeleteComposer(listComp &LC);
void menuShowComposer(listComp LC);

// music
void menuInsertMusicToComposer(listComp &LC);
void menuDeleteMusicFromComposer(listComp &LC);
void menuShowMusicOfComposer(listComp LC);

// user-only
void menuSearchComposer(listComp LC);
void menuSearchMusic(listComp LC);

#endif
