#include <iostream>

using namespace std;

int candyGame(int numCandies, int moveNum) 
{
	if (moveNum > 0) {
		if (numCandies == 17) //Solution found
		{
			cout << "Found solution, I have exactly 17 candies, with " << moveNum << " moves left" << "." << endl;
			return 0;
		}

		if (numCandies % 2 == 0) //If even reduce by half
		{
			if (candyGame(numCandies / 2, moveNum - 1) == 0)
			{
				cout << "Reduce " << numCandies << " by half to get " << numCandies / 2 << "." << endl;
				return 0;
			}
		}
		if (numCandies % 3 == 0 && numCandies + (numCandies / 3) <= 10000)
		{
			if (candyGame(numCandies + (numCandies / 3), moveNum - 1) == 0)
			{
				cout << "With " << numCandies << ", add 1/3 to get " << numCandies + (numCandies / 3) << "." << endl;
				return 0;
			}
		}
		if (numCandies + 23 <= 10000)
		{
			if (candyGame(numCandies + 23, moveNum - 1) == 0)
			{
				cout << "With " << numCandies << ", add 23 to get " << numCandies + 23 << "." << endl;
				return 0;
			}
		}
	}
	return -1; //No solution found
}
int main()
{
	int initialCandies =0;
	char choice;
	do
	{
		cout << "How many candies are you starting with? ";
		cin >> initialCandies;
		while (initialCandies <=0 || initialCandies> 10000)
		{
			cout << "Number of candies must be greater than 0 and no more than 10000" << endl;
			cout << "How many candies are you starting with? ";
			cin >> initialCandies;
		}
		cout << "Searching for a solution within 20 moves...." << endl;
		if (candyGame(initialCandies, 20) == -1) //No solution found
		{
			cout << "No solution found within 20 moves. Sorry." << endl;
		}
		cout << "Would you like to try again [Y/N]? ";
		cin >> choice;
		cout << endl;
	}while(choice == 'y' || choice == 'Y');
	return 0;
}