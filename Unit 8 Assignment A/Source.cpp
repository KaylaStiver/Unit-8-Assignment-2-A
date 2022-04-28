// Kayla Stiver
// CIS 1202 800
// April 28th 2022

#include <iostream>
#include <cctype>

using namespace std;

char character(char, int);

int main() {

	char start = 'A';
	int offset = 0;
	char returnChar = 'A';

	cout << "Please enter start character: ";
	cin >> start;
	cout << "Please enter offset: ";
	cin >> offset;
	returnChar = character(start, offset);
	cout << "Returned character is: " << returnChar << endl;

	return 0;
}
char character(char start, int offset) {
	char alphaUpper[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char alphaLower[27] = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < 27; i++) {
		if (isupper(start) != 0) {
			if (start == alphaUpper[i]) {
				i += offset;
				if (i > 26) {
					i -= 26;
				}
				return alphaUpper[i];
			}
		}
		if (islower(start) != 0) {
			if (start == alphaLower[i]) {
				i += offset;
				if (i > 26) {
					i -= 26;
				}
				return alphaLower[i];
			}
		}
	}
}