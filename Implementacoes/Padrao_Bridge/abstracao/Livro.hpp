#pragma once

#include <iostream>
#include <string>
#include "Publicacao.hpp"

using std::string;

class Livro : public Publicacao{
    public:
        Livro(Implementador *imp):Publicacao(imp){}

        string getISBN(){
            return "Método getISBN() de livro foi chamado";
        }

        string getTitulo() override {
            return "Método getTitulo() de livro foi chamado";
        }

        string getAutor(int id = 0) override {
            return "Método getAutor() de livro foi chamado";
        }

    private:


};