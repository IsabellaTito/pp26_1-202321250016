#include "subsistemas/debate/ColaboradorPolitico.hpp"

ColaboradorPolitico::ColaboradorPolitico(string nome,string partido)
    :nome(nome), partido(partido),inquiridor(false),microfone(make_shared<Microfone>()),mediador(nullptr){}

ColaboradorPolitico::ColaboradorPolitico(const ColaboradorPolitico& outro)
    : Politico(outro),
      nome(outro.nome),
      partido(outro.partido),
      inquiridor(outro.inquiridor),
      microfone(outro.microfone),
      mediador(outro.mediador)      
{}
