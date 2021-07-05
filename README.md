# Keno

Keno é um jogo de apostas muito popular parecido com loteria ou bingo. Os jogadores apostam escolhendo entre 1 e 20 números únicos no intervalo entre 1 e 80, inclusive. Quando os jogadores escolhem seus números, o jogo gera vinte números aleatórios entre 1 e 80. Baseado na quantidade de números que o jogador acertou, e no valor que ele apostou, ele recebe um valor de volta.
Para tanto, nessa versão 
  

# Como compilar?

## Usando CMake...

Neste trabalho, os exemplos serão de implementação do terminal, todos os testes estão na pasta `data`.

  

A compilação e execução do trabalho será feita usando CMake, para executá-lo faremos:

  

```

cd trabalho-1-raixasantos (ou o nome da pasta em que o projeto se encontra)

mkdir build && cd build

cmake ..

cmake --build .

```

  

# Como executar o projeto?

A compilação gera um executável com o nome keno dentro da pasta build, __no windows__ esse executável fica na pasta Debug. Logo após a compilação, para executar o programa gerado use os comandos:

  

No linux:

```

./keno

```

No windows:

```

.\Debug\keno.exe

```

  

## Como executar o conjunto dos testes planejados?

Para executar com o arquivo de aposta ou os arquivos de teste é necessário adicionar o local do arquivo após o comando, exemplo com o bet1.dat:

  

No linux:

```

./keno ../data/bet_1.dat

```

No windows:

```

.\Debug\keno.exe ..\data\bet_1.dat

```

  

# Limitações ou funcionalidades não implementadas no programa.
Não conseguimos identificar limitações ou funcionalidades não implementadas no programa.