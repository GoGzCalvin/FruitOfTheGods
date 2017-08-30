#pragma once
#include <iostream>

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


	cout << "You attacked and dealt  " << player.damage << " damage. The zombie has " << enemy.health << " health remaining." << endl;
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
	cout << "You have awoken..." << endl; 
	cout << "Your celestial powers are intact, however your angel wings will not appear..." << endl;
	cout << "You recall your betrayal to your angelic kin to set out on your quest to become the strongest being in existence a God with angelic power." << endl;
}

void battle(characters &player, characters & enemy)
{


	int input;

	



	cout << "Fruit of the Gods!" << endl;

	do
	{

		cout << "Input '1' to attack." << endl;
		cout << "Input '2' to heal" << endl;
		cout << "Input '3' to defend." << endl;


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
			cout << "The zombie has died." << endl;
		}

		else
		{
			cout << "Choose one of the available options. " << endl;
		}


	} while (player.health > 0 && enemy.health > 0);
}