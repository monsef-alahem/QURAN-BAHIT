/*************************************
 *  QURAN BAHIT
 *  AUTHOR  :   alahem monsef
 *  EMAIL   :   m.alahem09@gmail.com
 *  VERSION :   __
 *  DATE    :   11-may-2019
 *
 *************************************/

int color_switcher(int &x, int &y, int &z)
{
    static char state = 0;
    static char mem_state = 0;
    static int wait = 300;
    //orange
    if (state == 0) {
        x++;
        if (x > 253)
            state = 1;
    //rouge
    } else if (state == 1) {
        z--;
        if (z < 6) {
            mem_state = 2;
            state = 6;
        }
    //jaune
    } else if (state == 2) {
        y++;
        if (y > 254)
            state = 3;
    //vert
    } else if (state == 3) {
        x--;
        if (x < 6) {
            mem_state = 4;
            state = 6;
        }
    //cyan
    } else if (state == 4) {
        z++;
        if (z > 254)
            state = 5;
    //bleu
    } else if (state == 5) {
        y--;
        if (y < 6) {
            mem_state = 0;
            state = 6;
        }
    //wait
    } else {
        wait--;
        if (wait == 0) {
            wait = 300;
            state = mem_state;
        }
    }
    /* else {
        x++;
        if (x > 254)
            state = 0;
    }*/
}

//title
SDL_Texture* title_tex;
SDL_Surface* title_sur;

//message label
TTF_Font* msg_lbl_font;
SDL_Surface* msg_lbl_sur;
SDL_Texture* msg_lbl_tex;
SDL_Rect msg_lbl_rec = {13,270,0,0};


int init_hud()
{
    msg_lbl_font = TTF_OpenFont("arial.ttf", 25);

    //title
    title_sur = IMG_Load("title.png");
    title_tex = SDL_CreateTextureFromSurface(renderer, title_sur);

}

int update_hud()
{
    int w,h,i;
    // message notification
    static wchar_t wtext[30] = L"";
    SDL_Color text_color = {255,0,0};
/*    text_color.r = 255;
    text_color.g = 0;
    text_color.b = 0;*/

    //swprintf(wtext, 30, L"%c : \ufed1\ufead\ufea4\ufedf\ufe8d \ufe90\ufe98\ufedb\ufe8d", chr);
    msg_lbl_sur = TTF_RenderUNICODE_Solid(msg_lbl_font, (Uint16*)wtext, text_color);
    msg_lbl_tex = SDL_CreateTextureFromSurface(renderer, msg_lbl_sur);
    SDL_FreeSurface(msg_lbl_sur);
    SDL_QueryTexture(msg_lbl_tex, NULL, NULL, &w, &h);
    msg_lbl_rec.w = w;
    msg_lbl_rec.h = h;

}

int draw_hud()
{
    int w,h,i;
    SDL_Rect rect1, rect2;

    //message label text
    SDL_RenderCopy(renderer, msg_lbl_tex, NULL, &msg_lbl_rec);

    //title
    static int x = 5, y = 5, z = 255;


    color_switcher(x, y, z);
    color_switcher(x, y, z);
    color_switcher(x, y, z);
    color_switcher(x, y, z);
    color_switcher(x, y, z);
    color_switcher(x, y, z);

/*    if (state == 0) {
        x--;
        y++;
        if (y >= 255)
            state = 1;
    } else if (state == 1) {
        y--;
        z++;
        if (z >= 255)
            state = 2;
    } else {
        z--;
        x++;
        if (x >= 255)
            state = 0;
    }*/
    
    //printf("state : %d %d %d\n",x,y,z);
    change_pixel(title_sur,x,y,z,255);
    title_tex = SDL_CreateTextureFromSurface(renderer, title_sur);
    SDL_QueryTexture(title_tex, NULL, NULL, &w, &h);
    rect1 = (SDL_Rect){0,0,w,h};
    rect2 = (SDL_Rect){80,10,w,h};
    SDL_RenderCopy(renderer, title_tex, &rect1, &rect2);

    SDL_Rect rec = {13,10,50,50};
    SDL_SetRenderDrawColor( renderer,x,y,z,255); 
    SDL_RenderFillRect( renderer, &rec);

    SDL_Rect rec2 = {573,10,50,50}; 
    SDL_RenderFillRect( renderer, &rec2);


}
int free_hud()
{

    //message label 
    SDL_DestroyTexture(msg_lbl_tex);
    //SDL_FreeSurface(msg_lbl_sur);
    
    //title
    SDL_DestroyTexture(title_tex);
    //SDL_FreeSurface(title_sur);

    TTF_CloseFont(msg_lbl_font);
}