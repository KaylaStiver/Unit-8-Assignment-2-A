// Kayla Stiver
// CIS 1202 800
// April 28th 2022

#include <iostream>
#include <cctype>

using namespace std;

class Exceptions {
private:
	char start;
	int offset;
	char returnChar;
public:
	Exceptions() {
		start = 'A';
		offset = 0;
		returnChar = 'B';
	}

	class invalidCharacterException {};
	class invalidRangeException {};

	void setStart(char);
	void setOffset(int);
	char getStart() const;
	int getOffset() const;
	char character(char, int);
};

int main() {

	char start;
	int offset;
	char returnChar;

	Exceptions myException;

	cout << "Please enter start character: ";
	cin >> start;
	cout << "Please enter offset: ";
	cin >> offset;

	try {
		myException.setStart(start);
		myException.setOffset(offset);
		returnChar = myException.character(start, offset);
		cout << "Returned character is: " << returnChar << endl;
	}
	catch (Exceptions::invalidCharacterException) {
		cout << "Error: invalidCharacterException thrown." << endl;
	}
	catch (Exceptions::invalidRangeException) {
		cout << "Error: invalidRangeException thrown." << endl;
	}
	
	return 0;
}
void Exceptions::setStart(char expChar) {
	if (isalpha(expChar) == 0) {
		throw invalidCharacterException();
	}
	start = expChar;
}
void Exceptions::setOffset(int expInt) {
	if (start == 26 && expInt > 0) {
		throw invalidRangeException();
	}
	offset = expInt;
}
char Exceptions::getStart() const {
	return start;
}
int Exceptions::getOffset() const {
	return offset;
}
char Exceptions::character(char start, int offset) {
	char alphaUpper[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char alphaLower[27] = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < 27; i++) {
		if (isupper(start) != 0) {
			if (start == alphaUpper[i]) {
				i += offset;
				if (i < 0) {
					throw invalidRangeException();
				}
				if (i > 26) {
					throw invalidRangeException();
				}
				return alphaUpper[i];
			}
		}
		if (islower(start) != 0) {
			if (start == alphaLower[i]) {
				i += offset;
				if (i < 0) {
					throw invalidRangeException();
				}
				if (i > 26) {
					throw invalidRangeException();
				}
				return alphaLower[i];
			}
		}
	}
}