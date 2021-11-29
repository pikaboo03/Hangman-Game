// payal		PAYD1801
// sudipto sarkar  SARS1D1801

#include <iostream>

using namespace std;

//To find the guessed character from the array
bool isFound(char arr[], char guess)
{
	int count = 0;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] == guess)
			count++;
	}
	if (count > 0)
		return true;
	else
		return false;
}
// to count number of guess required
int countNumOfGuess(char arr[], int size, int numOfGuess)
{
	if (size < 10)
		numOfGuess = 10;
	else if (size > 20)
		numOfGuess = 20;
	else
		numOfGuess = size + 5;
	return numOfGuess;
}
// to count the length of the array when it is stopped
bool countLength(char arr[], int size, char a)
{
	int counter =0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != a)
		{
			counter++;
		}

	}
	if (counter == size)
		return true;
	else
		return false;
}
// to find the guess from the start index
bool isFoundFromIndex(int startIndex, char arr[], char guess)
{
	for(int i = startIndex; arr[i] != '\0'; i++)
	{
		if(arr[i] == guess)
			return true;
		else
			return false;
	}
}
//to replace the elements of array with the guess
char *replaceAll( char arr[], char str[], char guess)
{
	for(int i = 0; str[i] != '\0'; i++)
	{
		if(isFoundFromIndex(i, str, guess) == true)
			arr[i] = guess;
	}
	return arr;
}
//Comparing the two strings
int stringCompare(char str1[], char str2[])
{
	int answer=0, i=0;
	while( str1[i]!=NULL || str2[i]!=NULL)
	{
		if(str1[i]!=str2[i])
		{
			answer= 1;
			break;
		}
		i++;
	}
	return answer;
}

int main()
{
	char response;
	do
	{
		int length = 0;
		char *str = new char[20];	
		char *arr = new char[length];
		cout << "Enter the secret word(all in lowercase): ";
		cin >> str;
		cout << "=========================================" << endl;
		cout << endl;
		cout << "Word so far: ";
		while (str[length] != '\0')
		{
			length++;
		}
		char a = '*';
		for (int i = 0; i < length; i++)
		{
			arr[i] = a;
		}
		arr[length] = '\0';
		cout << arr << endl;

		int numOfGuess = 0;
		char guess;
	
		int i = 1;
		do
		{
			cout << "Take guess number " << i << ": ";
			cin >> guess;
			if (isFound(str, guess) == true)
			{
				cout << "got it!" << endl;
				cout << endl;
				cout << "Word so far: " << replaceAll(arr, str, guess) << endl;
				if(countLength(arr, length, a) == true)
					break;
			}
			else
			{
				cout << "Sorry." << endl;
				cout << endl;
				cout << "word so far: " << replaceAll(arr, str, guess) << endl;
			}
			i++;
		} while (i <= countNumOfGuess(arr, length, numOfGuess) && arr != str);
		if (stringCompare(str, arr)==0)
		{
			cout << "Good. You correctly guessed the word: " << str << endl;
		}
		else
			cout << "Sorry no more lives. The word is " << str << endl;
		cout << "Do you want to play one more time ? y / n ? ";
		cin >> response;
		cout << endl;
		} while (response != 'n');
		if (response == 'n')
			cout << "Bye!" << endl;
		system("pause");
		return 0;
}

