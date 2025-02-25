#include "Encryption.h"
#include <fstream>
bool(performceasarcipher(std::string &content, bool encrypt)) {
	int shift = encrypt ? 3 : -3;
	for (char& ch : content) {
		if (isalpha(ch)) {
			char base = isupper(ch) ? 'A' : 'a';
			ch = static_cast<char>((ch - base + shift + 26) % 26); 

		}
	}
	return true;

}
bool encryptFile(const std::string& filename, bool encrypt) {
	//open file
	std::ifstream infile(filename);
	if (!infile) {
		return false;

	}
	//Read content of the file
	std::string content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());

	infile.close();

	if (performceasarcipher(content, encrypt)) {
		std::ofstream outfile(encrypt ? "Encrypted_" + filename : "Decrypt_" + filename);
		if (!outfile) {
			return false;
		}

		outfile << content;
		outfile.close();
		return true;
	}

}
