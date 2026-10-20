<h1 align="center"> Jogo da Vida de Conway </h1>

### Simulação de autômatos celulares desenvolvida em C

<p align="center">
Simulação de gerações • Regras de Conway • Matrizes bidimensionais • Lógica de programação • Linguagem C
</p>

<p align="center">

<a href="../../issues">
<img src="https://img.shields.io/badge/Reportar-Bug-black?style=for-the-badge&logo=github">
</a>

<a href="../../issues">
<img src="https://img.shields.io/badge/Sugerir-Melhoria-blue?style=for-the-badge&logo=github">
</a>

</p>

<p align="center">

<img src="https://img.shields.io/badge/Linguagem-C-A8B9CC?style=flat-square&logo=c&logoColor=white">

<img src="https://img.shields.io/badge/Projeto-Educacional-blue?style=flat-square">

<img src="https://img.shields.io/badge/Interface-Terminal-black?style=flat-square">

<img src="https://img.shields.io/badge/Status-Em%20Desenvolvimento-orange?style=flat-square">

<img src="https://img.shields.io/badge/Version%20Control-Git%20%26%20GitHub-F05032?style=flat-square&logo=git&logoColor=white">

</p>

---

# Sobre o Projeto

O **Jogo da Vida de Conway** é uma implementação em linguagem C do famoso autômato celular criado pelo matemático John Horton Conway.

O programa simula a evolução de células vivas e mortas em um tabuleiro bidimensional, aplicando um conjunto de regras que determina o estado de cada célula nas gerações seguintes.

Apesar de possuir regras simples, o jogo apresenta comportamentos complexos que demonstram como padrões podem surgir a partir de condições iniciais relativamente simples.

Este projeto foi desenvolvido com o objetivo de praticar conceitos fundamentais da programação em C, incluindo matrizes, funções, ponteiros, estruturas de repetição, condicionais e manipulação de dados.

A implementação original utiliza um tabuleiro de dimensões fixas, inicialização aleatória e simulação de múltiplas gerações.

O projeto está em evolução, com foco na organização do código, melhoria da qualidade do software, portabilidade e implementação de testes.

---

# Objetivos do Projeto

O objetivo vai além de implementar as regras de um jogo.

Este projeto também serve como exercício prático para desenvolver conhecimentos em:

- Lógica de programação e algoritmos.
- Linguagem C e organização de funções.
- Manipulação de matrizes bidimensionais.
- Passagem de arrays para funções.
- Simulação de sistemas discretos.
- Controle de fluxo e estruturas condicionais.
- Gerenciamento de histórico de estados.
- Depuração e tratamento de erros.
- Organização de projetos com Git e GitHub.
- Refatoração e testes de software.

---

# Funcionalidades

### Inicialização do Tabuleiro

O tabuleiro é preenchido aleatoriamente com células vivas e mortas, criando uma configuração inicial para a simulação.

### Simulação de Gerações

O programa calcula o estado seguinte do tabuleiro com base nas regras do Jogo da Vida de Conway.

Cada geração representa uma nova etapa da evolução das células.

### Contagem de Vizinhos

Cada célula considera seus vizinhos nas oito posições adjacentes para determinar seu próximo estado.

### Estatísticas das Células

O programa possui funções para contar células vivas e mortas no tabuleiro.

### Histórico de Gerações

A implementação original utiliza uma matriz tridimensional para armazenar estados do tabuleiro ao longo da simulação.

### Interface no Terminal

A interação ocorre por meio de entrada e saída de texto, permitindo acompanhar a evolução da simulação.

---

# Regras do Jogo

O estado de cada célula na próxima geração depende da quantidade de células vivas em sua vizinhança.

Existem quatro regras fundamentais:

### 1. Morte por Isolamento

Uma célula viva com menos de duas células vivas vizinhas morre.

### 2. Sobrevivência

Uma célula viva com duas ou três células vivas vizinhas continua viva.

### 3. Morte por Superpopulação

Uma célula viva com mais de três células vivas vizinhas morre.

### 4. Reprodução

Uma célula morta com exatamente três células vivas vizinhas torna-se viva.

Todas as células evoluem simultaneamente. Por isso, o cálculo de uma geração deve considerar o estado anterior completo do tabuleiro.

---

# Tecnologias Utilizadas

<p align="center">

<img src="https://img.shields.io/badge/C-A8B9CC?style=for-the-badge&logo=c&logoColor=white">

<img src="https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git&logoColor=white">

