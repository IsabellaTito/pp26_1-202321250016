#include <iostream>
#include <memory>

#include "shared/FachadaDebate.hpp"
#include "shared/LogSystem.hpp"

using std::to_string, std::cout, std::endl, std::shared_ptr, std::make_shared;

FachadaDebate* FachadaDebate::instance = nullptr;

FachadaDebate::FachadaDebate(){mediador = std::make_shared<MediadorDebate>();} 

FachadaDebate& FachadaDebate::getInstance(){
    if(instance == nullptr){
        instance = new FachadaDebate();
        LogSystem::getInstance().registerLog("---------------- Fachada Inicializada ----------------");
    }
    return *instance;
}

void FachadaDebate::configuracaoTempo(int pergunta, int resposta, int replica, int treplica, int dr){
    LogSystem& log = LogSystem::getInstance();

    config.setPergunta(pergunta);
    log.registerLog("Tempo de pergunta setado: " + to_string(pergunta));
    config.setResposta(resposta);
    log.registerLog("Tempo de resposta setado: " + to_string(resposta));
    config.setReplica(replica);
    log.registerLog("Tempo de replica setado: " + to_string(replica));
    config.setTreplica(treplica);
    log.registerLog("Tempo de treplica setado: " + to_string(treplica));
    config.setDR(dr);
    log.registerLog("Tempo de DR setado: " + to_string(dr));

}

void FachadaDebate::cadastrarPolitico(string nome, string partido){
    gerenciador.criarPolitico(nome, partido, mediador.get());
    LogSystem::getInstance().registerLog("Politico " + nome + " do partido "+ partido + " foi cadastrado!");
}

void FachadaDebate::cadastrarEleitor(string nome, string cpf, string nomePolitico, string partidoPolitico){
    auto politico = gerenciador.obterPolitico(nomePolitico, partidoPolitico);
    if (politico == nullptr){
        LogSystem::getInstance()
            .registerLog("Politico nao encontrado");
        cout << "Politico não encontrado" << endl;
        return;
    }
    auto eleitor = make_shared<Eleitor>(nome, cpf, politico);
    politico->cadastrar(eleitor);
    LogSystem::getInstance()
            .registerLog("Eleitor " + nome + " cadastrado com sucesso");
}


int FachadaDebate::sorteioInquiridor(){
    auto escolhido = gerenciador.sortearPolitico();
    if (escolhido == nullptr){
        cout << "Todos os políticos já foram inquiridores." <<endl;
        return 0;
    }
    else{
        mediador->setInquiridor(escolhido);
        cout<<"Político sorteado: "<< escolhido->getNome() << " - " << escolhido->getPartido() <<endl;
        return 1;
    }
}

void FachadaDebate::escolherInquirido(string nome, string partido){
    auto escolhido = gerenciador.obterPolitico(nome,partido);

    if (escolhido == nullptr){
        LogSystem::getInstance().registerLog("Político não encontrado.");
        return;
    }

    mediador->setInquirido(escolhido);

    LogSystem::getInstance().registerLog("Político Inquirido: "
        + escolhido->getNome() 
        + " - " 
        + escolhido->getPartido());

}

void FachadaDebate::executaDebate(){
    mediador->debate(config);
    gerenciador.simularDR();
}

void FachadaDebate::executarDR(){
    if((mediador->getListaDR()).empty()){
        LogSystem::getInstance().registerLog("**Nenhum politico pediu direito de resposta.**");
        cout<< "**Nenhum politico pediu direito de resposta.**" << endl;
        return;
    }
    mediador->debate(config);
}
