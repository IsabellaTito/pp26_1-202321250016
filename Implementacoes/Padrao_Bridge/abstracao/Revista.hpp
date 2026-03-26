#pragma once

#include <iostream>
#include <string>
#include "Publicacao.hpp"

using std::string;

class Revista : public Publicacao{
    public:
        Revista(Implementador *imp):Publicacao(imp){};

        string getArtigo(){
            return "Método getArtigo() de revista foi chamado";
        }

        string getTitulo() override {
            return "Método getTitulo() de revista foi chamado";
        }

        string getAutor(int id = 0) override {
            return "Método getAutor() de revista foi chamado";
        }


};