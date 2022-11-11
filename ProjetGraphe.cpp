// ProjetGraphe.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//inversé les graphes orientes, faire un rapport ou il y'a un manuel utilisatur , arcs reflexible, graphe séparé,commentaires, documentations, structure du prjet,avancement 

#include <iostream>
#include <stdlib.h>
#include "CRead.h"
#include "CParser.h"


using namespace std;



int main(int argc, char* argv[])
{
	if (argc != 2) {

		cout << "Please give a filename as a parameter" << endl;

	}
	else {

		//Lecture du fichier texte et création du graph à l'aide de l'analyseur syntaxique
		CGraph* ptGRAGraph = CParser::PARCreateGraph((const char**)CRead::REAReadFile(argv[1]));
		
		cout << endl;
		

	}
}


