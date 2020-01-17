#include "activite.h"

Activite::Activite()
{
	codeActivite="";
	titre="";
	responsable="";
}

Activite::Activite(string inNumero, string inTitre, string inResponsable)
{
	codeActivite = inNumero;
	titre = inTitre;
	responsable = inResponsable;
}

//Activite::Activite(const Activite& inActivite)
//{
//	codeActivite = inActivite.codeActivite;
//	titre = inActivite.titre;
//	responsable = inActivite.responsable;
//}
//void TActivite::operator=(const TActivite& InActivite)
//{
//	MNoActivite = InActivite.MNoActivite;
//	MTitre = InActivite.MTitre;
//	MResponsable = InActivite.MResponsable;
//}
string Activite::getCodeActivite() const
{
	return codeActivite;
}

string Activite::getTitre() const
{
	return titre;
}

string Activite::getResponsable() const
{
	return responsable;
}
void Activite::InitialiserActivite(string inCode, string inTitre)
{
	codeActivite = inCode;
	titre = inTitre;
}
void Activite::AssignerUnResponsable(string inResponsable)
{
	responsable = inResponsable;
}
//void Activite::setCodeActivite(string inNumero)
//{
//	codeActivite = inNumero;
//}
//
//void Activite::setTitre(string inTitre)
//{
//	titre = inTitre;
//}
//
//void Activite::setResponsable(string inResponsable)
//{
//	responsable = inResponsable;
//}

