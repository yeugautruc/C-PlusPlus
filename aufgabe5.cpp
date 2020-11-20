
#include <ostream>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include "map"
#include <vector> //only use in sort method
#include <iterator>
#include <algorithm>
#include "FileName.h"
#include "AtcoCommand.h"
#include "Ocurrence.h"

using namespace std;

/* Methods to use
---------------------------*/

// Read text file method
string readTextFile(string url)
{
	string output, line;
	ifstream myfile(url);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			output += line + "\n";
		}
		myfile.close();
	}
	else
		cout << "Unable to open test file ";

	return output;
}

// Count word from string into a map
void wordsCount(const string &str, map<string, int> &wordsMap)
{
	int count = 1;
	istringstream wordStream(str);
	string word;
	while (wordStream >> word)
	{
		pair<map<string, int>::iterator, bool> returnValue;
		returnValue = wordsMap.insert(pair<string, int>(word, count));
		if (returnValue.second == false)
		{
			++returnValue.first->second;
		}
	}
};
void commandsCount(const string &str, map<string, int> &wordsMap)
{
	if (str.length() > 3) 
	{
		int count = 1;
		pair<map<string, int>::iterator, bool> returnValue;
		returnValue = wordsMap.insert(pair<string, int>(str, count));
		if (returnValue.second == false)
		{
			++returnValue.first->second;
		}
	}
};

// Comparator use in sort method (Z -> A)
bool cmp(pair<string, int> &a,
		 pair<string, int> &b)
{
	return a.second != b.second ? a.second > b.second : a.first > b.first;
};

// Get top word sequence
string topWords(map<string, int> &M)
{
	string output = "";
	vector<pair<string, int>> A;
	size_t sizeB = 0;
	for (auto &it : M)
	{
		A.push_back(it);
	}
	sort(A.begin(), A.end(), cmp);
	if (A.size() > 10)
	{
		sizeB = 10;
	}
	else
	{
		sizeB = A.size();
	}
	vector<pair<string, int>> B(A.begin(), A.begin() + sizeB);
	output += "The top 10 occurences\n";
	int counter = 1;
	for (auto &it : B)
	{
		if (counter < 4)
		{
			output += "" + to_string(counter) + ".";
			for (size_t i = 0; i < 20 - it.first.length(); i++)
			{
				output += " ";
			}
			output += it.first + ":   " + to_string(it.second) + "\n";
			counter++;
		}
		else
		{
			for (size_t i = 0; i < 22 - it.first.length(); i++)
			{
				output += " ";
			}
			output += it.first + ":   " + to_string(it.second) + "\n";
		}
	}
	return output;
};

// Get top commands
string topCommands(map<string, int> &M, int amount, string url)
{
	string output = "";
	vector<pair<string, int>> A;
	size_t sizeB = 0;
	for (auto &it : M)
	{
		A.push_back(it);
	}
	sort(A.begin(), A.end(), cmp);
	if (A.size() > unsigned(amount))
	{
		sizeB = amount;
	}
	else
	{
		sizeB = A.size();
	}
	vector<pair<string, int>> B(A.begin(), A.begin() + sizeB);
	output += "The top" + to_string(amount) + " type occurences specified in " + url + "\n";
	int counter = 1;
	for (auto &it : B)
	{
		if (counter < 2)
		{
			output += "" + to_string(counter) + ".";
			for (size_t i = 0; i < 20 - it.first.length(); i++)
			{
				output += " ";
			}
			output += it.first + ":   " + to_string(it.second) + "\n";
			counter++;
		}
		else
		{
			for (size_t i = 0; i < 22 - it.first.length(); i++)
			{
				output += " ";
			}
			output += it.first + ":   " + to_string(it.second) + "\n";
		}
	}
	return output;
};

// Resize dynamic array type Atcocommand
void resizeAtcoCommand(AtcoCommand *&inputArray, int &oldSize, int &newSize)
{
	AtcoCommand *temp = new AtcoCommand[oldSize];
	for (int i = 0; i < oldSize; i++)
	{
		temp[i] = inputArray[i];
	}
	delete[] inputArray;

	inputArray = new AtcoCommand[newSize];
	for (int i = 0; i < oldSize; i++)
	{
		inputArray[i] = temp[i];
	}
	delete[] temp;
};

// Resize dynamic array type Occurence
void resizeOcurrence(Ocurrence *&inputArray, int &oldSize, int &newSize)
{
	Ocurrence *temp = new Ocurrence[oldSize];
	for (int i = 0; i < oldSize; i++)
	{
		temp[i] = inputArray[i];
	}
	delete[] inputArray;

	inputArray = new Ocurrence[newSize];
	for (int i = 0; i < oldSize; i++)
	{
		inputArray[i] = temp[i];
	}
	delete[] temp;
};

// Init atcoCommand array with value and size
void initAtcoCommand(AtcoCommand *&a, string wert, int size)
{
	a = new AtcoCommand[size];
	for (int i = 0; i < size; i++)
	{
		AtcoCommand atcoCommand = AtcoCommand("2019-02-15__11-32-48-00:", wert, "ABP61 INIT_RESPONSE");
		a[i] = atcoCommand;
	}
	
};

