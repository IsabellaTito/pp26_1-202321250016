#include "subsistemas/eleitores/Eleitor.hpp"

void Eleitor::atualizar(){
    if(candidato->getMicrofone()){         
        LogSystem::getInstance().registerLog("---------> Eleitor "
            + nome 
            + " seu candidato, "
            + candidato->getNome()
            + ", está falando!");
        cout<< "--> Eleitor " << nome << " seu candidato, " << candidato->getNome() << ", está falando!" <<endl;
    }
}