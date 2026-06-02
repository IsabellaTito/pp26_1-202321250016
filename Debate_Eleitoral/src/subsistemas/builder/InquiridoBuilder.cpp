#include "subsistemas/builder/InquiridoBuilder.hpp"

#include <iostream>

using std::cout, std::endl;

InquiridoBuilder& InquiridoBuilder::criarMicrofone(){
    ColaboradorBuilder::criarMicrofone();
    return *this;
}

shared_ptr<ColaboradorPolitico> InquiridoBuilder::criarColaborador() const{
    auto copia = politico->clone();
    auto inquirido = make_shared<Inquirido>(*copia);

    if(microfone){
        inquirido->setMicrofone(this->microfone);
        cout<<"Criou Microfone"<<endl;
    }
    else
        cout<<"Microfone não conseguiu ser criado"<<endl;
    return inquirido;
}