#ifndef PRESSF_SCREEN_C
#define PRESSF_SCREEN_C

#include "screen.h"

static u8 screen_dirty_any;
static u8 screen_dirty[64];

const u16 PIXEL_COLOR_RGB565[4][4] = 
{
   {0x066B, 0xF98A, 0x49FE, 0xCE9F},
   {0x066B, 0xF98A, 0x49FE, 0xE71C},
   {0x066B, 0xF98A, 0x49FE, 0x97F4},
   {0xFFFF, 0xFFFF, 0xFFFF, 0x0000}
};

/* Returns the two-bit pixel data for a given pixel index */
u8 get_pixel(u8 *vram, u16 index)
{
   return (vram[index / 4] >> (3 - (index & 3)) * 2) & 3;
}

/* Returns the 2-bit palette index for a scanline (defined by column 126) */
u8 get_palette(u8 *vram, u16 index)
{
   return get_pixel(vram, (index & 0xFF80) + 126);
}

void draw_frame_rgb565(u8 *vram, u16 *buffer)
{
   if (!screen_dirty_any)
      return;
   else
   {
      u8 palette, pixel_data, x_pos, y_pos;
      u16 buffer_pos = 0;

      for (y_pos = 0; y_pos < VRAM_HEIGHT; y_pos++)
      {
         /* Don't waste time painting lines that haven't changed this frame */
         if (!screen_dirty[y_pos])
         {
            buffer_pos += VRAM_WIDTH;
            continue;
         }

         palette = get_palette(vram, y_pos);

         for (x_pos = 0; x_pos < VRAM_WIDTH; x_pos++, buffer_pos++)
         {
            pixel_data = get_pixel(vram, buffer_pos);
            buffer[buffer_pos] = PIXEL_COLOR_RGB565[palette][pixel_data];
         }

         screen_dirty[y_pos] = FALSE;
      }

      screen_dirty_any = FALSE;
   }
}

/* Writes a 2-bit pixel into the correct position in VRAM 
   We assume "value" is also 2-bit. */
void vram_write(u8 *vram, u8 x, u8 y, u8 value)
{
   u16 byte = (x + y * 128)/4;
   u8 final;
   u8 mask;

   screen_dirty_any = TRUE;
   screen_dirty[y]  = TRUE;
   switch (x & 3)
   {
   case 0:
      mask = 0x3F;
      break;
   case 1:
      mask = 0xCF;
      break;
   case 2:
      mask = 0xF3;
      break;
   case 3:
      mask = 0xFC;
      break;
   }
   final = value << ((3 - (x & 3)) * 2);

   vram[byte] &= mask;
   vram[byte] |= final;
}

#endif
