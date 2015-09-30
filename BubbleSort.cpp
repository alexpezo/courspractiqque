//============================================================================
// Name        : BubbleSort.cpp
// Author      : 
// Version     :
//============================================================================

#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>

using namespace std;

//============================================================================
// Faction     : lireFichier
// Author      :
// Version     :
//============================================================================
vector<int> lireFichier( string path )
{
	vector<int> donnesFichier;

    ifstream fichier( path.c_str() );  // on ouvre le fichier en lecture

    if(fichier)// si l'ouverture a réussi
    {
    	string strContenu;  // déclaration d'une chaîne qui contiendra la ligne lue

    	getline(fichier, strContenu);  // on met dans "contenu" la ligne

    	int nbContenu = atoi(strContenu.c_str());

    	donnesFichier.push_back( nbContenu );

    	fichier.close();  // on ferme le fichier
    }
    else  // sinon
            cerr << "Impossible d'ouvrir le fichier !" << endl;

    return donnesFichier;
}

//============================================================================
// Faction     : lireFichier
// Author      :
// Version     : pseudo code trouve sur http://en.wikipedia.org/wiki/Bubble_sort
//============================================================================
vector<int> bubbleSort(vector<int> donnesFichier, int start, int size)
{
	// Determine si un interchangement a eu lieu dans la derniere itaration
	bool swapped;
	int temp;

	do
	{
		swapped = false;
		for (int i = start+1; i < size; i++)
		{
			// Si la paire n'est pas ordonnee
			if (donnesFichier[i - 1] > donnesFichier[i])
			{
				temp = donnesFichier[i];
				donnesFichier[i] = donnesFichier[i-1];
				donnesFichier[i-1] =  temp;
				swapped = true;
			}
		}
	} while (swapped);
	return donnesFichier;
}

int main()
{
	string path = "";

	//Lecture du fichier
	vector<int> donnesFichier;

	donnesFichier = lireFichier(path);

	vector<int> result = bubbleSort(donnesFichier, 0, donnesFichier.size());
}
