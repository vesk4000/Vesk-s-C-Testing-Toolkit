/**
	Created by Vesk
	February 2018
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

int n;///the number of tests
string problemName;///the name of the problem
int nDigits;///the number of digits in a test name
double timeLimit;

ifstream text1;///the fstream objects for the two texts
ifstream text2;
ifstream timez;

void input();///just input, what do ya think it is
void mainLoop();
string addZeros(int x, int num);///add enough zeros before a number to make it an exact length
void mainSolve(int x);///we use a function in the mainLoop so we can just return; and use it as break;


int main()
{
	input();
	mainLoop();
	return 0;
}

///input()
void input()
{
	cout << "Enter the name of the problem: ";
	cin >> problemName;
	cout << "Enter the number of tests: ";
	cin >> n;
	cout << "Enter the number of digits in a test name: ";
	cin >> nDigits;
	cout << "Enter the time limit ";
	cin >> timeLimit;
}

///mainLoop()
void mainLoop()
{
	timez.open("times.txt");
	for(int i = 1;i <= n; ++i)
	{
		///open the files
		string nameT1 = problemName + "." + addZeros(nDigits, i) + ".sol";
		text1.open(nameT1.c_str());

		string nameT2 = problemName + "." + addZeros(nDigits, i) + ".user.sol";
		text2.open(nameT2.c_str());
		double timezd;
		timez >> timezd;

		mainSolve(i);
		if(timezd > timeLimit)
		{
			cout << " (Over TL -> " << timezd << " )" << endl;
		}
		else
			cout << " (Under TL -> " << timezd << " )" << endl;
		///close the files
		text1.close();
		text2.close();
	}
	timez.close();
}

///mainSolve()
void mainSolve(int x)
{

	///see if the files have the same number of lines
	int linesT1 = 0;///the number of lines in Text 1
	int linesT2 = 0;///the number of lines in Text 2
	string buffer;
	while(!text1.eof())
	{
		getline(text1, buffer);
		linesT1++;
	}
	while(!text2.eof())
	{
		getline(text2, buffer);
		linesT2++;
	}
	if(linesT1 != linesT2)
	{
		cout << "Test " << x << " is not correct";
		return;
	}

	///go to the beginnings of the files
	text1.clear();
	text2.clear();
	text1.seekg(0, ios::beg);
	text2.seekg(0, ios::beg);

	///compare the files line by line
	for(int j = 0;j < linesT1; ++j)
	{
		string t1;
		string t2;
		getline(text1,t1);
		getline(text2,t2);
		if(t1.compare(t2) != 0)
		{
			j = linesT1;
			cout << "Test " << x << " is not correct";
			return;
		}
	}
	cout << "Test " << x << " is correct";
	return;
}

///addZeros(int x)
string addZeros(int x, int num)
{
	stringstream ss;
	ss << num;
	string sn = ss.str();
	while(sn.size() < x)
	{
		sn = "0" + sn;
	}
	return sn;
}
