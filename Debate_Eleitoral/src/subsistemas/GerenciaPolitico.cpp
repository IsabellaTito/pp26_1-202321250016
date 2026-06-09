#include <random>
#include "subsistemas/GerenciaPolitico.hpp"

using std::make_shared;


GerenciaPolitico::GerenciaPolitico(){}

void GerenciaPolitico::criarPolitico(const string& nome, const string& partido, MediadorBase* mediador){
    auto politico =
        make_shared<ColaboradorPolitico>(
            nome,
            partido
        );

    politico->setMediador(mediador);

    politicos.push_back(politico);
}

shared_ptr<ColaboradorPolitico> GerenciaPolitico::obterPolitico(const string& nome, const string& partido){
    for(auto& politico : politicos){
        if(politico->getNome() == nome && politico->getPartido() == partido){
            return politico;
        }
    }
    return nullptr;
}


shared_ptr<ColaboradorPolitico> GerenciaPolitico::sortearPolitico(){
    LogSystem::getInstance().registerLog("Início do sorteio para Inquiridor");

    vector<shared_ptr<ColaboradorPolitico>> disponiveis;

    // Filtra apenas os ainda não sorteados
    for(auto& politico : politicos){
        if(!politico->getInquiridor()){
            disponiveis.push_back(politico);
        }
    }

    // Todos já participaram
    if(disponiveis.empty()){
        LogSystem::getInstance().registerLog(
            "Todos os políticos já foram inquiridores."
        );
        return nullptr;
    }

    // Gerador aleatório
    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(0,disponiveis.size() - 1);

    auto escolhido = disponiveis[dist(gen)];

    escolhido->setInquiridor(true);

    LogSystem::getInstance().registerLog(
        "Político sorteado: "
        + escolhido->getNome() 
        + " - " 
        + escolhido->getPartido()
    );

    return escolhido;
}

void GerenciaPolitico::simularDR(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> sorteio(0, 1);

    for (auto& politico: politicos){
        if(sorteio(gen) == 1){
            politico->pedirDR();
            LogSystem::getInstance().registerLog(
            "Político "
            + politico->getNome() 
            + " pediu direito de resposta"
            );
        } 
    }
}