#pragma once
#include <vector>

struct Otimono {
	int posX;
	int posY;
	int dead = 0;
};

void OtimonoProgram();
extern std::vector<Otimono>	otimonoArray;	//落ち物の可変長配列。