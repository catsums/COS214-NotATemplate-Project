#ifndef STRUCTS_H
#define STRUCTS_H

struct Position{
	int x = 0;
	int y = 0;
	Position(){x=0;y=0;}
	Position(int _x, int _y){
		x = _x; y = _y;
	}
};

enum Influence{
	LOW, MID, HIGH
};

#endif