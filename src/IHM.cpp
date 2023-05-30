/*************************************************************************
                           IHM  -  description
                             -------------------
    début                : 09/05/2023
    copyright            : (C) 2023 par Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Réalisation du module <Main> (fichier Main.cpp) ------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <utility>
using namespace std;

//------------------------------------------------------ Include personnel
#include "IHM.h"
#include "FileManager.h"
#include "DataSet.h"
#include "AppService.h"

// initialisation du dataSet (mise en mémoire des données)
DataSet* dataSet = new DataSet();


///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------ Fonctions privées

// fonctionnalités spécifiques à l'admin
void handleAdminFunctionalities()
{
    int choiceOk = 0;
    int choice;

    while (choiceOk == 0){
        cout << "Choose the corresponding number to what you which to do: \n\t1. Produce statistics (mean of air quality) in a specified circular area \n\t2. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
            case 1:
                choiceOk = 1;
                produceStatistics();
                break;

            case 2:
                choiceOk = 1;
                cout << "Exiting..." << endl;
                break;

            default:
                std::cout << "Invalid choice. Choose a number between 1 and 2 :)" << std::endl;
                break;
        }
    }
}

// fonctionnalités spécifiques aux PrivIndiv
void handlePrivateIndividualFunctionalities()
{
    int choiceOk = 0;
    int choice;

    while (choiceOk == 0){
        cout << "Choose the corresponding number to what you which to do: \n\t1. Produce statistics (mean of air quality) in a specified circular area \n\t2. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
            case 1:
                choiceOk = 1;
                produceStatistics();
                break;

            case 2:
                choiceOk = 1;
                cout << "Exiting..." << endl;
                break;

            default:
                std::cout << "Invalid choice. Choose a number between 1 and 2 :)" << std::endl;
                break;
        }
    }
}

// fonctionnalités spécifiques aux membres de Government Agency
void handleGovernmentAgencyFunctionalities()
{
    int choiceOk = 0;
    int choice;

    while (choiceOk == 0){
        cout << "Choose the corresponding number to what you which to do: \n\t1. Produce statistics (mean of air quality) in a specified circular area \n\t2. Observe the impact of an Air Cleaner \n\t3. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
            case 1:
                choiceOk = 1;
                produceStatistics();
                break;

            case 2:
                choiceOk = 1;
                observeImpact();
                break;

            case 3:
                choiceOk = 1;
                cout << "Exiting..." << endl;
                break;

            default:
                std::cout << "Invalid choice. Choose a number between 1 and 3 :)" << std::endl;
                break;
        }
    }
}

// fonctionnalités spécifiques aux fournisseurs
void handleProviderFunctionalities()
{
    int choiceOk = 0;
    int choice;

    while (choiceOk == 0){
        cout << "Choose the corresponding number to what you which to do: \n\t1. Produce statistics (mean of air quality) in a specified circular area \n\t2. Observe the impact of an Air Cleaner \n\t3. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
            case 1:
                choiceOk = 1;
                produceStatistics();
                break;

            case 2:
                choiceOk = 1;
                observeImpact();
                break;

            case 3:
                choiceOk = 1;
                cout << "Exiting..." << endl;
                break;

            default:
                std::cout << "Invalid choice. Choose a number between 1 and 3 :)" << std::endl;
                break;
        }
    }
}

int main()
{


    // get le type d'utilisateur
    int userType;
    int typeOk = 0;
    while (typeOk == 0){
        std::cout << "Enter the number corresponding to your user type: \n\t1. Member of Government Agency \n\t2. Private individual \n\t3. Provider \n\t4. Admin \n\t5. Exit" << endl;
        std::cin >> userType;

        switch (userType)
        {
            case 1:
                typeOk = 1;
                handleGovernmentAgencyFunctionalities();
                break;

            case 2:
                typeOk = 1;
                handlePrivateIndividualFunctionalities();
                break;

            case 3:
                typeOk = 1;
                handleProviderFunctionalities();
                break;

            case 4:
                typeOk = 1;
                handleAdminFunctionalities();
                break;

            case 5:
                typeOk = 1;
                cout << "Exiting...";
                break;

            default:
                std::cout << "Invalid user type. Choose a number between 1 and 4 :)" << std::endl;
                break;
        }
    }




    /*
    // Parcours de la unordered_map
    for (const auto& pair : sensorsMap)
    {
        const string& sensorId = pair.first;
        const Sensor& sensor = pair.second;

        // Affichage des informations du capteur
        cout << "ID: " << sensorId << ", Latitude: " << sensor.getCoord().getLatitude() << ", Longitude: " << sensor.getCoord().getLongitude() << endl;
    }
    // Parcours de la map
    for (const auto& pair : usersMap)
    {
        const string user = pair.first;
        const vector<string>& sensors = pair.second;

        // Affichage de l'utilisateur
        cout << "User: " << user << endl;

        // Affichage des capteurs associés à l'utilisateur
        for (const string& sensor : sensors)
        {
            cout << "Sensor: " << sensor << endl;
        }

        cout << endl; // Ligne vide pour séparer les utilisateurs
    }


    //parcours du vector measureList

    for(Measure measure : measureList)
    {
        // Accéder aux attributs de la mesure et effectuer des opérations
        string sensorId = measure.getSensorId();
        time_t dateMeas = measure.getDateMeas();
        string attributeType = measure.getAttributeType();
        double value = measure.getValue();

        // Afficher les valeurs de chaque mesure
        cout << "Sensor ID: " << sensorId << endl;
        cout << "Date: " << ctime(&dateMeas); // Converter date into readable date
        cout << "Attribute Type: " << attributeType << endl;
        cout << "Value: " << value << endl;

    }


    // Utilisez le vecteur cleanerList selon vos besoins
    for (AirCleaner cleaner : cleanerList) {
        cout << "ID: " << cleaner.getAirCleanerID() << endl;
        cout << "Latitude: " << cleaner.getCoord().getLatitude() << endl;
        cout << "Longitude: " << cleaner.getCoord().getLongitude() << endl;
        cout << "Date Start: " << ctime(&cleaner.getDateStart());
        cout << "Date Stop: " << ctime(&cleaner.getDateStop());
        cout << endl;
    }

    // Affichage des fournisseurs
    for (const auto& pair : providers) {
        const string& providerId = pair.first;
        const vector<string>& cleanerIds = pair.second;

        cout << "Provider ID: " << providerId << endl;
        cout << "Cleaner IDs: " << endl;
        for (const string& cleanerId : cleanerIds) {
            cout << "  - Cleaner ID: " << cleanerId << endl;
        }
        cout << endl;
    }
     */
    return 0;
}


