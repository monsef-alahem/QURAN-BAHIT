/*************************************
 *  QURAN BAHIT
 *  AUTHOR  :   alahem monsef
 *  EMAIL   :   m.alahem09@gmail.com
 *  VERSION :   __
 *  DATE    :   11-may-2019
 *
 *************************************/

#include <iostream>
//#include <cstdlib>
#include <string>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

wchar_t keytoutf[120][2] =
{
    //dad
    {'a', 0xfebd},
    {'a', 0xfebe},
    {'a', 0xfebf},
    {'a', 0xfec0},
    //waw hamza
    {'c', 0xfe85},
    {'c', 0xfe86},
    //yaa
    {'d', 0xfef1},
    {'d', 0xfef2},
    {'d', 0xfef3},
    {'d', 0xfef4},
    //tha
    {'e', 0xfe99},
    {'e', 0xfe9a},
    {'e', 0xfe9b},
    {'e', 0xfe9c},
    //baa
    {'f', 0xfe8f},
    {'f', 0xfe90},
    {'f', 0xfe91},
    {'f', 0xfe92},
    //lam
    {'g', 0xfedd},
    {'g', 0xfede},
    {'g', 0xfedf},
    {'g', 0xfee0},
    //alif
    {'h', 0xfefb},
    {'h', 0xfefc},
    {'h', 0xfe8d},
    {'h', 0xfe8d},
    //haa
    {'i', 0xfee9},
    {'i', 0xfeea},
    {'i', 0xfeeb},
    {'i', 0xfeec},
    //taa
    {'j', 0xfe95},
    {'j', 0xfe96},
    {'j', 0xfe97},
    {'j', 0xfe98},
    //noon
    {'k', 0xfee5},
    {'k', 0xfee6},
    {'k', 0xfee7},
    {'k', 0xfee8},
    //mim
    {'l', 0xfee1},
    {'l', 0xfee2},
    {'l', 0xfee3},
    {'l', 0xfee4},
    //kaf
    {'m', 0xfed9},
    {'m', 0xfeda},
    {'m', 0xfedb},
    {'m', 0xfedc},
    //alif maqsoura
    {'n', 0xfeef},
    {'n', 0xfef0},
    //khaa
    {'o', 0xfea5},
    {'o', 0xfea6},
    {'o', 0xfea7},
    {'o', 0xfea8},
    //hhaa
    {'p', 0xfea1},
    {'p', 0xfea2},
    {'p', 0xfea3},
    {'p', 0xfea4},
    //shin
    {'q', 0xfeb5},
    {'q', 0xfeb6},
    {'q', 0xfeb7},
    {'q', 0xfeb8},
    //qaf
    {'r', 0xfed5},
    {'r', 0xfed6},
    {'r', 0xfed7},
    {'r', 0xfed8},
    //sin
    {'s', 0xfeb1},
    {'s', 0xfeb2},
    {'s', 0xfeb3},
    {'s', 0xfeb4},
    //faa
    {'t', 0xfed1},
    {'t', 0xfed2},
    {'t', 0xfed3},
    {'t', 0xfed4},
    //ain
    {'u', 0xfec9},
    {'u', 0xfeca},
    {'u', 0xfecb},
    {'u', 0xfecc},
    //raa
    {'v', 0xfead},
    {'v', 0xfeae},
    //alif maqsoura hamza
    {'w', 0xfe89},
    {'w', 0xfe8a},
    {'w', 0xfe8b},
    {'w', 0xfe8c},
    //hamza
    {'x', 0xfe80},
    //ghain
    {'y', 0xfecd},
    {'y', 0xfece},
    {'y', 0xfecf},
    {'y', 0xfed0},
    //sad
    {'z', 0xfeb9},
    {'z', 0xfeba},
    {'z', 0xfebb},
    {'z', 0xfebc},
    //space
    {' ', 0x20},
    //jim
    {'^', 0xfe9d},
    {'^', 0xfe9e},
    {'^', 0xfe9f},
    {'^', 0xfea0},
    //dal
    {'$', 0xfea9},
    {'$', 0xfeaa},
    //tah
    {'%', 0xfec1},
    {'%', 0xfec2},
    {'%', 0xfec3},
    {'%', 0xfec4},
    //dhal
    {'*', 0xfeab},
    {'*', 0xfeac},
    //taa marbouta
    {',', 0xfe93},
    {',', 0xfe94},
    //waw
    {';', 0xfeed},
    {';', 0xfeee},
    //thah
    {':', 0xfeb5},
    {':', 0xfeb6},
    {':', 0xfeb7},
    {':', 0xfeb8},
    //zayn
    {'!', 0xfeaf},
    {'!', 0xfeb0}
};


