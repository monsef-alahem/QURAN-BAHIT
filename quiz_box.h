/*************************************
 *  QURAN BAHIT
 *  AUTHOR  :   alahem monsef
 *  EMAIL   :   m.alahem09@gmail.com
 *  VERSION :   __
 *  DATE    :   11-may-2019
 *
 *************************************/
#define CHAT_LINE_LEN 50
#define CHAT_LINES 20
typedef struct quiz_box_t {
    rgba_t col;
    rgba_t brd_col;
    int brd_tick;
    SDL_Rect rec;
    wchar_t text[CHAT_LINES][CHAT_LINE_LEN];
    text_line_t line[CHAT_LINES];
    int cursor_pos;
    int line_pos;
    TTF_Font* font;
    int font_size;
} quiz_box_t;


//place to declare struct
quiz_box_t quiz_box = {
    {0,255,240,255},
    {0,255,100,255},
    10,
    //{20,100,600,150},
    {20,150,600,310},
    {L"",L"",L""},
    {NULL},
    0,
    0,
    NULL,
    20
};

//utilities
int quiz_box_clean_lines()
{
    int i = 0;
    quiz_box.line_pos = 0;
    quiz_box.cursor_pos = 0;
    for (i=0;i<CHAT_LINES;i++)
        wmemset(quiz_box.text[i],0,CHAT_LINE_LEN);
}

void init_quiz_box()
{
    quiz_box.font = TTF_OpenFont("arial.ttf", quiz_box.font_size);
    int i = 0;
    for (i=0;i<CHAT_LINES;i++) {
        SDL_Color text_color = {0,255,100};
        quiz_box.line[i].rec = (SDL_Rect){quiz_box.rec.x+10,(quiz_box.rec.y)+(i * 20),quiz_box.rec.w,quiz_box.rec.h};
    }
}


void update_quiz_box()
{
    //update graphics
    int i,w,h = 0;
    for (i=0;i<CHAT_LINES;i++) {
        SDL_Color text_color = {0,255,100};
        quiz_box.line[i].sur = TTF_RenderUNICODE_Solid(quiz_box.font, (Uint16 *)quiz_box.text[i], text_color);
        SDL_DestroyTexture(quiz_box.line[i].tex);
        quiz_box.line[i].tex = SDL_CreateTextureFromSurface(renderer, quiz_box.line[i].sur);
        SDL_FreeSurface(quiz_box.line[i].sur);
        SDL_QueryTexture(quiz_box.line[i].tex, NULL, NULL, &w, &h);
        quiz_box.line[i].rec.w = w;
        quiz_box.line[i].rec.h = h;
    }

}

void draw_quiz_box()
{
    //draw border
    SDL_Rect border = {
        quiz_box.rec.x-quiz_box.brd_tick/2,
        quiz_box.rec.y-quiz_box.brd_tick/2,
        quiz_box.rec.w+quiz_box.brd_tick,
        quiz_box.rec.h+quiz_box.brd_tick};
    SDL_SetRenderDrawColor( renderer,0,255,100,255); 
    SDL_RenderFillRect( renderer, &border);

/*    SDL_Rect rect = {73,10,490,50};
    SDL_SetRenderDrawColor( renderer,0,255,100,255); 
    SDL_RenderFillRect( renderer, &rect);*/
    
    //draw box background rectangle
    SDL_SetRenderDrawColor( renderer,0,0,0,255); 
    SDL_RenderFillRect( renderer, &quiz_box.rec);

    //draw text
    SDL_SetRenderDrawColor( renderer,0,255,100,255); 
    int i;
    for (i = 0;i<CHAT_LINES;i++) {     
        SDL_RenderCopy(renderer, quiz_box.line[i].tex, NULL, (&quiz_box.line[i].rec));
    }

}

void free_quiz_box()
{
    int i;
    for (i = 0;i < CHAT_LINES;i++) { 
        SDL_DestroyTexture(quiz_box.line[i].tex);
        //SDL_FreeSurface(quiz_box.line[i].sur);
    }
    TTF_CloseFont(quiz_box.font);
}