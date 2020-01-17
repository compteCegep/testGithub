#ifndef EleveH 
#define EleveH
//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include "activite.h"
using namespace std;

class Eleve
{
  private:      
	string codeEleve;
    string nom;      
    string prenom;     
	Activite* activiteInscrite;
  public:       
	  Eleve();
	  Eleve(string inCode,string inNom,string inPrenom);
	  string getCodeEleve() const;
	  string getNom() const;
	  string getPrenom() const;
	  Activite* getActivite() const;
	  void InscrireEleve(string inCode, string inNom, string inPrenom);
	  /*void setCodeEleve(string inCode);
      void setNom(string inNom);
      void setPrenom(string inPrenom);*/
      void InscrireAUneActivite(Activite* inActivite);
};  
#endif

