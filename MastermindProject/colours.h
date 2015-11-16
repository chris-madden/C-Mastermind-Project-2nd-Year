//Array needs to be global for everything to see it
char computerColours[] = {"rgboivy"};

//Array used for hard level
char hardComputerColours[] = {"rgboivy_"};

//Player array to be filled with players colour choices
char playerArray[4 + 1];

int i, blackPeg = 0, whitePeg = 0;

int round = 0, numOfRounds;

//Counters and Level choice
int easyGameCounter = 0, mediumGameCounter = 0, hardGameCounter = 0, levelChoice = 0;

//Shuffles array
//Easy level
void easyShuffle()
{
	int temp, randomIndex;

	//Selects a random by using what time it is
	srand(time(NULL));

	//Shuffles array with no repeats. 
	for(i = 0; computerColours[i] != 0; i++)
	{
		
		//E.G [3] 'o'
		randomIndex = rand() % 7;

		//E.G temp is equal to the value in [3] 'o'
		temp = computerColours[randomIndex];

		//What ever value is in [0] E.G 'r' is put into [3]
		//values here getting swapped
		computerColours[randomIndex] = computerColours[i];

		//Value stored in temp is put into spot [1]
		//Value in temp 'o' is put into [0] which was 'r' place
		computerColours[i] = temp;
	
	}

}//End shuffleNoRepeats

//Shuffles array
//Medium level
void mediumShuffle()
{
	int temp, randomIndex;

	//Selects a random by using what time it is
	srand(time(NULL));

	//Shuffles array with no repeats. 
	for(i = 0; computerColours[i] != 0; i++)
	{
		
		//E.G [3] 'o'
		randomIndex = rand() % 7;

		//E.G temp is equal to the value in [3] 'o'
		temp = computerColours[randomIndex];

		//What ever value is in [0] E.G 'r' is put into [3]
		//values here getting swapped
		computerColours[randomIndex] = computerColours[i];

	}//End for

}//End shuffleRepeatsNoBlank

//Shuffles array
//Hard level
void hardShuffle()
{
	int temp, randomIndex;

	//Selects a random by using what time it is
	srand(time(NULL));

	//Shuffles array with no repeats. 
	for(i = 0; hardComputerColours[i] != 0; i++)
	{
		
		//E.G [3] 'o'
		randomIndex = rand() % 7;

		//E.G temp is equal to the value in [3] 'o'
		temp = hardComputerColours[randomIndex];

		//What ever value is in [0] E.G 'r' is put into [3]
		//values here getting swapped
		hardComputerColours[randomIndex] = hardComputerColours[i];

	}//End for

}//End shuffleRepeatsNoBlank

//Prints introduction
void intro()
{
	printf("================================================================================\n");
	printf("\t\t\t      Welcome to Mastermind\n\n");
	printf("================================================================================\n");

	printf("This is a game where you must break the code that the computer has set up.\n\n");
	printf("If you guess the correct colour in the correct position you'll receive\na black peg\n\n");
	printf("If you guess the correct colour in the wrong position you'll receive\na white peg\n\n");
	printf("You will select your difficulty level and then the number of rounds\nyou want to play\n\n");

	printf("================================================================================\n");
	printf("\t\t\t\t   Lets Begin!\n\n");
	printf("================================================================================\n");

}

//Allows user to select a level
void levelSelect()
{
	
	printf("\t\t\t----------------------------------\n");
	printf("\t\t\tPlease select the difficulty level\n");
	printf("\t\t\t----------------------------------\n\n");
		
	printf("\n1.Easy (Pick 4 colours with no repeats or blanks)\n\n2.Medium (Pick 4 colours, there can be repeats but no blanks)\n\n3.Hard (Pick 4 colours, there can be repeats and blanks)\n\n");

	//Flush buffer before next input
	fflush(stdin);

	scanf_s("%d", &levelChoice);

	//if statement to make sure program will only run 
	//if correct values are entered
	if(levelChoice >= 1 && levelChoice <= 3)
	{

		switch(levelChoice)
		{
		
		case 1: easyShuffle();
				break;

		case 2: mediumShuffle();
				break;

		case 3: hardShuffle();
				break;

		default: printf("\nInvalid choice, Try again");
				 levelSelect();

		}//End switch

	}
	else
	{
		//Error handling, player will get to choose again if first choice was invalid
		printf("\nInvalid choice, Try again");
		levelSelect();
	
	}//End if

}//End levelSelect

//Sets the number of rounds the player wants
void playerRoundChoice()
{
	printf("\n\n\t\t      ---------------------------------------\n");
	printf("\t\t      How many rounds would you like to play?\n\t\t\t\t      (Max of 15)\n");
	printf("\t\t      ---------------------------------------\n");

	//Flush buffer before next input
	fflush(stdin);

	scanf_s("%d", &numOfRounds);

	//Error handling in case player picks an invalid number of rounds
	if(numOfRounds < 1 || numOfRounds > 15)
	{
		printf("********************************************************************************\n");
		printf("\t\t     You must chose between 1 and 15, try again\n\n");
		printf("********************************************************************************\n\n");

		//Will ask the user to choose the number of rounds again
		playerRoundChoice();
	}//End if
	
}//End playerColChoice