<img src="https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=github&logoColor=white">

</p>

| Categoria | Tecnologia |
|---|---|
| Linguagem | C |
| Interface | Terminal |
| Estruturas de dados | Matrizes e arrays |
| Paradigma | Programação procedural |
| Controle de versão | Git |
| Hospedagem do código | GitHub |

---

# Destaques Técnicos

- Implementação em C.
- Tabuleiro bidimensional de 10 × 10 células.
- Inicialização aleatória.
- Aplicação das quatro regras fundamentais de Conway.
- Contagem de células vizinhas.
- Simulação de múltiplas gerações.
- Utilização de funções para organizar operações.
- Armazenamento de estados anteriores do tabuleiro.
- Projeto em evolução com foco em boas práticas de programação.

---

# Arquitetura

A versão original concentra as funcionalidades em um único arquivo C. Como parte da evolução do projeto, a proposta é separar as responsabilidades em módulos independentes.

Essa organização facilitará a manutenção, a leitura do código e a criação de testes automatizados.

```text
                    Jogo da Vida de Conway
                              |
                              v
                       Programa Principal
                           main.c
                              |
               +--------------+--------------+
               |                             |
               v                             v
       Operações do Tabuleiro          Lógica do Jogo
         tabuleiro.c                    logica.c
               |                             |
               v                             v
       Inicialização, cópia,         Contagem de vizinhos
       impressão e contagem          e próximas gerações
               |                             |
               +--------------+--------------+
                              |
                              v
                       Estado do Tabuleiro
```

**Observação:** o diagrama representa a arquitetura planejada para a refatoração. A implementação original ainda está concentrada em um único arquivo.

---

# Estrutura do Projeto

A estrutura proposta para a organização do repositório é:

```text
jogo-da-vida-conway/
│
├── src/
│   ├── main.c
│   ├── tabuleiro.c
│   └── logica.c
│
├── include/
│   ├── tabuleiro.h
│   └── logica.h
│
├── README.md
└── .gitignore
```

### Responsabilidade dos Arquivos

| Arquivo | Responsabilidade |
|---|---|
| `main.c` | Controlar o fluxo principal e a interação com o usuário |
| `tabuleiro.c` | Inicializar, imprimir, copiar e contar células |
| `logica.c` | Calcular vizinhos e simular novas gerações |
| `tabuleiro.h` | Declarar as funções relacionadas ao tabuleiro |
| `logica.h` | Declarar as funções relacionadas às regras do jogo |
| `README.md` | Documentar o projeto |
| `.gitignore` | Ignorar arquivos gerados e configurações locais |

A separação dos módulos será realizada gradualmente, preservando o código original durante as primeiras etapas.

---

# Como Funciona a Simulação

O fluxo geral do programa pode ser resumido nas seguintes etapas:

1. Inicializar o tabuleiro com células vivas e mortas.
2. Exibir a configuração inicial.
3. Receber a quantidade de gerações desejada.
4. Contar os vizinhos de cada célula.
5. Calcular o estado da próxima geração.
6. Atualizar o tabuleiro e registrar o histórico.
7. Exibir as gerações e as estatísticas disponíveis.
8. Finalizar ou reiniciar a simulação, conforme o fluxo do programa.

---

# Como Compilar e Executar

A compilação e a execução da versão original ainda precisam ser verificadas em um ambiente de desenvolvimento compatível.

O código utiliza operações de terminal que podem variar conforme o sistema operacional, além de funções de pausa e entrada de teclado que podem exigir bibliotecas específicas.

Após a revisão da portabilidade, as instruções definitivas de compilação serão adicionadas aqui.

### Compilação planejada

Após a separação dos arquivos e a verificação das dependências, a compilação com GCC poderá seguir um formato semelhante a:

```bash
gcc -Iinclude src/main.c src/tabuleiro.c src/logica.c -o jogo-da-vida
```

Esse comando é uma referência para a estrutura modular planejada. Ele não deve ser considerado validado até que os arquivos estejam separados e o programa seja compilado com sucesso.

---

# Limitações Conhecidas

A versão original possui algumas limitações que serão tratadas ao longo do desenvolvimento:

- Dimensões fixas de 10 × 10 células.
- Configuração inicial aleatória.
- Capacidade limitada para o histórico de gerações.
- Validação de entradas ainda precisa ser aprimorada.
- Operações de terminal dependentes do ambiente de execução.
- Portabilidade entre sistemas operacionais ainda não verificada.
- Testes automatizados ainda não implementados.
- Organização modular ainda planejada.

