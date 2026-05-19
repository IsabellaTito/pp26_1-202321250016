#include <iostream>

#include "shared/FachadaDebate.hpp"
#include "shared/cli.hpp"

using std::cout, std::endl;

int main(){
    
    FachadaDebate& fachada = FachadaDebate::getInstance();
    CLI& cli = CLI::getInstance(fachada);
    cli.run();
    
    return 0;
}