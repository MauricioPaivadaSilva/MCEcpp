<div align="center">

# MCEcpp

![GitHub top language](https://img.shields.io/github/languages/top/MauricioPaivadaSilva/MCEcpp) ![GitHub language count](https://img.shields.io/github/languages/count/MauricioPaivadaSilva/MCEcpp) ![GitHub License](https://img.shields.io/github/license/MauricioPaivadaSilva/MCEcpp) ![GitHub last commit (branch)](https://img.shields.io/github/last-commit/MauricioPaivadaSilva/MCEcpp/main) ![GitHub repo size](https://img.shields.io/github/repo-size/MauricioPaivadaSilva/MCEcpp)

</div>

### Resultados dos testes

<div align="center">

| Tipo do teste | Resultado |
|---|---|


</div>

## Sobre a biblioteca
A presente biblioteca aprensenta-se em sua *versão 0.1.2*, sendo a reescrita da biblioteca [MCEpy](https://github.com/MauricioPaivadaSilva/MCEpy) em C++, com o objetivo de facilitar a implementação e a possibilidade de uso em mais trabalhos.

Devido a essas condições o README.md tem a mesma base e os funcionamentos da aplicação/biblioteca serão os mesmos.

## Motivação

O presente projeto tem como motivação o trabalho desenvolvido pelo LABin - Labratório de educação inclusiva, que tem como intuito o a pesquisa-ação na área do ensino inclusivo.

## Sumário
* [Requisitos e forma de instalação](#requisitos-e-forma-de-instalação)
* [Funcionalidades esperadas](#funcionalidades-esperadas)
* [Resultados obtidos](#resultados-obtidos)
* [Formas de utilização](#formas-de-utilização)
* [Agradecimentos](#agradecimentos)
## Requisitos e forma de instalação


### Requisitos
<div align="center">

|Dependencia | Versão|
|---|---|
| SFML | 2.6.1 |
| g++ | 13.2.1 |

</div>

### Forma de Instalação

Dentro do diretório do projeto digite o comando `make`. Ele irá compilar os arquivos do projeto.

## Funcionalidades esperadas

- [ ] Receber dados de valores puramente reais;
- [ ] Receber dados de números complexos;
- [X] Receber os dados de frequência;
- [X] Gerar o gráfico de função senoidal;
- [ ] Gerar o ciclo trigonométrico;
- [ ] Gerar o vetor dentro do ciclo trigonométrico;
- [ ] Apresentar mais de um gráfico em uma única tela;
- [ ] Fazer a animação do ciclo trigonométrico;
- [ ] Fazer a animação do gráfico da função senoidal.

## Resultados obtidos

### Gráficos gerados

## Formas de utilização

* Chmada da lib:

```cpp

#include "include/graph.hpp"
```

* Utilização dentro de um programa CLI:

```cpp
int main(){

    float x;
    mc::principal objprincipal(x);
    std::cout << "\n Insira a frêquencia desejada: ";
    std::cin >> x;

    return 0;
}
```

Lembrando que neste caso o arquivo que você está criando está **no mesmo** diretório da biblioteca.

<!--
Lembrando que **todos** os dados devem ser inseridos como _str_. Assim como o parametro `"None"` **deve** ser mantido como segundo argumento, caso seja alterado, a lib irá trabalhar em modo de teste, gerando dados e salvando os mesmos.

Pode ser atribuido como valor imaginário tanto _i_ como _j_. E no caso dos gráficos animados, é necessário inserir _Hz_ após o valor, como no exemplo.
-->

* Quando for compilar o seu programa e for utilizar a biblioteca, digite o comando:

```bash

$ g++ -o <seu_programa> <seu_programa.cpp> -I./include -L./lib -lgraph -Wl,-rpath=./lib

```

Lembre de trocar o <seu_programa> pelo nome que você irá dar ao programa que deseja, e troque <seu_programa.cpp> pelo nome do arquivo principal do seu programa.

<div align="center">

|Exemplos de comandos que podem ser utilizados | Resumo da funcionalidade|
|---|---|
| `mc::principal objprincipal(hz)` | Recebe apenas valores do tipo `float`, pois interpreta diversos dados de entrada para poder aprezentar a frequência desejada. |

</div>

## Agradecimentos

 Assim como no [README.md](https://github.com/MauricioPaivadaSilva/MCEpy) quero agradecer a minha pedagoga e orientadora do PIBIC, Ma. Flávia Manuella de Almeida Ksiaszczyk, por proporcionar a oportunidade de gerar tal trabalho. Agradeço também ao meu professor de física Prof. Dr. Rudinei Celso de Souza Jantsch que nos auxiliou com interpretações físicas dos fenômenos elétricos de forma mais aprofundada. E por fim agradeço também ao Prof. Me. Cláudio Kleina, que me auxiliou com problemas ligados a programação do OA.