//Askes players to chose their colours and fills a player array
//Stop wrong entries
void playerColChoice()
{
	int k;
	char playerChoice;

		printf("\n\n\t\t\t     --------------------\n");
		printf("\t\t\t     Chose your 4 colours\n");
		printf("\t\t\t     --------------------\n\n");
		
		printf("    Type\n============\nr for red\ng for green\nb for blue\ny for yellow\ni for indigo\nv for violet\no for orange\n============\n");
		//Red, Green, Blue, Yellow, Indigo, Violet, orange\n(Use only first letter of colour for your entry)");

		//Gets players colour choice and fills an array
		for(k = 0; k < 4; k++)
		{

			printf("\n\nChoose Colour %d\n", k +1);
			printf("----------------\n");

			fflush(stdin);

			scanf_s("%c", &playerChoice);

			//Changes characters to lowercase
			playerChoice = tolower(playerChoice);

			//Checks characters are correct
			if(playerChoice == 'r' || playerChoice == 'g' || playerChoice =='b' || playerChoice == 'y' || playerChoice == 'i' || playerChoice == 'v' || playerChoice == 'o')
			{
		
				playerArray[k] = playerChoice;
		
			}
			else
			{
				//Error msg printed and starts method again
				printf("\n\n******************************************************************************\n");
				printf("\n\n\t\tYou can only enter r, g, b, y, i, v, or o\n");
				printf("\n\n******************************************************************************\n");

				//Set k to -1 so that it can be checked below to see if code 
				//needs to be re-run
				k = -1;
				break;

			}//End if
		
		}//End for

		//Checks to see if method needs to run again
		if(k == -1)
		{
			playerColChoice();
		}//End if
		else
		{
		
			printf("\n\nYou chose\n---------\n ");

			//Prints out whats in player array
			for(i = 0; i < 4; i++)
			{
				
				printf("%c ", playerArray[i]);
	
			}//End for

		}//End if
		
}//End playerColChoice

//Fills array for hard level
void hardColChoice()
{

		int k;
		char playerChoice;

		printf("\n\n\t\t\t     --------------------\n");
		printf("\t\t\t     Chose your 4 colours\n");
		printf("\t\t\t     --------------------\n\n");
		
		printf("    Type\n============\nr for red\ng for green\nb for blue\ny for yellow\ni for indigo\nv for violet\no for orange\n_ for blank\n============\n");

		//Gets players colour choice and fills an array
		for(k = 0; k < 4; k++)
		{

			printf("\n\nWhich colour do you want to choose?\n");

			fflush(stdin);

			scanf_s("%c", &playerChoice);

			//Changes characters to lowercase
			playerChoice = tolower(playerChoice);

			if(playerChoice == 'r' || playerChoice == 'g' || playerChoice =='b' || playerChoice == 'y' || playerChoice == 'i' || playerChoice == 'v' || playerChoice == 'o' || playerChoice == '_')
			{
		
				playerArray[k] = playerChoice;
		
			}
			else
			{
				//Error msg printed and starts method again
				printf("\n\n******************************************************************************\n");
				printf("\n\n\t\tYou can only enter r, g, b, y, i, v, o, or _\n");
				printf("\n\n******************************************************************************\n");

				//Set k to -1 so that it can be checked below to see if code 
				//needs to be re-run
				k = -1;
				break;
			
			}//End if
		
		}//End for

		//Checks to see if method needs to run again
		if(k == -1)
		{
			playerColChoice();
		}//End if
		else
		{
		
			printf("\n\nYou chose\n---------\n ");

			//Prints out what's in player array
			for(i = 0; i < 4; i++)
			{
				
				printf("%c ", playerArray[i]);
	
			}//End for

		}//End if

}//End hardColChoice

//This method will correctly compare the 2 arrays, Player array against computer array, used for medium and easy levels
void compareArrayElements()
{

	int temp;
	
	for(i = 0; i < 4; i++)
	{

		int j = 0;
		
		temp = i;

		while(j < 4)
		{

			//Compares the first elements of each array against each other
			if(temp == i)
			{
				//These compare elements [0]
				if(computerColours[i] == playerArray[temp])
				{
			
					blackPeg++;
					//Increase temp so that these elements don't get compared again
					temp++;
					break;
			
				}//End nested if

			}//End if

			//Compares elements [1][2][3] with i
			if(computerColours[i] == playerArray[j++])
			{
				
				whitePeg++;
				break;
			
			}//End if
	
		}//End while

	}//End for

	
}//End compareArrayElements

//Compares players choice with computers for the hard level
void compareHardArrayElements()
{

	int temp;
	
	for(i = 0; i < 4; i++)
	{

		int j = 0;
		
		temp = i;

		while(j < 4)
		{

			//Compares the first elements of each array against each other
			if(temp == i)
			{
				//These compare elements [0]
				if(hardComputerColours[i] == playerArray[temp])
				{
			
					blackPeg++;
					//Increase temp so that these elements don't get compared again
					temp++;
					break;
			
				}//End nested if

			}//End if

			//Compares elements [1][2][3] with i
			if(hardComputerColours[i] == playerArray[j++])
			{
				
				whitePeg++;
				break;
			
			}//End if
	
		}//End while

	}//End for

}//End compareHardArrayElements



