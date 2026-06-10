#pragma once

#include <string>
#include <memory>

#include "subsistemas/ConfiguraTempo.hpp"
#include "subsistemas/GerenciaPolitico.hpp"
#include "subsistemas/debate/MediadorDebate.hpp"
#include "subsistemas/eleitores/Eleitor.hpp"

using std::string, std::shared_ptr;

class FachadaDebate{

    private:
        static FachadaDebate *instance;

        ConfiguraTempo config;
        GerenciaPolitico gerenciador;
        shared_ptr<MediadorDebate> mediador;
        
        FachadaDebate();

        // Impede cópia
        FachadaDebate(const FachadaDebate&) = delete;
        FachadaDebate& operator=(const FachadaDebate&) = delete;

    public:

        static FachadaDebate& getInstance();
        void configuracaoTempo(int, int, int, int, int);
        void cadastrarPolitico(string, string);
        void cadastrarEleitor(string, string, string, string);
        int sorteioInquiridor();
        void escolherInquirido(string, string);
        void executaDebate();
        void executarDR();

};