#pragma once

#include <memory>
#include <queue>

#include "subsistemas/debate/MediadorBase.hpp"
#include "subsistemas/debate/Inquiridor.hpp"
#include "subsistemas/debate/Inquirido.hpp"
#include "subsistemas/estados/EstadoCiclos.hpp"
#include "subsistemas/estados/DireitoResposta.hpp"
#include "subsistemas/GerenciaPolitico.hpp"

using std::shared_ptr, std::queue, std::make_shared;

class ColaboradorPolitico;

class MediadorDebate : public MediadorBase, public std::enable_shared_from_this<MediadorDebate> {
    private:
        shared_ptr<Inquiridor> inquiridor;
        shared_ptr<Inquirido> inquirido;
        shared_ptr<EstadosDebate> estado;
        queue<shared_ptr<ColaboradorPolitico>> listaDR;

    public:

        MediadorDebate();

        void setInquiridor(shared_ptr<ColaboradorPolitico> politico);

        void setInquirido(shared_ptr<ColaboradorPolitico> politico);

        shared_ptr<Inquiridor> getInquiridor() const;

        shared_ptr<Inquirido> getInquirido() const;

        void debate(const ConfiguraTempo& config) override;

        void addListaDR(shared_ptr<ColaboradorPolitico> politico){listaDR.push(politico);}

        queue<shared_ptr<ColaboradorPolitico>>& getListaDR(){return listaDR;}

        void removeElementoDR(){listaDR.pop();}

        void setEstado(shared_ptr<EstadosDebate> estado){this->estado = estado;}

};