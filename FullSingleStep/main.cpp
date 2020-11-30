#include <iostream>
#include <string>

using namespace std;

//Plugboard settings
int pbset[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

//Rotor I settings
int rotor1[] = {69, 75, 77, 70, 76, 71, 68, 81, 86, 90, 78, 84, 79, 87, 89, 72, 88, 85, 83, 80, 65, 73, 66, 82, 67, 74};

//Rotor II settings
int rotor2[] = {65, 74, 68, 75, 83, 73, 82, 85, 88, 66, 76, 72, 87, 84, 77, 67, 81, 71, 90, 78, 80, 89, 70, 86, 79, 69};

//Rotor III settings
int rotor3[] = {66, 68, 70, 72, 74, 76, 67, 80, 82, 84, 88, 86, 90, 78, 89, 69, 73, 87, 71, 65, 75, 77, 85, 83, 81, 79};

//Reflector settings
int reflector[] = {89, 82, 85, 72, 81, 83, 76, 68, 80, 88, 78, 71, 79, 75, 77, 73, 69, 66, 70, 90, 67, 87, 86, 74, 65, 84};

//Chosen rotor for right rotor (I, II, III)
int rrottype;

//Chosen rotor for middle rotor (I, II, III)
int mrottype;

//Chosen rotor for left rotor (I, II, III)
int lrottype;

//Chosen letter for right rotor
int rrotset;

//Chosen letter for middle rotor
int mrotset;

//Chosen letter for left rotor
int lrotset;

//Stepping mechanism for right rotor
int rightrot = 0;

//Stepping mechanism for middle rotor
int middlerot = 0;

//Stepping mechanism for left rotor
int leftrot = 0;

//Determines the plugboard settings
void plugBoardSettings() {

	int first = 0;
	int second = 0;
	int count = 1;

	//Gets plugboard settings
	cout << "Welcome to the Plugboard!" << endl;
	for(int i = 0; i < 26; i++) {

		//If the setting has not already been made
		if(pbset[first] == 0) {
			int setting = 65 + first;
			char letter;

			//Gets the desired letter setting
			cout << "Please enter a setting for " << (char)setting << ": ";
			cin >> letter;

			//Checks for user stupidity
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

//Determines the rotor settings
void rotorSettings() {

	char rrotchar, mrotchar, lrotchar;
	char rrottypechar, mrottypechar, lrottypechar;

	//Get the desired letter setting for the right rotor
	cout << "Please enter a letter setting for the right rotor: ";
        cin >> rrotchar;
	
	//Check user stupidity
        while(toupper(rrotchar) < 65 || toupper(rrotchar) > 90) {
                cout << "This is not a letter. Try again: ";
                cin >> rrotchar;
        }

	//Get the desired letter setting for the middle rotor
        cout << "Please enter a letter setting for the middle rotor: ";
        cin >> mrotchar;

        //Check user stupidity
        while(toupper(mrotchar) < 65 || toupper(mrotchar) > 90) {
                cout << "This is not a letter. Try again: ";
                cin >> mrotchar;
        }

	//Get the desired letter setting for the left rotor
        cout << "Please enter a letter setting for the left rotor: ";
        cin >> lrotchar;

        //Check user stupidity
        while(toupper(lrotchar) < 65 || toupper(lrotchar) > 90) {
                cout << "This is not a letter. Try again: ";
                cin >> lrotchar;
        }

	//Get the desired rotor setting for the right rotor
        cout << "Please enter a rotor setting for the right rotor (1,2,3): ";
        cin >> rrottypechar;
	
	//Check user stupidity
        while((int)rrottypechar < 49 || (int)rrottypechar > 51) {
                cout << "This is not an option. Try again: ";
                cin >> rrottypechar;
        }

	//Get the desired rotor setting for the middle rotor
        cout << "Please enter a rotor setting for the middle rotor (1,2,3): ";
        cin >> mrottypechar;

        //Check user stupidity
        while((int)mrottypechar < 49 || (int)mrottypechar > 51) {
                cout << "This is not an option. Try again: ";
                cin >> mrottypechar;
        }

	//Get the desired rotor setting for the left rotor
        cout << "Please enter a rotor setting for the left rotor (1,2,3): ";
        cin >> lrottypechar;

        //Check user stupidity
        while((int)lrottypechar < 49 || (int)lrottypechar > 51) {
                cout << "This is not an option. Try again: ";
                cin >> lrottypechar;
        }

	//Assign the rotor type (I, II, III)
	rrottype = (int)rrottypechar - 48;

	//Assign the rotor type (I, II, III)
        mrottype = (int)mrottypechar - 48;

	//Assign the rotor type (I, II, III)
        lrottype = (int)lrottypechar - 48;

	//Assign rotor letter setting
        rrotset = toupper(rrotchar) - 65;

	//Assign rotor letter setting
        mrotset = toupper(mrotchar) - 65;

	//Assign rotor letter setting
        lrotset = toupper(mrotchar) - 65;

}

//Sends the string through the plugboard
int plugBoard(int letter) {

	return pbset[letter-65];

}

//Sends the string through the right rotor
int rightRotor(int letter) {

	//Reset stepping at 26th step
	if(rightrot == 26) {
		rightrot = 0;
		middlerot++;
	}

	//Encrypt character based on letter setting
	int newlet = (letter + rightrot + rrotset - 65) % 26;

	//Encrypt character based on rotor setting
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

//Sends the string through the middle rotor
int middleRotor(int letter) {

        //Reset stepping at 26th step
        if(middlerot == 26) {
                middlerot = 0;
		leftrot++;
        }

        //Encrypt character based on letter setting
        int newlet = (letter + middlerot + mrotset - 65) % 26;

        //Encrypt character based on rotor setting
        if(mrottype == 1) {
                return rotor1[newlet];
        }
        else if(mrottype == 2) {
                return rotor2[newlet];
        }
        else {
                return rotor3[newlet];
        }

}

//Sends the string through the left rotor
int leftRotor(int letter) {

        //Reset stepping at 26th step
        if(leftrot == 26) {
                leftrot = 0;
        }

        //Encrypt character based on letter setting
        int newlet = (letter + leftrot + lrotset - 65) % 26;

        //Encrypt character based on rotor setting
        if(lrottype == 1) {
                return rotor1[newlet];
        }
        else if(lrottype == 2) {
                return rotor2[newlet];
        }
        else {
                return rotor3[newlet];
        }

}

int reverse(int letter) {
	int leftLetter, middleLetter, rightLetter;

	//Reverse letter from left rotor
	if(lrottype == 1) {
		for(int i = 0; i < 26; i++) {
			if(rotor1[i] == letter) {
				leftLetter = i + 65 - leftrot - lrotset;
                                if(leftLetter < 65) {
                                        leftLetter = 90 - (65 - leftLetter) + 1;
                                }
			}
		}
	}
	else if(lrottype == 2) {
                for(int i = 0; i < 26; i++) {
                        if(rotor2[i] == letter) {
                                leftLetter = i + 65 - leftrot - lrotset;
                                if(leftLetter < 65) {
                                        leftLetter = 90 - (65 - leftLetter) + 1;
                                }
                        }
                }
        }
	else {
                for(int i = 0; i < 26; i++) {
                        if(rotor3[i] == letter) {
                                leftLetter = i + 65 - leftrot - lrotset;
                                if(leftLetter < 65) {
                                        leftLetter = 90 - (65 - leftLetter) + 1;
                                }
                        }
                }
        }

	//Reverse letter from middle rotor
	if(mrottype == 1) {
                for(int i = 0; i < 26; i++) {
                        if(rotor1[i] == leftLetter) {
                                middleLetter = i + 65 - middlerot - mrotset;
                                if(middleLetter < 65) {
                                        middleLetter = 90 - (65 - middleLetter) + 1;
                                }
                        }
                }
        }
	else if(mrottype == 2) {
                for(int i = 0; i < 26; i++) {
                        if(rotor2[i] == leftLetter) {
                                middleLetter = i + 65 - middlerot - mrotset;
                                if(middleLetter < 65) {
                                        middleLetter = 90 - (65 - middleLetter) + 1;
                                }
                        }
                }
        }
	else {
                for(int i = 0; i < 26; i++) {
                        if(rotor3[i] == leftLetter) {
                                middleLetter = i + 65 - middlerot - mrotset;
                                if(middleLetter < 65) {
                                        middleLetter = 90 - (65 - middleLetter) + 1;
                                }
                        }
                }
        }

	//Reverse letter from right rotor
	if(rrottype == 1) {
                for(int i = 0; i < 26; i++) {
                        if(rotor1[i] == middleLetter) {
                                rightLetter = i + 65 - rightrot - rrotset;
				if(rightLetter < 65) {
					rightLetter = 90 - (65 - rightLetter) + 1;
				}
                        }
                }
        }
	else if(rrottype == 2) {
                for(int i = 0; i < 26; i++) {
                        if(rotor2[i] == middleLetter) {
                                rightLetter = i + 65 - rightrot - rrotset;
                                if(rightLetter < 65) {
                                        rightLetter = 90 - (65 - rightLetter) + 1;
                                }
                        }
                }
        }
	else {
                for(int i = 0; i < 26; i++) {
                        if(rotor3[i] == middleLetter) {
                                rightLetter = i + 65 - rightrot - rrotset;
                                if(rightLetter < 65) {
                                        rightLetter = 90 - (65 - rightLetter) + 1;
                                }
                        }
                }
        }

	//Reverse letter from plugboard
	return plugBoard(rightLetter);

}

int Reflector(int letter) {
	int newlet = letter - 65;

	return reflector[newlet];
}

//Encrypt the message
void encrypt() {

	string message;

	//Ask for message
        cout << "\nPlease enter the message you want to encrypt: " << endl;
        cin.ignore();
        getline(cin, message);
	
	//Encrypt character by character
	cout << "\nMessage: " << endl;
        for(string::size_type i = 0; i < message.length(); i++) {
                //Changes the message to all uppercase
                int letter = toupper(message[i]);
                if(letter >= 65 && letter <= 90) {
                        //Sends message through plugBoard
                        int pb1 = plugBoard(letter);
                        int rotr = rightRotor(pb1);
			int rotm = middleRotor(rotr);
			int rotl = leftRotor(rotm);
			int reflect = Reflector(rotl);
			int rev = reverse(reflect);
                        char encrypt = (char)rev;
                        cout << encrypt;
                        rightrot++;
                }
                else {
                        char extra = (char)letter;
                        cout << extra;
                }
        }

}

int main(int argc, char *argv[]) {;

	cout << "Welcome to the Nazi Enigma Machine!\n" << endl;

	//Plugboard settings
        plugBoardSettings();
	cout << endl;
	
	//Rotor settings
	rotorSettings();
	cout << endl;

	//Encrypt
	encrypt();
	cout << endl;

	return 0;

}
