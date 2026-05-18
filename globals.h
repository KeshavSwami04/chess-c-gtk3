#ifndef GLOBALS_H
#define GLOBALS_H

#include <gtk/gtk.h>
#include <string.h>
#include <time.h>

extern char A[];
extern char B[];
extern char C[];
extern char D[];
extern char E[];
extern char P[];
extern char p[];
extern char a[];
extern char b[];
extern char c[];
extern char d[];
extern char e[];

extern char* chess_pieces[8][8];
typedef struct {
    int row;
    int col;
    // GtkWidget *button;
    gboolean is_pressed;
    GtkWidget *piece;
    char piece_name[50];
} ButtonData;
typedef struct {
    GtkWidget *piece;
    int row;
    int col;
} RemovedPiece;

extern GList *removed_pieces ;
extern ButtonData *first_pressed_button;
extern ButtonData *second_pressed_button;

extern int num_possible_moves;
extern int possible_moves[100][2];
extern int x;
extern int y;
extern int random;
extern int bot_move_random[2];

extern gboolean about_label_visible ;
extern GtkWidget *mode_window ;
extern GtkWidget *grid;
typedef enum { WHITE_TURN, BLACK_TURN } Turn;
extern Turn current_turn;

#endif
