#pragma once
#include "MoveBot.h"
#include <random>


class Game
{
	int mass[4][4];
	int old_mass[4][4];
	double koef[4][4];
	int score;
public:
	
	Game(){};

	friend ostream& operator<< (ostream& out, const Game& game);
	void gener();
	void updGener();
	void newKoef(double[4][4]);
	void printKoef();
	void massCopy();
	int endGame();
	int bot();
	void gameProc();
};




void Game::gener()
{
	int index, i, j, l;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			mass[i][j] = 0;
	random_device rd;
	mt19937 gen(rd());
	l = 0;
	index = gen() % 16;
	i = index / 4;
	j = index % 4;
	while (mass[i][j] != 0)
	{
		index = (index + 1) % 16;
		i = index / 4;
		j = index % 4;

	}
	index = gen() % 2 + 1;
	mass[i][j] = index * 2;
	l++;
}



void Game::updGener()
{
	int i, j, index;
	random_device rd;
	mt19937 gen(rd());

	index = gen() % 16;
	i = index / 4;
	j = index % 4;
	while (mass[i][j] != 0)
	{
		index = (index + 1) % 16;
		i = index / 4;
		j = index % 4;

	}
	index = gen() % 10 + 1;
	mass[i][j] = (index/10+1) * 2;

}




void Game::massCopy()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			old_mass[i][j] = mass[i][j];
}



void Game::newKoef(double k[4][4])
{

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			koef[i][j] = k[i][j];
	return;

}


int Game::endGame()
{
	int bufmass[4][4], i, j, m;
	for (m = 0; m < 4; m++)
	{
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				bufmass[i][j] = mass[i][j];
		allmove(m, bufmass);
		if (!massComp(bufmass, mass))
			return 0;
	}
	return 1;
}


int Game::bot()
{
	int x, i, j, p;
	cin >> x;

	for (p = 0; p < 4; p++)
	{

	}



	return x;
}


void Game::gameProc()
{
	score = 0;
	gener();
	while (1) {
		updGener();
		if (endGame())
			return;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				cout << mass[i][j] << ' ';
			cout << '\n';
		}
		massCopy();
		do{
			score += allmove(bot(), mass);
		}while (massComp(mass, old_mass));

	}
}




void Game::printKoef()
{

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << koef[i][j] << ' ';
		cout << '\n';
	}

}


ostream& operator << (ostream& out, const Game& game)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			out << game.mass[i][j] << ' ';
		out << '\n';
	}

	return out;
}


