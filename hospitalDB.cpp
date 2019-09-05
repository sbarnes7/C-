#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

#include "PatientAccount.h"
#include "Surgery.h"

using namespace std;

bool patientSortChargeA(PatientAccount p1, PatientAccount p2)
{
	return p1.getTotal() < p2.getTotal();
}
bool patientSortChargeD(PatientAccount p1, PatientAccount p2)
{
	return p1.getTotal() > p2.getTotal();
}
bool patientSortNameA(PatientAccount p1, PatientAccount p2)
{
	return p1.getLName() < p2.getLName();
}
bool patientSortNameD(PatientAccount p1, PatientAccount p2)
{
	return p1.getLName() > p2.getLName();
}
//function prototypes
int numPatientsInput();
void InitializePatient(PatientAccount[], int&);
void menu(PatientAccount[], int&);

void findPatient(PatientAccount[], int&);
void findPatientFee(PatientAccount[], int&);
void displayPatientInfo(PatientAccount[], int&);
void patientFeeInfoDatabase(PatientAccount[], int&);
void sortPatientInfo(PatientAccount[], int&);
void displayMorePatientInfo(PatientAccount[], int&);

int main()
{
	//dynamically allocates the patients to save space
	int numPatients = numPatientsInput();
	PatientAccount * patient = new PatientAccount[numPatients];
	InitializePatient(patient, numPatients);
	patient[0].getLName();
	menu(patient, numPatients);
	//frees up space
	delete[] patient;
	cout << "Goodbye!" << endl;
	return 0;
}
//function to ask and display the number of patients
int numPatientsInput()
{
	int numPatients;
	cout << "Please enter how many patients there are." << endl;
	do {
		cin >> numPatients;
		if (numPatients < 1)
			cout << "Inavlid input. Must be 1 or higher." << endl;
	} while (numPatients < 1);
	return numPatients;
}

