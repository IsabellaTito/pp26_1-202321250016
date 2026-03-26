#pragma once

#include <iostream>
#include <string>
#include "Implementador.hpp"

#include "../abstracao/Publicacao.hpp"

using std::string;

class Publicacao;

class PublicacaoImplXML : public Implementador{
    public:
        PublicacaoImplXML(){}
        
        string getDados(Publicacao *tipo) override {
            return "Metodo getDados() com *** XML *** foi chamado";
        }
};