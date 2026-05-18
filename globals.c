#include "globals.h"

char A[]="Arook_black.png";
char B[]="Bknight_black.png";
char C[]="Cbishop_black.png";
char D[]="Dqueen_black.png";
char E[]="Eking_black.png";
char P[]="Ppawn_black.png";
char p[]="ppawn_white.png";
char a[]="arook_white.png";
char b[]="bknight_white.png";
char c[]="cbishop_white.png";
char d[]="dqueen_white.png";
char e[]="eking_white.png";

char* chess_pieces[8][8] = {
        {a,b,c,e,d,c,b,a},
        {p,p,p,p,p,p,p,p},
        {"","","","","","", "", ""},
        {"","","","","","", "", ""},
        {"","","","","","", "", ""},
        {"","","","","","", "", ""},
        {P,P,P,P,P,P,P,P},
        {A,B,C,E,D,C,B,A}
    };

GList *removed_pieces = NULL;
ButtonData *first_pressed_button = NULL;
ButtonData *second_pressed_button = NULL;

int num_possible_moves=0;
int possible_moves[100][2]={{-1,-1}};
int x=-1;
int y=-1;
int bot_move_random[2]={-1,-1};
int random=1;
gboolean about_label_visible = FALSE;
GtkWidget * mode_window = NULL;
GtkWidget *grid=NULL;
Turn current_turn = WHITE_TURN;
