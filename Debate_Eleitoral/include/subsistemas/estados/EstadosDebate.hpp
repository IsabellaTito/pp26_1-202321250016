#pragma once

#include "subsistemas/ConfiguraTempo.hpp"

class EstadosDebate{
    public:
        virtual ~EstadosDebate() = default;

        virtual void run(const ConfiguraTempo& config) = 0;

};