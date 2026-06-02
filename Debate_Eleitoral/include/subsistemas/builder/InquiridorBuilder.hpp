#pragma once

#include <memory>
#include "subsistemas/builder/ColaboradorBuilder.hpp"
#include "subsistemas/debate/Inquiridor.hpp"

using std::shared_ptr, std::make_shared;

class InquiridorBuilder : public ColaboradorBuilder{
    public:
        InquiridorBuilder(const shared_ptr<ColaboradorPolitico> politico):ColaboradorBuilder(politico){}

        InquiridorBuilder& criarMicrofone();
        shared_ptr<ColaboradorPolitico> criarColaborador() const override;

};