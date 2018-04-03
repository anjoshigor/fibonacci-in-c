# Primeiro Trabalho Prático de Laboratório de Programação


## Especificacao

O trabalho deve ser realizado individualmente ou em grupos de dois alunos. A resolução do trabalho tem que ser enviada até ao final do dia 8 de Abril ao respectivo professor da turma (Mário Florido : amf@dcc.fc.up.pt ou João Silva: joaoms@joaoms.com) com o subject: Laboratório de programação- Trabalho 1

É obrigatória a apresentação dos trabalhos na respectiva aula da semana de 9 a 13 de Abril.

Enunciado:

1.  Implemente uma função recursiva para calcular o enésimo número de fibonacci.

2. Optimize a função anterior usando um array de resultados parciais tais que a[i] contém o número de fibonacci de ordem i (programação dinâmica). Teste as duas versões e verifique que a segunda calcula valores para inteiros maiores do que a primeira.

3.  (parte mais valorizada do trabalho) Implemente um módulo de aritmética para big-numbers e utilize-o para implementar uma terceira versão da sucessão de fibonacci. Teste esta ultima versão e verifique que calcula valores maiores do que as duas anteriores.

### Ex:

Um big-number é representado por uma lista dos seus dígitos. O objectivo deste módulo da alínea 3) é representar estruturas para big-numbers (usando listas) e respectivos construtores e funções de acesso e implementar as funções básicas de aritmética para big-numbers (soma, diferença, multiplicação e divisão). Para facilitar estas operações, assuma que os dígitos estão na lista por ordem inversa. Exemplo:

123 + 49 = 172 é representado por:

[3, 2, 1] + [9, 4]  = [2, 7, 1]

Na implementação deve usar os princípios de programação estruturada e por módulos dados nas aulas.

## Implementação

O projeto divide-se em 3 módulos, que são os seguintes:

| Fibonacci   | Big Integer | List   |
| ----------- |-------------| -------|
| fibo.h      | bigInt.h    | list.h |
| fibo.c      | bigInt.c    | list.c |

O módulo de **Fibonacci** implemente os **3** pontos especficados no trabalho, utilizando funções 
padronizadas que recebem um inteiro e retornam o resultado do cálculo de Fibonacci em formato de string:

```C
char *recursiveFibo(int n);

char *dpFibo(int n);

char *bigFibo(int n);
```

Sendo a última (`char *bigFibo(int n);`) implementada utilizando a noção de Big Integers e Lists dos demais módulos. Ao utilizar a representação de inteiros como listas e o cálcula da soma personalizada, é possível realizar cálculos de enésimos termos maiores que as versões recursivas e de programação dinâmica.

As estruturas de **Lista** e **Big Integer** foram implementadas como mostradas a seguir:

`bigInt.h`
```C
typedef struct bigInt
{
    list digits;
} * bigInt;
```

`list.h`
```C
typedef struct intlist
{
    int value;
    struct intlist *rest;
} * list;
```

## Utilização

Para utilizar a implementação acima, basta importar o módulo `fibo.h` e utilizar as funções disponíveis, mas ainda há uma forma interativa de utilizar o projeto através da linha de comando. Basta executar os seguintes comandos na pasta raiz do projeto.

`make build`: este comando irá compilar o projeto

`make run`: este comando irá rodar o projeto e será possível interagir da seguinte forma

```sh
----------------------------------------
-----------TRABALHO PRATICO 1-----------
----------------------------------------


-----------------MENU:------------------
| Escolha a opcao desejada:            |
| [1] Fibonacci recursivo              |
| [2] Fibonacci c/ Dynamic Programming |
| [3] Fibonacci c/ Big Integers        |
----------------------------------------
Sua escolha: 3

Voce quer calcular Fibonacci de que numero?
Sua escolha: 121

Calculando o Fibonacci de 121 usando [3] Fibonacci c/ Big Integers...

----------------------------------------
| RESULTADO: 8670007398507948658051921 
----------------------------------------
```

Uma vez que já tenha utilizado o programa, é de boa prática utilizar o comando a seguir:

`make clean`: este comando remove o executável da pasta e para criá-lo novamente basta usar o `make build`

Ainda, é possível utilizar o `make all` que realiza os 3 passos acima de uma só vez.

```
Desenvolvido por
Higor Araújo dos Anjos
up201711183@fc.up.pt
```

