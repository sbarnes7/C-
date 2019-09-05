#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

//Samuel Barnes
//project 1

int main()
{
	/*fstream scores;
	string data;
	fstream grades;*/
	string stringA = "", stringB ="", stringC="", stringD="", stringE="";
	double a = 0, b = 0, c = 0, d = 0, e = 0, total = 0;
	//opening the files to print data to
		scores.open("scores.txt");
		grades.open("grades.txt");
		srand(time(0));
		//runs a for loop generating 30 students with random grades
		for(int student = 1; student < 31; student++)
	{
		//creates the random numbers between 50 and 100	
		const int MIN_VALUE = 50;
		const int MAX_VALUE = 100;
		int score = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
		//prints the student with their corresponding scores to the scores file
		scores << "Student " << student << "   " << score << "\n";
		//keeps a count of the number of each letter grade and creates a string for the grades in each letter
		if (score > 89 && score < 101)
		{
			a++;
			stringA += to_string(score) + "   ";
		}
		else if (score > 79 && score < 90)
		{
			b++;
			stringB += to_string(score) + "   ";
		}
		else if (score > 69 && score < 80)
		{
			c++;
			stringC += to_string(score) + "   ";
		}
		else if (score > 59 && score < 70)
		{
			d++;
			stringD += to_string(score) + "   ";
		}
		else if (score < 60)
		{
			e++;
			stringE += to_string(score) + "   ";
		}
		//variable created to store the sum of all grades for an average
		total = score + total;
		
		
		
	}
		scores.close();
		//prints the number of each letter grade to the grades file
		grades << "A: " << a << "\n" << "B: " << b << endl << "C: " << c << endl << "D: " << d << endl << "Fail: " << e  << "  :(" << endl;
		grades.close();
		//prints the average test score based on the total divided by 30
		cout << "The average test score is " << total / 30 << "%" << endl;
		//prints the percent of students in each letter grade category
		cout << "Percent A: " << (a / 30) * 100 <<"%" << "  Total A: " << a << endl 
			<< "Percent B: " << (b / 30) * 100 <<"%"<< "  Total B: " << b << endl
			<< "Percent C: " << (c / 30) * 100<<"%" << "  Total C: "<< c << endl
			<< "Percent D: " << (d / 30) * 100 <<"%"<< "  Total D: " << d << endl
			<< "Percent Fail: " << (e / 30) * 100 <<"%"<< "  Total Failed: "<< e << endl;
		int answer = 0;
		//a while loop that tests the condition after one run to display the menu and input an answer
		do
		{ 
			cout << "Please choose from the following menu, or 6 to exit the program.\n";
			cout << "1.) display student scores with grade A on screen\n2.) display student scores with B on screen\n3.) display student scores with C on screen\n4.) display student scores with D on screen\n5.) display student scores with grade F on screen\n6.) exit the program\n";
			
			cin >> answer;
			//displays the scores in the letter grade chosen by user input
			if (answer == 1)
				cout << stringA << endl;//cout scores of a
			else if (answer == 2)
				cout << stringB << endl;//cout scores of b
			else if (answer == 3)
				cout << stringC << endl;//cout scores of c
			else if (answer == 4)
				cout << stringD << endl;//cout scores of d
			else if (answer == 5)
			cout << stringE<< " better study more next time :)"<<endl;//cout scores of fail
			else
			{
			cout << "Thank you for running the program!\n";
			}
		}while (answer != 6);
		return 0;
}