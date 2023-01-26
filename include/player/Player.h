#ifndef PLAYER_H
#define PLAYER_H

#include "../../include/entity/EntityHuman.h"

class Player : public EntityHuman {

public:
	Player();

public:
	void handleInput();

};

#endif