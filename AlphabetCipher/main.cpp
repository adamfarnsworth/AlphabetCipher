#include <iostream>
#include "Cipher.h";

int main() {
	Cipher cf;

	std::string message = "";
	std::string key = "";
	std::string keyword = "";
	std::string encodedMessage = "";
	std::string decodedMessage = "";
	std::string secretString = "";

	// decoding
	key = "cloak";
	message = "klatrgafedvtssdwywcyty";
	keyword = cf.createKeyword(key, message);
	decodedMessage = cf.getDecodedMessage(keyword, message);
	std::cout << decodedMessage << std::endl;

	key = "python";
	message = "pjphmfamhrcaifxifvvfmzwqtmyswst";
	keyword = cf.createKeyword(key, message);
	decodedMessage = cf.getDecodedMessage(keyword, message);
	std::cout << decodedMessage << std::endl;

	key = "moore";
	message = "rcfpsgfspiecbcc";
	keyword = cf.createKeyword(key, message);
	decodedMessage = cf.getDecodedMessage(keyword, message);
	std::cout << decodedMessage << std::endl;

	// repeats till user exits manually
	while (true) {

		// gets the key and the message from the user
		secretString = "";
		getline(std::cin, secretString);

		// assigns values
		key = secretString.substr(0, secretString.find(" "));
		message = secretString.substr(secretString.find(" ") + 1, secretString.length() - 1);

		//creating keyword and encoded message
		keyword = cf.createKeyword(key, message);
		encodedMessage = cf.getEncodedMessage(keyword, message);

		// encoded message
		std::cout << encodedMessage << std::endl;

	}

}