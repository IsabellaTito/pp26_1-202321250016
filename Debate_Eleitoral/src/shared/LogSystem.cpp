#include "shared/LogSystem.hpp"

#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

using std::cout, std::cerr;

LogSystem::LogSystem(const string& file_path):file_path(file_path){
    file.open(this->file_path, std::ios::app);

    if(!file.is_open()){
        cerr << "Erro ao abrir log\n";
    }
}

LogSystem::~LogSystem(){
    if(file.is_open()){
        file.close();
    }

}

LogSystem& LogSystem::getInstance(const string& file_path){
    static LogSystem instance(file_path);
    return instance;
}

string LogSystem::getCurrentTime(){

    auto now = std::chrono::system_clock::now();

    auto time_t_now = std::chrono::system_clock::to_time_t(now);

    std::tm local_time = *std::localtime(&time_t_now);

    std::stringstream ss;

    ss << std::put_time(&local_time, "[%d/%m/%Y %H:%M:%S]");

    return ss.str();

}

void LogSystem::registerLog(const string& message){

    if (!file.is_open()) {
        return;
    }

    file << getCurrentTime() 
         << " [INFO]"
         << " - "
         << message
         << std::endl;

}

string LogSystem::getLogsRegister() const{
    
    std::ifstream reader(file_path);

    if (!reader.is_open()) {
        return "Erro ao abrir arquivo de log";
    }

    std::stringstream buffer;

    buffer << reader.rdbuf();

    return buffer.str();

}