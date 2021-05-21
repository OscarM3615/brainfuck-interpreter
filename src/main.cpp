#include <iostream>
#include "Parser.h"

using namespace std;

int main(int argc, char** argv) {
	Parser* parser;
	ifstream file;
	string code;

	if (argc != 2) {
		cout << "[*] No file specified." << endl;
		return 1;
	}

	file = ifstream(argv[1]);

	if (!file.is_open()) {
		cout << "[*] Source file not found." << endl;
		return 1;
	}

	while (file.good()) {
		code.push_back(file.get());
	}

	try {
		parser = new Parser(code.c_str());
		parser->run();
	} catch (string error) {
		cout << endl << "[*] " << error << endl;
	}

	delete parser;

	return 0;
}
