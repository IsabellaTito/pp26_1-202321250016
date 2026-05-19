#pragma once

#include <memory>

#include "subsistemas/debate/MediadorBase.hpp"
#include "subsistemas/debate/Inquiridor.hpp"
#include "subsistemas/debate/Inquirido.hpp"

using std::shared_ptr;

class ColaboradorPolitico;

class MediadorDebate : public MediadorBase{
    private:
        shared_ptr<Inquiridor> inquiridor;

        shared_ptr<Inquirido> inquirido;

    public:

        void setInquiridor(shared_ptr<ColaboradorPolitico> politico);

        void setInquirido(shared_ptr<ColaboradorPolitico> politico);

        shared_ptr<Inquiridor> getInquiridor() const;

        shared_ptr<Inquirido> getInquirido() const;

        void debate(const ConfiguraTempo& config) override;

};