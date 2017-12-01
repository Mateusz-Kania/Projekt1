

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>

#include "functions-stat.h"

struct results calculateResults(std::string fileName) {
	using namespace std;
	struct results results {
		false, 0, 0, 0, 0, 0, 0, 1
	};
	ifstream loadingStream;
	loadingStream.open(fileName);
	if (!loadingStream.is_open()) {
		return results;
	}
	char c;
	unsigned int aktualnaLinia = 0;
	bool stanSlowa = false;
	while (loadingStream.get(c)) {

		switch (identifySign(c)) {
		case 1:
			results.cyfry++;
			aktualnaLinia++;

			break;
		case 2:
			results.samogloski++;
			aktualnaLinia++;
			if (!stanSlowa) {
				stanSlowa = true;
				results.slowa++;
			}

			break;
		case 3:
			results.spolgloski++;
			aktualnaLinia++;
			if (!stanSlowa) {
				stanSlowa = true;
				results.slowa++;
			}

			break;
		case 4:
			results.bialeZnaki++;
			if (stanSlowa) {
				stanSlowa = false;
			}

			break;
		case 5:
			results.bialeZnaki++;
			if (aktualnaLinia > results.maxZnakow) {
				results.maxZnakow = aktualnaLinia;
			}
			aktualnaLinia = 0;
			if (stanSlowa) {
				stanSlowa = false;
			}
			results.liczbaWierszy++;

			break;
		case 6:
			aktualnaLinia++;
			break;

		}


	}
	loadingStream.close();
	if (aktualnaLinia > results.maxZnakow) {
		results.maxZnakow = aktualnaLinia;
	}
	results.correct = true;
	return results;
}


char saveResultsToFile(std::string fileName, struct results r) {
	using namespace std;
	if (!r.correct) {
		return 2;//b³¹d poprawnoœci wyników
	}
	ofstream savingStream;
	savingStream.open(fileName, ios_base::trunc);
	if (!savingStream.is_open()) {
		return 1;//b³¹d œcie¿ki pliku
	}
	savingStream <<
		"Liczba samog³osek:" << r.samogloski << endl <<
		"Liczba spó³g³osek:" << r.spolgloski << endl <<
		"Liczba cyfr:" << r.cyfry << endl <<
		"Liczba s³ów:" << r.slowa << endl <<
		"Liczba wierszy:" << r.liczbaWierszy << endl <<
		"Liczba bia³ych znaków:" << r.bialeZnaki << endl <<
		"Maksymalna liczba znaków w wierszu:" << r.maxZnakow;
	savingStream.close();
	return 0;
}

char identifySign(char c) {//1 cyfra, 2 samogloska, 3 spolgloska,4 bialy znak(bez nowej linii),5 nowa linia, 6 inny znak

	if ((int)c >= 97 && (int)c <= 122) {
		switch ((int)c) {
		case 97:
			return 2;
		case 101:
			return 2;
		case 105:
			return 2;
		case 111:
			return 2;
		case 117:
			return 2;
		case 121:
			return 2;
		default:
			return 3;
		}
	}
	if ((int)c >= 65 && (int)c <= 90) {
		switch ((int)c) {
		case 65:
			return 2;
		case 69:
			return 2;
		case 73:
			return 2;
		case 79:
			return 2;
		case 85:
			return 2;
		case 89:
			return 2;
		default:
			return 3;
		}
	}

	if ((int)c >= 48 && (int)c <= 57) {
		return 1;
	}
	if ((int)c == 10) {
		return 5;
	}

	if ((int)c == 9 || (int)c == 32) {
		return 4;
	}
	if ((int)c == -91 || (int)c == -58 || (int)c == -54 || (int)c == -93 || (int)c == -47 || (int)c == -45) {
		return 2;
	}
	if ((int)c == -116 || (int)c == -113 || (int)c == -81 || (int)c == -71 || (int)c == -26 || (int)c == -22 || (int)c == -77 || (int)c == -15 || (int)c == -13 || (int)c == -100 || (int)c == -97 || (int)c == -65) {
		return 3;
	}

	return 6;

}

std::string askAQuestion(std::string question) {
	using namespace std;
	cout << question << endl;
	string message;
	cin >> message;
	return message;
}

void recognizeArguments(std::string argNames[], std::string argValues[], int argArraySize, int argc, char * argv[], bool &help) {
	for (int i = 1; i < argc; ++i) {
		for (int j = 0; j < argArraySize; ++j) {
			if (argNames[j] == argv[i]) {

				if (i + 1 < argc) {
					argValues[j] = argv[++i];

				
				}
				break;
			}
		}
		if (strcmp(argv[i], "-h") == 0) {
			help = true;
		}

	}

}
