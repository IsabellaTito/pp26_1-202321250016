#pragma once

class ConfiguraTempo;

class MediadorBase{
    public:
        virtual ~MediadorBase() = default;

        virtual void debate(const ConfiguraTempo& config) = 0;

};