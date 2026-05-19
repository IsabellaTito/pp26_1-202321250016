#pragma once

class EleitorObservador{
    public:
        virtual ~EleitorObservador() = default;

        virtual void atualizar() = 0;

};