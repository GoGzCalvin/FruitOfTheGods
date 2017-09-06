#pragma once
#include <iostream>
#include "GameEffects.h"
using namespace std;

struct characters
{
	char name[50];
	int health;
	int damage;
	int heal;
	int healthRemaining;
	double defense;
};

void DealDamage(characters &player, characters &enemy)
{
	player.health -= enemy.damage;
	enemy.health -= player.damage;

	// Player Attack
	DelayText(25, "You attacked and dealt ");
	ColorPicker(11);
	cout << player.damage;
	ColorPicker(15);
	DelayText(25, " damage. The enemy has ");
	ColorPicker(12);
	cout << enemy.health;
	ColorPicker(15);
	DelayText(25, " health remaining.");
	cout << "\n";



	// Enemy Attack
	DelayText(25, "The enemy attacked and dealt ");
	ColorPicker(12);
	cout << enemy.damage;
	ColorPicker(15);
	DelayText(25, " damage. The player has ");
	ColorPicker(10);
	cout << player.health;
	ColorPicker(15);
	DelayText(25, " health remaining.");
	cout << "\n";
}

void Heal(characters &player)
{
	player.healthRemaining = (player.health + player.heal);
	
	DelayText(25, "You healed ");
	ColorPicker(10);
	cout << player.heal;
	ColorPicker(15);
	DelayText(25, " damage. You have ");
	ColorPicker(10);
	cout << player.healthRemaining;
	ColorPicker(15);
	DelayTextWithSkip(25, " health remaining. \n");
}

void Defend(characters &player, characters &enemy)
{
	player.defense = (enemy.damage * 0.75);

	player.health -= player.defense;

	DelayText(25, "The enemy attacked and dealt ");
	ColorPicker(12);
	cout << player.defense;
	ColorPicker(15);
	DelayText(25, " damage. ");
	DelayText(25, "The player has ");
	ColorPicker(10);
	cout << player.health;
	ColorPicker(15);
	DelayTextWithSkip(25, " health remaining.");
}

void playerStats(characters &player)
{
	
	cout << "Health. ";
	ColorPicker(10);
	cout << player.health << endl;
	ColorPicker(15);

	cout << "Attack. ";
	ColorPicker(12);
	cout << player.damage << endl;
	ColorPicker(15);

	cout << "Defense. ";
	ColorPicker(11);
	cout << player.defense << endl;
	ColorPicker(15);


}

void enemyStats(characters &enemy)
{

	cout << "Health. ";
	ColorPicker(10);
	cout << enemy.health << endl;
	ColorPicker(15);

	cout << "Attack. ";
	ColorPicker(12);
	cout << enemy.damage << endl;
	ColorPicker(15);

	cout << "Defense. ";
	ColorPicker(11);
	cout << enemy.defense << endl;
	ColorPicker(15);


}


void introduction(characters &player)
{
	ColorPicker(14);
	char playerName[25];
	
	DelayTextWithSkip(25, "Welcome to Fruit of the Gods! \n");
	DelayTextWithSkip(25, "You have awoken... \n");
	DelayTextWithSkip(25, "Your celestial powers are intact, however your angel wings will not appear... \n");
	DelayTextWithSkip(25, "You recall your betrayal to your angelic kin to set out on your quest to become the strongest being in existence a God with angelic power. \n");
	DelayTextWithSkip(25, "Although you can't seem to remember your name, what was it again? \n");


	ColorPicker(11);
	cin >> player.name;
	cout << "\n";
	char buffer[80] = "Hello, ";
	strcat_s(buffer, player.name);
	cout << "\n";
	DelayTextWithSkip(15, buffer);
	cout << "\n";

	
}

void afterBattle(characters player)
{
	ColorPicker(12);
	char playerName[25];
	

	DelayText(25, "Well done ");
	ColorPicker(11);
	DelayTextWithSkip(25,player.name);
	cout << "\n";
	ColorPicker(12);
	DelayTextWithSkip(25, "You have grown since your betrayal to the angels. \n");
	DelayTextWithSkip(25, "Our brothers and sisters assumed you would have lost your grace after betraying us. \n");
	DelayTextWithSkip(25, "Although it appears your wings have been revoked to prevent you from returning to the celestial plain. \n");
	DelayText(25, "We shall meet again \n");
	ColorPicker(11);
	DelayTextWithSkip(25, player.name);
	ColorPicker(15);





}

void battle(characters &player, characters & enemy)
{
	ColorPicker(15);
	int input;

	DelayText(25, "You have been challenged by your superior ");
	ColorPicker(12);
	DelayTextWithSkip(25, "Altair.");
	
	do
	{
		// Attack
		ColorPicker(15);
		cout << "Input '1' to ";
		ColorPicker(12);
		cout << " attack \n";
		ColorPicker(15);


		// Heal
		cout << "Input '2' to ";
		ColorPicker(10);
		cout <<	" heal \n";


		// Defend
		ColorPicker(15);
		cout << "Input '3' to ";
		ColorPicker(11);
		cout << " defend \n";
		ColorPicker(15);


		// Player Stats
		ColorPicker(15);
		cout << "Input '4' to ";
		ColorPicker(14);
		cout << " view player stats \n";
		ColorPicker(15);


		//EnemyStats
		cout << "Input '5' to ";
		ColorPicker(12);
		cout << " view enemy stats \n";
		ColorPicker(15);


		cin >> input;

		if (input == 1)
		{
			DealDamage(player, enemy);
		}

		else if (input == 2)
		{
			Heal(player);
		}

		else if (input == 3)
		{
			Defend(player, enemy);
		}

		else if (input == 4)
		{
			playerStats(player);
		}

		else if (input == 5)
		{
			enemyStats(enemy);
		}


		else if (player.health < 0)
		{
			DelayTextWithSkip(25, "You have been defeated.");
		}

		else if (enemy.health < 0)
		{
			DelayTextWithSkip(25, "The enemy has been defeated.");
		}

		else
		{
			cout << "Choose one of the available options. " << endl;
		}


	} while (player.health > 0 && enemy.health > 0);
}