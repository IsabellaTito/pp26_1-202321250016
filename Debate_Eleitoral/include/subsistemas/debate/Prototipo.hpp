#pragma once

#include <memory>

using std::shared_ptr;

class ColaboradorPolitico;

class Prototipo{
    public:
        virtual ~Prototipo() = default;

        virtual shared_ptr<ColaboradorPolitico> clone( ) const = 0;
};