#pragma once

#include <memory>
#include "subsistemas/estados/EstadosDebate.hpp"

using std::shared_ptr, std::make_shared;

class MediadorDebate;

class EstadoCiclos : public EstadosDebate{
    private:
        shared_ptr<MediadorDebate> contexto;

    public:
        EstadoCiclos(shared_ptr<MediadorDebate> cont){contexto = cont;}
        void run(const ConfiguraTempo& config) override;

};
