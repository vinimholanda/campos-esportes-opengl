# Campos de esportes em OpenGL

Campos de futebol, vôlei e tênis feitos usando a bliblioteca OpenGL para a disciplina de Computação Gráfica da UFAL.

## Como compilar e executar

Para exibir cada um dos campos na tela é necessário ter a biblioteca OpenGL e o compilador g++ instalados no seu computador. A seguir é necessário abrir um terminal e dentro da pasta baixada do github, executar cada um dos comandos abaixo:

**g++ futebol.cpp -o futebol -lGL -lGLU -lglut**

**g++ variacoes/volei.cpp -o variacoes/volei -lGL -lGLU -lglut**    

**g++ variacoes/tenis.cpp -o variacoes/tenis -lGL -lGLU -lglut**

Assim, os programas foram compilados. Feito isso, agora é possivel executar cada um dos campos individualmente em uma janela, usando os comandos a seguir no terminal:

**./futebol**

**./variacoes/volei**

**./variacoes/tenis**

**(!) Importante:** Se você estiver usando o windows, é necessário trocar o **#include <GL/glut.h>**, para **##include <gl/glut.h>**, na primeira linha de cada um dos arquivos. O include muda em cada sistema operacional.

## Funcionalidades

Ao executar cada campo, um menu com os comandos será exibido na tela, mostrando as interações em cada um. Em todos eles é possível mover a bola com as teclas **WASD**, marcar um gol (se a bola realmente entrar na barra), mudar entre câmeras predefinidas com o **1** e **2** do teclado, ou move-las livremente com as setinhas, reiniciar o placar com **C** e ocultar o menu com essas instruções com a tecla **H**.

## Screenshots

Algumas screenshots de como deve aparecer na sua tela:

![futebol](https://user-images.githubusercontent.com/73549297/196065671-0c446264-d19d-4d31-9d61-fceb29957d85.png)
![tenis](https://user-images.githubusercontent.com/73549297/196065923-200438e2-9051-4873-9fc1-976b2741fb38.png)
![volei](https://user-images.githubusercontent.com/73549297/196065924-b2121667-7178-469b-904d-8e9b736944e5.png)
