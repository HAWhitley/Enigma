#include <iostream>
#include <string>

using namespace std;

int pbset[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int rotor1[] = {69, 75, 77, 70, 76, 71, 68, 81, 86, 90, 78, 84, 79, 87, 89, 72, 88, 85, 83, 80, 65, 73, 66, 82, 67, 74};
int rotor2[] = {65, 74, 68, 75, 83, 73, 82, 85, 88, 66, 76, 72, 87, 84, 77, 67, 81, 71, 90, 78, 80, 89, 70, 86, 79, 69};
int rotor3[] = {66, 68, 70, 72, 74, 76, 67, 80, 82, 84, 88, 86, 90, 78, 89, 69, 73, 87, 71, 65, 75, 77, 85, 83, 81, 79};
int rrottype;
int rrotset;
int rightrot = 0;

//determines the plugboard settings
void plugBoardSettings() {
	int first = 0;
	int second = 0;
	int count = 1;
	cout << "Welcome to the Plugboard!" << endl;
	for(int i = 0; i < 26; i++) {
		int set = 65 + i;
		if(pbset[first] == 0) {
			int setting = 65 + first;
			char letter;
			cout << "Please enter a setting for " << (char)setting << ": ";
			cin >> letter;
			for(int j = 0; j < 26; j++) {
				while (toupper(letter) == pbset[j]) {
					cout << "Letter was already entered. Try again: ";
					cin >> letter;
				}
			}
			second = toupper(letter) - 65;
			pbset[first] = toupper(letter);
			pbset[second] = first + 65;
		}
		first++;
	}
}

//sends the string through the plugboard
int plugBoard(int letter) {
	return pbset[letter-65];
}

int rightRotor(int letter) {
	if(rightrot == 26) {
		rightrot = 0;
	}
	int newlet = (letter + rightrot + rrotset - 65) % 26;
	if(rrottype == 1) {
		return rotor1[newlet];
	}
	else if(rrottype == 2) {
		return rotor2[newlet];
	}
	else {
		return rotor3[newlet];
	}
}

int main(int argc, char *argv[]) {

	string message;
	char rrotchar;

	cout << "Welcome to the Nazi Enigma Machine!\n" << endl;

	//Plugboard settings
        plugBoardSettings();
	cout << endl;

	cout << "Please enter a letter setting for the right rotor: ";
	cin >> rrotchar;
	while(toupper(rrotchar) < 65 || toupper(rrotchar) > 90) {
		cout << "This is not a letter. Try again: ";
		cin >> rrotchar;
	}
	cout << "Please enter a rotor setting for the right rotor (1,2,3): ";
	cin >> rrottype;
	while(rrottype < 1 || rrottype > 3) {
	       	cout << "This is not an option. Try again: ";
		cin >> rrottype;
 	}		

	rrotset = toupper(rrotchar) - 65;

	//Ask for message
	cout << "\nPlease enter the message you want to encrypt: " << endl;
	cin.ignore();
	getline(cin, message);

	cout << "\nMessage: " << endl;
	for(string::size_type i = 0; i < message.length(); i++) {
		//Changes the message to all uppercase
		int letter = toupper(message[i]);
		if(letter >= 65 && letter <= 90) {
			//Sends message through plugBoard
	       		int pb1 = plugBoard(letter);
			int rotr = rightRotor(pb1);
			char encrypt = (char)rotr;
			cout << encrypt;
			rightrot++;
		}
		else {
			char extra = (char)letter;
			cout << extra;
		}	
	}
	cout << endl;
	return 0;

}