// Init atcoCommand array with value
void initAtcoCommand(AtcoCommand *&a, string wert)
{
	for (int i = 0; i < 50; i++)
	{
		AtcoCommand atcoCommand = AtcoCommand("2019-02-15__11-32-48-00:", wert, "ABP61 INIT_RESPONSE");
		a[i] = atcoCommand;
	}
};

// Init occurence array with value and size
void initOcurrence(Ocurrence *&a, string wert, int size)
{
	a = new Ocurrence[size];
	for (int i = 0; i < size; i++)
	{
		Ocurrence ocurrence = Ocurrence(wert, 1);
		a[i] = ocurrence;
	}
};

// Init occurence array with value
void initOcurrence(Ocurrence *&a, string wert)
{
	for (int i = 0; i < 50; i++)
	{
		Ocurrence ocurrence = Ocurrence(wert, 1);
		a[i] = ocurrence;
	}
};
/* End methods to use
---------------------------*/

/* Struct ultilmate type
---------------------------*/
struct UltilType
{
	string url;
	map<string, int> wordsMap;
	map<string, int> commandsMap;

	// Two dynamic array to save Occurence and AtcoCommand
	Ocurrence *ocurrences;
	AtcoCommand *atcoCommands;

	int lengthArray{};

	// Constructor
	UltilType()
	{
		atcoCommands = new AtcoCommand[1];
		ocurrences = new Ocurrence[1];
	}

	// Constructor to get AtcoCommand from
	UltilType(AtcoCommand *&arr, map<string, int> &w, map<string, int> &c, string &u, int &size)
	{
		int sizeA = 1;
		int sizeO = 1;
		atcoCommands = new AtcoCommand[sizeA];
		ocurrences = new Ocurrence[sizeO];

		for (int i = 0; i < size; i++)
		{
			atcoCommands[sizeA - 1] = arr[i];
			int newSize = sizeA + 1;
			resizeAtcoCommand(atcoCommands, sizeA, newSize);
			sizeA++;
		}

		// Itterator command map into Occurrence dynamic array
		map<string, int>::iterator it = c.begin();
		for (pair<string, int> element : c)
		{
			// Accessing KEY from element
			std::string word = element.first;
			// Accessing VALUE from element.
			int count = element.second;

			// Keep occurence in to dynamic array
			Ocurrence ocur = Ocurrence(word, count);
			ocurrences[sizeO - 1] = ocur;
			int newSize = sizeO + 1;
			// Resize array after add to get more space for new one
			resizeOcurrence(ocurrences, sizeO, newSize);
			sizeO++;
		};

		lengthArray = size;
		wordsMap = w;
		commandsMap = c;
		url = u;
	}

	// Get top commands
	string getTopCommands(int amount)
	{
		return topCommands(commandsMap, amount, url);
	}

	// Get top word sequence
	string getTopWords()
	{
		return topWords(wordsMap);
	}

	// Print method
	void print()
	{
		for (size_t i = 0; i < unsigned(lengthArray); i++)
		{
			if (atcoCommands[i].toString().length() > 10)
			{
				cout << atcoCommands[i].toString() << endl;
			}
		}
		cout << topWords(wordsMap) << endl;
		cout << topCommands(commandsMap, 20, url) << endl;
	}
};

/* All test methods above:
existsTest						check if able to acces file
dateTimeSplitMethodTest			check if split method works
topOcurrencesTest				check if get top occurence method works
resizeOccurencesTest			check if resize Occurence method works
resizeAtcoCommandTest			check if resize AtcoCommand method works
---------------------------*/

bool existsTest(const string &name)
{
	ifstream myFile(name);
	if (myFile.fail())
	{
		return false;
	}
	cout << "Test file exist                 OK" << endl;
	return true;
};

bool dateTimeSplitMethodTest(UltilType input, string testString)
{
	if (testString.find(input.atcoCommands[0].getFormattedDateTime().toString().substr(2, input.atcoCommands[0].getFormattedDateTime().toString().length() - 4)) != -1)
	{
		cout << "Test split                      OK" << endl;
		return true;
	}
	return false;
};

bool topOcurrencesTest(UltilType input, string testString)
{
	if (testString.find(input.getTopCommands(20)) != -1)
	{
		cout << "Test top occurences method      OK" << endl;
		return true;
	}
	return false;
};

/* Create an AtcoCommand Dynamic Array with old word sequence
Use resize method to resize the dynamic array from 4 to 50
and set all word sequence value of the array to new word squence.
Check if all elements has a new word sequence value.*/
bool resizeAtcoCommandTest()
{
	AtcoCommand *a;
	a = new AtcoCommand[1];
	const string wert = "old word sequence";
	const string newWert = "new word sequence";
	int oldSize = 4;
	int newSize = 50;

	initAtcoCommand(a, wert, oldSize);
	resizeAtcoCommand(a, oldSize, newSize);
	initAtcoCommand(a, newWert);

	// Check of dynamic array after resize works
	for (size_t i = 0; i < unsigned(newSize); i++)
	{
		if (a[i].getWordSequence().find(newWert) == -1)
		{
			delete[] a;
			return false;
		}
	}
	delete[] a; // Release memory
	cout << "Test resize AtcoCommand method  OK" << endl;
	return true;
}

