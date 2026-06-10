#include <iostream>
#include <random>

#include "subsistemas/debate/MediadorDebate.hpp"

#include "subsistemas/debate/ColaboradorPolitico.hpp"
#include "subsistemas/estados/EstadosDebate.hpp"
#include "subsistemas/ConfiguraTempo.hpp"
#include "subsistemas/builder/InquiridoBuilder.hpp"
#include "subsistemas/builder/InquiridorBuilder.hpp"
#include "shared/LogSystem.hpp"

using std::cout, std::endl;

MediadorDebate::MediadorDebate():estado(nullptr){}

void MediadorDebate::setInquiridor(shared_ptr<ColaboradorPolitico> politico){
    inquiridor = make_shared<Inquiridor>(*(InquiridorBuilder(politico).criarMicrofone().criarColaborador()));
}

void MediadorDebate::setInquirido(shared_ptr<ColaboradorPolitico> politico){
    inquirido = make_shared<Inquirido>(*(InquiridoBuilder(politico).criarMicrofone().criarColaborador()));
}

shared_ptr<Inquiridor> MediadorDebate::getInquiridor() const{return inquiridor;}

shared_ptr<Inquirido> MediadorDebate::getInquirido() const{return inquirido;}

void MediadorDebate::debate(const ConfiguraTempo& config){
    if(!estado){
            estado = make_shared<EstadoCiclos>(shared_from_this());
    }
    estado->run(config);
}