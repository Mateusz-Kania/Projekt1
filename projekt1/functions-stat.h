
#ifndef HEADER_H
#define HEADER_H
#pragma once
#include "stdafx.h"
#include <string>

struct results {
	bool correct; //okreœla poprawnoœæ wyników
	unsigned int cyfry;
	unsigned int samogloski;
	unsigned int spolgloski;
	unsigned int bialeZnaki;
	unsigned int slowa;
	unsigned int maxZnakow;
	unsigned int liczbaWierszy;
};
struct results calculateResults(std::string fileName);
char saveResultsToFile(std::string fileName, struct results results);
char identifySign(char c);
void recognizeArguments(std::string argNames[], std::string argValues[], int argArraySize, int argc, char * argv[],bool &help);
std::string askAQuestion(std::string question);
#endif