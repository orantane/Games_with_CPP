#include <iostream>
#include <ctime>

void PrintIntroduction(int LevelDifficulty)
{
	// Print the "story" to the terminal.
	std::cout << "\n\nYou just broke into the bank vault and start stashing the cash from a big pile in the middle of the vault.\n";
	std::cout << "Once you have all the cash ready to go in your bags, you realize you still have some room left and the alarm is not yet on.\n";
	std::cout << "A row of safety deposit boxes in lining the back wall with simple three number combination locks on them.\nThere's not much time, but maybe you could get some extra loot from them.\n";
	std::cout << "All you need to do is figure out the correct codes to open them.\n\nThere's a list next to the boxes that gives you some hints to what the codes might be...\nYou start with the box that seems to have the easiest code: Difficulty " << LevelDifficulty << ".";
}

bool PlayGame(int LevelDifficulty)
{
	// This game is really simple and a part of a Udemy course about C++ in Unreal Engine.
	if (LevelDifficulty == 1)
		PrintIntroduction(LevelDifficulty);
	else
		std::cout << "\n*** You put the valuables into your bag and move on to the next debosit box with a difficulty of: " << LevelDifficulty << ". ***\n";

	// Declare 3 number code.
	const int CodeA = rand() % LevelDifficulty + LevelDifficulty;
	const int CodeB = rand() % LevelDifficulty + LevelDifficulty;
	const int CodeC = rand() % LevelDifficulty + LevelDifficulty;
	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;
	int	CodeResult = (((CodeA * 10) + CodeB) * 10) + CodeC; 

	// Print the sum and product to the terminal.
	std::cout << std::endl << "# There are 3 numbers in the code.";
	std::cout << std::endl << "# The codes add up to: " << CodeSum;
	std::cout << std::endl << "# The codes multiply to give: " << CodeProduct << std::endl;

	int PlayerGuess;
	int GuessA, GuessB, GuessC;

	// Store the player guess
	std::cin >> PlayerGuess;

	// Here I separate the numbers to individual digits. In the Udemy course the idea was to read each code number with its own cin call and the player had to input the numbers separetly.
	// I felt like that is unintuitive, so I went with this approach which is also more efficient.
	GuessA = PlayerGuess / 100;
	GuessB = PlayerGuess / 10 - (GuessA * 10);
	GuessC = PlayerGuess - (GuessB * 10) - (GuessA * 100);
	
	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;
	
	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		std::cout << "*** The lock makes an audible click as it opens, the code was correct! ***\n";
		return true;
	}
	else
	{
		std::cout << "*** The lock stays locked, you have entered the wrong code. The correct code seemed to be " << CodeResult << ". Alarms start to ring, it's time to run! ***\n";
		return false;
	}
}

int		main()
{
	int LevelDifficulty = 1;
	const int MaxDifficulty = 5;
	srand(time(NULL)); // Seed rand with a new random sequence based on time of day

	while (LevelDifficulty <= MaxDifficulty) // Loop the game until all levels are completed or the answer is wrong.
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear(); // Clears any errors
		std::cin.ignore(); // Discards the buffer
		if (bLevelComplete)
		{
			LevelDifficulty++;
		}
		else
			return 0;
		
	}
	std::cout << "\n*** Great job! You cleared all five boxes and your time is running out, time to get out. ***\n";
	return 0;
}