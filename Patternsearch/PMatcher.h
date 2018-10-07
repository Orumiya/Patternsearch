#pragma once
#include <map>
#include <string>
#include <vector>

using namespace std;
class PMatcher
{
public:
	PMatcher(string);
	~PMatcher();

	vector<string>* _dictionary;
	vector<string>* _finalSolutions;
	vector<string>* _partialSolutions;
	bool _isSolution;

	//getter
	map<int, string> getMapOfNumbers() const;
	map<int, string> _mapOfNumbers;

	void backTrack(int, vector<string>*, bool, vector<string>*);

private: 
	
	map<int, string> createMapOfNumbers();
	void readDictionary(string);
};