wchar_t* name_soura(int soura)
//std::wstring soura_name_gen(int soura)
{
    switch (soura)
    {

   case 114:
       return L"\ufeb1\ufe8e\ufee8\ufedf\ufe8d";
       break;
   case 113:
       return L"\ufed5\ufee0\ufed4\ufedf\ufe8d";
       break;
   case 112:
       return L"\ufeb9\ufefc\ufea7\ufef9\ufe8d";
       break;
   case 111:
       return L"\ufea9\ufeb4\ufee4\ufedf\ufe8d";
       break;
   case 110:
       return L"\ufead\ufebc\ufee8\ufedf\ufe8d";
       break;
   case 109:
       return L"\ufee5\ufeed\ufead\ufed3\ufe8e\ufedc\ufedf\ufe8d";
       break;
   case 108:
       return L"\ufead\ufe9b\ufeed\ufedc\ufedf\ufe8d";
       break;
   case 107:
       return L"\ufee5\ufeed\ufecb\ufe8e\ufee4\ufedf\ufe8d";
       break;
   case 106:
       return L"\ufeb5\ufef3\ufead\ufed7";
       break;
   case 105:
       return L"\ufedd\ufef4\ufed4\ufedf\ufe8d";
       break;
   case 104:
       return L"\ufe93\ufeaf\ufee4\ufeec\ufedf\ufe8d";
       break;
   case 103:
       return L"\ufead\ufebc\ufecc\ufedf\ufe8d";
       break;
   case 102:
       return L"\ufead\ufe9b\ufe8e\ufedc\ufe98\ufedf\ufe8d";
       break;
   case 101:
       return L"\ufe94\ufecb\ufead\ufe8e\ufed8\ufedf\ufe8d";
       break;
   case 100:
       return L"\ufe95\ufe8e\ufef3\ufea9\ufe8e\ufecc\ufedf\ufe8d";
       break;
   case 99:
       return L"\ufe94\ufedf\ufeaf\ufedf\ufeaf\ufedf\ufe8d";
       break;
   case 98:
       return L"\ufe94\ufee8\ufef4\ufe92\ufedf\ufe8d";
       break;
   case 97:
       return L"\ufead\ufea9\ufed8\ufedf\ufe8d";
       break;
   case 96:
       return L"\ufed5\ufee0\ufecc\ufedf\ufe8d";
       break;
   case 95:
       return L"\ufee5\ufef4\ufe98\ufedf\ufe8d";
       break;
   case 94:
       return L"\ufea1\ufead\ufeb8\ufedf\ufe8d";
       break;
   case 93:
       return L"\ufef0\ufea4\ufec0\ufedf\ufe8d";
       break;
   case 92:
       return L"\ufedd\ufef4\ufee0\ufedf\ufe8d";
       break;
   case 91:
       return L"\ufeb1\ufee4\ufeb8\ufedf\ufe8d";
       break;
   case 90:
       return L"\ufea9\ufee0\ufe92\ufedf\ufe8d";
       break;
   case 89:
       return L"\ufead\ufea0\ufed4\ufedf\ufe8d";
       break;
   case 88:
       return L"\ufe94\ufef4\ufeb7\ufe8e\ufed0\ufedf\ufe8d";
       break;
   case 87:
       return L"\ufef0\ufee0\ufecb\ufef7\ufe8d";
       break;
   case 86:
       return L"\ufed5\ufead\ufe8e\ufec1\ufedf\ufe8d";
       break;
   case 85:
       return L"\ufe9d\ufeed\ufead\ufe92\ufedf\ufe8d";
       break;
   case 84:
       return L"\ufed5\ufe8e\ufed8\ufeb8\ufee7\ufef9\ufe8d";
       break;
   case 83:
       return L"\ufee5\ufef4\ufed4\ufed4\ufec1\ufee4\ufedf\ufe8d";
       break;
   case 82:
       return L"\ufead\ufe8e\ufec1\ufed4\ufee7\ufef9\ufe8d";
       break;
   case 81:
       return L"\ufead\ufef3\ufeed\ufedc\ufe98\ufedf\ufe8d";
       break;
   case 80:
       return L"\ufeb1\ufe92\ufecb";
       break;
   case 79:
       return L"\ufe95\ufe8e\ufecb\ufeaf\ufe8e\ufee8\ufedf\ufe8d";
       break;
   case 78:
       return L"\ufe88\ufe92\ufee8\ufedf\ufe8d";
       break;
   case 77:
       return L"\ufe95\ufefc\ufeb3\ufead\ufee4\ufedf\ufe8d";
       break;
   case 76:
       return L"\ufee5\ufe8e\ufeb4\ufee7\ufef9\ufe8d";
       break;
   case 75:
       return L"\ufe94\ufee3\ufe8e\ufef4\ufed8\ufedf\ufe8d";
       break;
   case 74:
       return L"\ufead\ufe9b\ufea9\ufee4\ufedf\ufe8d";
       break;
   case 73:
       return L"\ufedd\ufee3\ufeaf\ufee4\ufedf\ufe8d";
       break;
   case 72:
       return L"\ufee5\ufea0\ufedf\ufe8d";
       break;
   case 71:
       return L"\ufea1\ufeed\ufee7";
       break;
   case 70:
       return L"\ufe9d\ufead\ufe8e\ufecc\ufee4\ufedf\ufe8d";
       break;
   case 69:
       return L"\ufe94\ufed7\ufe8e\ufea4\ufedf\ufe8d";
       break;
   case 68:
       return L"\ufee1\ufee0\ufed8\ufedf\ufe8d";
       break;
   case 67:
       return L"\ufed9\ufee0\ufee4\ufedf\ufe8d";
       break;
   case 66:
       return L"\ufee1\ufef3\ufead\ufea4\ufe98\ufedf\ufe8d";
       break;
   case 65:
       return L"\ufed5\ufefc\ufec1\ufedf\ufe8d";
       break;
   case 64:
       return L"\ufee5\ufe91\ufe8e\ufed0\ufe98\ufedf\ufe8d";
       break;
   case 63:
       return L"\ufee5\ufeed\ufed8\ufed3\ufe8e\ufee8\ufee4\ufedf\ufe8d";
       break;
   case 62:
       return L"\ufe94\ufecc\ufee4\ufea0\ufedf\ufe8d";
       break;
   case 61:
       return L"\ufed1\ufebc\ufedf\ufe8d";
       break;
   case 60:
       return L"\ufe94\ufee8\ufea4\ufe98\ufee4\ufee4\ufedf\ufe8d";
       break;
   case 59:
       return L"\ufead\ufeb8\ufea4\ufedf\ufe8d";
       break;
   case 58:
       return L"\ufe94\ufedf\ufea9\ufe8e\ufea0\ufee4\ufedf\ufe8d";
       break;
   case 57:
       return L"\ufea9\ufef3\ufea9\ufea4\ufedf\ufe8d";
       break;
   case 56:
       return L"\ufe94\ufecc\ufed7\ufe8d\ufeed\ufedf\ufe8d";
       break;
   case 55:
       return L"\ufee5\ufe8e\ufee4\ufea3\ufead\ufedf\ufe8d";
       break;
   case 54:
       return L"\ufead\ufee4\ufed8\ufedf\ufe8d";
       break;
   case 53:
       return L"\ufee1\ufea0\ufee8\ufedf\ufe8d";
       break;
   case 52:
       return L"\ufead\ufeed\ufec1\ufedf\ufe8d";
       break;
   case 51:
       return L"\ufe95\ufe8e\ufef3\ufead\ufe8d\ufeab\ufedf\ufe8d";
       break;
   case 50:
       return L"\ufed5";
       break;
   case 49:
       return L"\ufe95\ufe8d\ufead\ufea0\ufea4\ufedf\ufe8d";
       break;
   case 48:
       return L"\ufea2\ufe98\ufed4\ufedf\ufe8d";
       break;
   case 47:
       return L"\ufea9\ufee4\ufea4\ufee3";
       break;
   case 46:
       return L"\ufed1\ufe8e\ufed8\ufea3\ufef7\ufe8d";
       break;
   case 45:
       return L"\ufe94\ufef4\ufe9b\ufe8e\ufea0\ufedf\ufe8d";
       break;
   case 44:
       return L"\ufee5\ufe8e\ufea7\ufeab\ufedf\ufe8d";
       break;
   case 43:
       return L"\ufed1\ufead\ufea7\ufeaf\ufedf\ufe8d";
       break;
   case 42:
       return L"\ufeef\ufead\ufeed\ufeb8\ufedf\ufe8d";
       break;
   case 41:
       return L"\ufe95\ufee0\ufebc\ufed3";
       break;
   case 40:
       return L"\ufead\ufed3\ufe8e\ufecf";
       break;
   case 39:
       return L"\ufead\ufee3\ufeaf\ufedf\ufe8d";
       break;
   case 38:
       return L"\ufeb9";
       break;
   case 37:
       return L"\ufe95\ufe8e\ufed3\ufe8e\ufebc\ufedf\ufe8d";
       break;
   case 36:
       return L"\ufeb1\ufef3";
       break;
   case 35:
       return L"\ufead\ufec1\ufe8e\ufed3";
       break;
   case 34:
       return L"\ufe84\ufe92\ufeb3";
       break;
   case 33:
       return L"\ufe8f\ufe8d\ufeaf\ufea3\ufef7\ufe8d";
       break;
   case 32:
       return L"\ufe93\ufea9\ufea0\ufeb4\ufedf\ufe8d";
       break;
   case 31:
       return L"\ufee5\ufe8e\ufee4\ufed8\ufedf";
       break;
   case 30:
       return L"\ufee1\ufeed\ufead\ufedf\ufe8d";
       break;
   case 29:
       return L"\ufe95\ufeed\ufe92\ufedc\ufee8\ufecc\ufedf\ufe8d";
       break;
   case 28:
       return L"\ufeb9\ufebc\ufed8\ufedf\ufe8d";
       break;
   case 27:
       return L"\ufedd\ufee4\ufee8\ufedf\ufe8d";
       break;
   case 26:
       return L"\ufe80\ufe8d\ufead\ufecc\ufeb8\ufedf\ufe8d";
       break;
   case 25:
       return L"\ufee5\ufe8e\ufed7\ufead\ufed4\ufedf\ufe8d";
       break;
   case 24:
       return L"\ufead\ufeed\ufee8\ufedf\ufe8d";
       break;
   case 23:
       return L"\ufee5\ufeed\ufee8\ufee3\ufe85\ufee4\ufedf\ufe8d";
       break;
   case 22:
       return L"\ufe9e\ufea4\ufedf\ufe8d";
       break;
   case 21:
       return L"\ufe80\ufe8e\ufef4\ufe92\ufee7\ufef7\ufe8d";
       break;
   case 20:
       return L"\ufeea\ufec1";
       break;
   case 19:
       return L"\ufee1\ufef3\ufead\ufee3";
       break;
   case 18:
       return L"\ufed1\ufeec\ufedc\ufedf\ufe8d";
       break;
   case 17:
       return L"\ufe80\ufe8d\ufead\ufeb3\ufef9\ufe8d";
       break;
   case 16:
       return L"\ufedd\ufea4\ufee8\ufedf\ufe8d";
       break;
   case 15:
       return L"\ufead\ufea0\ufea4\ufedf\ufe8d";
       break;
   case 14:
       return L"\ufee1\ufef4\ufeeb\ufe8d\ufead\ufe91\ufe87";
       break;
   case 13:
       return L"\ufea9\ufecb\ufead\ufedf\ufe8d";
       break;
   case 12:
       return L"\ufed1\ufeb3\ufeed\ufef3";
       break;
   case 11:
       return L"\ufea9\ufeed\ufeeb";
       break;
   case 10:
       return L"\ufeb1\ufee7\ufeed\ufef3";
       break;
   case 9:
       return L"\ufe94\ufe91\ufeed\ufe98\ufedf\ufe8d";
       break;
   case 8:
       return L"\ufedd\ufe8e\ufed4\ufee7\ufef7\ufe8d";
       break;
   case 7:
       return L"\ufed1\ufe8d\ufead\ufecb\ufef7\ufe8d";
       break;
   case 6:
       return L"\ufee1\ufe8e\ufecc\ufee7\ufef7\ufe8d";
       break;
   case 5:
       return L"\ufe93\ufea9\ufe8b\ufe8e\ufee4\ufedf\ufe8d";
       break;
   case 4:
       return L"\ufe80\ufe8e\ufeb4\ufee8\ufedf\ufe8d";
       break;
   case 3:
       return L"\ufee5\ufe8d\ufead\ufee4\ufecb\ufedd\ufe81";
       break;
   case 2:
       return L"\ufe93\ufead\ufed8\ufe92\ufedf\ufe8d";
       break;
   case 1:
       return L"\ufe94\ufea4\ufe97\ufe8e\ufed4\ufedf\ufe8d";
       break;
    }
}

