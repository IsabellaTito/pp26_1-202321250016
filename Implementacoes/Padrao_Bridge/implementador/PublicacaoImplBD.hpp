#pragma once

#include <iostream>
#include <string>
#include "Implementador.hpp"

#include "../abstracao/Publicacao.hpp"

using std::string;

class Publicacao;

class PublicacaoImplBD : public Implementador{
    public:
        PublicacaoImplBD(){}

        string getDados(Publicacao *tipo) override {
            return "Pegando dados com BD";
        }
};