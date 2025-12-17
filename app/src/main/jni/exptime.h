#pragma once


#include <ctime>
#include <sstream>
#include <iomanip>
#include <string>

class ExpireDate {
    public:
    ExpireDate() {
        std::time_t now = std::time(nullptr);
        expirationTime = std::chrono::system_clock::from_time_t(now);
    }
    void setExpirationDate(int day, int month, int year) {
        std::tm tm_struct = {};
        tm_struct.tm_mday = day;
        tm_struct.tm_mon = month - 1;
        tm_struct.tm_year = year - 1900;
        std::time_t expirationTime_t = std::mktime(&tm_struct);
        expirationTime = std::chrono::system_clock::from_time_t(expirationTime_t);
    }
    bool isExpired() {
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
        return now >= expirationTime;
    }
    private:
    std::chrono::system_clock::time_point expirationTime;
};
