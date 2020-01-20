#include <string>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "..\screen\screen.h"
#include "donnees.h"
using namespace std;

#include "activite.h" 
#include "eleve.h" 

Donnees lesDonneesDuProgramme;
//const int maxActivites = 10;
//const int maxEleves = 25;
//
//Activite lesActivites[maxActivites];
int nombreActivitesReelles = 0;

//Eleve lesEleves[maxEleves];
int nombreElevesReels = 0;

char AfficherMenu();
void AjouterActivite();
void AfficherLesActivites();
void AjouterLesEleves();
void AfficherLesEleves();
void InscrireUnEleve(string, string, string);
void InscrireEleveActivite();
int RechercherEleve(string eleveVoulu);
int RechercherActivite(string activiteVoulu);
void AfficherLesInscriptions();

void Afficher(Eleve);
void Afficher(Activite);

int main()
{
	char choix = ' ';
	while (choix != '0')
	{
		choix = AfficherMenu();
		switch (choix)
		{
		case '1': AjouterActivite();
			break;
		case '2': AfficherLesActivites();
			break;
		case '3': AjouterLesEleves();
			break;
		case '4': AfficherLesEleves();
			break;
		case '5': InscrireEleveActivite();
			break;
		case '6': AfficherLesInscriptions();
			break;
		}
	}
}

//----------------------------------------------------------------------------------------
char AfficherMenu()
{
	char choix;
	ClrScr();
	Gotoxy(15, 4);
	cout << "1- Ajouter une nouvelle activite";
	Gotoxy(15, 6);
	cout << "2- Liste des activites";
	Gotoxy(15, 8);
	cout << "3- Ajouter tous les eleves";
	Gotoxy(15, 10);
	cout << "4- Liste des eleves";
	Gotoxy(15, 12);
	cout << "5- Inscrire un eleve a une activite";
	Gotoxy(15, 14);
	cout << "6- Liste des inscriptions d'une activite";
	Gotoxy(15, 16);
	cout << "0- Arreter";
	Gotoxy(15, 18);
	cout << "Choix: ";
	cin >> choix;
	return choix;
}

//----------------------------------------------------------------------------------------
void AjouterActivite()
{
	string code;
	string titre;
	string responsable;
	ClrScr();
	cout << "Code activite: ";
	cin >> code;
	cout << "Titre: ";
	cin >> titre;
	cout << "Responsable: ";
	cin >> responsable;
	//ajoutez les instructions permettant d'inscrire la nouvelle activité dans le tableau des activités
	//utilisez nombreActivites comme indice pour le tableau
	lesDonneesDuProgramme.lesActivites[nombreActivitesReelles].InitialiserActivite(code, titre);
	lesDonneesDuProgramme.lesActivites[nombreActivitesReelles].AssignerUnResponsable(responsable);

	nombreActivitesReelles++;
}

//----------------------------------------------------------------------------------------
void AfficherLesActivites()
{
	ClrScr();
	for (int cpt = 0; cpt < nombreActivitesReelles; cpt++)
	{
		Afficher(lesDonneesDuProgramme.lesActivites[cpt]);
		//cout << lesActivites[cpt].getCodeActivite() << " -- " << lesActivites[cpt].getTitre() << " -- " << lesActivites[cpt].getResponsable() << endl;
	}
	_getch();
}

//----------------------------------------------------------------------------------------
void AjouterLesEleves()
{
	InscrireUnEleve("111", "Laroche", "Arthur");
	InscrireUnEleve("222", "Cailloux", "Fred");
	InscrireUnEleve("333", "Cailloux", "Delima");
	InscrireUnEleve("444", "Laroche", "Bertha");
	InscrireUnEleve("555", "Cailloux", "Agathe");
	InscrireUnEleve("666", "Laroche", "Boumboum");
	InscrireUnEleve("777", "Mirock", "Pierre");
	InscrireUnEleve("888", "Roche", "Onezime");
	InscrireUnEleve("999", "Roche", "Alfreda");
	InscrireUnEleve("112", "Cailloux", "Dino");
}