//global variables
typedef struct arab_line_t {
    unsigned char in_byte[10000];
    size_t bytes;
    uint32_t in_utf[10000];
    size_t utfs;
} arab_line_t;

typedef struct arab_line_light_t {
    unsigned char in_byte[100];
    size_t bytes;
    uint32_t in_utf[50];
    size_t utfs;
} arab_line_light_t;

//arab_line_t quran_data[114][286];

int aya = 0;
int soura = 0;


//pointer variables


#include "utf8.h"
#include "arabtype.h"

using namespace std;

wchar_t get_key_from_utf(wchar_t wch)
{
    for (int i = 0 ; i < 100 ; i++) {
        if (keytoutf[i][1] == wch)
            return keytoutf[i][0];

    }
    return '?';
}

int read_line(arab_line_t *line, std::ifstream &ifs)
{
    //lecture du chiffre
    int i = 2;
    char aya_num[5] = "000";
    char soura_num[5] = "000";

    static int once = 0;
    //sauter des ratures sur le fichier
    if (!once) {
        ifs.get();
        ifs.get();
        ifs.get();
        once = 1;
    }

    //parse soura number
    while( ifs.good() ) {
        unsigned char ch = ifs.get();
        if (ch <= '9' && ch >= '0'){
            if(i == 2)
                soura_num[2] = ch;
            else if(i == 1) {
                soura_num[1] = soura_num[2];
                soura_num[2] = ch;
            } else {
                soura_num[0] = soura_num[1];
                soura_num[1] = soura_num[2];
                soura_num[2] = ch;
            }
        } else {
            break;
        }
        i--;
    }

    i = 2;
    //parse aya number
    while( ifs.good() ) {
        unsigned char ch = ifs.get();
        if (ch <= '9' && ch >= '0'){
            if(i == 2)
                aya_num[2] = ch;
            else if(i == 1) {
                aya_num[1] = aya_num[2];
                aya_num[2] = ch;
            } else {
                aya_num[0] = aya_num[1];
                aya_num[1] = aya_num[2];
                aya_num[2] = ch;
            }
        } else {
            break;
        }
        i--;
    }

    soura = atoi(soura_num);
    aya = atoi(aya_num);

    //printf("soura = %s\n", soura_num);
    //printf("aya = %s\n\n", aya_num);
    //printf("soura = %d\n", soura);
    //printf("aya = %d\n\n", aya);


    //lecture de l'arabe
    i=0;
    while( ifs.good() ) {
        unsigned char ch = ifs.get();
        if (ifs.good())
            line->in_byte[i] = ch;
        //printf("char = %c\n", ch);
        i++;
        if(ch == '\n')
            break;
    }
    line->bytes = i-1;
    line->in_utf[0] = 0;
    line->utfs = line->bytes*4;

}

