#ifndef GAME_H
#define GAME_H
#include"globals.h"
void pawn_moves_black(int x, int y, char* h[8][8]);
void pawn_moves_white(int x, int y, char* h[8][8]);
void rook_moves_white(int x, int y, char* h[8][8]);
void rook_moves_black(int x, int y, char* h[8][8]);
void king_moves_black(int x, int y, char* h[8][8]);
void king_moves_white(int x, int y, char* h[8][8]);
void knight_moves_black(int x, int y, char* h[8][8]);
void knight_moves_white(int x, int y, char* h[8][8]);
void bishop_moves_black(int x, int y, char* h[8][8]);
void bishop_moves_white(int x, int y, char* h[8][8]);
void queen_moves_white(int x, int y, char* h[8][8]);
void queen_moves_black(int x, int y, char* h[8][8]);
void filter_invalid_moves_black(int x,int y,char* h[8][8]);
void filter_invalid_moves_white(int x,int y,char* h[8][8]);
int check_black(char*h[8][8]);
int check_white(char *h[8][8]);
void random_move(int k, int s[][2]);
void ai_random(char* h[8][8]);
int checkmate_black(char* h[8][8]);
int checkmate_white(char* h[8][8]);
#endif 
