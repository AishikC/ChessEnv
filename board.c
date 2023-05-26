#include <stdio.h>
#include <stdlib.h>
#include "chess.h"


int main(){
	parse_file("magnus.pgn");
	//printf("Converted value is %d\n", convert_position("E7"));
	return 0;
}
