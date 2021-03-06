#ifndef SPRITE_H
#define SPRITE_H


typedef struct{
    unsigned int data[512];
} SBLOCK;

typedef struct{
    unsigned int data[4096];
} CBLOCK;

#define SCREENBLOCK ((SBLOCK*)(0x6000000))
#define CHARBLOCK ((CBLOCK*)(0x6000000))
#define REG_MOSAIC (*(unsigned short*)(0x400004C))
#define MOSAIC_VALUES(bh, bv, oh, ov) ((bh) | ((bv)<<4) | ((oh)<<8) | ((ov)<<12))

/*BACKGROUND STUFF*/

#define REG_BG0CNT  (*(u16 *) 0x4000008) //BG 0 control
#define REG_BG0HOFS (*(u16 *) 0x4000010) //BG 0 Horizontal Offset
#define REG_BG0VOFS (*(u16 *) 0x4000012) //BG 0 Vertical Offset
#define REG_BG1CNT  (*(u16 *) 0x400000A) //BG 1 control
#define REG_BG1HOFS (*(u16 *) 0x4000014) //BG 1 Horizontal Offset
#define REG_BG1VOFS (*(u16 *) 0x4000016) //BG 1 Vertical Offset
#define REG_BG2CNT  (*(u16 *) 0x400000C) //BG 2 control
#define REG_BG2HOFS (*(u16 *) 0x4000018) //BG 2 Horizontal Offset
#define REG_BG2VOFS (*(u16 *) 0x400001A) //BG 2 Vertical Offset
#define REG_BG3CNT  (*(u16 *) 0x400000E) //BG 3 control
#define REG_BG3HOFS (*(u16 *) 0x400001C) //BG 3 Horizontal Offset
#define REG_BG3VOFS (*(u16 *) 0x400001E) //BG 3 Vertical Offset

#define BG_4BPP (0 << 7)
#define BG_8BPP (1 << 7)
#define BG_REG_32x32 (0 << 14)
#define BG_REG_64x32 (1 << 14)
#define BG_REG_32x64 (2 << 14)
#define BG_REG_64x64 (3 << 14)
#define BG_MOSAIC (1 << 6)

#define CBB(i) ((i) << 2) //place this in the BG CNT register to define what Character block the data is in
#define SBB(i) ((i) << 8) //place this in the BG CNT register to define what Screen block the Map is in

/*SPRITE STUFF*/
typedef struct{
    unsigned short attr0;
    unsigned short attr1;
    unsigned short attr2;
    unsigned short fill;
}OBJ_ATTR;

#define SPRITE_MODE_1D (1 << 6) //put this into REG_DISPCNTL to enable 1D mapping mode
#define SPRITE_ENABLE (1 << 12) //put this into REG_DISPCNTL to enable sprites

#define ATTR0_REGULAR (0 << 8) //Normal Sprites
#define ATTR0_AFFINE (1 << 8) //Affine Sprites
#define ATTR0_HIDE (2 << 8) // Hide Sprites
#define ATTR0_DOUBLE_AFFINE (3 << 8) //Double Affine Sprites (Never used it before so don't ask me -Peter)
#define ATTR0_NORMAL (0 << 10) //Normal Rendering
#define ATTR0_BLEND (1 << 10) //Enables Alpha Blending.  Don't worry about it.  Unless you want too =D
#define ATTR0_WIN (2 << 10) //Object Window mode.  Again, no idea.
#define ATTR0_MOSAIC (1 << 12) //Enables the mosaic effect for this sprite.  It's a cool visual effect.  We can talk about it on thursday perhaps
#define ATTR0_4BPP (0 << 13) //16 color Sprites
#define ATTR0_8BPP (1 << 13) //256 color Sprites
#define ATTR0_SQUARE (0 << 14) //Square Shape
#define ATTR0_WIDE (1 << 14) // Wide Shape
#define ATTR0_TALL (2 << 14) //Tall Shape

#define ATTR1_HFLIP (1 << 12)
#define ATTR1_VFLIP (1 << 13)
#define ATTR1_SIZE8 (0 << 14)
#define ATTR1_SIZE16 (1 << 14)
#define ATTR1_SIZE32 (2 << 14)
#define ATTR1_SIZE64 (3 << 14)
#define ATTR1_AFFINEINDEX(n) (n<<9)

#define OAM ((OBJ_ATTR*)(0x7000000))
#define SPRITE_PAL ((unsigned short*)(0x5000200))

#define SPRITEOFFSET16(r,c) (r)*32+(c)
#define ATTR2_PALETTE_BANK(pbn) ((pbn)<<12)

#endif
