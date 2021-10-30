#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void histogram();

int main()
{

	ifstream dataFile("C:\\Users\\mijac\\Downloads\\xfile.txt");
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

	double totalScore = 0;
	double score[25];
	int numCorrect;
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
					totalScore++;
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
		cout << fixed << setprecision(2) << (score[j] / 30) * 100 << '%' << endl;
	}

	// Bad data checking
	if (l > 0)
	{
		cout << "\nErrors:\n";
		for (int m = 0; m < l; m++)
		{
			cout << "\"" << errorQuestion[m] << "\" detected as answer for " << errorName[m]
				<< " on question " << errorQuestionNum[m] << endl;
		}
	}

	double averageScore = (((totalScore / 25) / 30) * 100);
	cout << "\nThe average exam score is: " << averageScore << "%\n\n";

	return 0;
}

void histogram() { //fix this shit

	int row1 = 0, row2 = 0, row3 = 0, row4 = 0, row5 = 0, row6 = 0; //call "score"
	for (int n = 0; n < 25; n++)
	{
		if (score[n] >= 0 && score[n] <= 5) {
			row1++;
		}
		else if (score[n] >= 6 && score[n] <= 10) {
			row2++;
		}
		else if (score[n] >= 11 && score[n] <= 15) {
			row3++;
		}
		else if (score[n] >= 16 && score[n] <= 20) {
			row4++;
		}
		else if (score[n] >= 21 && score[n] <= 25) {
			row5++;
		}
		else {
			row6++;
		}
	}

	cout << "Frequency\n" << "=========\n";
	cout << left << setw(15) << "Score" << left << setw(15) << "Obtained By"
		<< "    5   10   15   20   25" << endl;
	cout << left << setw(15) << "-----" << left << setw(15) << "-----------"
		<< "----|----|----|----|----|" << endl;
	cout << left << setw(20) << "0...5" << left << setw(10) << row1;
	for (int r1 = 0; r1 < row1; r1++)
	{
		cout << '*';
	}
	cout << '\n' << left << setw(20) << "6...10" << left << setw(10) << row2;
	for (int r2 = 0; r2 < row2; r2++)
	{
		cout << '*';
	}
	cout << '\n' << left << setw(20) << "11...15" << left << setw(10) << row3;
	for (int r3 = 0; r3 < row3; r3++)
	{
		cout << '*';
	}
	cout << '\n' << left << setw(20) << "16...20" << left << setw(10) << row4;
	for (int r4 = 0; r4 < row4; r4++)
	{
		cout << '*';
	}
	cout << '\n' << left << setw(20) << "21...25" << left << setw(10) << row5;
	for (int r5 = 0; r5 < row5; r5++)
	{
		cout << '*';
	}
	cout << '\n' << left << setw(20) << "26...30" << left << setw(10) << row6;
	for (int r6 = 0; r6 < row6; r6++)
	{
		cout << '*';
	}
	cout << endl;

}