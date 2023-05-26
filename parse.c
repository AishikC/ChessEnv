#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ASCII_LOWER 97
#define ASCII_UPPER 65

/* Converts chess notation position to number from 0 to 63
 * EX: A5 ---> 6
 */
int convert_position(const char* input){
	unsigned char char_column;
	unsigned int column;
	unsigned int row;
	sscanf(input, "%c%d", &char_column, &row);

	if(row<1 || row>8){
		return -1;
	}
	//lowercase
	if(char_column<=104 && char_column>=ASCII_LOWER){
		column = char_column - ASCII_LOWER;
	}
	//uppercase
	else if(char_column<=72 && char_column>=ASCII_UPPER){
		column = char_column - ASCII_UPPER;
	}
	else{
		return -1;
	}
	return ((row-1)*8 + column);
}


/* Parses .pgn files and returns pointer to an array of moves
 */
int parse_file(const char* file_name){
	char * buffer = 0;
	long length;
	
	FILE * f = fopen (file_name, "rb");

	if(f)
	{
		fseek(f, 0, SEEK_END);
		length = ftell (f);
		fseek(f, 0, SEEK_SET);
		buffer = malloc (length);
		if(buffer)
		{
			fread(buffer, 1, length, f);
		}
		fclose (f);
	}

	int j=0;
	char buf_pruned[length];
	char *move_list[1000];
	
	if(buffer){
		int newline_count = 0;
		int space_count = 0;
		int num;
		char w_move[5];
		char b_move[5];
		char move_buf[10];
		int i;
		for(i=0; i<length; i++){
			if(buffer[i] == '\n'){
				newline_count += 1;
			}
			if(newline_count>7){
				break;
			}
		}

		if(buffer[0]!='\n'){
			buffer += i;
		}

		char *ptr = strtok(buffer, " ");
		int k = 0;
		int count = 0;
		while(ptr!=NULL){
			if(count%3!=0){
				move_list[k] = ptr;
				k += 1;
			}
			count += 1;
			ptr = strtok(NULL, " ");
		}
	}
	
	return 0;
}

