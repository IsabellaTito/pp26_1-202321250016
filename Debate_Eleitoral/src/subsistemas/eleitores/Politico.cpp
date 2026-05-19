#include <algorithm>

#include "subsistemas/eleitores/Politico.hpp"

#include "shared/LogSystem.hpp"

Politico::Politico(const Politico& outro): eleitores(outro.eleitores){}

void Politico::cadastrar(shared_ptr<EleitorObservador> eleitor){
    eleitores.push_back(eleitor);
}

void Politico::remover(shared_ptr<EleitorObservador> eleitor){
    eleitores.erase(
        remove(eleitores.begin(),
               eleitores.end(),
               eleitor),
        eleitores.end()
    );    
}

void Politico::notificar(){
    for(auto eleitor: eleitores){
        eleitor->atualizar();
    }
}