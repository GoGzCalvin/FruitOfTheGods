#pragma once
#include <iostream>

using namespace std;

struct characters
{
	int health;
	int damage;
	int heal;
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
	player.heal += player.health;

	cout << "You have healed " << player.heal << " damage. " << "You have " <<player.health << " health remaining." << endl;
}

void Defend(characters &player, characters &enemy)
{
	player.defense = (enemy.damage * 0.70);

	player.health -= player.defense;

	cout << "The enemy attacked and dealt " << player.defense << " damage. The player has " << player.health << " health remaining." << endl;
}


void battle()
{


	int input;

	characters player;

	player.health = 100;
	player.damage = 15;
	player.defense = 10;
	player.heal = 20;


	characters enemy;

	enemy.health = 150;
	enemy.damage = 20;
	enemy.defense = 5;
	enemy.heal = 15;




	do
	{
		cout << "Fruit of the Gods!" << endl;





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
			Defend();
		}


		else if (player.health == 0)
		{
			cout << "Player has died." << endl;
		}

		else if (enemy.health == 0)
		{
			cout << "The zombie has died." << endl;
		}

		else
		{
			cout << "Choose one of the available options. " << endl;
		}


	} while (player.health >= 0 || enemy.health >= 0);
}