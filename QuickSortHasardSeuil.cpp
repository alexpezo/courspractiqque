//============================================================================
// Name        : QuickSortSortHasard.cpp
// Author      : 
// Version     :
//============================================================================

#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>

using namespace std;

int nbSeuil = 1;

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
// Version     : pseudo code trouvé sur http://fr.wikipedia.org/wiki/Tri_rapide
//============================================================================
int partition( vector<int> donnesFichier, int left, int right )
{
	int i = left, j = right;
	int tmp;
	int ind = rand()%donnesFichier.size();
	int pivot = donnesFichier[ind];

	while (i <= j)
	{
		while (donnesFichier[i] < pivot)
			i++;
		while (donnesFichier[j] > pivot)
			j--;
		if (i <= j)
		{
			tmp = donnesFichier[i];
			donnesFichier[i] = donnesFichier[j];
			donnesFichier[j] = tmp;
			i++;
			j--;
		}
	}

	return i;
}

//============================================================================
// Faction     : lireFichier
// Author      :
// Version     : pseudo code trouvé sur http://fr.wikipedia.org/wiki/Tri_rapide
//============================================================================
vector<int> QuickSortHasardSeuil(vector<int> donnesFichier, int first, int last)
{
	if(first < last)
	{
		if(first + nbSeuil < last)
		{
			int pivot = first;
			pivot = partition( donnesFichier, first, last);
			if (first < pivot - 1)
				QuickSortHasardSeuil(donnesFichier, first, pivot-1);
			if (pivot < last)
				QuickSortHasardSeuil(donnesFichier, pivot+1, last);
		}
/*		else
		{
			//BubbleSort.sort(values, first, last+1);
		}*/

	}
	return donnesFichier;
}

int main()
{
	string path = "";

	//Lecture du fichier
	vector<int> donnesFichier;

	donnesFichier = lireFichier(path);

	vector<int> result = QuickSortHasardSeuil(donnesFichier, 0, donnesFichier.size()-1);
}
