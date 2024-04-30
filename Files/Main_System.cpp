
/*
Name:		Muhammad Fawad Hussain Awan
Roll#		23i0719
Section:	F
Instructer: Marrium Hida
TA:			Ariyan Chaudhary
*/

#include<iostream>
#include"Computer.h"
#include"Components.h"
#include"CPU.h"

using namespace std;


int main() {


	PCAssembly myPC;
	MACAssembly myMAC;//main class objects containing all others pricess
	string details;//="\n\n\n\n\n\n\n\n-----------------------------------------------------------------------------\n Details:\n\n";
	bool main = true;
	bool sub = true;
	while (main) {// runs till user exits program
		sub = true;
		details = "\n\n\n\n\n\n\n\n-----------------------------------------------------------------------------\n Details:\n\n";

		char ch;
		while (sub) {// runs untill system is complete or procedure fails to restart

			int choice;
			cout << "\nWelcome to MFHA_A3 Computer Assembly!" << endl;
			cout << "What do you want to buy:\n1.PC\n2.Mac\nCHoice:";
			cin >> choice;
			if (choice == 1) {
				cout << "What do you want to buy:\n1.Desktop\n2.Laptop\n3.Tablet\nCHoice:";
				cin >> choice;
				if (choice >= 1 && choice <= 3)
					sub=myPC.AssemblePC(choice);
				else
					sub = false;
				details += myPC.getDetails();
				details += "\nTotalPrice: Rs. " + to_string(myPC.getTotalPrice());
			}
			else if(choice == 2) {
				cout << "What do you want to buy:\n1.Desktop\n2.Laptop\n3.Tablet\nCHoice:";
				cin >> choice;
				if (choice >= 1 && choice <= 3)
					sub=myMAC.AssembleMAC(choice);
				else
					sub = false;
				details += myMAC.getDetails();
				details += "\nTotalPrice: Rs. " + to_string(myMAC.getTotalPrice());
			}
			else {
				cout << "\n\ninvalid input\n";
				sub = false;
			}




			if (sub == true)
				break;
			
		}
		
		if (!sub) {
			cout << "\nProcess Failed!\n";
			cout << "To restart enter \'1\':";
			cin >> ch;
			if (ch != '1')
				main = false;
		}
		else {
			
			cout << details;
			cout << "\nTo restart enter \'1\':";
			cin >> ch;
			if (ch != '1')
				main = false;
		}
	}

	cout << "\n\n Thank you for using MFHA_A3 Computer Assembly Services!" << endl;

	return 0;
}