#pragma once

#include <vector>
#include <memory>
#include <string>

#include "subsistemas/eleitores/EleitorObservador.hpp"

using std::vector, std::shared_ptr, std::string, std::make_shared;

class Politico{
    private:
        vector<shared_ptr<EleitorObservador>> eleitores;
    
    public:
        Politico() = default;
        Politico(const Politico& outro);
        void cadastrar(shared_ptr<EleitorObservador>);
        void remover(shared_ptr<EleitorObservador>);
        void notificar();

};