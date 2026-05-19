#pragma once

#include <fstream>
#include <string>

using std::string;

class LogSystem{
    private:
        string file_path;
        std::ofstream file;

        string getCurrentTime();
        LogSystem(const string& file_path);

         // Impede cópia
        LogSystem(const LogSystem&) = delete;
        LogSystem& operator=(const LogSystem&) = delete;


    public:

        ~LogSystem();

        static LogSystem& getInstance(const string& file_path = "app.log");
        
        void registerLog(const string& message);

        string getLogsRegister() const;

};