#pragma once

#include <memory>
#include "subsistemas/builder/ColaboradorBuilder.hpp"
#include "subsistemas/debate/Inquirido.hpp"

using std::shared_ptr, std::make_shared;

class InquiridoBuilder : public ColaboradorBuilder{
    public:
        InquiridoBuilder(const shared_ptr<ColaboradorPolitico> politico):ColaboradorBuilder(politico){}

        InquiridoBuilder& criarMicrofone();
        shared_ptr<ColaboradorPolitico> criarColaborador() const override;

};