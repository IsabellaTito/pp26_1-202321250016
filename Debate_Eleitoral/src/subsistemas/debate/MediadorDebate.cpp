#include "subsistemas/debate/MediadorDebate.hpp"

#include "subsistemas/debate/ColaboradorPolitico.hpp"
#include "subsistemas/ConfiguraTempo.hpp"
#include "subsistemas/builder/InquiridoBuilder.hpp"
#include "subsistemas/builder/InquiridorBuilder.hpp"
#include "shared/LogSystem.hpp"

#include <iostream>

using std::cout, std::endl;


void MediadorDebate::setInquiridor(shared_ptr<ColaboradorPolitico> politico){
    inquiridor = make_shared<Inquiridor>(*(InquiridorBuilder(politico).criarMicrofone().criarColaborador()));
}

void MediadorDebate::setInquirido(shared_ptr<ColaboradorPolitico> politico){
    inquirido = make_shared<Inquirido>(*(InquiridoBuilder(politico).criarMicrofone().criarColaborador()));
}

shared_ptr<Inquiridor> MediadorDebate::getInquiridor() const{return inquiridor;}

shared_ptr<Inquirido> MediadorDebate::getInquirido() const{return inquirido;}

void MediadorDebate::debate(const ConfiguraTempo& config){
    LogSystem::getInstance().registerLog("------ INICIO DEBATE -------");
    cout << "Inquiridor está perguntando" << endl;
    inquiridor->perguntar(config.getPergunta());
    cout << "Inquirido está respondendo" << endl;
    inquirido->responder(config.getResposta());
    cout << "Inquiridor está na replica" << endl;
    inquiridor->replica(config.getReplica());
    cout << "Inquirido está na treplica" << endl;
    inquirido->treplica(config.getTreplica());
    LogSystem::getInstance().registerLog("------ FIM DEBATE -------");
    LogSystem::getInstance().registerLog("Configure novamente para uma nova rodada!");
}