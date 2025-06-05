//
// Created by david on 6/5/2025.
//

#ifndef AXE_H
#define AXE_H

#include "drawfunc.h"

void axe() {
	drawLine ({-100, 0}, {100, 0}, 5.0, BLACK);
	drawLine ({0, 100}, {0, -100}, 5.0, BLACK);
}



#endif //AXE_H
