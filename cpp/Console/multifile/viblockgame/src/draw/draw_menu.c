#include "draw.h"
#include "internal.h"
#include "../textgfx/textgfx.h"
#include "../version.h"

void draw_blockgame_logo(int x, int y)
{
	int bl;
	x-=4;
	drawbl(0x773, 1, x, y);
	drawbl(0x311, 4, x+7, y);
	drawbl(0x535, 6, x+12, y);
	drawbl(0x753, 7, x+19, y);
	drawbl(0x572, 2, x+26, y);
	drawbl(0x577, 3, x+33, y);
	drawbl(0x737, 5, x+40, y);
	setattr_normal();
}

void print_viblockgame_ver(int x, int y)
{
	setcurs(x, y);
	setattr_bold();
	printstr(VIBLOCKGAME_VER);
	setattr_normal();
}
