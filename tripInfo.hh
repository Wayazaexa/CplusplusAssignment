/**
 * @file tripInfo.hh
 * @author Joakim Englund (joakimenglund@protonmail.com)
 * @brief This is the hh-file for the tripInfo class which contains data that
 * both flight and booking contain. Its only purpose is to include inheritance
 * in this project.
 * @version 0.1
 * @date 2022-11-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>

#ifndef TRIPINFO_CLASS
#define TRIPINFO_CLASS

/**
 * @brief This is the definition of the TripInfo class.
 * 
 */
class TripInfo
{
private:
    std::string date;
    std::string time;
    std::string dep;
    std::string des;
public:
    TripInfo() {}
    ~TripInfo() {}
    std::string getDep() { return this->dep; }
    std::string getDes() { return this->des; }
    std::string getDate() { return this->date; }
    std::string getTime() { return this->time; }
    void setDep(std::string dep) { this->dep = dep; }
    void setDes(std::string des) { this->des = des; }
    void setDate(std::string date) { this->date = date; }
    void setTime(std::string time) { this->time = time; }
};

#endif
