#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include "colours.h"

void intro();

void levelSelect();

void easyShuffle();

void mediumShuffle();

void hardShuffle();

void playerRoundChoice();

void playerColChoice();

void compareArrayElements();

main()
{

	FILE * fPointer;

	fopen_s(&fPointer, "GameData.txt", "r+");

	fprintf(fPointer, "This page contains your game data");

	fclose(fPointer);

	//Introduction to mastermind
	intro();

	//Choose easy, medium or hard
	//Does the shuffling
	levelSelect();

	//Choose have many rounds you want to play
	playerRoundChoice();

	printf("\n\n");

	//Plays Easy and Medium games
	if(levelChoice == 1 || levelChoice == 2)
	{

		//Will increment the number of easy games you have played and print to text file
		if(levelChoice == 1)
		{
			fopen_s(&fPointer, "GameData.txt", "r+");

			fseek( fPointer, 129, SEEK_SET );

			fscanf_s(fPointer, "%d", &easyGameCounter);

			easyGameCounter++;

			fseek( fPointer, 100, SEEK_SET );

			fprintf(fPointer, "Number of easy games played: %d", easyGameCounter);

			fclose(fPointer);
		}//End if

		//Will increment the number of medium games you have played and print to text file
		if(levelChoice == 2)
		{
			fopen_s(&fPointer, "GameData.txt", "r+");

			fseek( fPointer, 228, SEEK_SET );

			fscanf_s(fPointer, "%d", &mediumGameCounter);

			mediumGameCounter++;

			fseek( fPointer, 197, SEEK_SET );

			fprintf(fPointer, "Number of medium games played: %d", mediumGameCounter);

			fclose(fPointer);
		}//End if
		
		//Easy, Medium game fully working
		while(round < numOfRounds)
		{
			//Prints out round you're on and number of rounds
			printf("\n\t\t\t\tRound %d of %d", round + 1, numOfRounds);
			printf("\n\t\t\t\t~~~~~~~~~~~~~");
	
			//Player inputs colours
			playerColChoice();

			//Player array is compared the the computer array
			compareArrayElements();

			//This is your feeback from each round
			//Displays your white and black pegs
			printf("\n\n\nYou got\n-------\n");
			printf("Black pegs: %d\nWhite Pegs: %d\n\n", blackPeg, whitePeg);

			//Prints when you win
			if(blackPeg == 4 && whitePeg == 0)
			{
		
				printf("********************************************************************************");
				printf("\n\t\t\tCongratulations you won!!\n");
				printf("********************************************************************************\n");
				break;

			}

			//Resets the counters for the pegs for the next round
			blackPeg = whitePeg = 0;

			//Counts up rounds so while loop can be exited
			round++;
	
		}//End while

		printf("\n\n");

		//Prints when you lose
		if(blackPeg != 4)
		{
		
			printf("================================================================================\n");
			printf("\n\t\t\tUnlucky, you lost, please try again\n");
			printf("\n================================================================================\n");

			printf("\nComputers colours were\n======================\n\t");

			//Shows what the computer chose
			for(i = 0; i < 4; i++)
			{
	
				printf("%c ", computerColours[i]);
	
			}//End for

		}//End if

	}//End if for easy medium level select

	//Plays hard level game
	if(levelChoice == 3)
	{

		fopen_s(&fPointer, "GameData.txt", "r+");

		fseek( fPointer, 323, SEEK_SET );

		fscanf_s(fPointer, "%d", &hardGameCounter);

		hardGameCounter++;

		fseek( fPointer, 294, SEEK_SET );

		fprintf(fPointer, "Number of hard games played: %d", hardGameCounter);

		fclose(fPointer);

		//Easy, Medium game fully working
		while(round < numOfRounds)
		{
			//Prints out round you're on and number of rounds
			printf("\n\t\t\t\tRound %d of %d", round + 1, numOfRounds);
			printf("\n\t\t\t\t~~~~~~~~~~~~~");
	
			//Player inputs colours
			hardColChoice();

			//Player array is compared the the computer array
			compareHardArrayElements();

			//This is your feeback from each round
			//Displays your white and black pegs
			printf("\n\n\nYou got\n-------\n");
			printf("Black pegs: %d\nWhite Pegs: %d\n\n", blackPeg, whitePeg);

			//Prints when you win
			if(blackPeg == 4 && whitePeg == 0)
			{
		
				printf("********************************************************************************");
				printf("\n\t\t\tCongratulations you won!!\n\n");
				printf("********************************************************************************\n");
				break;

			}

			//Resets the counters for the pegs for the next round
			blackPeg = whitePeg = 0;

			//Counts up rounds so while loop can be exited
			round++;
	
		}//End while

		printf("\n\n");

		//Prints when you lose
		if(blackPeg != 4)
		{
		
			printf("================================================================================\n");
			printf("\n\t\t\tUnlucky, you lost, please try again\n");
			printf("\n================================================================================\n");

			printf("\nComputers colours were\n======================\n\t");

			//Shows what the computer chose
			for(i = 0; i < 4; i++)
			{
	
				printf("%c ", hardComputerColours[i]);
	
			}//End for

		}//End if	

	}//End if

	printf("\n\n");
	
	system("pause");

}//End main


