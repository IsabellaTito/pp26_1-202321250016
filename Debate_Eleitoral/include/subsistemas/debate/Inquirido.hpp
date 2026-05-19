#pragma once

#include "subsistemas/debate/ColaboradorPolitico.hpp"
#include "shared/LogSystem.hpp"

class Inquirido : public ColaboradorPolitico{
    public:
        Inquirido(const ColaboradorPolitico& politico);

        void responder(int tempo);

        void treplica(int tempo);
};