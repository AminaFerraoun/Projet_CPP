#ifndef C_READ_H 
#define C_READ_H 


#include <stdio.h>
#include <stdlib.h>
#include <fstream>

#define Error_File 10
#define Error_Openning_File 20
#define Error_Nb_Node 30
#define Error_Nb_Edge 40

#pragma warning(disable : 4996)
#pragma warning(disable : 4244)
#pragma warning(disable : 4430)

class CRead {

public : 


	/*Méthode qui permet de lire le fichier txt (analyseur lexical)
	Entrée : const char* ptcParam qui correspond au nom du fichier
	Sortie : retourne un char** dans lequel se trouve es données lu dans le fichier txt
	*/
	static char** REAReadFile(const char* ptcParam);
	
};

#endif