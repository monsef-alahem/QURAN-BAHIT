/*************************************
 *  QURAN BAHIT
 *  AUTHOR  :   alahem monsef
 *  EMAIL   :   m.alahem09@gmail.com
 *  VERSION :   __
 *  DATE    :   11-may-2019
 *
 *************************************/


//utiliser sdl2
#include <SDL2/SDL.h>

//ouvrir des images a part bmp avec sdl2
#include <SDL2/SDL_image.h>

//lire sons et musiques avec sdl2
#include <SDL2/SDL_mixer.h>

//afficher du text avec sdl2
#include <SDL2/SDL_ttf.h>

#include <string.h>
#include <stdio.h>
#include <wchar.h>
#include <cmath>

int buff_i = 0;
wchar_t buff[100][80];
wchar_t query[80] = L"heloooejjfiejf";

#include "baht_tools.h"

///fin des headers


//variables globales

int i = 0;
int ret = 0;
int coins_left = 7;
int idx = 0;
int level_id = 0;



//variables globales SDL2
SDL_Window* window;
SDL_Renderer* renderer;
Mix_Chunk *wave;
Mix_Music *music;
SDL_Event event;
#define KEYS 38
typedef struct key_t{
    char letter;
    unsigned char hexcode[2];
    SDL_Keycode code; 
}key_t;

void wstrcpy(uint32_t *src, wchar_t *dest, int size)
{
    int i;
    for (i = 0 ; i < size ; i++) {
        dest[i] = src[i];
    }
    dest[size] = 0;
}
int mywcscmp(uint32_t *t1, wchar_t *t2)
{
    int i;
    for (i = 0 ;  ; i++) {
        if(t1[i] != t2[i])
            return 1;
        else if (t1[i] == t2[i] && t1[i] == 0)
            break;
    }
    return 0;
}


int find_word();

#include "ui.h"

/*
d8a7 d884 alif lam
*/

key_t key_table[KEYS] = {
    {'a', {0xd8,0xb6}, SDLK_a},
    {'b', {0xd8,0xa7}, SDLK_b},
    {'c', {0xd8,0xa4}, SDLK_c},
    {'d', {0xd9,0x8a}, SDLK_d},
    {'e', {0xd8,0xab}, SDLK_e},
    {'f', {0xd8,0xa8}, SDLK_f},
    {'g', {0xd9,0x84}, SDLK_g},
    {'h', {0xd8,0xa7}, SDLK_h},
    {'i', {0xd9,0x87}, SDLK_i},
    {'j', {0xd8,0xaa}, SDLK_j},
    {'k', {0xd9,0x86}, SDLK_k},
    {'l', {0xd9,0x85}, SDLK_l},
    {'m', {0xd9,0x83}, SDLK_m},
    {'n', {0xd9,0x89}, SDLK_n},
    {'o', {0xd8,0xae}, SDLK_o},
    {'p', {0xd8,0xad}, SDLK_p},
    {'q', {0xd8,0xb4}, SDLK_q},
    {'r', {0xd9,0x82}, SDLK_r},
    {'s', {0xd8,0xb3}, SDLK_s},
    {'t', {0xd9,0x81}, SDLK_t},
    {'u', {0xd8,0xb9}, SDLK_u},
    {'v', {0xd8,0xb1}, SDLK_v},
    {'w', {0xd8,0xa6}, SDLK_w},
    {'x', {0xd8,0xa1}, SDLK_x},
    {'y', {0xd8,0xba}, SDLK_y},
    {'z', {0xd8,0xb5}, SDLK_z},
    {'_', {0xd8,0xb0}, SDLK_8},
    {'-', {0xd8,0x00}, SDLK_6},
    {'\'', {0xd8,0x00}, SDLK_4},
    {' ', {0x20}, SDLK_SPACE},
    {'^', {0xd8,0xac}, SDLK_CARET},
    {'$', {0xd8,0xaf}, SDLK_DOLLAR},
    {'%', {0xd8,0xb7}, 249},//%
    {'*', {0xd8,0xb0}, SDLK_ASTERISK},
    {',', {0xd8,0xa9}, SDLK_COMMA},
    {';', {0xd9,0x88}, SDLK_SEMICOLON},
    {':', {0xd8,0xb8}, SDLK_COLON},
    {'!', {0xd8,0xb2}, SDLK_EXCLAIM}

};

