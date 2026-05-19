#pragma once

#include <string>
#include <vector>

class FachadaDebate;

class CLI {
private:
    FachadaDebate& fachada;

    CLI(FachadaDebate& FachadaDebate);

    void executarComando(const std::vector<std::string>& args);

public:
    static CLI& getInstance(FachadaDebate& FachadaDebate);

    void run();
};