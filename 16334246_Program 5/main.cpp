#include <iostream>
#include <fstream>
#include "Audio.h"
#include "Video.h"
#include "Media.h"

using namespace std;

int main() {
	// Array of pointers to Media
	Media* arr[200];

	// Variables to store filenames and type of object read
	string fileName, type, audioFile, videoFile;

	// Declare filestreams
	ifstream f;
	ofstream file1;
	ofstream file2;

	// Audio and video objects to store data read from file
	Video v;
	Audio a;

	// Index to store the number of elements read
	int index = 0;

	// Ask user to enter input and output file names
	cout << "Enter input file name: ";
	getline(cin, fileName);

	cout << "Enter audio output file: ";
	getline(cin, audioFile);

	cout << "Enter video output file: ";
	getline(cin, videoFile);

	// Open the files
	f.open(fileName);
	file1.open(audioFile);
	file2.open(videoFile);

	// Exit from program if there is an error opening input file
	if (!f) {
		cout << "Unable to open input file, exiting..." << endl;
		return 1;
	}

	// Keep reading until we reach end of file or 200 objects
	while (!f.eof() && index < 200) {
		f >> type;
		if (!f.fail()) {
			// Create an object of type Video or Audio depending upon type read
			if (type == "V") {
				Video* ptr = new Video();
				ptr->ReadData(f);
				arr[index++] = ptr;
			}
			else if (type == "A") {
				Audio* ptr = new Audio();
				ptr->ReadData(f);
				arr[index++] = ptr;
			}
		}
	}

	// For all the objects read into array write them into files
	for (int i = 0; i < index; i++) {
		if (arr[i]->getType() == "Audio") {
			arr[i]->WriteData(file1);
			file1 << "****************************************" << endl;
		}
		else if (arr[i]->getType() == "Video") {
			arr[i]->WriteData(file2);
			file2 << "****************************************" << endl;
		}
	}

	// Display message to user that file has been written successfully
	cout << "Files written successfully!" << endl;

	// Close all the files
	f.close();
	file1.close();
	file2.close();
	return 0;
}