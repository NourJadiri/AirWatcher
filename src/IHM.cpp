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
#include <regex>
#include <limits>
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
                produceStatistics();
                break;

            case 2:
                choiceOk = 1;
                cout << "Going back to main menu..." << endl;
                break;

            default:
                cout << "Invalid choice. Choose a number between 1 and 2 :)" << endl;
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
                produceStatistics();
                break;

            case 2:
                choiceOk = 1;
                cout << "Going back to main menu..." << endl;
                break;

            default:
                cout << "Invalid choice. Choose a number between 1 and 2 :)" << endl;
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
                produceStatistics();
                break;

            case 2:
                observeImpact();
                break;

            case 3:
                choiceOk = 1;
                cout << "Going back to main menu..." << endl;
                break;

            default:
                cout << "Invalid choice. Choose a number between 1 and 3 :)" << endl;
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
                produceStatistics();
                break;

            case 2:
                observeImpact();
                break;

            case 3:
                choiceOk = 1;
                cout << "Going back to main menu..." << endl;
                break;

            default:
                cout << "Invalid choice. Choose a number between 1 and 3 :)" << endl;
                break;
        }
    }
}

int main()
{
    testComputeMeanATMOIdx();
    testGetSensorsAround();
    testMeasureAtMoment();
    // get le type d'utilisateur
    int userType;
    int typeOk = 0;
    while (typeOk == 0){
        cout << "Enter the number corresponding to your user type: \n\t1. Member of Government Agency \n\t2. Private individual \n\t3. Provider \n\t4. Admin \n\t5. Exit" << endl;
        cin >> userType;

        switch (userType)
        {
            case 1:
                handleGovernmentAgencyFunctionalities();
                break;

            case 2:
                handlePrivateIndividualFunctionalities();
                break;

            case 3:
                handleProviderFunctionalities();
                break;

            case 4:
                handleAdminFunctionalities();
                break;

            case 5:
                typeOk = 1;
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid user type. Choose a number between 1 and 4 :)" << endl;
                break;
        }
    }
    testComputeMeanATMOIdx();


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
        cout << "Choose the corresponding number to what you which to do: \n\t1. Compute the mean of air quality in a specified circular area at a given MOMENT \n\t2. Compute the mean of air quality in a specified circular area at a given PERIOD OF TIME (not implemented) \n\t3. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "You chose to compute the mean of air quality at a given moment." << endl;
                produceStatsMoment();
                break;

            case 2:
                cout << "You chose to compute the mean of air quality at a specified period of time." << endl;
                cout << "Not implemented yet" << endl;
                break;

            case 3:
                choiceOk = 1;
                cout << "Going back to user menu..." << endl;
                break;

            default:
                cout << "Invalid choice. Choose a number between 1 and 3 :)" << endl;
                break;
        }
    }
}

void produceStatsMoment()
{
    time_t day;
    string dayStr;

    // conversion de time_t vers un string au format YYYY-MM-DD
    tm* date = localtime(&day);
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", date);
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
            cout << "Error: Please enter a valid day." << endl;
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
        cout << "Enter the radius in km (it must be between 0 and 20 000): ";
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

    AppService* appServ = new AppService(*dataSet);

    //double stats = 3.2;
    double stats = appServ->produceStatsMoment(day, Coordinates(longitude, latitude), radius);
    if(stats == - 1) cout << "No matching sensors for the given area." << endl;
    else if(stats == -2) cout << "No realiable measurements related to this date." << endl;
    else {
        // affichage
        cout << "Mean of ATMO indexes computed with the sensors around:" << endl;
        cout << "\tCenter = (" << longitude << ", " << latitude << ")" << endl;
        cout << "\tRadius = " << radius << " km" << endl;
        cout << "\t-> Mean ATMO index = " << stats << endl;
    }
}



void observeImpact()
{
    int choiceOk = 0;
    int choice;

    while (choiceOk == 0){
        cout << "You chose to observe the impact of an Air Cleaner." << endl;
        cout << "Choose the corresponding number to what you which to do: \n\t1. Get the radius of the cleaned zone (not implemented) \n\t2. Get the level of improvement in air quality \n\t3. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "You chose to observe the impact of an Air Cleaner by getting the radius of the zone it cleaned." << endl;
                cout << "Not implemented yet" << endl;
                break;

            case 2:
                cout << "You chose to observe the impact of an Air Cleaner by getting the level of improvement of air quality around it." << endl;
                obsImpactLvlImprov();
                break;

            case 3:
                choiceOk = 1;
                cout << "Going back to user menu..." << endl;
                break;

            default:
                cout << "Invalid choice. Choose a number between 1 and 3 :)" << endl;
                break;
        }
    }
}

