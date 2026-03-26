#include <iostream>
#include <string>
#include "abstracao/Livro.hpp"
#include "abstracao/Revista.hpp"
#include "implementador/PublicacaoImplBD.hpp"
#include "implementador/PublicacaoImplXML.hpp"

using std::string, std::cout, std::endl;

int main(){

    Livro MobyDick(new PublicacaoImplBD()), EuRobo(new PublicacaoImplXML());
    Revista Veja(new PublicacaoImplBD()), Forbes(new PublicacaoImplXML());
    
    cout << "------ Livro MobyDick ------" << endl;
    cout << MobyDick.obterDados() << endl;
    cout << MobyDick.getISBN() << endl;
    cout << MobyDick.getAutor() << endl;
    cout << MobyDick.getTitulo() << endl;

    cout << " " << endl;

    cout << "------ Livro Eu, Robô ------" << endl;
    cout << EuRobo.obterDados() << endl;
    cout << EuRobo.getISBN() << endl;
    cout << EuRobo.getAutor() << endl;
    cout << EuRobo.getTitulo() << endl;

    cout << " " << endl;

    cout << "------ Revista Veja ------" << endl;
    cout << Veja.obterDados() << endl;
    cout << Veja.getArtigo() << endl;
    cout << Veja.getAutor() << endl;
    cout << Veja.getTitulo() << endl;

    cout << " " << endl;

    cout << "------ Revista Forbes ------" << endl;
    cout << Forbes.obterDados() << endl;
    cout << Forbes.getArtigo() << endl;
    cout << Forbes.getAutor() << endl;
    cout << Forbes.getTitulo() << endl;


    return 0;
}