#pragma once

#include <memory>
#include "subsistemas/debate/ColaboradorPolitico.hpp"
#include "shared/Microfone.hpp"

using std::shared_ptr, std::make_shared;

class ColaboradorBuilder{
    protected:
        const shared_ptr<ColaboradorPolitico> politico;
        shared_ptr<Microfone> microfone;

    public:
        ColaboradorBuilder(const shared_ptr<ColaboradorPolitico> politico) : politico(politico), microfone(nullptr) {}

        ColaboradorBuilder& criarMicrofone();

        virtual shared_ptr<ColaboradorPolitico> criarColaborador() const = 0;
};
