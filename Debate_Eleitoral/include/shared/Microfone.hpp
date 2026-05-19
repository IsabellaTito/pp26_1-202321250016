#pragma once

#include <string>
#include <thread>
#include <chrono>

#include "shared/LogSystem.hpp"

class Microfone{

    private:
        bool microAtivo;

    public:

        Microfone(){microAtivo=false;}

        void liga(){microAtivo=true;}
        void desliga(){microAtivo=false;}
        bool getMicrofone() const {return microAtivo;}

        void passaTempo(int tempo);

};