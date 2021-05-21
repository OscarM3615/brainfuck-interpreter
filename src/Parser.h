#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Parser {
	private:
		unsigned char memory[255] = {0};
		unsigned char cursor;
		const char* instruction;
	public:
		Parser(const char program[]);

		void run();

		void toRight();
		void toLeft();
		void add();
		void substract();
		void write();
		void read();
		void startLoop();
		void endLoop();
};

Parser::Parser(const char program[]) {
	this->cursor = 0;
	this->instruction = program;
}

void Parser::run() {
	while (*instruction) {
		switch (*instruction) {
			case '>':
				this->toRight();
				break;
			case '<':
				this->toLeft();
				break;
			case '+':
				this->add();
				break;
			case '-':
				this->substract();
				break;
			case ',':
				this->read();
				break;
			case '.':
				this->write();
				break;
			case '[':
				this->startLoop();
				break;
			case ']':
				this->endLoop();
				break;
		}

		this->instruction++;
	}
}

/* Move the cursor position to the right. */
void Parser::toRight() {
	this->cursor++;
}

/* Move the cursor position to the left. */
void Parser::toLeft() {
	this->cursor--;
}

/* Increment the current cell value. */
void Parser::add() {
	this->memory[this->cursor]++;
}

/* Decrement the current cell value. */
void Parser::substract() {
	this->memory[this->cursor]--;
}

/* Print the current cell value. */
void Parser::write() {
	cout << this->memory[this->cursor];
}

/* Read char to the current cell. */
void Parser::read() {
	cin >> this->memory[this->cursor];
}

/* Skip the instructions inside the loop if current cell value is 0. */
void Parser::startLoop() {
	int counter = 1;

	if ((int)this->memory[this->cursor] == 0) {
		do {
			this->instruction++;

			if (*this->instruction == '[') counter++;
			else if (*this->instruction == ']') counter--;
		} while (counter != 0);
	}
}

/* Return to the matching '[' */
void Parser::endLoop() {
	int counter = 0;

	do {
		if (*this->instruction == '[') counter++;
		else if (*this->instruction == ']') counter--;

		this->instruction--;
	} while (counter != 0);
}

#endif
