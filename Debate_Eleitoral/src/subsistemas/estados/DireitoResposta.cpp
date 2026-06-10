#include <iostream>

#include "subsistemas/estados/DireitoResposta.hpp"
#include "subsistemas/estados/EstadoCiclos.hpp"
#include "subsistemas/debate/MediadorDebate.hpp"
#include "shared/LogSystem.hpp"

using std::cout, std::endl, std::cin, std::toupper;

void DireitoResposta::run(const ConfiguraTempo& config){
    LogSystem::getInstance().registerLog("------ INICIANDO DR -------");
    cout << "------ INICIANDO DR -------"<<endl;
    
    auto& lista = contexto->getListaDR();
    while(!lista.empty()){
        shared_ptr<ColaboradorPolitico> politicoAtual = lista.front();

        cout << "\nPolitico: "<< politicoAtual->getNome() << " Partido: " << politicoAtual->getPartido() << "\n Conceder DR? (S/N): ";
        LogSystem::getInstance().registerLog("Politico: " + politicoAtual->getNome() + " Partido: "+ politicoAtual->getPartido() + " Conceder DR? (S/N)");

        char opcao;
        cin >> opcao;

        if(toupper(opcao) == 'S'){
            LogSystem::getInstance().registerLog("AÇÃO CONCEDIDA! Executando direito de resposta para Politico " + politicoAtual->getNome() + " - " + politicoAtual->getPartido());
            
            //cria microfone
            shared_ptr<Microfone> microfone = make_shared<Microfone>();
            politicoAtual->setMicrofone(microfone);

            //permite falar e notifica os eleitores
            microfone->liga();
            politicoAtual->notificar();
            LogSystem::getInstance().registerLog(
                "Microfone aberto para direito de resposta!(DR)"
            );
            microfone->passaTempo(config.getDR());
        }
        else if(toupper(opcao) == 'N'){
            LogSystem::getInstance().registerLog("AÇÃO NEGADA! Politico " + politicoAtual->getNome() + " - " + politicoAtual->getPartido() + " não terá direito de resposta.");
        }

        politicoAtual->retirarPedidoDR();
        lista.pop();
        cin.ignore(10000,'\n');
    }
    LogSystem::getInstance().registerLog("Todos os pedidos de Direito de Resposta foram processados.");
    cout << "\nTodos os pedidos de Direito de Resposta foram processados."<<endl;

    LogSystem::getInstance().registerLog("------ FIM DR -------");
    cout << "------ FIM DR -------"<<endl;

    LogSystem::getInstance().registerLog("Configure os tempo novamente e refaça o sorteio para um próximo debate!");
    std::cout << "Configure os tempo novamente e refaça o sorteio para um próximo debate!" << std::endl;

    contexto->setEstado(make_shared<EstadoCiclos>(contexto));

}
