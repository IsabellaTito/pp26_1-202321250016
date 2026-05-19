#include "subsistemas/debate/Inquirido.hpp"

Inquirido::Inquirido(const ColaboradorPolitico& politico): ColaboradorPolitico(politico){}

void Inquirido::responder(int tempo){
    microfone->liga();
    notificar();
    LogSystem::getInstance().registerLog(
        "Microfone aberto para resposta!"
    );
    microfone->passaTempo(tempo);
}

void Inquirido::treplica(int tempo){
    microfone->liga();
    notificar();
    LogSystem::getInstance().registerLog(
        "Microfone aberto para treplica!"
    );
    microfone->passaTempo(tempo);
}