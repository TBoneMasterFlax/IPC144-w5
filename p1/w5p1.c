/*
	==================================================
	Workshop #5 (Part-1):
	==================================================
	Name   : Tuan Nguyen
	ID     : 109062166
	Email  : tnguyen140@myseneca.ca
	Section: NFF
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_PATH_LENGTH 5
#define MAX_PATH_DEPTH 14

struct PlayerInfo
{
	int lives;
	char symbol;
	int treasuresFound;
	int positionHistory[MAX_PATH_DEPTH][MAX_PATH_LENGTH];
};

struct GameInfo
{
	int moves;
	int pathLength;
	int bombs[MAX_PATH_DEPTH][MAX_PATH_LENGTH];
	int treasures[MAX_PATH_DEPTH][MAX_PATH_LENGTH];
};

int main(void)
{
	int flag = 1, i, j;
	struct PlayerInfo player;
	struct GameInfo game;
	char symbol;
	int lives;
	int path_length;
	int moves;
	

	printf("================================\n");
	printf("         Treasure Hunt!         \n");
	printf("================================\n");
	printf("\nPLAYER Configuration\n");
	printf("--------------------\n");
	printf("Enter a single character to represent the player: ");
	scanf("%c", &symbol);
	player.symbol = symbol;
	do
	{
		printf("Set the number of lives: ");
		scanf("%d", &lives);
		if (lives >= 1 && lives <= 10)
		{
			player.lives = lives;
			flag = 0;
		}
		else
			printf("     Must be between 1 and 10!\n");
	} while (flag);
	printf("Player configuration set-up is complete\n");



	printf("\nGAME Configuration\n");
	printf("------------------\n");
	flag = 1;
	do
	{
		printf("Set the path length (a multiple of 5 between 10-70): ");
		scanf("%d", &path_length);
		if (path_length % 5 == 0 && path_length >= 10 && path_length <= 70)
		{
			game.pathLength = path_length;
			flag = 0;
		}
		else
			printf("     Must be a multiple of 5 and between 10-70!!!\n");
	} while (flag);
	flag = 1;
	do
	{
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &moves);
		if (moves >= 3 && moves <= 26)
		{
			game.moves = moves;
			flag = 0;
		}
		else
			printf("    Value must be between 3 and 26\n");
	} while (flag);



	printf("\nBOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
	for (i = 0; i < (game.pathLength / 5); i++)
	{
		printf("   Positions [%2d-%2d]: ", (5 * i) + 1, (5 * i) + 5);
		scanf("%d %d %d %d %d", &game.bombs[i][0], &game.bombs[i][1], &game.bombs[i][2], &game.bombs[i][3], &game.bombs[i][4]);
	}
	printf("BOMB placement set\n");



	printf("\nTREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
	for (i = 0; i < (game.pathLength / 5); i++)
	{
		printf("   Positions [%2d-%2d]: ", (5 * i) + 1, (5 * i) + 5);
		scanf("%d %d %d %d %d", &game.treasures[i][0], &game.treasures[i][1], &game.treasures[i][2], &game.treasures[i][3], &game.treasures[i][4]);
	}
	printf("TREASURE placement set\n");



	printf("\nGAME configuration set-up is complete...\n");
	printf("\n------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");
	printf("Player:\n");
	printf("   Symbol     : %c\n", player.symbol);
	printf("   Lives      : %d\n", player.lives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n");
	printf("\nGame:\n");
	printf("   Path Length: %d\n", game.pathLength);
	printf("   Bombs      : ");
	for (i = 0; i < (game.pathLength / 5); i++)
	{
		for (j = 0; j < MAX_PATH_LENGTH; j++)
		{
			printf("%d", game.bombs[i][j]);
		}
	}
	printf("\n   Treasure   : ");
	for (i = 0; i < (game.pathLength / 5); i++)
	{
		for (j = 0; j < MAX_PATH_LENGTH; j++)
		{
			printf("%d", game.treasures[i][j]);
		}
	}
	printf("\n\n====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");
	return 0;
}