void obsImpactLvlImprov ()
{
    // choix du Air Cleaner
    string idAC;
    while (true) {
        cout << "Enter the ID ('CleanerX', with X the number of the AirCleaner) of the AirCleaner around which you wish to observe the level of improvement: ";
        cin >> idAC;

        // Regular expression pattern pour vérifier qu'on a bien 'Cleaner' followed by one or more digits
        regex pattern("^Cleaner\\d+$");

        if (!regex_match(idAC, pattern)) {
            cout << "Invalid ID. Please enter an ID in the format 'CleanerX', where X is the number of the AirCleaner." << endl;
            continue;
        }

        // valid input, on sort de la loop
        break;
    }

    // choix du rayon
    double radius;
    while (true) {
        cout << "Enter the radius in km (it must be between 0 and 20 000): ";
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

    AppService* appServ = new AppService(*dataSet);
    pair<int,vector<double>> stats = appServ->obsImpactLvlImprov(idAC, radius);

    if (stats.first ==-1)
        cout << "No matching AirCleaner founded." << endl;
    else {
        double improvement = stats.second[2];
        // affichage
        cout << "Impact Level (ATMO index difference) of the AirCleaner " << idAC << " on a " << radius << " km radius:" << endl;
        cout << "-> ATMO index before action of AirCleaner = " << stats.second[0] << endl;
        cout << "-> ATMO index after action of AirCleaner = " << stats.second[1] << endl;
        cout << "-> ATMO level of improvement: " << (improvement > 0 ? "+" : "") << improvement << endl;    }
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

void testComputeMeanATMOIdx()
{
    vector<Measure> measures;

    tm timeStruct = {};
    string dateTimeString = "2019-01-01 12:00:00";

    // Extraction des composantes de la date/heure
    sscanf(dateTimeString.c_str(), "%d-%d-%d %d:%d:%d",
           &timeStruct.tm_year, &timeStruct.tm_mon, &timeStruct.tm_mday,
           &timeStruct.tm_hour, &timeStruct.tm_min, &timeStruct.tm_sec);

    // Ajustement des valeurs de la structure tm
    timeStruct.tm_year -= 1900; // Année depuis 1900
    timeStruct.tm_mon -= 1;     // Mois de 0 à 11

    // Conversion en time_t
    time_t time = mktime(&timeStruct);

    cout << "Converted time_t value: " << time << endl;

    Measure measure1("Sensor0", time, "O3", 50.25);
    Measure measure2("Sensor0", time, "NO2", 74.5);
    Measure measure3("Sensor0", time, "SO2", 41.5);
    Measure measure4("Sensor0", time, "PM10",44.75);

    measures.push_back(measure1);
    measures.push_back(measure2);
    measures.push_back(measure3);
    measures.push_back(measure4);

    AppService *app = new AppService(*dataSet);
    int atmo = app->computeMeanATMOIdx(measures);
    cout << "La moyenne ATMO vaut : " << atmo << endl;
    delete app;


}

void testGetSensorsAround()
{
    AppService appService;

    // Call the getSensorsAround method
    Coordinates center(30, 40);
    double radius = 30.0;
    vector<Sensor> sensorsAround = appService.getSensorsAround(center, radius);
    if(sensorsAround.empty()) cout << "No sensors around for the specified area."<<endl;
    else
    {
        // Print the sensors found within the radius
        cout << "Sensors within the radius:" << endl;
        for (const Sensor& sensor : sensorsAround)
        {
            cout << "Sensor ID: " << sensor.getId() << endl;
            cout << "Sensor Coordinates: (" << sensor.getCoord().getLongitude() << ", " << sensor.getCoord().getLatitude() << ")" << endl;
        }
    }
}

void testMeasureAtMoment()
{
    AppService appService;

    vector<Sensor> sensors;
    sensors.push_back(Sensor((string)"Sensor0", Coordinates(10, 20)));
    sensors.push_back(Sensor((string)"Sensor2", Coordinates(15, 25)));
    sensors.push_back(Sensor((string)"Sensor3", Coordinates(30, 40)));
    sensors.push_back(Sensor((string)"Sensor4", Coordinates(35, 45)));

    tm timeStruct = {};
    string dateTimeString = "2019-01-01 12:00:00";

    // Extraction des composantes de la date/heure
    sscanf(dateTimeString.c_str(), "%d-%d-%d %d:%d:%d",
           &timeStruct.tm_year, &timeStruct.tm_mon, &timeStruct.tm_mday,
           &timeStruct.tm_hour, &timeStruct.tm_min, &timeStruct.tm_sec);

    // Ajustement des valeurs de la structure tm
    timeStruct.tm_year -= 1900; // Année depuis 1900
    timeStruct.tm_mon -= 1;     // Mois de 0 à 11

    // Conversion en time_t
    time_t time = mktime(&timeStruct);

    vector<Measure> meas = appService.getMeasuresAtMoment(sensors, time);

    if(meas.empty()) cout << "No measure found for the specified date."<<endl;
    else
    {
        // Print the sensors found within the radius
        cout << "measures :" << endl;
        for (Measure& measure : meas)
        {
            cout << "Sensor ID: " << measure.getSensorId() << endl;
            cout << "measure : " << measure.getDateMeas() << ", " << measure.getAttributeValue() << ";" << measure.getValue()<< endl;
        }
    }


}