int find_word() {
    int x = 0;
    x = input_box.text[input_box.line_pos].utfs;
    lauch_seach(input_box.text[input_box.line_pos].in_utf, x);
    //wave = Mix_LoadWAV("good.mp3");
    //Mix_PlayChannel(-1, wave, 0);
    int i = 0;
    for (i = 0 ; i < 15 ; i++) {
        wcscpy(quiz_box.text[i], buff[buff_i-1-13+i]);
    }
}


int main(int argc, char**args)
{

    //demmarer sdl2
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);

    //initialiser l'affichage du texte et choix police
    TTF_Init();

    //initialiser audio
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 2048 );

    //contruire une fenêtre
    window = SDL_CreateWindow( "QURAN BAHIT", 500, 300, 640, 480, 0 );
    Uint32 flag = 0;
    SDL_SetWindowFullscreen(window, flag);

    //création de l'ecran de dessin dans la fenêtre
    renderer = SDL_CreateRenderer( window, -1, 0 );
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );


    init_ui();
    

    int loop = 1;
    int i = 0;
    int ret = 0;

    while ( loop )
    {
        //efface l'ecran de dessin avec le noir (r,v,b,a) a = alpha la transparence
        SDL_SetRenderDrawColor( renderer,0,0,0,255);
        SDL_RenderClear( renderer );

        //entrée de clavier
        while ( SDL_PollEvent( &event ) ) {
            if ( event.type == SDL_QUIT) {                
                    loop = 0;
            } else if ( event.type == SDL_KEYDOWN ) {
                //cout << event.key.keysym.sym << endl;
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    loop = 0;
                }
                if (event.key.keysym.sym == SDLK_RETURN) {
/*                  static int once = 1;
                    if (!once)
                    {
                        input_box_clean_lines();
                        once = 1;
                    } else { */
                    wchar_t bbbt[80];
                    wstrcpy((uint32_t*)input_box.text[0].in_utf, (wchar_t*)bbbt, input_box.text[0].utfs);
                    wcscpy(query, bbbt);
                    find_word();
                    //input_box_clean_lines();
                    //}
                }
                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                    step_back();
                    //input_box.text[input_box.line_pos][input_box.cursor_pos] = 0;
                }

                if (event.key.keysym.sym == SDLK_DELETE) {
                    input_box_clean_lines();
                }
                if (event.key.keysym.sym == SDLK_DOWN) {
/*                    if (input_box.line_pos < 2) {        
                        input_box.cursor_pos = input_box.line_pos*50;
                        input_box.line_pos++;
                    }*/
                }

                for (i = 0 ; i < KEYS ; i++) {
                    if (event.key.keysym.sym == key_table[i].code) {
    /*                  static int once = 1;
                        if (!once) {
                            input_box_clean_lines();
                            once = 1;
                        }*/
                        input_box_append_letter(key_table[i].hexcode);
                        wave = Mix_LoadWAV("key.mp3");
                        Mix_PlayChannel(-1, wave, 0);

                    }
                }


            }
        }
        update_ui();

        draw_ui();

        //affiche l'ecran de dessin sur la fenetre
        SDL_RenderPresent(renderer);

        //pause x millisecondes avant de recommencer la boucle "while"
        SDL_Delay(32);
    }

    //quand on quitte le programme (la boucle while) on detruit ce qu'on a crée
    //pour éviter les fuites de mémoire sur l'ordinateur
    Mix_FreeChunk(wave);
    Mix_FreeMusic(music);
    free_ui();
    Mix_CloseAudio();
    TTF_Quit();
    SDL_Quit();

}