void produceStatistics()
{
    int choiceOk = 0;
    int choice;

    while (choiceOk == 0){
        cout << "You chose to produce statistics (get the mean of air quality) in a specified circular area." << endl;
        cout << "Choose the corresponding number to what you which to do: \n\t1. Compute the mean of air quality in a specified circular area at a given MOMENT \n\t2. Compute the mean of air quality in a specified circular area at a given PERIOD OF TIME \n\t3. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
            case 1:
                choiceOk = 1;
                cout << "You chose to compute the mean of air quality at a given moment." << endl;
                produceStatsMoment();
                break;

            case 2:
                choiceOk = 1;
                cout << "You chose to compute the mean of air quality at a specified period of time." << endl;
                produceStatsPeriod();
                break;

            case 3:
                choiceOk = 1;
                cout << "Exiting..." << endl;
                break;

            default:
                std::cout << "Invalid choice. Choose a number between 1 and 3 :)" << endl;
                break;
        }
    }
}

void produceStatsMoment()
{
    time_t day;
    string dayStr;

    // conversion de time_t vers un string au format YYYY-MM-DD
    std::tm* date = std::localtime(&day);
    char buffer[11];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", date);
    dayStr = buffer;

    // choix du moment
    while (true) {
        cout << "Enter the day (YYYY-MM-DD): ";
        cin >> dayStr;

        if (!isValidDateFormat(dayStr))
        {
            cout << "Error: The date format YYYY-MM-DD must be respected" << endl;
            continue;
        }

        if (isDateAfterToday(dayStr))
        {
            cout << "Error: Please enter a valid day." << std::endl;
            continue;
        }

        tm validatedDate = {};
        validatedDate.tm_year = stoi(dayStr.substr(0, 4)) - 1900;
        validatedDate.tm_mon = stoi(dayStr.substr(5, 2)) - 1;
        validatedDate.tm_mday = stoi(dayStr.substr(8, 2));
        day = mktime(&validatedDate);

        // valid input, on sort de la loop
        break;
    }

    // choix des coordonnées
    double longitude;
    while (true) {
        cout << "Enter the longitude (it must be between -180 and 180): ";
        if (!(cin >> longitude)) {
            cout << "Please enter numbers only." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (longitude < -180 || longitude > 180) {
            cout << "Longitude is outside the valid range. \nLongitude: -180 to +180" << endl;
            continue;
        }

        // valid input, on sort de la loop
        break;
    }

    double latitude;
    while (true) {
        cout << "Enter the latitude (it must be between -90 and 90): ";
        if (!(cin >> latitude)) {
            cout << "Please enter numbers only." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (latitude < -90 || latitude > 90) {
            cout << "Latitude is outside the valid range. \nLatitude: -90 to +90" << endl;
            continue;
        }

        // valid input, on sort de la loop
        break;
    }

    // choix du rayon
    double radius;
    while (true) {
        cout << "Enter the radius in km (it must be between 0 and 2000): ";
        if (!(cin >> radius)) {
            cout << "Please enter numbers only." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (radius < 0 || radius > 20000) {
            cout << "Radius is outside the valid range. \nRadius: 0 to 20 000" << endl;
            continue;
        }

        // valid input, on sort de la loop
        break;
    }

    // Call the produceStatsMoment() method with the user-provided values
    AppService* appServ = new AppService(*dataSet);
    double stats = appServ->produceStatsMoment(day, Coordinates(longitude, latitude), radius);

    // Display the calculated statistics
    cout << "Statistics for the specified moment: " << endl;
    cout << "Mean of ATMO indexes computed with the sensors at:\n"
         << "Coordinates = (" << longitude << ", " << latitude << ")\n"
         << "R = " << radius << "\n"
         << "->  " << stats << endl;

}


void observeImpact()
{
    int choiceOk = 0;
    int choice;

    while (choiceOk == 0){
        cout << "You chose to observe the impact of an Air Cleaner." << endl;
        cout << "Choose the corresponding number to what you which to do: \n\t1. Get the radius of the cleaned zone \n\t2. Get the level of improvement in air quality \n\t3. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
            case 1:
                choiceOk = 1;
                cout << "You chose observe the impact of an Air Cleaner by getting the radius of the zone it cleaned." << endl;
                obsImpactRadius();
                break;

            case 2:
                choiceOk = 1;
                cout << "You chose observe the impact of an Air Cleaner by getting the level of improvement of air quality around it." << endl;
                obsImpactLvlImprov();
                break;

            case 3:
                choiceOk = 1;
                cout << "Exiting..." << endl;
                break;

            default:
                std::cout << "Invalid choice. Choose a number between 1 and 3 :)" << std::endl;
                break;
        }
    }
}




// fonction pour vérifier si la date est après aujourd'hui
bool isDateAfterToday(const string& date)
{
    time_t currentTime = time(nullptr);
    tm* now = localtime(&currentTime);

    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;
    int currentDay = now->tm_mday;

    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));

    if (year > currentYear)
        return true;
    else if (year == currentYear && month > currentMonth)
        return true;
    else if (year == currentYear && month == currentMonth && day > currentDay)
        return true;

    return false;
}

// fonction pour vérifier que le format de la date est conforme
bool isValidDateFormat(const string& date)
{
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    // Check if the year, month, and day components are valid integers
    try {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
    } catch (const exception& e) {
        return false;
    }

    return true;
}