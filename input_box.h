/*************************************
 *  QURAN BAHIT
 *  AUTHOR  :   alahem monsef
 *  EMAIL   :   m.alahem09@gmail.com
 *  VERSION :   __
 *  DATE    :   11-may-2019
 *
 *************************************/
#define INPUT_LINE_LEN 50
typedef struct text_box_t {
    rgba_t col;
    rgba_t brd_col;
    int brd_tick;
    SDL_Rect rec;
    arab_line_t text[3];
    text_line_t line[3];
    SDL_Rect txt_cursor;
    int cursor_pos;
    int chr_pos;
    int line_pos;
    TTF_Font* font;
    int font_size;
    int len[3];
}text_box_t;


//place to declare struct

text_box_t input_box = {
    {0,255,240,255},
    {0,255,100,255},
    10,
    //{20,340,600,120},
    {20,80,600,50},
    {NULL,NULL,NULL},
    {
    NULL,NULL,{30,90,370,190},
    NULL,NULL,{30,90+30,370,190},
    NULL,NULL,{30,90+60,370,190}
    },
    {8,20,10,20},
    0,
    0,
    0,
    NULL,
    20,
    {0,0,0}
};

//utilities
int input_box_clean_lines()
{
    int i = 0;
    input_box.line_pos = 0;
    input_box.cursor_pos = 0;
    input_box.chr_pos = 0;
    for (i=0;i<3;i++){
        wmemset((wchar_t*)input_box.text[i].in_utf,0x0000,150);
        memset((wchar_t*)input_box.text[i].in_byte,0x0000,150);
        input_box.text[i].utfs = 0;
        input_box.text[i].bytes = 0;
        input_box.len[i] = 0;
    }
}

int step_back()
{
    if (input_box.chr_pos < 1)
        return 1;
    unsigned char c = input_box.text[input_box.line_pos].in_byte[input_box.chr_pos];
    if (c == 0x20) {
        input_box.text[input_box.line_pos].in_byte[input_box.chr_pos] = 0;
        input_box.chr_pos--;
        input_box.text[i].bytes--;
    } else {           
        input_box.text[input_box.line_pos].in_byte[input_box.chr_pos] = 0;
        input_box.chr_pos--;
        input_box.text[i].bytes--;
        input_box.text[input_box.line_pos].in_byte[input_box.chr_pos] = 0;
        input_box.chr_pos--;
        input_box.text[i].bytes--;
    }

    input_box.cursor_pos--;
    input_box.len[input_box.line_pos]--;
    
    input_box.text[input_box.line_pos].utfs = input_box.len[input_box.line_pos]*4;

    get_presentation_form_b(&input_box.text[input_box.line_pos]);
    reverse_line(&input_box.text[input_box.line_pos]);
    correct(&input_box.text[input_box.line_pos]);
}

int input_box_append_letter(unsigned char *c)
{
    if (input_box.line_pos < 2) {
        if (c[0] == 0x20) {
            input_box.text[input_box.line_pos].in_byte[input_box.chr_pos] = c[0];
            input_box.chr_pos++;
        } else {           
            input_box.text[input_box.line_pos].in_byte[input_box.chr_pos] = c[0];
            input_box.chr_pos++;
            input_box.text[input_box.line_pos].in_byte[input_box.chr_pos] = c[1];
            input_box.chr_pos++;
        }
        input_box.len[input_box.line_pos]++;
        input_box.cursor_pos++;
        if (input_box.cursor_pos == INPUT_LINE_LEN-1) {
            input_box.line_pos++;
            input_box.cursor_pos = 0;
            return 1;
        }
    }
    if (input_box.line_pos == 2) {
        //input_box.text[input_box.line_pos].in_byte[((input_box.cursor_pos+1)*2)-2] = c[0]; //0=0 1=2
        //input_box.text[input_box.line_pos].in_byte[((input_box.cursor_pos+1)*2)-1] = c[1]; //0=1 1=3
        if (input_box.cursor_pos < INPUT_LINE_LEN-1)
            input_box.cursor_pos++;
    }

    //input_box.text[input_box.line_pos].in_utf[0] = 0xfeb9;
    //input_box.text[input_box.line_pos].in_utf[1] = 0xfebf;

    //input_box.text[input_box.line_pos].bytes = ((input_box.cursor_pos+1)*2)-2;
    input_box.text[input_box.line_pos].bytes = input_box.chr_pos;
    input_box.text[input_box.line_pos].in_utf[0] = 0;
    //input_box.text[input_box.line_pos].in_utf[input_box.cursor_pos] = 0xfeeb;
    input_box.text[input_box.line_pos].utfs = input_box.len[input_box.line_pos]*4;

    get_presentation_form_b(&input_box.text[input_box.line_pos]);
    reverse_line(&input_box.text[input_box.line_pos]);
    correct(&input_box.text[input_box.line_pos]);
}
/*
int input_box_append_letter(unsigned char *c)
{
    static int i;
    tt[i] = 0xfeeb;
    i++;
}

*/

