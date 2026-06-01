#pragma once

#include <string>
#include <memory>

#include "subsistemas/debate/Prototipo.hpp"
#include "shared/Microfone.hpp"
#include "subsistemas/debate/MediadorBase.hpp"
#include "subsistemas/eleitores/Politico.hpp"

using std::string, std::shared_ptr, std::make_shared;

class ColaboradorPolitico : public Politico, public Prototipo{
    protected:
        string nome;
        string partido;
        bool inquiridor;
        shared_ptr<Microfone>microfone;
        MediadorBase* mediador;
         
    public:

        ColaboradorPolitico(string,string);

        ColaboradorPolitico(const ColaboradorPolitico& outro);

        void setNome(string nome){this->nome = nome;}
        string getNome() const{return nome;}

        void setPartido(string partido){this->partido = partido;}
        string getPartido() const{return partido;}

        void setInquiridor(bool inqui){inquiridor = inqui;}
        bool getInquiridor() const{ return inquiridor;}

        void setMediador(MediadorBase* med){mediador = med;}

        bool getMicrofone(){return microfone->getMicrofone();}

        shared_ptr<ColaboradorPolitico> clone() const override;

};