
#ifndef BABY_CTHULU____
#define BABY_CTHULU____

#include <nds.h>


typedef bool (*bluCallback)();

enum bluFunc{
BLUFRAMFUNC = 0,
BLURENDFUNC = 1
};

struct bluSprite{
int init;
int frame;
int framerate;
int counter;
int x;
int y;
int fps;
int id;
int priority;
unsigned short* gfx;
const unsigned int* tiles;
const unsigned short* pal;
unsigned int tlen;
unsigned int plen;
SpriteMapping sm;
SpriteSize sz;
SpriteColorFormat sfmt;
};

struct bluAnimation{
unsigned short frames;
const unsigned short** palList;
const unsigned int** tileList;
unsigned int* tlen;
unsigned int* plen;
};

struct bluBG{

};

enum blumsg{
NO_MSG = 0,
PWR_ON = 1,
KEYPRESS = 2,
QUIT = 3
};

struct bluVent{
blumsg msg;
u32 keys;
u16 flags;
bluVent* next;
};

class bcthulu{
public:
virtual void 	Release() = 0;

virtual void 	System_Start() = 0;
virtual void 	System_SetFunc(bluCallback func, bluFunc fblu) = 0;

virtual void 	GFX_Initiate() = 0;
virtual void 	GFX_LDSprite(bluSprite* bsp) = 0;
virtual void 	GFX_BltSpr(bluSprite* bsp) = 0;
virtual void 	GFX_PlayAnimation(bluSprite* bsp, bluAnimation* ban) = 0;
virtual int 	GFX_AddAnimationFrame(bluAnimation* ban, u16 index, const u32* tile, const u16* pal, u32 tlength, u32 plength) = 0;
virtual void 	GFX_InitAnimationFrames(bluAnimation* ban, u16 frames) = 0;
virtual void 	GFX_ReleaseAnimationFrames(bluAnimation* ban) = 0;
virtual void 	GFX_Init3DDevice() = 0;

virtual void	Input_Init() = 0;
virtual bluVent Input_PumpQueue() = 0;
virtual int 	Input_KeysPressed() = 0;
virtual int 	Input_KeysHeld() = 0;
virtual void 	Input_PushEvent(bluVent bvent) = 0;
};

extern bcthulu* bluCreate();
#endif

