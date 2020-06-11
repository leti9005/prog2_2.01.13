#include <iostream>
#include <fstream>

using namespace std;

const char input[] = "input.txt";
const char output[] = "output.txt";

class Editor
{
	public:
		Editor(string line) {
			int i = 0;
			bool prevSpace = false;

			while ((int)line[i] != 0) {
				bool push = true;

				if (line[i] == ' ' && this->index > 0 && this->text[this->index - 1] == ' ') {
					push = false;
				}

				if (push) {
					this->text[this->index] = line[i];
					this->index++;
				}

				i++;
			}
		};


		void saveToFile(const string& outputFileName) {
			ofstream outputFile(outputFileName, ios_base::app);

			if (outputFile.is_open()) {
				for (int i = 0; i < this->index; i++) {
					outputFile << this->text[i];
				}

				outputFile << endl;
				outputFile.close();
			}
		};

	private:
		char text[0x255]{};
		int index = 0;
};


int main () {
	ifstream inputFile(input);

	ofstream clearFile(output, ios_base::trunc);
	clearFile.close();

	if (inputFile.is_open()) {
		string inputLine;

		while(getline(inputFile, inputLine)) {
			Editor line(inputLine);

			line.saveToFile(output);

		};
		inputFile.close();
	}
}
