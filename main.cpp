#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
const int totalstd = 10;
const int amntscores = 5;
void getdata(int ids2[totalstd], string names2[totalstd], int scores2[totalstd][amntscores]);
void detgrade(int totals2[totalstd], int scores2[totalstd][amntscores], char grades2[totalstd], string names2[totalstd]);
void classhighscore(int totals2[totalstd], int maximum2, string maxstd2, string names2[totalstd]);
string searchstud(string names2[totalstd]);
void displaystud(string search2, string names2[totalstd], int scores2[totalstd][amntscores]);
void report121(string names2[totalstd], char grades2[totalstd]);
int main() {
	int ids[totalstd];
	int scores[totalstd][amntscores];
	int totals[totalstd] = { 0,0,0,0,0,0,0,0,0,0 };
	int maximum = 0, alltestscores = 0;
	string names[totalstd], maxstd, search;
	char grades[totalstd];
	getdata(ids, names, scores);
	detgrade(totals, scores, grades, names);
	classhighscore(totals, maximum, maxstd, names);
	search = searchstud(names);
	displaystud(search, names, scores);
	report121(names, grades);
	system("Pause");
	return 0;
}
void getdata(int ids2[totalstd], string names2[totalstd], int scores2[totalstd][amntscores])
{
	ifstream inFile;
	inFile.open("data121.txt");

	for (int i = 0; i < totalstd; i++) {
		inFile >> ids2[i];
		inFile.ignore(1, ',');
		inFile.ignore(1, ' ');
		getline(inFile, names2[i], ',');
		for (int j = 0; j < amntscores; j++) {
			inFile >> scores2[i][j];
			inFile.ignore();
		}
	}
	inFile.close();
}
void detgrade(int totals2[totalstd], int scores2[totalstd][amntscores], char grades2[totalstd], string names2[totalstd])
{
	for (int k = 0; k < totalstd; k++) {
		for (int l = 0; l < amntscores; l++) {
			totals2[k] += scores2[k][l];
		}
	}

	for (int k = 0; k < totalstd; k++)
	{
		if ((totals2[k] >= 90) && (totals2[k] <= 100)) {
			grades2[k] = 'A';
		}
		else if ((totals2[k] >= 80) && (totals2[k] <= 89)) {
			grades2[k] = 'B';
		}
		else if ((totals2[k] >= 70) && (totals2[k] <= 79)) {
			grades2[k] = 'C';
		}
		else if ((totals2[k] >= 60) && (totals2[k] <= 69)) {
			grades2[k] = 'D';
		}
		else if ((totals2[k] >= 0) && (totals2[k] <= 59)) {
			grades2[k] = 'F';
		}
	}
	for (int i = 0; i < totalstd; i++) {
		cout << left << setw(18) << names2[i] << ", your total test score is " << totals2[i] << " and you are receiving the letter grade " << grades2[i] << "." << endl;

	}
}
void classhighscore(int totals2[totalstd], int maximum2, string maxstd2, string names2[totalstd])
{
	for (int i = 0; i < totalstd; i++) {
		if (totals2[i] > maximum2)
			maximum2 = totals2[i];
		if (totals2[i] == maximum2)
			maxstd2 = names2[i];
	}
	cout << endl << left << setw(18) << maxstd2 << ", Congratulations!!! You have received the overall maximum points " << maximum2 << endl;
}
string searchstud(string names2[totalstd])
{
	char choice;
	string search2;
	bool flag = false;
	cout << "Would you like to search for a student in the class(y/n)? " << endl;
	cin >> choice;
	cin.ignore();
	if ((choice == 'y') || (choice == 'Y'))
	{
		cout << "Please enter the student's name whom you would want to search for(separate first and last with space): " << endl;
		getline(cin, search2);
		do {
			for (int i = 0; i < totalstd; i++)
			{
				if (names2[i] == search2)
				{
					flag = true;
					break;
				}
			}
			if (flag == true) {
				return search2;
			}
			if (flag == false) {
				flag = false;
				cout << "Error!! Either the name you entered was not capitalized, mispelled, or there is no student in the class that matches the name entered." << endl;
				cout << "Please enter a studnet name who is in the class: " << endl;
				getline(cin, search2);
			}
		} while (flag == false);
	}
	if ((choice == 'n') || (choice == 'N'))
	{
		search2 = "None";
		return search2;
	}
}
void displaystud(string search2, string names2[totalstd], int scores2[totalstd][amntscores])
{
	for (int i = 0; i < totalstd; i++)
	{
		if (search2 == names2[i])
		{
			for (int j = 0; j < amntscores; j++)
				cout << scores2[i][j] << " ";
		}
		else if (search2 == "None")
			break;
	}
}
void report121(string names2[totalstd], char grades2[totalstd])
{
	ofstream outFile;
	outFile.open("report121.txt");
	for (int i = 0; i < totalstd; i++) {
		outFile << left << setw(18) << names2[i] << " " << "Grade: " << grades2[i] << endl;
	}
	cout << endl;
}
