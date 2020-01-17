#include "eleve.h"
#include <conio.h>

Eleve::Eleve()
{
	codeEleve = "";
	nom = "";
	prenom = "";
	activiteInscrite = NULL;
}

Eleve::Eleve(string inNumero, string inNom,string inPrenom)
{
	codeEleve = inNumero;
	nom = inNom;
	prenom = inPrenom;
	activiteInscrite = NULL;
}

string Eleve::getCodeEleve() const
{
  return codeEleve;
}

string Eleve::getNom() const
{
  return nom;
}

string Eleve::getPrenom() const
{
  return prenom;
}

Activite* Eleve::getActivite() const
{
  return activiteInscrite;
}

void Eleve::InscrireEleve(string inCode, string inNom, string inPrenom)
{
	codeEleve = inCode;
	nom = inNom;
	prenom = inPrenom;
}
void Eleve::InscrireAUneActivite(Activite* inActivite)
{
	activiteInscrite = inActivite;
}
//void TEleve::setCodeEleve(string inCode)
//{
//  mCodeEleve = inCode;
//}
//
//void TEleve::setNom(string inNom)
//{
//  mNom = inNom;
//}
//
//void TEleve::setPrenom(string inPrenom)
//{
//  mPrenom = inPrenom;
//}


