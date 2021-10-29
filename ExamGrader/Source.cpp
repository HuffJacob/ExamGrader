#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

	ifstream dataFile("C:\\Users\\mijac\\OneDrive\\Documents\\xfile.txt");
	string answerKey;
	string names;
	string grades;
	string namesArr[25];
	string gradesArr[25];
	
	getline(dataFile, answerKey);
	cout << "Answer key: " << answerKey << "\n\n";

	cout << left << setw(25) << "Student Name" << left << setw(37) << "Answers" << "Score" << endl;

	int i = 0;
	while (getline(dataFile, names) && getline(dataFile, grades))
	{
		namesArr[i] = names;
		gradesArr[i] = grades;
		i++;
	}

	string errorName[25];
	string errorQuestion[25];
	int errorQuestionNum[25];
	int l = 0;

	int numCorrect;
	int score[25];
	const char* questionArr;
	const char* answerArr;
	answerArr = answerKey.c_str();

	for (int j = 0; j < 25; j++)
	{
		questionArr = gradesArr[j].c_str();
		numCorrect = 0;

		for (int k = 0; k < 30; k++)
		{
			if (questionArr[k] == 'T' || questionArr[k] == 'F')
			{
				if (questionArr[k] == answerArr[k])
				{
					numCorrect++;
				}
			}
			else
			{
				errorName[l] = namesArr[j];
				errorQuestion[l] = questionArr[k];
				errorQuestionNum[l] = k + 1;
				l++;
			}
		}

		score[j] = numCorrect;
		
		cout << left << setw(25) << namesArr[j];
		cout << left << setw(37) << gradesArr[j];
		cout << score[j] << endl;
	}

	// Bad data checking
	cout << "\nErrors:\n";
	for (int m = 0; m < l; m++)
	{
		cout << "\"" << errorQuestion[m] << "\" detected as answer for " << errorName[m]
			 << " on question " << errorQuestionNum[m] << endl;
	}

	return 0;
}