#pragma once

#include <iostream>
#include <string>
#include "../implementador/Implementador.hpp"
#include "../implementador/PublicacaoImplXML.hpp"
#include "../implementador/PublicacaoImplBD.hpp"

using std::string;

class Publicacao{

    public:
        Publicacao(Implementador *imp){
            this->imp = imp;
        }

        string obterDados(){
           return imp->getDados(this);
        }

        virtual string getTitulo() = 0;

        virtual string getAutor(int id) = 0;

    private:
        Implementador *imp;
        int id;
        string autor;
        string titulo;
    
};