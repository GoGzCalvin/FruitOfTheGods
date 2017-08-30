#include <iostream>
#include "characters.h"
#include "GameEffects.h"

using namespace std;

int main()
{
	characters player;

	player.health = 100;
	player.damage = 15;
	player.defense = 10;
	player.heal = 30;


	characters enemy;

	enemy.health = 150;
	enemy.damage = 20;
	enemy.defense = 5;
	enemy.heal = 15;

	introduction();
	battle(player, enemy);




	//battle(player, ogre);
}