//----------------------------------------------------------------------------------------
void AfficherLesEleves()
{
	ClrScr();
	for (int cpt = 0; cpt < nombreElevesReels; cpt++)
	{
		Afficher(lesDonneesDuProgramme.lesEleves[cpt]);
		//cout << lesEleves[cpt].getCodeEleve() << " -- " << lesEleves[cpt].getPrenom() << " -- " << lesEleves[cpt].getNom() << endl;
	}
	_getch();
}
//----------------------------------------------------------------------------------------
void InscrireUnEleve(string inCode, string inNom, string inPrenom)
{
	lesDonneesDuProgramme.lesEleves[nombreElevesReels].InscrireEleve(inCode, inNom, inPrenom);
	nombreElevesReels++;
}

//----------------------------------------------------------------------------------------
void InscrireEleveActivite()
{
	string eleve;
	string activite;
	int cptEleve;
	int cptActivite;
	ClrScr();
	cout << "Code de l'eleve a inscrire: ";
	cin >> eleve;
	cptEleve = RechercherEleve(eleve);
	if (cptEleve != maxEleves)
	{
		Afficher(lesDonneesDuProgramme.lesEleves[cptEleve]);
		cout << "Activite desiree: ";
		cin >> activite;
		cptActivite = RechercherActivite(activite);
		if (cptActivite != maxActivites)
		{
			Afficher(lesDonneesDuProgramme.lesActivites[cptActivite]);
			lesDonneesDuProgramme.lesEleves[cptEleve].InscrireAUneActivite(&lesDonneesDuProgramme.lesActivites[cptActivite]);
			cout << "inscription effectuee";
		}
		else
		{
			Gotoxy(30, 20);
			cout << "mauvaise activite";
		}
	}
	else
	{
		Gotoxy(30, 20);
		cout << "Eleve inexistant";
	}
	_getch();
}

//----------------------------------------------------------------------------------------
int RechercherEleve(string inCodeVoulu)
{
	int cptEleve = 0;
	bool trouve = false;
	while (trouve == false && cptEleve < maxEleves)
	{
		if (lesDonneesDuProgramme.lesEleves[cptEleve].getCodeEleve() == inCodeVoulu)
		{
			trouve = true;
		}
		else
		{
			cptEleve++;
		}
	}
	return cptEleve;
}

//----------------------------------------------------------------------------------------
int RechercherActivite(string inCodeActiviteVoulue)
{
	bool trouve = false;
	int cptActivite = 0;
	while (trouve == false && cptActivite < maxActivites/*nombreActivites*/)
	{
		if (lesDonneesDuProgramme.lesActivites[cptActivite].getCodeActivite() == inCodeActiviteVoulue)
		{
			trouve = true;
		}
		else
		{
			cptActivite++;
		}
	}
	return cptActivite;
}
//----------------------------------------------------------------------------------------
void Afficher(Eleve inEleve)
{
	cout << inEleve.getPrenom() << " " << inEleve.getNom() << "\n";
}

//----------------------------------------------------------------------------------------
void Afficher(Activite inActivite)
{
	cout << inActivite.getCodeActivite() << " " << inActivite.getTitre() << inActivite.getResponsable() << "\n";
}
//----------------------------------------------------------------------------------------
void AfficherLesInscriptions()
{
	string activite;
	ClrScr();
	cout << "Code de l'activite: ";
	cin >> activite;
	for (int cpt = 0; cpt < maxEleves; cpt++)
	{
		if (lesDonneesDuProgramme.lesEleves[cpt].getActivite() != NULL)
		{
			if (lesDonneesDuProgramme.lesEleves[cpt].getActivite()->getCodeActivite() == activite)
			{
				Afficher(lesDonneesDuProgramme.lesEleves[cpt]);
			}
		}
	}
	_getch();
}







