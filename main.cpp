#include <iostream>
#include <fstream>

using namespace std;

const char input[] = "input.txt";
const char output[] = "output.txt";
const int MAX_SIZE = 2000;

struct String
{
	public:
		void addChar(const char & inputChar) {
			this->text[this->index] = inputChar;
			this->index++;
		}


		bool isMarker(const char & inputChar) {
			return inputChar == this->marker;
		}


		void removeInnerSpaces() {
			int i = 0;

			int firstLetter = -1, lastLetter = -1;

			while (!this->isMarker(this->text[i])) {
				if (this->text[i] != ' ') {
					if (firstLetter == -1) {
						firstLetter = i;
					}

					lastLetter = i;
				}

				i++;
			}

			int j = firstLetter + 1;

			while (j <= lastLetter) {
				if (this->text[j] == ' ' && this->text[j - 1] == ' ') {
					this->shiftLeft(j);

					lastLetter--;
				} else {
					j++;
				}
			}
		}


		void shiftLeft(int startIndex = 0) {
			unsigned i = startIndex;

			while(!this->isMarker(this->text[i])) {
				this->text[i] = this->text[i+1];
				i++;
			}

			this->index--;
		}


		void saveToFile(const string& outputFileName) {
			ofstream outputFile(outputFileName, ios_base::app);

			if (outputFile.is_open()) {
				int i = 0;

				while (!this->isMarker(this->text[i])) {
					outputFile << this->text[i];
					i++;
				}

				outputFile << endl;
				outputFile.close();
			}
		};

	private:
		char text[MAX_SIZE]{};
		int index = 0;
		char marker = '@';
};


int main () {
	cout << "В тексте из файла ввода будут заменены все группы пробелов на одинарный, например, 'два  пробела' станет 'два пробела'\n"
		<< "Результат будет записан в output.txt";
	ifstream inputFile(input);

	ofstream clearFile(output, ios_base::trunc);
	clearFile.close();

	String line;

	if (inputFile.is_open()) {
		char inputChar;

		while(inputFile >> noskipws >> inputChar) {
			line.addChar(inputChar);
		}

		line.addChar('@');
		inputFile.close();
	}

	line.removeInnerSpaces();

	line.saveToFile(output);
}
