#include "subsistemas/debate/MediadorDebate.hpp"
#include "subsistemas/debate/ColaboradorPolitico.hpp"

ColaboradorPolitico::ColaboradorPolitico(string nome,string partido)
    :nome(nome), partido(partido),inquiridor(false),microfone(nullptr),mediador(nullptr), pedidoDR(false){}

ColaboradorPolitico::ColaboradorPolitico(const ColaboradorPolitico& outro)
    : Politico(outro),
      enable_shared_from_this<ColaboradorPolitico>(),
      nome(outro.nome),
      partido(outro.partido),
      inquiridor(outro.inquiridor),
      microfone(outro.microfone),
      mediador(outro.mediador),
      pedidoDR(outro.pedidoDR)      
{}

shared_ptr<ColaboradorPolitico> ColaboradorPolitico::clone() const{
    return std::make_shared<ColaboradorPolitico>(*this);
}

void ColaboradorPolitico::pedirDR(){
    auto* mediadorDebate = dynamic_cast<MediadorDebate*>(this->mediador);
    if(mediadorDebate){
        pedidoDR = true;
        mediadorDebate->addListaDR(shared_from_this());
    }
}