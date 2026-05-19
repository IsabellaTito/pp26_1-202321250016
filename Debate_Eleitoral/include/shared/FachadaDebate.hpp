#pragma once

#include <string>

#include "subsistemas/ConfiguraTempo.hpp"
#include "subsistemas/GerenciaPolitico.hpp"
#include "subsistemas/debate/MediadorDebate.hpp"
#include "subsistemas/eleitores/Eleitor.hpp"

using std::string;

class FachadaDebate{

    private:
        static FachadaDebate *instance;

        ConfiguraTempo config;
        GerenciaPolitico gerenciador;
        MediadorDebate mediador;
        
        FachadaDebate(){}

        // Impede cópia
        FachadaDebate(const FachadaDebate&) = delete;
        FachadaDebate& operator=(const FachadaDebate&) = delete;

    public:

        static FachadaDebate& getInstance();
        void configuracaoTempo(int, int, int, int);
        void cadastrarPolitico(string, string);
        void cadastrarEleitor(string, string, string, string);
        int sorteioInquiridor();
        void escolherInquirido(string, string);
        void executaDebate();

};