/* Create an Occurence Dynamic Array with old value
Use resize method to resize the dynamic array from 4 to 50
and set all value of the array to new value.
Check if all elements has a new value.*/
bool resizeOcurrenceTest()
{
	Ocurrence *o;
	o = new Ocurrence[1];
	const string wert = "old value";
	const string newWert = "new value";
	int oldSize = 4;
	int newSize = 50;

	initOcurrence(o, wert, oldSize);
	resizeOcurrence(o, oldSize, newSize);
	initOcurrence(o, newWert);

	// Check of dynamic array after resize works
	for (size_t i = 0; i < unsigned(newSize); i++)
	{
		if (o[i].getValue().find(newWert) == -1)
		{
			delete[] o;
			return false;
		}
	}
	delete[] o; // Release memory
	cout << "Test resize Ocurrence method    OK" << endl;
	return true;
}

// End test methods
/*________________________________________________________*/

// Main method to read text file and input to main type (AtcoCommand Array and Occurence Array)
void readFileGetOutput(string url, UltilType &output)
{
	int size = 1;
	map<string, int> wordsMap;
	map<string, int> commandsMap;
	AtcoCommand *atcoCommands;
	atcoCommands = new AtcoCommand[size];

	string line, fileName, wordSequence, commands;
	ifstream file(url);
	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			if (line.find(":") != -1)
			{
				if (wordSequence.length() != 0)
				{
					// Finish last read AtcoCommand
					AtcoCommand atcoCommand = AtcoCommand(fileName, wordSequence, commands);
					atcoCommands[size - 1] = atcoCommand;
					int newSize = size + 1;
					resizeAtcoCommand(atcoCommands, size, newSize);
					size++;
					commands = "";
				}
				fileName = line;
				getline(file, line);
				wordSequence = line;
			}
			else
			{
				commands += line + "\n ";
			}
		}

		// Last AtcoCommand is read
		AtcoCommand atcoCommand = AtcoCommand(fileName, wordSequence, commands);
		atcoCommands[size - 1] = atcoCommand;

		file.close();

		// Count words sequence and commands into map
		for (int i = 0; i < size; i++)
		{
			wordsCount(atcoCommands[i].getWordSequence(), wordsMap);
			for (int k = 0; k < atcoCommands[i].getSizeCommands(); k++)
			{
				commandsCount(atcoCommands[i].getcommands(k).getMainCommands(), commandsMap);
			}
		}

		// Input data in to AtcoCommand Dynamic Array and Occurence Dynamic Array
		output = UltilType(atcoCommands, wordsMap, commandsMap, url, size);
	}
};

/*Main method
---------------------------*/
int main(int argc, char *argv[])
{
	UltilType test;
	UltilType output;
	string file = "longTest.txt";
	string testFileURL = "shortTest.txt";

	// Check if input parameter require test
	if (argc > 1 && string(argv[1]) == "--test")
	{
		string testString = readTextFile("testString.txt");

		// Test if testString is read
		if (testString.length() == 0)
		{
			system("Color 04");
			cout << "\nTest fileTest exist: Fail" << endl;
			return 0;
		}

		// Test if main text file exist
		if (!existsTest(file))
		{
			system("Color 04");
			cout << "Test text file exist: Fail" << endl;
			return 0;
		}

		// Test if resize AtcoCommand and Occurence method works
		if (!resizeAtcoCommandTest() || !resizeOcurrenceTest())
		{
			system("Color 04");
			cout << "Test resize method: Fail" << endl;
			return 0;
		}

		// Read test file and input to string to check functional method works
		readFileGetOutput(testFileURL, test);

		// Test if split method works
		if (!dateTimeSplitMethodTest(test, testString))
		{
			system("Color 04");
			cout << "Test split method: Fail" << endl;
			return 0;
		}

		// Test if read top occurence method work
		if (!topOcurrencesTest(test, testString))
		{
			system("Color 04");
			cout << "Test top Ocurrneces Method: Fail" << endl;
			return 0;
		}

		// Print out result if all test passed.
		system("Color 0A");
		cout << "\n    Cool! All tests passed." << endl;
		return 1;
	}

	// If input parameter is read, read input data
	if (argc > 1 && string(argv[1]) == "read")
	{
		if (existsTest(argv[2]))
		{
			file = argv[2];
		}
		else
		{
			cout << "File not found!" << endl;
			return 0;
		}
	}

	// Read data and print out
	readFileGetOutput(file, output);
	cout << "Result:\n " << endl;
	output.print();
	return 1;
}