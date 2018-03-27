#include "Cipher.h"

Cipher::Cipher() {
	std::string abc = "abcdefghijklmnopqrstuvwxyz";
	char temp = 'a';

	// creating cipher array
	for (int i = 0; i < 26; i++) {
		cipher[i] = abc;

		//saving first letter
		temp = abc.at(0);

		//erasing first letter
		abc.erase(0, 1);

		//appending it to the end
		abc.push_back(temp);
	}
}

Cipher::~Cipher() {
}

char Cipher::getEncodedLetter(char a, char b) {
	// a = 0, b = 1, ... z = 25
	int indexA = (a - 97);
	int indexB = (b - 97);

	return cipher[indexA].at(indexB);
}
char Cipher::getDecodedLetter(char a, char b) {
	// a = 0, b = 1, ... z = 25
	int indexA = (a - 97);
	int indexB = cipher[indexA].find(b);

	return cipher[0].at(indexB);
}

std::string Cipher::createKeyword(std::string key, std::string message) {
	std::string keyword = "";
	int j = 0;
	for (int i = 0; i < message.length(); i++) {

		//reset to begining of key if nessesarry
		if (j > key.length() - 1)
			j = 0;

		keyword.push_back(key.at(j));
		j++;

	}
	return keyword;
}

std::string Cipher::getEncodedMessage(std::string keyword, std::string message) {
	std::string EncodedMessage = "";

	for (int i = 0; i < keyword.length(); i++) 
		EncodedMessage.push_back(getEncodedLetter(keyword[i], message[i]));
	
	return EncodedMessage;
}

std::string Cipher::getDecodedMessage(std::string keyword, std::string EncodedMessage) {
	std::string DecodedMessage = "";

	for (int i = 0; i < keyword.length(); i++)
		DecodedMessage.push_back(getDecodedLetter(keyword[i], EncodedMessage[i]));

	return DecodedMessage;
}