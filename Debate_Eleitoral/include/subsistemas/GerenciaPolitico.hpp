#pragma once

#include <vector>
#include <memory>
#include <string>

#include "subsistemas/debate/ColaboradorPolitico.hpp"

#include "shared/LogSystem.hpp"

using std::string, std::vector, std::shared_ptr;

class GerenciaPolitico{
    private:
        vector<shared_ptr<ColaboradorPolitico>> politicos;

    public:
        GerenciaPolitico();

        void criarPolitico(const string& nome, const string& partido, MediadorBase* mediador);

        shared_ptr<ColaboradorPolitico> obterPolitico(const string& nome, const string& partido);

        shared_ptr<ColaboradorPolitico> sortearPolitico();

};