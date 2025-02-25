#include<iostream>
#include"Encryption.h"
#include <string>

int main() {
	char mode;
	std::string filename;
	std::cout << "Enter filename: " ;
	std::getline(std::cin >> std::ws, filename);
	std::cout << "Enter a mode e to encrypt or d to decrypt: ";
	std::cin >> mode;
	std::cout << '\n';

	if ((char)tolower(mode) == 'e') {
		if (encryptFile(filename, true)) {
			std::cout << "Encrpytion successul" << '\n';
		}
		else {
			std::cerr << "Error: Encryption failed" << '\n';
		}

	}
	else if ((char)tolower(mode) == 'd') {
		if (encryptFile(filename, false)) {
			std::cout << "Decrpytion successul" << '\n';
		}
		else {
			std::cerr << "Error: Decryption failed" << '\n';
		}
	}
	else
	{
		std::cerr << "Error: invalid input";
	}




}