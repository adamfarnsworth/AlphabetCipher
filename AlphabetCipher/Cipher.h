#pragma once
#include <string>
#include <iostream>

class Cipher{

public:
	Cipher();
	~Cipher();
	std::string createKeyword(std::string key, std::string message);
	std::string getEncodedMessage(std::string keyword, std::string message);
	std::string getDecodedMessage(std::string keyword, std::string EncodedMessage);

private:
	std::string cipher[26];
	char getEncodedLetter(char a, char b);
	char getDecodedLetter(char a, char b);
};