int reverse_line(arab_line_t *line)
{
    uint32_t revsed_line[sizeof(line->in_utf)];
    int i;
    int j = line->utfs -1;
    //copier la ligne a inverser
    for (i = 0 ; i < line->utfs ; i++) {
        revsed_line[j] = line->in_utf[i];
        j--;
    }
    for (i = 0 ; i < line->utfs ; i++) {
        //printf("rev : %x\n", revsed_line[i]);
        line->in_utf[i] = revsed_line[i]; 
    }
}

/*int write_line(arab_line_t *line)
{
    static int is_beg = 1, is_end = 0;
    static int prev_soura = 1;

    if (soura == 114 && aya == 6)
        is_end = 1;

    if (prev_soura != soura) {
        prev_soura = soura;
        is_end = is_beg = 1;
    }

    if (is_end) {
        wofs.seekp(-3, std::ios_base::cur);
        wofs << "\n    },\n";
        is_end = 0;
    }
    
    if (is_beg) {
        wofs << "    {\n";
        is_beg = 0;   
    }


    //write line
    wofs << "       L\"";
    for( int i = 0; i < line->utfs; ++i ) {
        if (line->in_utf[i] == ' ') {
            wofs << " ";
        } else {
            wofs << "\\u" << std::hex << line->in_utf[i];
        }
    }
    wofs << "\",";

}*/

