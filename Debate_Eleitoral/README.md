# 🎙️ DEBATE ELEITORAL 🗳️

Projeto desenvolvido como resolução de uma atividade acadêmica proposta em prova, cujo objetivo era evoluir uma modelagem UML e implementar um sistema completo para gerenciamento de debates políticos.

A proposta simula uma aplicação utilizada por apresentadores de rádio e televisão durante debates eleitorais, permitindo controlar o tempo de fala dos candidatos, alternar microfones automaticamente e até notificar eleitores em tempo real quando seu candidato estiver falando.

A implementação deste projeto busca atender às seguintes questões propostas em prova.

---

## Questão 3 — Controle do Debate

O sistema deveria permitir que um apresentador fosse capaz de:

- Sortear candidatos para iniciar as rodadas;
- Controlar o direito de fala dos participantes;
- Gerenciar automaticamente os tempos de:
  - pergunta;
  - resposta;
  - réplica;
  - tréplica;
- Alternar automaticamente os microfones entre os candidatos;
- Registrar todas as ações realizadas durante o debate;
- Possibilitar execução tanto em:
  - Interface de Linha de Comando (CLI);
  - Interface Gráfica (GUI).

Além disso, cada candidato só pode assumir o papel de **inquiridor** uma única vez durante o debate.

## Questão 5 — Notificação para Eleitores

Após o sucesso do protótipo inicial, foi adicionada uma nova funcionalidade:

> Agora os eleitores podem receber notificações em tempo real quando o seu candidato estiver falando.

### Funcionalidades adicionadas

- Cadastro de eleitores;
- Associação entre eleitor e candidato;
- Sistema de notificações em tempo real;
- Envio automático da mensagem:

```text
"SEU CANDIDATO ESTÁ FALANDO"
```

---

## 🧩 Modelagem UML

```text
Exemplo:
![Modelagem UML](./docs/uml.png)
```

## ▶️ Como Executar

### Compilar a aplicação

```bash
make app
```

### Executar o sistema

```bash
make run
```

### Logs da Aplicação

Para visualizar o log e acompanhar os eventos em tempo real, abra outro terminal e execute o seguinte comando:

```bash
tail -f app.log
```
