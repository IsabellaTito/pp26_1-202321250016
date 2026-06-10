#pragma once

#include <memory>
#include "subsistemas/estados/EstadosDebate.hpp"

using std::shared_ptr, std::make_shared;

class MediadorDebate;

class DireitoResposta : public EstadosDebate{
    private:
        shared_ptr<MediadorDebate> contexto;

    public:
        DireitoResposta(shared_ptr<MediadorDebate> cont){contexto = cont;}
        void run(const ConfiguraTempo& config) override;

};
