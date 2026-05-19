#pragma once

#include <memory>

#include "subsistemas/debate/ColaboradorPolitico.hpp"
#include "shared/LogSystem.hpp"


using std::shared_ptr;

class Inquiridor : public ColaboradorPolitico{
    public:
        Inquiridor(const ColaboradorPolitico& politico);

        void perguntar(int tempo);

        void replica(int tempo);

        void escolhaInquirido(shared_ptr<ColaboradorPolitico> politico);
};