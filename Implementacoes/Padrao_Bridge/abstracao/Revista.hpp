#pragma once

#include <iostream>
#include <string>
#include "Publicacao.hpp"

using std::string;

class Revista : public Publicacao{
    public:
        Revista(Implementador *imp):Publicacao(imp){};

        string getArtigo(){
            return "Pegando artigo da revista";
        }

        string getTitulo() override {
            return "Pegando titulo da revista";
        }

        string getAutor(int id = 0) override {
            return "Pegando nome do autor da revista";
        }


};