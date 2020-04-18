#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>

#include "Constants.hpp"
#include "CSVHandler.hpp"

class Appointments
{
public:
    Appointments(std::string filePath);
    void display(unsigned int userCol, std::string userId, std::vector<unsigned int> displayedColumns = {});
    bool schedule(std::string patientId, std::string nurseId);
    int getHoursRate(std::string patientDisease, std::string nurseExperience);
    std::vector<std::vector<std::string>>* getData();
    void setData(std::vector<std::vector<std::string>> data);

private:
    void afficherEntete(std::vector<unsigned int>& displayedColumns);
    void filtrerAppointments(unsigned int userCol, std::string userId, std::vector<std::vector<std::string>>& filteredAppointments);

    std::vector<std::string> createNewAppointment(std::string patientId, std::string nurseId);

    std::vector<std::string> _headers;
    CSVHandler _csvHandler;
    std::vector<std::vector<std::string>> _data;

    const unsigned int _COLUMN_WIDTH = 14;
};
