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
	cout << answerKey << endl;

	cout << left << setw(25) << "Student Name" << left << setw(37) << "Answers" << "Score" << endl;

	int i = 0;
	while (getline(dataFile, names) && getline(dataFile, grades))
	{
		namesArr[i] = names;
		gradesArr[i] = grades;
		cout << left << setw(25) << namesArr[i]; // put later in for loop w scores
		cout << left << setw(37) << gradesArr[i] << endl;
		i++;
	}

	const char* answerArr;
	answerArr = answerKey.c_str();

	const char* questionArr;

	for (int j = 0; j < 25; j++)
	{
		questionArr = gradesArr[j].c_str(); // for i = 0-24, put gradesArr[i] into questionArr and compare

		for (int k = 0; k < 30; k++)
		{
			//compare here
		}

		cout << endl;
	}



	/*
	for (int k = 0; k < 30; k++)
	{
		for loop for comparing each letter
	}
	*/
}