int correct(arab_line_t *line)
{
    for( int i = 0; i < line->utfs; i++ )
    {
        ///raaa
        if (line->in_utf[i] == 0xfeae)
            line->in_utf[i] = 0xfead;
        //dhaa
        if (line->in_utf[i] == 0xfec6)
            line->in_utf[i] = 0xfec5;
        ///baaa
        if (line->in_utf[i] == 0xfe90)
            line->in_utf[i] = 0xfe8f;
        ///zaaa
        if (line->in_utf[i] == 0xfeb0)
            line->in_utf[i] = 0xfeaf;
        ///fAA
        if (line->in_utf[i] == 0xfed2)
            line->in_utf[i] = 0xfed1;
        ///qaf
        if (line->in_utf[i] == 0xfed6)
            line->in_utf[i] = 0xfed5;
        ///lam
        if (line->in_utf[i] == 0xfeee)
            line->in_utf[i] = 0xfeed;
        ///lam AKHIR
        if (line->in_utf[i] == 0xfede)
            line->in_utf[i] = 0xfedd;
        ///noun
        if (line->in_utf[i] == 0xfee6)
            line->in_utf[i] = 0xfee5;
        ///waw
        if (line->in_utf[i] == 0xfeee)
            line->in_utf[i] = 0xfeed;
        ///dal
        if (line->in_utf[i] == 0xfeaa)
            line->in_utf[i] = 0xfea9;
        ///dhal
        if (line->in_utf[i] == 0xfeac)
            line->in_utf[i] = 0xfeab;
        ///sin
        if (line->in_utf[i] == 0xfeb2)
            line->in_utf[i] = 0xfeb1;
        ///shin
        if (line->in_utf[i] == 0xfeb6)
            line->in_utf[i] = 0xfeb5;
        ///kaf
        if (line->in_utf[i] == 0xfeda)
            line->in_utf[i] = 0xfed9;
        ///mim
        if (line->in_utf[i] == 0xfee2)
            line->in_utf[i] = 0xfee1;
        ///TA FLAWL
        if (line->in_utf[i] == 0xfec3)
            line->in_utf[i] = 0xfec1;
        ///TA
        if (line->in_utf[i] == 0xfec4)
            line->in_utf[i] = 0xfec1;
        ///SAD
        if (line->in_utf[i] == 0xfeba)
            line->in_utf[i] = 0xfeb9;
        ///TA2
        if (line->in_utf[i] == 0xfe96)
            line->in_utf[i] = 0xfe95;
        ///HAMZA WAW
        if (line->in_utf[i] == 0xfe86)
            line->in_utf[i] = 0xfe85;
        ///HAMZA dadh
        if (line->in_utf[i] == 0xfec7)
            line->in_utf[i] = 0xfec5;

    }
}

