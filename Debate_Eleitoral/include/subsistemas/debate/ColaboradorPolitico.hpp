#pragma once

#include <string>
#include <memory>

#include "subsistemas/debate/Prototipo.hpp"
#include "shared/Microfone.hpp"
#include "subsistemas/debate/MediadorBase.hpp"
#include "subsistemas/eleitores/Politico.hpp"

using std::string, std::shared_ptr, std::make_shared, std::enable_shared_from_this;

class ColaboradorPolitico : public Politico, public Prototipo, public enable_shared_from_this<ColaboradorPolitico> {
    protected:
        string nome;
        string partido;
        bool inquiridor;
        shared_ptr<Microfone>microfone;
        MediadorBase* mediador;
        bool pedidoDR;
         
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
        MediadorBase* getMediador(){return mediador;}

        void setMicrofone(shared_ptr<Microfone> micro){microfone=micro;}
        bool getMicrofone(){return microfone->getMicrofone();}

        void pedirDR();
        bool getDR(){return pedidoDR;}
        void retirarPedidoDR(){pedidoDR = false;}
        
        shared_ptr<ColaboradorPolitico> clone() const override;

};