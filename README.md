# Trabalho-1
Repositório contendo as especificações do Trabalho 1 da disciplina de LP1

# Documento de Especificação

Leia o documento de especificação contido em [Especificação do Trabalho 1](https://docs.google.com/document/d/1nwQxiP9YQzU3O-H4YQMqWRtylqO1AOke8y1rQF7cPEc/edit?usp=sharing). Preencha o autor.md com as informações relativas ao grupo/autor.

## Usando cmake
Neste trabalhho, os exemplos serão de implementação do terminal, todos os testes estão na pasta `data`.

A compilação e execução do trabalho pode ser feita usando cmake, para executa-lo faremos:

```
cd trabalho-1-raixasantos (ou o nome da pasta em que o projeto se encontra)
mkdir build
cd build
cmake ..
cmake --build .
```
A compilação gera um executável com o nome keno dentro da pasta build, __no windows__ esse executável fica na pasta Debug. Logo após a compilação, para executar o programa gerado use os comandos:

No linux:
```
./keno
```
No windows:
```
.\Debug\keno.exe
```
Para executar com o arquivo de aposta ou os arquivos de teste é necéssario adicionar o local do arquivo após o comando, exemplo com o bet1:
No linux:
```
./keno ../data/bet_1.dat
```
No windows:
```
.\Debug\keno.exe ..\data\bet_1.dat
```