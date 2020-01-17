#ifndef ACTIVITE_H 
#define ACTIVITE_H

#include "..\screen\screen.h"
#include <string>
#include <iostream>
using namespace std;

class Activite
{
private:
	string codeActivite;
	string titre;
	string responsable;
public:
	Activite();
	Activite(string inNumero, string inTitre, string inResponsable);
	//Activite(const Activite &);
	//void operator=(const TActivite &);
	string getCodeActivite() const;
	string getTitre() const;
	string getResponsable() const;
	void InitialiserActivite(string code, string titre);
	void AssignerUnResponsable(string responsable);
/*	void setCodeActivite(string inNumero);
	void setTitre(string inTitre);
	void setResponsable(string inResponsable);*/
};

#endif