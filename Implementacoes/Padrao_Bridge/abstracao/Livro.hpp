#pragma once

#include <iostream>
#include <string>
#include "Publicacao.hpp"

using std::string;

class Livro : public Publicacao{
    public:
        Livro(Implementador *imp):Publicacao(imp){}

        string getISBN(){
            return "Pegando ISBN de livro";
        }

        string getTitulo() override {
            return "Pegando titulo de livro";
        }

        string getAutor(int id = 0) override {
            return "Pegando nome do autor do livro";
        }

    private:


};