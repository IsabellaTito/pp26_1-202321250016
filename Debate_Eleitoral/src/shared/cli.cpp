#include <iostream>
#include <sstream>

#include "shared/cli.hpp"
#include "shared/FachadaDebate.hpp"
#include "shared/LogSystem.hpp"


CLI& CLI::getInstance(FachadaDebate& fachada)
{
    static CLI instance(fachada);
    return instance;
}


CLI::CLI(FachadaDebate& fachada) : fachada(fachada) {}

void CLI::run()
{
    std::string input;

    std::cout << "CLI iniciada. Digite 'help' para ajuda e 'exit' para sair.\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "exit") {
            LogSystem::getInstance().registerLog("Saindo do sistema...");
            break;
        }

        std::istringstream iss(input);
        std::vector<std::string> args;
        std::string word;

        while (iss >> word) {
            args.push_back(word);
        }

        if (!args.empty()) {
            executarComando(args);
        }
    }
}

void CLI::executarComando(const std::vector<std::string>& args){
    // cadastrar politico <nome>,<partido>
    if (args[0] == "cadastrar" && args.size() >= 4 && args[1] == "politico") {
        fachada.cadastrarPolitico(args[2], args[3]);
        std::cout << "Politico cadastrado com sucesso." << std::endl;
    }

    // cadastrar eleitor <nome>,<cpf>,<nome-politico>,<partido-politico>
    else if (args[0] == "cadastrar" && args.size() >= 5 && args[1] == "eleitor") {
        fachada.cadastrarEleitor(args[2], args[3], args[4], args[5]);
        std::cout << "Eleitor cadastrado com sucesso." << std::endl;
    }

    // configurar tempo <pergunta> <reposta> <replica> <treplica>
    else if (args[0] == "configurar" && args.size() >= 6 && args[1] == "tempo") {
        fachada.configuracaoTempo(std::stof(args[2]), std::stof(args[3]), std::stof(args[4]), std::stof(args[5]));
        std::cout << "Configurações de cronometro definidas com sucesso." << std::endl;
    }

    /*
    //Lista sistema de logs
    else if (args[0] == "exibir" && args.size() >= 2 && args[1] == "log") {
        std::cout << "Lista de logs..." << std::endl;
    }
    */

    // sortear inquiridor
    else if (args[0] == "sortear" && args.size() >= 2 && args[1] == "inquiridor") {
        int result = fachada.sorteioInquiridor();
        if (result == 1){
            std::cout << "Inquiridor sorteado com sucesso." << std::endl;
        }
    }

    // escolher inquirido <nome>,<partido>
    else if(args[0] == "escolher" && args.size() >= 4 && args[1] == "inquirido") {
        fachada.escolherInquirido(args[2], args[3]);
        std::cout << "Inquirido escolhido com sucesso." << std::endl;
    }

    // Start debate session
    else if(args[0] == "iniciar" && args.size() >= 2 && args[1] == "debate") {
        fachada.executaDebate();
        std::cout << "Fim da seção de debate entre os candidatos." << std::endl;
         std::cout << "Configure os tempo novamente para uma nova rodada!" << std::endl;
    }

    // Help
    else if(args[0] == "help" && args.size() >= 1) {
        std::cout << "Lista de comandos do sistem:" << std::endl;
        std::cout << "  * cadastrar politico <nome> <partido>" << std::endl;
        std::cout << "  * cadastrar eleitor <nome> <cpf> <nome-politico> <partido-politico>" << std::endl;
        std::cout << "  * configurar tempo <pergunta> <reposta> <replica> <treplica>" << std::endl;
        //std::cout << "  * exibir log " << std::endl;
        std::cout << "  * sortear inquiridor " << std::endl;
        std::cout << "  * escolher inquirido <nome-politico> <partido-politico> " << std::endl;
        std::cout << "  * iniciar debate " << std::endl;
        std::cout << "  * exit" << std::endl;
    }

    else {
        std::cout << "Comando inválido." << std::endl;
    }

}

