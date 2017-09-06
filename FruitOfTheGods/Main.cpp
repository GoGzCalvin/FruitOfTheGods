#include <iostream>
#include "characters.h"
#include "GameEffects.h"

using namespace std;

int main()
{
	characters player;

	player.health = 100;
	player.damage = 20;
	player.defense = 15;
	player.heal = 30;


	characters enemy;

	enemy.health = 150;
	enemy.damage = 25;
	enemy.defense = 5;
	enemy.heal = 15;

	introduction(player);
	battle(player, enemy);
	afterBattle(player);


	//battle(player, ogre);
}