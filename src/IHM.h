/*************************************************************************
                           IHM  -  interface console & lancement programme
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

int main ( );
// Mode d'emploi :
// Interface utilisateur
// remonte toutes les données en mémoire

void handleAdminFunctionalities ( );

void handlePrivateIndividualFunctionalities ( );

void handleGovernmentAgencyFunctionalities ( );

void handleProviderFunctionalities ( );

void observeImpact ( );

void produceStatistics ( );

void produceStatsMoment ( );

void obsImpactLvlImprov ( );

bool isDateAfterToday( const string& date );

bool isValidDateFormat( const string& date );

void testComputeMeanATMOIdx();

#endif // IHM_H