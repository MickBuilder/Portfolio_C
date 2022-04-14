#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

#define BUFFERSIZE 128
#define WHITE makecol(255, 255, 255)

int main()
{
   BITMAP* buffer = NULL;
   char    edittext[BUFFERSIZE];
   int     caret  = 0;

   /* typical Allegro initialization */
   allegro_init();
   install_keyboard();
   set_gfx_mode(GFX_AUTODETECT, 320, 240, 0, 0);

   buffer = create_bitmap(320, 240);

   do
   {
      if(keypressed())
      {
         int  newkey   = readkey();
         char ASCII    = newkey & 0xff;
         char scancode = newkey >> 8;

         /* a character key was pressed; add it to the string */
         if(ASCII >= 32 && ASCII <= 126)
         {
                                if(caret < BUFFERSIZE - 1)
                                {
                                        edittext[caret] = ASCII;
                                        caret++;
                                        edittext[caret] = '\0';
                                }
         }
         else if(scancode == KEY_BACKSPACE)
         {
            if (caret > 0) caret--;
            edittext[caret] = '\0';
         }
      }
      
      /* all drawing goes here */
      clear(buffer);
      textout(buffer, font, edittext, 0, 10, WHITE);
      vline(buffer, caret * 8, 8, 18, WHITE);
      blit(buffer, screen, 0, 0, 0, 0, 320, 240);

   }
   while(!key[KEY_ESC]);
   
   destroy_bitmap(buffer);

   return 0;
}
END_OF_MAIN()
