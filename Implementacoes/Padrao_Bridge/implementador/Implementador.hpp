#pragma once

#include <iostream>
#include <string>

#include "../abstracao/Publicacao.hpp"

using std::string;

class Publicacao;

class Implementador{
    public:
        Implementador(){}

        virtual string getDados(Publicacao *tipo) = 0;
        
};