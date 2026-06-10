#include <iostream>

#include "subsistemas/estados/EstadoCiclos.hpp"
#include "subsistemas/debate/MediadorDebate.hpp"
#include "shared/LogSystem.hpp"

using std::cout, std::endl;

void EstadoCiclos::run(const ConfiguraTempo& config){
    shared_ptr<Inquirido> inquirido = contexto->getInquirido();
    shared_ptr<Inquiridor> inquiridor = contexto->getInquiridor();

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
    LogSystem::getInstance().registerLog("Debate finalizado. Inicie o direito de resposta");

    contexto->setEstado(make_shared<DireitoResposta>(contexto));
}
