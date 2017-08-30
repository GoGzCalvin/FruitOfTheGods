#pragma once
#include <iostream>
#include "GameEffects.h"
using namespace std;

struct characters
{
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


	cout << "You attacked and dealt  " << player.damage << " damage. The enemy has " << enemy.health << " health remaining." << endl;
	cout << "The enemy attacked and dealt " << enemy.damage << " damage. The player has " << player.health << " health remaining." << endl;
}

void Heal(characters &player)
{
	player.healthRemaining = (player.health + player.heal);
	
	cout << "You have healed " << player.heal << " damage." << "You have " << player.healthRemaining << " health remaining." << endl;
}

void Defend(characters &player, characters &enemy)
{
	player.defense = (enemy.damage * 0.75);

	player.health -= player.defense;

	cout << "The enemy attacked and dealt " << player.defense << " damage. The player has " << player.health << " health remaining." << endl;
}


void introduction()
{
	ColorPicker(14);
	char playerName[20];

	/*cout << "Fruit of the Gods!" << endl;*/
	
	DelayTextWithSkip(20, "Welcome to Fruit of the Gods!");
	//ColorPicker(10);
	DelayTextWithSkip(20, "You have awoken...");
	DelayTextWithSkip(20, "Your celestial powers are intact, however your angel wings will not appear...");
	DelayTextWithSkip(20, "You recall your betrayal to your angelic kin to set out on your quest to become the strongest being in existence a God with angelic power.");
	DelayTextWithSkip(20, "Although you can't seem to remember your name, what was it again?");

	cin >> playerName;

	char buffer[80] = "Hello ";
	strcat_s(buffer, playerName);
	DelayTextWithSkip(20, buffer);


	
}

void battle(characters &player, characters & enemy)
{
	ColorPicker(12);
	int input;

	DelayTextWithSkip(20, "Your superior Diana has confronted you. ");

	do
	{
		DelayTextWithSkip(20, "Input '1' to attack.");
		DelayTextWithSkip(20, "Input '2' to heal");
		DelayTextWithSkip(20, "Input '3' to defend.");;


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


		else if (player.health < 0)
		{
			cout << "Player has died." << endl;
		}

		else if (enemy.health < 0)
		{
			cout << "The enemy has died." << endl;
		}

		else
		{
			cout << "Choose one of the available options. " << endl;
		}


	} while (player.health > 0 && enemy.health > 0);
}