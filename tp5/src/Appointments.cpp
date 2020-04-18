#include "Appointments.hpp"

Appointments::Appointments(std::string filePath) : _csvHandler(CSVHandler(filePath))
{
    this->_headers = this->_csvHandler.getHeader(); // It is correct to return vector<T> as lvalue.
    this->_data = std::vector<std::vector<std::string>>();
    this->setData(this->_csvHandler.getData());
}


void Appointments::afficherEntete(std::vector<unsigned int>& displayedColumns)
{
    // 1. On remplit le vecteur displayedColumns par tous les indexes des colonnes du fichier CSV:
    if (displayedColumns.empty())
    {
        displayedColumns = std::vector<unsigned int>(this->_headers.size());
        std::iota(displayedColumns.begin(), displayedColumns.end(), 0);
    }

    // 2. On affiche toutes les en-têtes des colonnes voulues du fichier CSV:
    for (unsigned int col : displayedColumns)
    {
        std::cout << std::setw(this->_COLUMN_WIDTH)
                  << this->_headers[col];
    }
    std::cout << std::endl
              << std::string(displayedColumns.size() * this->_COLUMN_WIDTH, '_')
              << std::endl;
}

void Appointments::filtrerAppointments(unsigned int userCol, std::string userId, std::vector<std::vector<std::string>>& filteredAppointments)
{
    // On filtre les rendez-vous pour ne conserver ceux de l'utilisateur passé en paramètre (soit un infirmier ou un patient):
    std::copy_if(
        this->getData()->begin(),
        this->getData()->end(),
        std::back_inserter(filteredAppointments),
            [userId, userCol](std::vector<std::string> appointment) {
                return appointment[userCol] == userId;
            });
}

void Appointments::display(unsigned int userCol, std::string userId, std::vector<unsigned int> displayedColumns)
{
    //1. Afficher l'entête du tableau
    afficherEntete(displayedColumns);
    //2. Filter les rendez-vous pour conserver uniquement ceux du patient 
    //   dans filteredAppointments
    std::vector<std::vector<std::string>> filteredAppointments;
    filtrerAppointments(userCol, userId, filteredAppointments);

    //3.. On affiche ensuite les rendez-vous filtrés à l'écran:
    unsigned int appointmentIdx = 1;
    for (std::vector<std::string> filteredAppointment : filteredAppointments)
    {
        std::cout << appointmentIdx++
                  << '.' 
                  << std::setw(this->_COLUMN_WIDTH - 2);

        for (unsigned int col : displayedColumns)
        {
            std::cout << filteredAppointment[col].substr(0, this->_COLUMN_WIDTH - 1)
                      << std::setw(this->_COLUMN_WIDTH);
        }
        std::cout << '\n';
    }
    
}

bool Appointments::schedule(std::string patientId, std::string nurseId)
{
    std::vector<std::string> newAppointment = this->createNewAppointment(patientId, nurseId);

    for (std::vector<std::string> appointment : *(this->getData()))
    {
        bool isOccupied = newAppointment[APPOINTMENT_DATE] == appointment[APPOINTMENT_DATE] &&
                          newAppointment[APPOINTMENT_TIME] == appointment[APPOINTMENT_TIME];
        if (isOccupied)
        {
            return false; // Schedule did not work
        }
    }
    // Update appointment list and file.
    this->getData()->push_back(newAppointment);
    this->_csvHandler.writeData(newAppointment);
    return true;
}

//Restructuration
int Appointments::getHoursRate(std::string patientDisease, std::string nurseExperience)
{   
    int rate = 2;
    if(patientDisease == "covid-19")
        return rate;

    rate = 20;
    int yearsExperience = std::stoi(nurseExperience);
    if(yearsExperience > 2 && yearsExperience < 5)
        rate *= 1.5;
    else if(yearsExperience >= 5)
        rate *= 1.8;
    return rate;
}

//Restructuration : méthodes de AppointmentData
std::vector<std::vector<std::string>>* Appointments::getData()
{
    return &this->_data;
}

void Appointments::setData(std::vector<std::vector<std::string>> data)
{
    this->_data = data;
}

std::vector<std::string> Appointments::createNewAppointment(std::string patientId, std::string nurseId)
{
    std::vector<std::string> newAppointment(this->_headers.size());
    newAppointment[APPOINTMENT_NURSE_ID] = nurseId;
    newAppointment[APPOINTMENT_PATIENT_ID] = patientId;

    std::cout << "\nVeuillez indiquer la date du rendez-vous [jj/mm/aaaa]: ";
    std::cin >> newAppointment[APPOINTMENT_DATE];

    std::cout << "\nVeuillez indiquer le moment du rendez-vous [AM/PM]: ";
    std::cin >> newAppointment[APPOINTMENT_TIME];

    std::cout << "\nVeuillez indiquer la raison du rendez-vous: ";
    std::cin >> newAppointment[APPOINTMENT_REASON];

    return newAppointment;
}