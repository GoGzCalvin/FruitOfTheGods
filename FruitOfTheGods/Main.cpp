#include <iostream>
#include <fstream>
#include <string>
#include "characters.h"
#include "GameEffects.h"

using namespace std;


void Start(characters &player, characters &enemy)
{

	
	string userResponse;

	DelayTextWithSkip(25, "Welcome to Fruit of the Gods! \n");
	DelayTextWithSkip(25, "Would you like to start a new game or load a save file? \n");

	cin >> userResponse;

	if (userResponse == "New" || "new")
	{
		updatedIntro(player);
	}

	else if (userResponse == "Load" || "load")
	{
		LoadCharacter(player);
		battle(player, enemy);
		afterBattle(player);
	}

	else
	{
		DelayTextWithSkip(25, "That isn't one of the options.");
	}

}





int main()
{
	characters player;

	/*player.health = 100;
	player.strength = 20;
	player.defense = 15;
	player.healing = 30;*/


	characters enemy;

	enemy.health = 150;
	enemy.strength = 25;
	enemy.defense = 5;
	enemy.healing = 15;

	//Start of game
	Start(player, enemy);
	//Load old file or create new?

	//if(Load old file)
	//LoadFromFileVersion


	//else create new
	//CharacterCreation


	//updatedIntro(player);
	//introduction(player);
	battle(player, enemy);
	afterBattle(player);
}