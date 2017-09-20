#include <iostream>
#include <fstream>
#include <string>
#include "characters.h"
#include "GameEffects.h"

using namespace std;


void Start(characters &player, characters &enemy, characters &knight)
{

	
	string userResponse;

	ColorPicker(15);
	DelayTextWithSkip(25, "Welcome to Fruit of the Gods! \n");
	while (userResponse != "New" || userResponse != "Load")
	{
		DelayTextWithSkip(25, "Would you like to start a new game or load a save file?" "\n" "Enter 'New' or 'Load'");

		cin >> userResponse;

		if (userResponse == "New")
		{
			updatedIntro(player);
			battle(player, enemy);
			afterAltair(player);
			experience(player);
			battle2(player, knight);
		}

		else if (userResponse == "Load")
		{
			LoadCharacter(player);
			ColorPicker(15);
			DelayText(25, "Welcome Back ");
			ColorPicker(11);
			cout << player.name;
			DelayText(25, "\n");

			battle(player, enemy);
			afterAltair(player);
			experience(player);

			battle2(player, knight);
		}

		else
		{
			DelayTextWithSkip(25, "That isn't one of the options.");
		}
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

	enemy.health = 100;
	enemy.strength = 20;

	characters knight;
	knight.health = 50;
	knight.strength = 25;
	
	//enemy.defense = 5;
	//enemy.healing = 15;

	//Start of game
	Start(player, enemy, knight);
	//Load old file or create new?

	//if(Load old file)
	//LoadFromFileVersion


	//else create new
	//CharacterCreation


	//updatedIntro(player);
	//introduction(player);
	//battle(player, enemy);
	//afterBattle(player);
}