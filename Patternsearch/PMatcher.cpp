#include "pch.h"
#include "PMatcher.h"
#include <map>
#include <string>
#include <functional>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

PMatcher::PMatcher(string filename_)
{
	_mapOfNumbers = createMapOfNumbers();
	readDictionary(filename_);
	_finalSolutions = new vector<string>;
	_partialSolutions = new vector<string>;
	bool _isSolution = false;

}


PMatcher::~PMatcher()
{
	delete _dictionary;
	delete _finalSolutions;
	delete _partialSolutions;
}

map<int, string> PMatcher::createMapOfNumbers() {
	_mapOfNumbers =  map<int, string>();
	
	_mapOfNumbers.insert(make_pair(2, "abc"));
	_mapOfNumbers.insert(make_pair(3, "def"));
	_mapOfNumbers.insert(make_pair(4, "ghi"));
	_mapOfNumbers.insert(make_pair(5, "jkl"));
	_mapOfNumbers.insert(make_pair(6, "mno"));
	_mapOfNumbers.insert(make_pair(7, "pqrs"));
	_mapOfNumbers.insert(make_pair(8, "tuv"));
	_mapOfNumbers.insert(make_pair(9, "wxyz"));
	
	return _mapOfNumbers;
}

//getter
map<int, string> PMatcher::getMapOfNumbers() const {
	return _mapOfNumbers;
}

//dictionary
void PMatcher::readDictionary(string filename_) {
	string line;
	ifstream _nameFile;
	_dictionary = new vector<string>;
	_nameFile.open(filename_);
	while (getline(_nameFile, line)) {
		_dictionary->push_back(line);
	}
	
	_nameFile.close();
	
}

void PMatcher::backTrack(int level_, vector<string>* partialSolutions_, bool isSolution_, vector<string>* finalSolutions_) {
	string input = "7822377";
	level_ = 7; //input size
	map<int, string> ::iterator mapIterator = _mapOfNumbers.begin();
	int i = 0;
	while (i < level_) {
		int key = input[i]-48;
		string letters_ = _mapOfNumbers[key];
		int mapLevel_ = letters_.size();
		int j = 0;
		while (j < mapLevel_) { //3 vagy 4 iteráció
			char searchLetter = letters_[j];
			if (searchInDictionary(searchLetter, partialSolutions_, i)) {
				cout << "x" << endl;
			}

			j++;
		}
		//char letter = letters_[i];
		//cout << "letters : " << letters_ << " and size: " << size << endl;
		i++;
	}


}

bool PMatcher::searchInDictionary(char searchLetter, vector<string>* partialSolutions_, int index) {
	vector<string>::iterator it = _dictionary->begin();
	bool isPartialSolution_ = false;
	while (it != _dictionary->end()) {

		if ((*it).at(index) == searchLetter)
		{
			partialSolutions_->push_back((*it));
			cout << (*it) << endl;
			isPartialSolution_ = true;
		}
		it++;
	}

	return true;
}
