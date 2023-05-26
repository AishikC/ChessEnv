#ifndef CHESS
#define CHESS
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "parse.c"

typedef enum {pawn, rook, knight, bishop, queen, king} Piece_type;
typedef enum {a, b, c, d, e, f, g, h} column;

typedef struct Positions{
	Piece_type piece;
	uint8_t cur_position;
	uint8_t next_position;
} position;


#endif
