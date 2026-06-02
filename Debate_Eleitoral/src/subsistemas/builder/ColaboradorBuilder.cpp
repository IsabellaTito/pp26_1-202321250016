#include "subsistemas/builder/ColaboradorBuilder.hpp"

ColaboradorBuilder& ColaboradorBuilder::criarMicrofone(){
    microfone = make_shared<Microfone>();
    politico->setMicrofone(microfone);
    return *this;
}