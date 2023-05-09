/*************************************************************************
                           IHM  -  lancement du programme
                             -------------------
    début                : 09/05/2023
    copyright            : (C) 2023 par Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Interface du module <IHM> (fichier IHM.h) -------------------
#if ! defined ( IHM_H )
#define IHM_H

//------------------------------------------------------------------------
// Rôle du module <IHM>
// Ce module permet le lancement du programme par le système lors de
// l'exécution, à travers l'appel à une procédure test
//------------------------------------------------------------------------

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------ Fonctions privées
static void test ( );
// Mode d'emploi :
// Procédure de test appelée par la fonction Main
// Permet de mieux tracer les destructeurs à la fin de l'éxécution de
// l'application

int main ( );
// Mode d'emploi :
// Appelle la procédure test

#endif // IHM_H