#include "subsistemas/debate/Inquiridor.hpp"
#include "subsistemas/debate/MediadorDebate.hpp"

Inquiridor::Inquiridor(const ColaboradorPolitico& politico) : ColaboradorPolitico(politico){}

void Inquiridor::perguntar(int tempo){
    microfone->liga();
    notificar();
    LogSystem::getInstance().registerLog(
        "Microfone aberto para pergunta!"
    );
    microfone->passaTempo(tempo);
}

void Inquiridor::replica(int tempo){
    microfone->liga();
    notificar();
    LogSystem::getInstance().registerLog(
        "Microfone aberto para replica!"
    );
    microfone->passaTempo(tempo);
}

void Inquiridor::escolhaInquirido(shared_ptr<ColaboradorPolitico> politico){
    MediadorDebate* med = dynamic_cast<MediadorDebate*>(mediador);

    if(med != nullptr){
        med->setInquirido(politico);
    }
}