void InitializePatient(PatientAccount patient[], int &numPatients)
{
	for (int i = 0; i < numPatients; i++)
	{
		cout << "Patient: " << i + 1 << endl;
		patient[i].setFName();
		patient[i].setLName();
		patient[i].setNumDays();
		patient[i].setStayCost();
		cout << "=================================================" << endl;
		cout << "The Cost of the Stay is: $" << patient[i].getStayCost() << endl;
		cout << "=================================================" << endl;
		patient[i].setSurgery();
		patient[i].setPharmacy();
		patient[i].setCharge();
	}
	return;
}
//function that displays the menu in a loop while the user can look up different things on a patient
void menu(PatientAccount patient[], int &numPatients)
{
	char choice;
	do {
		cout << "======================================" << endl;
		cout << "Patient Fee Information Database Menu." << endl;
		cout << "======================================" << endl;
		cout << "V - View Patient Fee Information Database." << endl;
		cout << "F - Find Patient Fee Information by Patient Name." << endl;
		cout << "S - Sort Patient Fee Information." << endl;
		cout << "A - Add Patient Fee." << endl;
		cout << "Q - Quit the program." << endl;
		cin >> choice;
		//input validation
		if (choice != 'V' && choice != 'F' && choice != 'S' && choice != 'A' && choice != 'Q' && choice != 'v' && choice != 'f' && choice != 's' && choice != 'a' && choice != 'q')
			cout << "Invalid choice!" << endl;
		toupper(choice);
		switch (choice)
		{
		case 'v':
		case 'V':
			cout << endl;
			cout << "Viewing Patient Fee Information Database." << endl;
			patientFeeInfoDatabase(patient, numPatients);
			cout << endl;
			break;
		case 'f':
		case 'F':
			cout << endl;
			cout << "Finding Patient Fee Information by Patient Name." << endl;
			cout << endl;
			findPatient(patient, numPatients);
			break;
		case 's':
		case 'S':
			cout << endl;
			cout << "Sorting Patient Fee Information." << endl;
			sortPatientInfo(patient, numPatients);
			cout << endl;
			break;
		case 'a':
		case 'A':
			cout << endl;
			cout << "Adding Patiend Fee." << endl;
			cout << endl;
			findPatientFee(patient, numPatients);
			break;
		case 'q':
		case 'Q':
			cout << endl;
			cout << "Exiting Program." << endl;
			cout << endl;
			break;
		default:
			cout << endl;
			cout << "Invalid input. Please try again." << endl;
			cout << endl;
			break;
		}
	} while (choice != 'Q' && choice != 'q');
	return;
}
//function used for finding a patient
void findPatient(PatientAccount patient[], int &numPatients)
{
	string choiceLast;
	string choiceFirst;
	cout << "Enter the last name of the person you wish to search for. (Enter Quit to exit)" << endl;
	cin >> choiceLast;
	cout << "Enter the first name." << endl;
	cin >> choiceFirst;
	for (int i = 0; i < numPatients; i++)
	{
		if (!choiceLast.compare(patient[i].getLName()))
		{
			if (!choiceFirst.compare(patient[i].getFName()))
			{
				displayMorePatientInfo(patient, i);
				return;
			}
		}
	}
	cout << "Patient not found!" << endl;
	return;
}
//searches for a patient and displays their charge
void findPatientFee(PatientAccount patient[], int &numPatients)
{
	string choiceLast;
	string choiceFirst;
	cout << "Enter the last name of the person you wish to search for. (Enter Quit to exit)" << endl;
	cin >> choiceLast;
	cout << "Enter the first name." << endl;
	cin >> choiceFirst;
	for (int i = 0; i < numPatients; i++)
	{
		if (!choiceLast.compare(patient[i].getLName()))
		{
			if (!choiceFirst.compare(patient[i].getFName()))
				patient[i].addFee();
			return;
		}
	}
	cout << "Patient not found!" << endl;
	return;
}
//function to display a patients general information
void displayPatientInfo(PatientAccount patient[], int &patientNum)
{
	cout << "======================================" << endl;
	cout << "The patient " << patient[patientNum].getLName() << " ";
	cout << patient[patientNum].getFName() << endl;
	cout << "Spent " << patient[patientNum].getNumDays() << " day(s) in the hospital and their bill is $";
	cout << patient[patientNum].getCharge() << endl;
	cout << "======================================" << endl;
	return;
}
//function to sort the patients
void sortPatientInfo(PatientAccount patient[], int &patientNum)
{
	int choice;
	do {
		cout << "Choose how you would like the patients to be sorted. (-1 to quit)" << endl;
		cout << "1) Last name ascending.\n2) Last name descending.\n3) Charge amount ascending.\n4) Charge amount descending." << endl;
		cin >> choice;
		switch (choice)
		{
		case -1:
			return;
		case 1:
			sort(patient, patient + patientNum, patientSortNameA);
			for (int i = 0; i < patientNum; i++)
			{
				displayPatientInfo(patient, i);
			}
			break;
		case 2:
			sort(patient, patient + patientNum, patientSortNameD);
			for (int i = 0; i < patientNum; i++)
			{
				displayPatientInfo(patient, i);
			}
			break;
		case 3:
			sort(patient, patient + patientNum, patientSortChargeA);
			for (int i = 0; i < patientNum; i++)
			{
				displayPatientInfo(patient, i);
			}
			break;
		case 4:
			sort(patient, patient + patientNum, patientSortChargeD);
			for (int i = 0; i < patientNum; i++)
			{
				displayPatientInfo(patient, i);
			}
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != -1);
	return;
}
//displays the patients information
void patientFeeInfoDatabase(PatientAccount patient[], int &patientNum)
{
	cout << "====================================" << endl;
	cout << "Patient Fee Information" << endl;
	for (int i = 0; i < patientNum; i++) {
		patient[i].setCharge();
		cout << "====================================" << endl;
		cout << "Patient Name: " << patient[i].getFName() << " " << patient[i].getLName() << endl;
		cout << "Cost of Stay in hospital: $" << patient[i].getStayCost() << endl;
		cout << "Cost of Surgery: $" << patient[i].surgeryCost() << endl;
		cout << "Cost of Medication : $" << patient[i].pharmacyCost() << endl;
		cout << "Added Fees: $" << patient[i].getFee() << endl;
		cout << "The total bill is: $" << patient[i].getCharge() << endl;

	}
}

void displayMorePatientInfo(PatientAccount patient[], int &i)
{
	cout << "====================================" << endl;
	cout << "Patient Fee Information" << endl;
	patient[i].setCharge();
	cout << "====================================" << endl;
	cout << "Patient Name: " << patient[i].getFName() << " " << patient[i].getLName() << endl;
	cout << "Cost of Stay in hospital: $" << patient[i].getStayCost() << endl;
	cout << "Cost of Surgery: $" << patient[i].surgeryCost() << endl;
	cout << "Cost of Medication : $" << patient[i].pharmacyCost() << endl;
	cout << "Added Fees: $" << patient[i].getFee() << endl;
	cout << "The total bill is: $" << patient[i].getCharge() << endl;
	cout << "Types of surgery:" << endl;
	patient[i].Surgeries();
	cout << "Types of medication:" << endl;
	patient[i].Medications();
}