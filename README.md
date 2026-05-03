# calculadora-C

# Processo de Desenvolvimento da Calculadora em C

## Visao Geral

Este resumo registra as principais etapas da evolucao da calculadora em C, saindo de uma funcao de soma com erros basicos ate chegar a um programa modular, com validacao de entrada e repeticao.

## Etapas Principais

### 1. Correcao da funcao `soma`

No inicio, o programa tinha erros como:

- declaracao e definicao de funcao inconsistentes
- funcao `int` sem `return`
- variavel `result` usada sem receber valor

Aprendizado:

- declaracao, definicao e chamada precisam ser coerentes
- funcoes com retorno devem realmente devolver um valor

### 2. Separacao entre calcular e imprimir

Depois da correcao inicial, a logica foi melhorada:

- a funcao matematica passou a calcular e retornar
- o `main` passou a imprimir o resultado

Aprendizado:

- calcular e exibir sao responsabilidades diferentes

### 3. Evolucao para calculadora com `switch`

O programa deixou de fazer apenas soma e passou a escolher operacoes com `switch case`.

Operacoes implementadas:

- soma
- subtracao
- multiplicacao
- divisao

Aprendizados:

- uso de `switch`
- importancia do `break`
- leitura correta de `char` com `scanf(" %c", &opcao)`

### 4. Uso de `double`

As variaveis e funcoes foram adaptadas para trabalhar com numeros reais:

- `double`
- `scanf("%lf", ...)`
- `printf("%.2lf", ...)`

Aprendizado:

- o tipo escolhido no `main` precisa bater com os tipos usados nas funcoes

### 5. Tratamento de divisao por zero

Foi adicionada validacao para impedir divisao por zero.

Aprendizado:

- alem de erros de sintaxe, programas precisam tratar regras invalidas de execucao

### 6. Criacao de `validacaoOpcao`

Foi criada uma funcao para:

- pedir a operacao
- repetir enquanto a entrada for invalida
- retornar apenas uma opcao valida

Aprendizado:

- uma funcao deve receber apenas os parametros que realmente precisa

### 7. Rename para `calculadora.c`

O arquivo deixou de se chamar `hello.c` e passou a se chamar:

- `calculadora.c`

Isso deixou o nome coerente com a finalidade do programa.

### 8. Extracao da funcao `calcular`

O `switch` saiu do `main` e foi para a funcao:

- `calcular`

Aprendizado:

- o `main` deve coordenar o fluxo
- a logica de decisao pode ficar isolada em outra funcao

### 9. Retorno de status + resultado por ponteiro

Para evitar ambiguidade entre erro e resultado valido, a funcao `calcular` passou a:

- retornar `int` como status
- escrever o resultado em `double *result`

Aprendizado:

- `return 1` pode representar sucesso
- `return 0` pode representar erro
- `*result` permite alterar a variavel original do `main`

### 10. Robustez em `calcular`

Foi adicionado:

- `default: return 0;`

Aprendizado:

- uma funcao fica mais robusta quando tem comportamento definido mesmo para entradas inesperadas

### 11. Repeticao da calculadora

O programa passou a executar varias operacoes em sequencia com `do ... while`.

Aprendizado:

- a condicao do laco deve refletir exatamente quando repetir e quando encerrar

### 12. Validacao de numeros

Foi criada a funcao:

- `validarNumero`

Responsabilidade:

- ler um numero real
- detectar entrada invalida
- repetir ate obter um `double` valido

Aprendizados:

- `scanf` pode falhar
- sem limpeza de buffer, o programa pode ficar preso na mesma entrada invalida

### 13. Generalizacao de `validarNumero`

A funcao passou a receber a mensagem do prompt por parametro:

- `const char *mensagem`

Exemplo:

- `validarNumero("Digite o primeiro numero: ");`
- `validarNumero("Digite o segundo numero: ");`

Aprendizado:

- uma funcao fica mais reutilizavel quando recebe a parte variavel por parametro

### 14. Criacao de `limparBuffer`

A limpeza da entrada foi centralizada em:

- `void limparBuffer(void);`

Aprendizado:

- trechos repetidos podem virar funcao auxiliar

### 15. Criacao de `validarNovaOperacao`

Foi criada uma funcao para validar a resposta de continuar:

- aceita apenas `S`, `s`, `N` ou `n`
- mostra erro em caso de entrada invalida

Aprendizado:

- o mesmo cuidado usado para validar numeros e operacoes pode ser aplicado a outras entradas do programa

## Estrutura Atual

O programa ficou dividido assim:

- `main`
  coordena o fluxo geral

- `validarNumero`
  le e valida numeros reais

- `validacaoOpcao`
  le e valida a operacao matematica

- `validarNovaOperacao`
  le e valida a resposta de continuar ou encerrar

- `limparBuffer`
  limpa o restante da entrada digitada

- `calcular`
  escolhe a operacao e retorna status

- `soma`, `sub`, `mult`, `divisao`
  executam os calculos

## Principais Aprendizados

- diferenca entre declaracao, definicao e chamada
- uso correto de `return`
- passagem por valor
- uso de ponteiros para retornar resultado por referencia
- validacao de `char` com `scanf(" %c", ...)`
- validacao de `double`
- limpeza de buffer com `getchar()`
- separacao de responsabilidades
- uso de funcoes auxiliares
- organizacao de codigo para evolucao futura

## Estado Atual

O arquivo principal do projeto e:

- `calculadora.c`

Hoje a calculadora possui:

- operacoes basicas
- suporte a `double`
- validacao de numeros
- validacao de operacao
- validacao da resposta de continuacao
- tratamento de divisao por zero
- repeticao de uso
- separacao de logica, entrada e validacao

O processo mostrou uma evolucao de um exercicio simples para um programa mais organizado, robusto e preparado para crescer.
