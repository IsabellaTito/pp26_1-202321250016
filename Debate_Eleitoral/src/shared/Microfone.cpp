#include "shared/Microfone.hpp"

void Microfone::passaTempo(int tempo){
    LogSystem& log = LogSystem::getInstance();

    while(tempo > 0){

        log.registerLog(
            "    Tempo restante: "
            + std::to_string(tempo)
        );

        std::this_thread::sleep_for(
            std::chrono::seconds(1)
        );

        tempo--;
    }

    desliga();

    log.registerLog("Microfone desligado");

}