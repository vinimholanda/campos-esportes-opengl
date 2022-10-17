# Campos de esportes em OpenGL

Campos de futebol, vôlei e tênis feitos usando a bliblioteca open gl para a disciplina de Computação Gráfica da UFAL.

## Como rodar

Para exibir cada um dos campos na tela é necessário ter a biblioteca OpenGL e o compilador g++ instalados no seu computador. A seguir é necessário abrir um terminal e dentro da pasta baixada do github, executar cada um dos comandos abaixo:

g++ futebol.cpp -o futebol -lGL -lGLU -lglut

g++ variacoes/volei.cpp -o variacoes/volei -lGL -lGLU -lglut    

g++ variacoes/tenis.cpp -o variacoes/tenis -lGL -lGLU -lglut

Assim, os programas foram compilados. Feito isso, agora é possivel executar cada um dos campos individualmente em uma janela, usando os comandos a seguir no terminal:

./futebol

./variacoes/volei

./variacoes/tenis

**(!) Importante:** Se você estiver usando o windows, é necessário trocar o **#include <GL/glut.h>**, para **##include <gl/glut.h>**, na primeira linha de cada um dos arquivos. O include muda em cada sistema operacional.

## Funcionalidades

Ao rodar cada campo, um menu com os comandos será exibido na tela, mostrando as interações em cada um. Em todos eles é possível mover a bola com as setinhas, marcar um gol, mudar entre câmeras predefinidas ou move-las livremente, reiniciar o placar e ocultar o menu com essas instruções.
