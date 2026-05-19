#pragma once

#include <string>
#include <iostream>
#include <memory>

#include "subsistemas/eleitores/EleitorObservador.hpp"
#include "subsistemas/debate/ColaboradorPolitico.hpp"
#include "shared/LogSystem.hpp"

using std::string, std::cout, std::endl, std::shared_ptr, std::weak_ptr;

class Eleitor : public EleitorObservador{

    private:
        string nome;
        string cpf;
        shared_ptr<ColaboradorPolitico> candidato;

    public:
        Eleitor(const string& nome, const string& cpf, shared_ptr<ColaboradorPolitico> candidato): nome(nome), cpf(cpf), candidato(candidato){}

        void setNome(const string& nome){this->nome = nome;}
        string getNome(){return nome;}

        void setCPF(const string& cpf){this->cpf = cpf;}
        string getCPF(){return cpf;}

        void atualizar() override;

};