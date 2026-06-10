#pragma once

class ConfiguraTempo{

    private:
        int pergunta;
        int resposta;
        int replica;
        int treplica;
        int dr;

    public:

        ConfiguraTempo(){
            pergunta = 0;
            resposta = 0;
            replica = 0;
            treplica = 0;
            dr = 0;
        }

        void setPergunta(int temp){pergunta = temp;}
        int getPergunta() const{return pergunta;}

        void setResposta(int temp){resposta = temp;}
        int getResposta() const{return resposta;}

        void setReplica(int temp){replica = temp;}
        int getReplica() const{return replica;}

        void setTreplica(int temp){treplica = temp;}
        int getTreplica() const{return treplica;}

        void setDR(int temp){dr = temp;}
        int getDR() const{return dr;}
};