Esses pontos representam oportunidades de melhoria e fazem parte da evolução do projeto.

---

# Roadmap

O desenvolvimento será realizado em etapas, priorizando a preservação do código original e a introdução gradual de boas práticas.

## Etapas iniciais

- [x] Implementação original das regras de Conway.
- [x] Inicialização aleatória do tabuleiro.
- [x] Simulação de gerações.
- [x] Funções para contar células e vizinhos.
- [ ] Documentação do projeto no GitHub.
- [ ] Organização dos arquivos do repositório.
- [ ] Configuração do `.gitignore`.

## Melhorias planejadas

- [ ] Separar a lógica do jogo em módulos.
- [ ] Criar arquivos de cabeçalho.
- [ ] Corrigir os limites do histórico.
- [ ] Aprimorar a validação das entradas.
- [ ] Melhorar a compatibilidade entre sistemas operacionais.
- [ ] Adicionar testes automatizados.
- [ ] Criar um Makefile para facilitar a compilação.
- [ ] Permitir dimensões configuráveis do tabuleiro.
- [ ] Melhorar a apresentação visual no terminal.

---

# Organização e Versionamento

O projeto utiliza Git para registrar sua evolução em etapas pequenas e compreensíveis.

Os commits serão organizados de acordo com o tipo de alteração realizada:

| Tipo | Finalidade | Exemplo |
|---|---|---|
| `chore` | Organização e configuração | `chore: add gitignore` |
| `docs` | Documentação | `docs: improve project README` |
| `refactor` | Reorganização do código sem alterar o comportamento esperado | `refactor: separate board operations` |
| `fix` | Correção de erros | `fix: handle generation history boundaries` |
| `test` | Inclusão de testes | `test: cover core game rules` |

A intenção é manter um histórico de desenvolvimento claro, facilitando a compreensão das decisões técnicas e das melhorias implementadas.

---

# Aprendizados

Este projeto oferece uma oportunidade prática para explorar conceitos importantes da programação:

- Como representar um sistema usando matrizes.
- Como aplicar regras a cada elemento de uma estrutura.
- Como atualizar estados simultaneamente.
- Como dividir um problema em funções menores.
- Como preservar e consultar estados anteriores.
- Como identificar limitações de uma implementação.
- Como organizar um repositório profissional.
- Como utilizar commits para documentar a evolução de um projeto.

---

# Próximos Passos

A evolução do Jogo da Vida de Conway seguirá uma abordagem incremental.

Primeiro, o código original será preservado e documentado. Em seguida, as funções serão separadas por responsabilidade, os limites do histórico serão revisados e os testes serão introduzidos quando houver um ambiente de compilação disponível.

O objetivo é transformar uma implementação educacional em um projeto de portfólio organizado, documentado e cada vez mais confiável.

---

# Contribuições

Sugestões, melhorias e relatos de problemas são bem-vindos.

Para contribuir:

1. Faça um fork do repositório.
2. Crie uma branch para sua alteração.

```bash
git checkout -b feature/nova-melhoria
```

3. Registre suas alterações em um commit.

```bash
git commit -m "feat: add new improvement"
```

4. Envie sua branch.

```bash
git push origin feature/nova-melhoria
```

5. Abra um Pull Request descrevendo as mudanças.

---

# Licença

A licença do projeto ainda deve ser definida.

Caso queira permitir o uso, a modificação e a distribuição do código sob os termos de uma licença de código aberto, considere adicionar um arquivo `LICENSE` com a licença escolhida.

---

# Author

<div align="center">

## Rafael Sanguini Colagrossi

Software Developer passionate about Artificial Intelligence, Financial Technology and Full-Stack Development.

Building modern software focused on performance, clean architecture and great user experience.

<br>

<a href="https://github.com/rsanguini">
<img src="https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=github&logoColor=white">
</a>

<a href="https://linkedin.com/in/rafaelsanguini">
<img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white">
</a>

<a href="mailto:rafaelcolagrossi@gmail.com">
<img src="https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white">
</a>

</div>

<div align="center">

---

## Jogo da Vida de Conway

**Pequenas regras. Padrões complexos. Aprendizado contínuo.**

Desenvolvido em C como projeto de estudo de algoritmos, autômatos celulares e boas práticas de programação.

⭐ Se você gostou do projeto, considere deixar uma estrela no repositório!

</div>
