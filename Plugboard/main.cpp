#include <iostream>
#include <string>

using namespace std;

int pbset[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

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

int main(int argc, char *argv[]) {

	string message;

	cout << "Welcome to the Nazi Enigma Machine!\n" << endl;

	//Plugboard settings
	plugBoardSettings();

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
			char encrypt = (char)pb1;
			cout << encrypt;
		}
		else {
			char extra = (char)letter;
			cout << extra;
		}	
	}
	cout << endl;
	return 0;

}
