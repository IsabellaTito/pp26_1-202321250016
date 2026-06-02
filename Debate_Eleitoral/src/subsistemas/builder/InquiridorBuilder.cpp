#include "subsistemas/builder/InquiridorBuilder.hpp"

#include <iostream>

using std::cout, std::endl;

InquiridorBuilder& InquiridorBuilder::criarMicrofone(){
    ColaboradorBuilder::criarMicrofone();
    return *this;
}

shared_ptr<ColaboradorPolitico> InquiridorBuilder::criarColaborador() const{
    auto copia = politico->clone();
    auto inquiridor = make_shared<Inquiridor>(*copia);

    if(microfone){
        inquiridor->setMicrofone(this->microfone);
        cout<<"Criou Microfone"<<endl;
    }
    else
        cout<<"Microfone não conseguiu ser criado"<<endl;
    return inquiridor;
}