int count_lines(std::ifstream &ifs)
{
    int lines = 0;
    std::string str;
    while (! ifs.eof() ) {
        getline (ifs,str);
        if(str[0] == '*')
            break;
        lines++;
    }
    ifs.seekg (0, ifs.beg);
    return lines;
}

int is_text_match(uint32_t *text, uint32_t *text2, int size)
{
    for (int i = 0 ; i < size ; i++) {
        //printf("1 : %x\n", text[i]);
        //printf("2 : %x\n\n", text2[i]);
        if (text[i] != text2[i])
            return 0;
    }
    printf("found in soura %d aya %d\n", soura, aya);
    swprintf(buff[buff_i],50, L"found in soura %d-%s aya %d", soura, name_soura(soura), aya);
    buff_i++;
    return 1;
}

int search_arab(arab_line_t *line, uint32_t *text, int txtsize)
{
    int j = txtsize;
    int recurence = 0, ret = 0;
    int k = line->utfs;
    for (int i = k-txtsize ; i > -1 ; i--) { 
        ret = is_text_match(&line->in_utf[i], text, j);
        recurence += ret;
    }
    return recurence;
}

void lauch_seach(uint32_t *utext, int len)
{
    std::ifstream ifs("quran-simple-clean-aya.txt");
    int lines = count_lines(ifs);
    //printf("lines = %d\n", lines);
    
    //wchar_t text[100][80];
    //int idx = 0;

    int recurence = 0;
    int prev_recurence = 0;
    arab_line_t line;

    //le mot 'rahman' comme exemple en unicode
    //uint32_t wtext[6] = {0xfee1,0xfef4,0xfea3,0xfead,0xfedf,0xfe8d}; 

    for (int i = 0 ; i < lines ; i++) { 
        read_line(&line, ifs);
        get_presentation_form_b(&line);
        reverse_line(&line);
        correct(&line);
        recurence += search_arab(&line, (uint32_t*)utext, len);
/*        if (prev_recurence != recurence) {    
            printf("found in soura %d aya %d\n", soura, aya);
            prev_recurence = recurence;
        }*/
        //search_arab(&line, wtext, 6);
        //write_line(&line);
        if (i == lines-1)
            break;
    }
    //idx++;
    printf("found %d times\n", recurence);
    swprintf(buff[buff_i],50, L"%s found %d times", query, recurence);
    buff_i++;
    //wcscpy(quiz_box.text[0],
    ifs.close();
    //return (wchar_t**)text;
}

/*int main()
{
    lauch_seach();
    system("pause");
    return 0;
}*/

