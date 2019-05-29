/*************************************
 *  QURAN BAHIT
 *  AUTHOR  :   alahem monsef
 *  EMAIL   :   m.alahem09@gmail.com
 *  VERSION :   __
 *  DATE    :   11-may-2019
 *
 *************************************/

typedef struct rgba_t {
    int r;
    int g;
    int b;
    int a;
}rgba_t;

typedef struct text_line_t {
    SDL_Surface* sur;
    SDL_Texture* tex;
    SDL_Rect rec;
}text_line_t;


SDL_Color getpixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
    // printf("b :%d\n", bpp);
 
        SDL_Color PixelColor2 = {p[0],p[1],p[2],p[3]};
        return PixelColor2;
}

void SetPixelColor(SDL_Surface* pSurface, int X, int Y, Uint32 Pixel)
{
    Uint32* pPixels = (Uint32*)pSurface->pixels;

    pPixels[(Y * pSurface->w) + X] = Pixel;
}

void change_pixel(SDL_Surface *sur,char r,char g,char b,char a)
{
    int i;
    int j;

    const int SurfaceWidth  = sur->w;
    const int SurfaceHeight = sur->h;

    // Loop through the second surface' pixel data
    for(i = 0; i < SurfaceHeight; i++)
    {
        for(j = 0; j < SurfaceWidth; j++)
        {
            SDL_Color pxc = getpixel(sur, j, i);
            Uint32 NewPixelValue;
            //char val = 250;

            //white
/*            if (pxc.r > val && pxc.g > val && pxc.b > val && pxc.a > 250) {
                pxc.r = 0;
                pxc.g = 0;
                pxc.b = 0;
                pxc.a = 0;
            }*/
            //green
            if (pxc.r > 4 && pxc.g > 4 && pxc.b > 4) {
                pxc.r = r;
                pxc.g = g;
                pxc.b = b;
                pxc.a = a;
            }

            NewPixelValue = SDL_MapRGBA(sur->format, pxc.r, pxc.g, pxc.b, pxc.a);
       
            if(SDL_MUSTLOCK(sur))
                SDL_LockSurface(sur);


            SetPixelColor(sur, j, i, NewPixelValue);
            // printf("g :%d\n", pxc.r);
            // printf("g :%d\n", pxc.g);
            // printf("b :%d\n", pxc.b);
 

            if(SDL_MUSTLOCK(sur))
                SDL_UnlockSurface(sur);
        }
    }
}

#include "input_box.h"
#include "quiz_box.h"
#include "hud.h"

void init_ui()
{
    init_input_box();
    init_quiz_box();
    init_hud();
}

void update_ui()
{
    update_input_box();
    update_quiz_box();
    update_hud();
}

void draw_ui()
{
    draw_input_box();
    draw_quiz_box();
    draw_hud();
}

int free_ui()
{
    free_input_box();
    free_quiz_box();
    free_hud();
}