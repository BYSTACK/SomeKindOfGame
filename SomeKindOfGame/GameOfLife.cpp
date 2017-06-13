#include "GameOfLife.h"
#include "cstdlib"
#include "ctime"


GameOfLife::GameOfLife()
{
	srand(static_cast<unsigned int>(time(0)));

	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			newGrid[i][j] = false;
			grid[i][j] = rand()%2;
		}
	}

	/*
	//�������� �������
	grid[1][0] = true;
	grid[2][1] = true;
	grid[0][2] = true;
	grid[1][2] = true;
	grid[2][2] = true;
	*/


	body.setFillColor(sf::Color::Black);
	body.setSize(sf::Vector2f(30.f, 30.f));
	
}

void GameOfLife::Update()
{
	//���� � ����� ������ 2 ��� 3 ������ ��� ��������, ����� �������
	// ���� � ������� ������ 3 ������, �� ��� �������



	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			int sides[4];
			int alN = 0; // ����� ������

			sides[0] = i - 1;
			sides[1] = i + 1;
			sides[2] = j - 1;
			sides[3] = j + 1;
			if (sides[0] < 0)
				sides[0] = 25;
			if (sides[1] > 25)
				sides[1] = 0;
			if (sides[2] < 0)
				sides[2] = 19;
			if (sides[3] > 19)
				sides[3] = 0;

			if (grid[sides[0]][j])
				alN++;
			if (grid[sides[1]][j])
				alN++;
			if (grid[i][sides[2]])
				alN++;
			if (grid[i][sides[3]])
				alN++;
			if (grid[sides[0]][sides[2]])
				alN++;
			if (grid[sides[1]][sides[2]])
				alN++;
			if (grid[sides[0]][sides[3]])
				alN++;
			if (grid[sides[1]][sides[3]])
				alN++;

			if (grid[i][j] == true)
			{
				if (alN == 2 || alN == 3)
				{
					newGrid[i][j] = true;
				}
				else
				{
					newGrid[i][j] = false;
				}
			}
			if (grid[i][j] == false)
			{
				if (alN == 3)
				{
					newGrid[i][j] = true;
				}
			}
		}
	}
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			grid[i][j] = newGrid[i][j];
			newGrid[i][j] = false;
		}
	}
}

void GameOfLife::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (grid[i][j] == true)
			{
				body.setPosition(i * 30, j * 30);
				window.draw(body);
			}
		}
	}
}

GameOfLife::~GameOfLife()
{
}