void init_input_box()
{
    input_box.font = TTF_OpenFont("arial.ttf", input_box.font_size);
    int i = 0;
    for (i=0;i<3;i++) {
        SDL_Color text_color = {0, 255, 240};
    }
}


void update_input_box()
{
    //update graphics
    int i,w,h = 0;

    //uint32_t text[16]= {0xfeeb};
    //wchar_t text[16]= L"Hello World!";
    //input_box.text[input_box.line_pos].in_utf[0] = 0xfeeb;
    //input_box.text[input_box.line_pos].in_utf[1] = 0xfeeb;
/*input_box.text[input_box.line_pos].in_utf[0] = 0xfeec;
input_box.text[input_box.line_pos].in_utf[1] = 0xfeeb;
input_box.text[input_box.line_pos].in_utf[2] = 0xfeeb;
input_box.text[input_box.line_pos].in_utf[3] = 0;*/
                            /*printf("%x\n", input_box.text[input_box.line_pos].in_utf[0]);
                            printf("%x\n", input_box.text[input_box.line_pos].in_utf[1]);
                            printf("%x\n", input_box.text[input_box.line_pos].in_utf[2]);
                            printf("%x\n", input_box.text[input_box.line_pos].in_utf[3]);
                            printf("%x\n", input_box.text[input_box.line_pos].in_utf[4]);
                            printf("%x\n", input_box.text[input_box.line_pos].in_utf[5]);
                            printf("%x\n\n", input_box.text[input_box.line_pos].in_utf[6]);*/
//printf("%x\n", input_box.text[input_box.line_pos].in_byte[0]);
//printf("%x\n", input_box.text[input_box.line_pos].in_byte[1]);
    //printf("%x\n", input_box.text[input_box.line_pos].in_utf[0]);
    //printf("%x\n", input_box.text[input_box.line_pos].in_utf[1]);
    wchar_t bbbt[1000];//= L"\ufeef\ufeed\ufe98\ufeb4\ufee4\ufedf\ufe8d \ufe94\ufef3\ufe8e\ufeec\ufee7";

    
    for (i=0;i<3;i++) {
        SDL_Color text_color = {255,255,255};
        //input_box.line[i].sur = TTF_RenderUTF8_Solid(input_box.font, text, text_color);
    wstrcpy((uint32_t*)input_box.text[i].in_utf, (wchar_t*)bbbt, input_box.text[i].utfs);
    input_box.line[i].sur = TTF_RenderUNICODE_Solid(input_box.font, (Uint16*)bbbt, text_color);
    //input_box.line[i].sur = TTF_RenderUNICODE_Solid(input_box.font, (Uint16*)tt, text_color);
//input_box.line[i].sur = TTF_RenderUNICODE_Solid(input_box.font, (Uint16*)text, text_color);
        //input_box.line[i].sur = TTF_RenderText_Solid(input_box.font, input_box.text[i], text_color);
        SDL_DestroyTexture(input_box.line[i].tex);
        input_box.line[i].tex = SDL_CreateTextureFromSurface(renderer, input_box.line[i].sur);
        SDL_FreeSurface(input_box.line[i].sur);
        SDL_QueryTexture(input_box.line[i].tex, NULL, NULL, &w, &h);
        input_box.line[i].rec.w = w;
        input_box.line[i].rec.h = h;
    }

    //update cursor position
    input_box.txt_cursor.x = 30 + w;
    input_box.txt_cursor.y = 350 + input_box.line_pos*30;

    //correction of cursor pos bug
    if (input_box.cursor_pos == 0)
        input_box.txt_cursor.x = 10 + 30;

}

void draw_input_box()
{
    //draw border
    SDL_Rect border = {
        input_box.rec.x-input_box.brd_tick/2,
        input_box.rec.y-input_box.brd_tick/2,
        input_box.rec.w+input_box.brd_tick,
        input_box.rec.h+input_box.brd_tick};
    SDL_SetRenderDrawColor( renderer,255,255,0,120); 
    SDL_RenderFillRect( renderer, &border);
    
    //draw input box background rectangle
    SDL_SetRenderDrawColor( renderer,0,0,0,255); 
    SDL_RenderFillRect( renderer, &input_box.rec);

    //draw text
    SDL_SetRenderDrawColor( renderer,
        0,255,100,255
    ); 
    int i;
    for (i = 0;i<3;i++) {     
        SDL_RenderCopy(renderer, input_box.line[i].tex, NULL, (&input_box.line[i].rec));
    }

    if (SDL_GetTicks()/500 % 2 == 0) {
        SDL_SetRenderDrawColor( renderer,255,255,0,255); 
        SDL_RenderFillRect( renderer, &input_box.txt_cursor);
    }

}

void free_input_box()
{
    int i;
    for (i = 0;i < 3;i++) { 
        SDL_DestroyTexture(input_box.line[i].tex);
        //SDL_FreeSurface(input_box.line[i].sur);
    }
    TTF_CloseFont(input_box.font);
}