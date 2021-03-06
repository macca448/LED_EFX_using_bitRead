/*
 * By using HEX values with "bitRead" we can create a binary value for array state
 * examples: 0x8001 = 0b1000000000000000 and 0xffff = 0b1111111111111111
 * Depending on what look you are after the patterns can be looped back & forth
 * or just in one direction. Each pattern below is run in all 3 possible modes.
 */

const uint16_t 
    p1[]={0x0, 0x8000, 0xc000, 0xe000, 0xf000, 0xf800, 0xfc00, 0xfe00, 0xff00, 0xff80, 0xffc0, 0xffe0, 
          0xfff0, 0xfff8, 0xfffc, 0xfffe, 0xffff, 0x7fff, 0x3fff, 0x1fff, 0xfff, 0x7ff, 0x3ff, 0x1ff, 
          0xff, 0x7f, 0x3f, 0x1f, 0xf, 0x7, 0x3, 0x1, 0x0},

    p2[]={0x0, 0x8001, 0xc003, 0xe007, 0xf00f, 0xf81f, 0xfc3f, 0xfe7f, 0xffff, 0x7ffe, 0x3ffc, 0x1ff8, 
          0xff0, 0x7e0, 0x3c0, 0x180, 0x0},
    
    p3[]={0xffff, 0xfffe, 0xfffc, 0xfff9, 0xfff3, 0xffe7, 0xffcf, 0xff9f, 0xff3f, 0xfe7f, 0xfcff, 0xf9ff, 
          0xf3ff, 0xe7ff, 0xcfff, 0x9fff, 0x3fff, 0x7fff, 0xffff},

    p4[]={0x0, 0x1, 0x2, 0x5, 0xa, 0x15, 0x2a, 0x55, 0xaa, 0x155, 0x2aa, 0x555, 0xaaa, 0x1555, 0x2aaa,
          0x5555, 0xaaaa, 0x5554, 0xaaa8, 0x5550, 0xaaa0, 0x5540, 0xaa80, 0x5500, 0xaa00, 0x5400, 0xa800,
          0x5000, 0xa000, 0x4000, 0x8000, 0x0};
