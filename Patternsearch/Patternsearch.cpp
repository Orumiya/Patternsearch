#include "pch.h"
#include <iostream>
#include "PMatcher.h"
#include <string>
#include <iterator>
#include <map>

using namespace std;

int main()
{
	PMatcher pm("C:\\Users\\eskasza\\source\\repos\\Patternsearch\\Patternsearch\\testWordList.txt");
	//a vektor első x elemének kilistázása
	/*for (int i = 0; i < 15; i++)
	{
		cout << (*pm._dictionary)[i] << endl;
	}*/

	//map-on végigiterálás
	/*
	map<int, string>::iterator it = pm._mapOfNumbers.begin();
	while (it != pm._mapOfNumbers.end()) {
		cout << (it->first) << " : " << (it->second) << endl;
		it++;
	}
	*/

	pm.backTrack(3, pm._partialSolutions, pm._isSolution, pm._finalSolutions);
	
}


