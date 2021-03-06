// projekt1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <string>
#include <iostream>
#include <fstream>

#include "functions-stat.h"

int main(int argc, char * argv[])
{
	using namespace std;
	setlocale(LC_ALL, "");
	string argNames[2] = { "-i","-o"};
	string argValues[2];
	bool help = false;
	recognizeArguments(argNames, argValues, 2, argc, argv,help);
	if (help) {
		cout <<endl<< "Program określa dane statystyczne pliku wejściowego: liczbę cyfr, samogłosek, spółgłosek, słów, wierszy, maksymalną liczbę znaków i zapisuje je do pliku wyjściowego."<<endl
			<<"Aby określić plik wejściowy użyj przełącznika '-i'."<<endl
			<< "Aby określić plik wyjściowy użyj przełącznika '-o'."<<endl
			<< "Jeżeli pliki nie zostaną podane, program poprosi o ich podanie przy pomocy konsoli.";
		return 0;
	}
	if (argValues[0] == "") {
		argValues[0] = askAQuestion("Podaj ścieżkę pliku wejściowego.");

	}
	if (argValues[1] == "") {
		argValues[1] = askAQuestion("Podaj ścieżkę pliku wyjściowego.");

	}
	struct results r = calculateResults(argValues[0]);
	if (r.correct) {
		if (saveResultsToFile(argValues[1], r) == 0) {
			cout << "Statystyki zostały zapisane do pliku " << argValues[1];
		}
		else {
			cout << "Niepoprawna ścieżka pliku wyjściowego";
		}
	}
	else {
		cout << "Niepoprawna ścieżka pliku wejściowego";
	}
	return 0;
}
