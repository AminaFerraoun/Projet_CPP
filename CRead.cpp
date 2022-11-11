#include "CRead.h"
#include "CException.h"
#include <iostream>
#include <cstdlib>

using namespace std;



/*Méthode qui permet de lire le fichier txt (analyseur lexical)
Entrée : const char* ptcParam qui correspond au nom du fichier
Sortie : retourne un char** dans lequel se trouve es données lu dans le fichier txt
*/
char** CRead::REAReadFile(const char* cParam) {

	char** ptptcTable = (char**)malloc(30*sizeof(char*));
	char cLine[255];
	char* ptcBufferAfter;
	char* ptcBufferBefore;
	int iCount = 2;

	ifstream FileName(cParam);

	if (!FileName) {
		CException EXCObject;
		EXCObject.EXCSetValue(Error_File);
		throw EXCObject;
	}

	if (FileName.is_open()) {





		// Lecture du nombre de sommet





		FileName.getline(cLine, 255); // lecture de la ligne

		while (cLine[0] == '\0' || cLine[0] == '\n' || cLine[0] == '\r') {
			FileName.getline(cLine, 255);
		}

		ptcBufferBefore = strtok(cLine, "="); //Séparation de la ligne en fonction du =
		ptcBufferAfter = strtok(NULL, "=");

		if (ptcBufferAfter == nullptr) {
			CException EXCObject;
			EXCObject.EXCSetValue(Error_Nb_Node);
			throw EXCObject;
		}

		ptptcTable[0] = strdup(ptcBufferAfter); //le char** stocke une copie de ce qui se trouve apres le =
		



		//Lecture du nombre d'arc




		FileName.getline(cLine, 255);

		while (cLine[0] == '\0' || cLine[0] == '\n' || cLine[0] == '\r') {
			FileName.getline(cLine, 255);
		}

		ptcBufferBefore = strtok(cLine, "=");
		ptcBufferAfter = strtok(NULL, "=");

		if (ptcBufferAfter == nullptr) {
			CException EXCObject;
			EXCObject.EXCSetValue(Error_Nb_Edge);
			throw EXCObject;
		}

		ptptcTable[1] = strdup(ptcBufferAfter);





		//Lecture de la ligne "Sommets=["




		FileName.getline(cLine, 255);
		while (cLine[0] == '\0' || cLine[0] == '\n' || cLine[0] == '\r') {
			FileName.getline(cLine, 255);
		}






		//Lecture des numéros de sommets

		


		FileName.getline(cLine, 255);

		while (cLine[0] != ']') {

			ptcBufferBefore = strtok(cLine, "=");
			ptcBufferAfter = strtok(NULL, "=");

			if (ptcBufferAfter == nullptr) {
				CException EXCObject;
				EXCObject.EXCSetValue(Error_Nb_Edge);
				throw EXCObject;
			}

			ptptcTable[iCount] = strdup(ptcBufferAfter);
			iCount++;
			FileName.getline(cLine, 255);

		}




		//Lecture de la ligne "Arcs=["





		FileName.getline(cLine, 255);
		while (cLine[0] == '\0' || cLine[0] == '\n' || cLine[0] == '\r') {
			FileName.getline(cLine, 255);
		}




		// Lecture des debuts et fin d'arcs





		FileName.getline(cLine, 255);

		while (cLine[0] != ']') {

			ptcBufferBefore = strtok(cLine, "=");
			ptcBufferAfter = strtok(NULL, "=");
			//cout << "Test1 pctBufferAfter : " << atoi(ptcBufferAfter) << endl;
			ptptcTable[iCount] = strdup(ptcBufferAfter);
			iCount++;
			

			//cout << "Test2 pctBufferAfter : " << atoi(ptcBufferAfter) << endl;
			

			if (ptcBufferAfter == nullptr) {
				CException EXCObject;
				EXCObject.EXCSetValue(Error_Nb_Edge);
				throw EXCObject;
			}

			ptcBufferAfter = strtok(NULL, ",");
			ptptcTable[iCount] = strdup(ptcBufferAfter);
			iCount++;
			FileName.getline(cLine, 255);

		}

	}
	else {
		CException EXCObject;
		EXCObject.EXCSetValue(Error_Openning_File);
		throw EXCObject;
	}


	return ptptcTable;
}