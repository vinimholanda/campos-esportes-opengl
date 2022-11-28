#include <GL/glut.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cstdio>
#include "stb_image.h"
#include <iostream>
#include <string>

using namespace std;

// Valores iniciais
// RGB
float red = 0;
float green = 0;
float blue = 0;

// Esfera
float xe = 0.0, ye = 0.38, ze = 0.0;
int n1 = 0, n2 = 0;

// Look at
int xla = 1, yla = 4, zla = 8,
    xxla = 0, yyla = 0, zzla = 0,
    xxxla = 0, yyyla = 1, zzzla = 0;

// Menu
bool ocultar_menu = false;

int x_placar = -3;
int y_placar = 3;

float y_horario = 3.0;
float y_luz_status = 2.5;

float y_aviso1 = -3.0;
float y_aviso2 = -4.0;
float y_aviso3 = -5.0;
float y_aviso4 = -6.0;
float y_aviso5 = -7.0;
float y_aviso6 = -8.0;

// Horario e iluminação
int luz = 0;
int timee = 0;

//texturas
GLuint texturas[6];

// Vértices e cores dos sóidos
// Campo
float vertex_campo[8][3] =
    {
        {-3.0, 0.0, 2.0},  // vertice A
        {-3.0, 0.2, 2.0},  // vertice B
        {3.0, 0.2, 2.0},   // vertice C
        {3.0, 0.0, 2.0},   // vertice D
        {-3.0, 0.0, -2.0}, // vertice E
        {-3.0, 0.2, -2.0}, // vertice F
        {3.0, 0.2, -2.0},  // vertice G
        {3.0, 0.0, -2.0},  // vertice H
};

GLfloat color_campo[8][3] =
    {
        {0.5, 0.35, 0.05}, // vertice A
        {0.0, 0.5, 0.0},   // vertice B
        {0.0, 0.5, 0.0},   // vertice C
        {0.5, 0.35, 0.05}, // vertice D
        {0.5, 0.35, 0.05}, // vertice E
        {0.0, 0.5, 0.0},   // vertice F
        {0.0, 0.5, 0.0},   // vertice G
        {0.5, 0.35, 0.05}, // vertice H
};

// Traves
float vertex_trave_esquerda[8][3] = 
{
    {-2.9, 0.2, 0.4},        //vertice A 
    {-2.9, 0.5, 0.4},        //vertice B 
    {-2.6, 0.7, 0.4},        //vertice C
    {-2.6, 0.2, 0.4},        //vertice D
    {-2.9, 0.2, -0.4},       //vertice E 
    {-2.9, 0.5, -0.4},       //vertice F 
    {-2.6, 0.7, -0.4},       //vertice G
    {-2.6, 0.2, -0.4},       //vertice H
};

float vertex_trave_direita[8][3] = 
{
    {2.9, 0.2, 0.4},        //vertice A 
    {2.9, 0.5, 0.4},        //vertice B 
    {2.6, 0.7, 0.4},        //vertice C
    {2.6, 0.2, 0.4},        //vertice D
    {2.9, 0.2, -0.4},       //vertice E 
    {2.9, 0.5, -0.4},       //vertice F 
    {2.6, 0.7, -0.4},       //vertice G
    {2.6, 0.2, -0.4},       //vertice H
};

GLfloat color_trave[8][3] = 
{
    {1, 1, 1},              //vertice A
    {1, 1, 1},              //vertice B 
    {1, 1, 1},              //vertice C
    {1, 1, 1},              //vertice D
    {1, 1, 1},              //vertice E
    {1, 1, 1},              //vertice F
    {1, 1, 1},              //vertice G
    {1, 1, 1},              //vertice H
};

float vertex_arquibancada_centro_baixo[8][3] = 
{
    {-2.2, 0.0, -2.2},      //vertice A 
    {-2.2, 0.5, -2.2},      //vertice B
    {2.2, 0.5, -2.2},       //vertice C
    {2.2, 0.0, -2.2},       //vertice D
    {-2.2, 0.0, -3.2},     //vertice E 
    {-2.2, 0.5, -3.2},     //vertice F 
    {2.2, 0.5, -3.2},      //vertice G
    {2.2, 0.0, -3.2},      //vertice H
};

float vertex_arquibancada_centro_meio[8][3] = 
{
    {-2.2, 0.5, -2.4},      //vertice A 
    {-2.2, 0.8, -2.4},      //vertice B
    {2.2, 0.8, -2.4},       //vertice C
    {2.2, 0.5, -2.4},       //vertice D
    {-2.2, 0.5, -3.2},     //vertice E 
    {-2.2, 0.8, -3.2},     //vertice F 
    {2.2, 0.8, -3.2},      //vertice G
    {2.2, 0.5, -3.2},      //vertice H
};

float vertex_arquibancada_centro_cima[8][3] = 
{
    {-2.2, 0.8, -2.6},      //vertice A 
    {-2.2, 1.1, -2.6},      //vertice B
    {2.2, 1.1, -2.6},       //vertice C
    {2.2, 0.8, -2.6},       //vertice D
    {-2.2, 0.8, -3.2},     //vertice E 
    {-2.2, 1.1, -3.2},     //vertice F 
    {2.2, 1.1, -3.2},      //vertice G
    {2.2, 0.8, -3.2},      //vertice H
};

float vertex_arquibancada_esquerda_baixo[8][3] = 
{
    {-4.2, 0.0, 1.3},      //vertice A 
    {-4.2, 0.5, 1.3},      //vertice B
    {-3.2, 0.5, 1.3},       //vertice C
    {-3.2, 0.0, 1.3},       //vertice D
    {-4.2, 0.0, -1.3},     //vertice E 
    {-4.2, 0.5, -1.3},     //vertice F 
    {-3.2, 0.5, -1.3},      //vertice G
    {-3.2, 0.0, -1.3},      //vertice H
};

float vertex_arquibancada_esquerda_meio[8][3] = 
{
    {-4.2, 0.5, 1.3},      //vertice A 
    {-4.2, 0.8, 1.3},      //vertice B
    {-3.4, 0.8, 1.3},       //vertice C
    {-3.4, 0.5, 1.3},       //vertice D
    {-4.2, 0.5, -1.3},     //vertice E 
    {-4.2, 0.8, -1.3},     //vertice F 
    {-3.4, 0.8, -1.3},      //vertice G
    {-3.4, 0.5, -1.3},      //vertice H
};

float vertex_arquibancada_esquerda_cima[8][3] = 
{
    {-4.2, 0.8, 1.3},      //vertice A 
    {-4.2, 1.2, 1.3},      //vertice B
    {-3.6, 1.2, 1.3},       //vertice C
    {-3.6, 0.8, 1.3},       //vertice D
    {-4.2, 0.8, -1.3},     //vertice E 
    {-4.2, 1.2, -1.3},     //vertice F 
    {-3.6, 1.2, -1.3},      //vertice G
    {-3.6, 0.8, -1.3},      //vertice H
};

float vertex_arquibancada_direita_baixo[8][3] = 
{
    {4.2, 0.0, 1.3},      //vertice A 
    {4.2, 0.5, 1.3},      //vertice B
    {3.2, 0.5, 1.3},       //vertice C
    {3.2, 0.0, 1.3},       //vertice D
    {4.2, 0.0, -1.3},     //vertice E 
    {4.2, 0.5, -1.3},     //vertice F 
    {3.2, 0.5, -1.3},      //vertice G
    {3.2, 0.0, -1.3},      //vertice H
};

float vertex_arquibancada_direita_meio[8][3] = 
{
    {4.2, 0.5, 1.3},      //vertice A 
    {4.2, 0.8, 1.3},      //vertice B
    {3.4, 0.8, 1.3},       //vertice C
    {3.4, 0.5, 1.3},       //vertice D
    {4.2, 0.5, -1.3},     //vertice E 
    {4.2, 0.8, -1.3},     //vertice F 
    {3.4, 0.8, -1.3},      //vertice G
    {3.4, 0.5, -1.3},      //vertice H
};

float vertex_arquibancada_direita_cima[8][3] = 
{
    {4.2, 0.8, 1.3},      //vertice A 
    {4.2, 1.2, 1.3},      //vertice B
    {3.6, 1.2, 1.3},       //vertice C
    {3.6, 0.8, 1.3},       //vertice D
    {4.2, 0.8, -1.3},     //vertice E 
    {4.2, 1.2, -1.3},     //vertice F 
    {3.6, 1.2, -1.3},      //vertice G
    {3.6, 0.8, -1.3},      //vertice H
};

GLfloat color_arquibancada[8][3] = 
{
    {1, 1, 1},              //vertice A
    {1, 1, 1},              //vertice B 
    {1, 1, 1},              //vertice C
    {1, 1, 1},              //vertice D
    {1, 1, 1},              //vertice E
    {1, 1, 1},              //vertice F
    {1, 1, 1},              //vertice G
    {1, 1, 1},              //vertice H
};

// Monta sólidos com as coordenadas para a textura
void quad(GLuint nome,int a, int b, int c, int d)
{
    glBindTexture(GL_TEXTURE_2D, nome);

    glBegin(GL_QUADS);
    glColor3fv(color_campo[a]);
    glVertex3fv(vertex_campo[a]);
    glTexCoord2f(0.0, 0.0);

    glColor3fv(color_campo[b]);
    glVertex3fv(vertex_campo[b]);
    glTexCoord2f(0.0, 1.0);

    glColor3fv(color_campo[c]);
    glVertex3fv(vertex_campo[c]);
    glTexCoord2f(1.0, 1.0);

    glColor3fv(color_campo[d]);
    glVertex3fv(vertex_campo[d]);
    glTexCoord2f(1.0, 0.0);
    glEnd();
}

void traves(int a,int b,int c,int d)
{
    glBegin(GL_QUADS);
        glColor3fv(color_trave[a]);
        glVertex3fv(vertex_trave_esquerda[a]);

        glColor3fv(color_trave[b]);
        glVertex3fv(vertex_trave_esquerda[b]);

        glColor3fv(color_trave[c]);
        glVertex3fv(vertex_trave_esquerda[c]);

        glColor3fv(color_trave[d]);
        glVertex3fv(vertex_trave_esquerda[d]);

    glEnd();
    
    glBegin(GL_QUADS);
        glColor3fv(color_trave[a]);
        glVertex3fv(vertex_trave_direita[a]);

        glColor3fv(color_trave[b]);
        glVertex3fv(vertex_trave_direita[b]);

        glColor3fv(color_trave[c]);
        glVertex3fv(vertex_trave_direita[c]);

        glColor3fv(color_trave[d]);
        glVertex3fv(vertex_trave_direita[d]);
    glEnd();
}

void arquibancada_centro(GLuint nome,int a,int b,int c,int d)
{
    glBindTexture(GL_TEXTURE_2D, nome);
    
    glBegin(GL_QUADS);
        glColor3fv(color_arquibancada[a]);
        glVertex3fv(vertex_arquibancada_centro_baixo[a]);
        glTexCoord2f(0.0, 0.0);


        glColor3fv(color_arquibancada[b]);
        glVertex3fv(vertex_arquibancada_centro_baixo[b]);
        glTexCoord2f(0.0, 1.0);

        glColor3fv(color_arquibancada[c]);
        glVertex3fv(vertex_arquibancada_centro_baixo[c]);
        glTexCoord2f(1.0, 1.0);

        glColor3fv(color_arquibancada[d]);
        glVertex3fv(vertex_arquibancada_centro_baixo[d]);
        glTexCoord2f(1.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3fv(color_arquibancada[a]);
        glVertex3fv(vertex_arquibancada_centro_meio[a]);
        glTexCoord2f(0.0, 0.0);

        glColor3fv(color_arquibancada[b]);
        glVertex3fv(vertex_arquibancada_centro_meio[b]);
        glTexCoord2f(0.0, 1.0);

        glColor3fv(color_arquibancada[c]);
        glVertex3fv(vertex_arquibancada_centro_meio[c]);
        glTexCoord2f(1.0, 1.0);

        glColor3fv(color_arquibancada[d]);
        glVertex3fv(vertex_arquibancada_centro_meio[d]);
        glTexCoord2f(1.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3fv(color_arquibancada[a]);
        glVertex3fv(vertex_arquibancada_centro_cima[a]);
        glTexCoord2f(0.0, 0.0);

        glColor3fv(color_arquibancada[b]);
        glVertex3fv(vertex_arquibancada_centro_cima[b]);
        glTexCoord2f(0.0, 1.0);

        glColor3fv(color_arquibancada[c]);
        glVertex3fv(vertex_arquibancada_centro_cima[c]);
        glTexCoord2f(1.0, 1.0);

        glColor3fv(color_arquibancada[d]);
        glVertex3fv(vertex_arquibancada_centro_cima[d]);
        glTexCoord2f(1.0, 0.0);
    glEnd();
}

void arquibancada_esquerda(GLuint nome,int a,int b,int c,int d){

    glBindTexture(GL_TEXTURE_2D, nome);

    glBegin(GL_QUADS);
        glColor3fv(color_arquibancada[a]);
        glVertex3fv(vertex_arquibancada_esquerda_baixo[a]);
        glTexCoord2f(0.0, 0.0);

        glColor3fv(color_arquibancada[b]);
        glVertex3fv(vertex_arquibancada_esquerda_baixo[b]);
        glTexCoord2f(0.0, 1.0);

        glColor3fv(color_arquibancada[c]);
        glVertex3fv(vertex_arquibancada_esquerda_baixo[c]);
        glTexCoord2f(1.0, 1.0);

        glColor3fv(color_arquibancada[d]);
        glVertex3fv(vertex_arquibancada_esquerda_baixo[d]);
        glTexCoord2f(1.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3fv(color_arquibancada[a]);
        glVertex3fv(vertex_arquibancada_esquerda_meio[a]);
        glTexCoord2f(0.0, 0.0);

        glColor3fv(color_arquibancada[b]);
        glVertex3fv(vertex_arquibancada_esquerda_meio[b]);
        glTexCoord2f(0.0, 1.0);

        glColor3fv(color_arquibancada[c]);
        glVertex3fv(vertex_arquibancada_esquerda_meio[c]);
        glTexCoord2f(1.0, 1.0);

        glColor3fv(color_arquibancada[d]);
        glVertex3fv(vertex_arquibancada_esquerda_meio[d]);
        glTexCoord2f(1.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3fv(color_arquibancada[a]);
        glVertex3fv(vertex_arquibancada_esquerda_cima[a]);
        glTexCoord2f(0.0, 0.0);

        glColor3fv(color_arquibancada[b]);
        glVertex3fv(vertex_arquibancada_esquerda_cima[b]);
        glTexCoord2f(0.0, 1.0);

        glColor3fv(color_arquibancada[c]);
        glVertex3fv(vertex_arquibancada_esquerda_cima[c]);
        glTexCoord2f(1.0, 1.0);

        glColor3fv(color_arquibancada[d]);
        glVertex3fv(vertex_arquibancada_esquerda_cima[d]);
        glTexCoord2f(1.0, 0.0);
    glEnd();
}

void arquibancada_direita(GLuint nome,int a,int b,int c,int d)
{
    glBindTexture(GL_TEXTURE_2D, nome);

    glBegin(GL_QUADS);
        glColor3fv(color_arquibancada[a]);
        glVertex3fv(vertex_arquibancada_direita_baixo[a]);
        glTexCoord2f(0.0, 0.0);

        glColor3fv(color_arquibancada[b]);
        glVertex3fv(vertex_arquibancada_direita_baixo[b]);
        glTexCoord2f(0.0, 1.0);

        glColor3fv(color_arquibancada[c]);
        glVertex3fv(vertex_arquibancada_direita_baixo[c]);
        glTexCoord2f(1.0, 1.0);

        glColor3fv(color_arquibancada[d]);
        glVertex3fv(vertex_arquibancada_direita_baixo[d]);
        glTexCoord2f(1.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3fv(color_arquibancada[a]);
        glVertex3fv(vertex_arquibancada_direita_meio[a]);
        glTexCoord2f(0.0, 0.0);

        glColor3fv(color_arquibancada[b]);
        glVertex3fv(vertex_arquibancada_direita_meio[b]);
        glTexCoord2f(0.0, 1.0);

        glColor3fv(color_arquibancada[c]);
        glVertex3fv(vertex_arquibancada_direita_meio[c]);
        glTexCoord2f(1.0, 1.0);

        glColor3fv(color_arquibancada[d]);
        glVertex3fv(vertex_arquibancada_direita_meio[d]);
        glTexCoord2f(1.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3fv(color_arquibancada[a]);
        glVertex3fv(vertex_arquibancada_direita_cima[a]);
        glTexCoord2f(0.0, 0.0);

        glColor3fv(color_arquibancada[b]);
        glVertex3fv(vertex_arquibancada_direita_cima[b]);
        glTexCoord2f(0.0, 1.0);

        glColor3fv(color_arquibancada[c]);
        glVertex3fv(vertex_arquibancada_direita_cima[c]);
        glTexCoord2f(1.0, 1.0);

        glColor3fv(color_arquibancada[d]);
        glVertex3fv(vertex_arquibancada_direita_cima[d]);
        glTexCoord2f(1.0, 0.0);
    glEnd();
}

void campo()
{
    glEnable(GL_TEXTURE_2D);
    quad(texturas[1],0, 3, 2, 1); //frente da posicao inicial
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    quad(texturas[1],2, 3, 7, 6); //direita
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    quad(texturas[2],0, 4, 7, 3); //baixo
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    quad(texturas[1],1, 2, 6, 5); //cima
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    quad(texturas[1],4, 5, 6, 7); // atras
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    quad(texturas[1],0, 1, 5, 4); //esquerda
    glDisable(GL_TEXTURE_2D);
}

void traves()
{
    traves(0,3,2,1);
    traves(2,3,7,6);
    traves(0,4,7,3);
    traves(1,2,6,5);
    traves(4,5,6,7);
    traves(0,1,5,4);
}

void arquibancada()
{
    //1 (CENTRO)
    glEnable(GL_TEXTURE_2D);
        if (timee >= 8 && timee <= 22){
            arquibancada_centro(texturas[0],0,3,2,1); //frente
        }else{
            arquibancada_centro(texturas[3],0,3,2,1); //frente
        }
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
        arquibancada_centro(texturas[3],2,3,7,6); //direita
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
        arquibancada_centro(texturas[3],0,4,7,3); //baixo
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
        arquibancada_centro(texturas[3],1,2,6,5); //cima
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
        arquibancada_centro(texturas[3],4,5,6,7); //atras
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
        arquibancada_centro(texturas[3],0,1,5,4); //esquerda
    glDisable(GL_TEXTURE_2D);

    //2 (ESQ)
    glEnable(GL_TEXTURE_2D);
    arquibancada_esquerda(texturas[3],0,3,2,1); //esquerda
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
        if (timee >= 8 && timee <= 22){
            arquibancada_esquerda(texturas[0],2,3,7,6); //frente
        }else{
            arquibancada_esquerda(texturas[3],2,3,7,6); //frente
        }
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    arquibancada_esquerda(texturas[3],0,4,7,3);
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    arquibancada_esquerda(texturas[3],1,2,6,5);
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    arquibancada_esquerda(texturas[3],4,5,6,7);
    glDisable(GL_TEXTURE_2D);
    
    glEnable(GL_TEXTURE_2D);
    arquibancada_esquerda(texturas[3],0,1,5,4);
    glDisable(GL_TEXTURE_2D);

    //3 (DIR)
    glEnable(GL_TEXTURE_2D);
    arquibancada_direita(texturas[3],0,3,2,1); //direita
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
        if (timee >= 8 && timee <= 22){
            arquibancada_direita(texturas[0],2,3,7,6); //frente
        }else{
            arquibancada_direita(texturas[3],2,3,7,6); //frente
        }
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    arquibancada_direita(texturas[3],0,4,7,3);
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    arquibancada_direita(texturas[3],1,2,6,5);
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    arquibancada_direita(texturas[3],4,5,6,7);
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    arquibancada_direita(texturas[3],0,1,5,4);
    glDisable(GL_TEXTURE_2D);    
} 

// Linhas do campo
void bresenham(float x1, float y1, float x2, float y2, float z)
{
    float M,p,dx,dy,x,y,t;

    if((x2-x1)==0)
       M = (y2-y1);
    else
       M = (y2-y1)/(x2-x1);

    if(fabs(M)<1)
    {
        if(x1>x2)
        {
            t = x1;
            x1 = x2;
            x2 = t;

            t = y1;
            y1 = y2;
            y2 = t;
        }

        dx = fabs(x2-x1);
        dy = fabs(y2-y1);
        p = 2*dy-dx;
        x=x1;
        y=y1;

        glBegin(GL_POINTS);
            while(x<=x2)
            {
              glVertex3f(x, y, z);
              x=x+0.01;

              if(p>=0)
              {
                 if(M<1)
                    y=y+0.01;
                else
                    y=y-0.01;
                 p = p+2*dy-2*dx;
              }
              else
              {
                  y=y;
                  p = p+2*dy;
              }
            }
        glEnd();
    }

    if(fabs(M)>=1)
    {
        if(y1>y2)
        {
            t = x1;
            x1 = x2;
            x2 = t;

            t = y1;
            y1 = y2;
            y2 = t;
        }

        dx = fabs(x2-x1);
        dy = fabs(y2-y1);
        p = 2*dx-dy;
        x=x1;
        y=y1;

        glBegin(GL_POINTS);
            while(y<=y2)
            {
              glVertex3f(x, y, z);
              y=y+1;

              if(p>=0)
              {
                 if(M>=1)
                    x=x+1;
                else
                    x=x-1;
                 p = p+2*dx-2*dy;
              }
              else
              {
                  x=x;
                  p = p+2*dx;
              }
            }
        glEnd();
    }

    glFlush();
}

// Mover camera
double rotacionar_y = 0;
double rotacionar_x = 0;
void teclado(int key, int x, int y)
{
    if (key == GLUT_KEY_RIGHT)
        rotacionar_y += 5;
    else if (key == GLUT_KEY_LEFT)
        rotacionar_y -= 5;
    else if (key == GLUT_KEY_UP)
        rotacionar_x += 5;
    else if (key == GLUT_KEY_DOWN)
        rotacionar_x -= 5;
    glutPostRedisplay();
}

// Escrever avisos
void escrever_texto(const char *string, float x, float y) 
{
    int j = strlen( string );

    glColor3f(1.0,1.0,1.0);
    glRasterPos2f(x, y);

    for( int i = 0; i < j; i++ ) {
    glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, string[i] );
    }
}

// Iluminar o campo
void ilumina()
{
    //PARTE DE LUZ
    glEnable( GL_LIGHTING );
    float globalAmb[] = {0.5f, 0.5f, 0.5f, 1.f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmb);

    //quando a luz sera desligada
    if(timee >= 8 && timee <= 17){
        glEnable(GL_LIGHT0);
        //glEnable(GL_LIGHT1);
        //glEnable(GL_LIGHT2);
        glEnable(GL_LIGHT3);
        luz = 1;
    }else if(timee >= 17 && timee <= 22){
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glEnable(GL_LIGHT2);
        glEnable(GL_LIGHT3);
        luz = 2;
    }else{
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
        glDisable(GL_LIGHT3);
        luz = 0;
    };
    glEnable( GL_COLOR_MATERIAL );

    //propriedades das luzes individuais
    float light0[4][4] = {
                {0.1f, 0.1f, 0.1f, 1.f}, //ambient
                {0.8f, 0.8f, 0.8f, 1.f}, //diffuse
                {1.f, 1.f, 1.f, 1.f}, //specular
                {100.0, 5.0, 2.0, 1.0}, //position

    };

    glLightfv(GL_LIGHT0, GL_AMBIENT, &light0[0][0]);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, &light0[1][0]);
    glLightfv(GL_LIGHT0, GL_SPECULAR, &light0[2][0]);
    glLightfv(GL_LIGHT0, GL_POSITION, &light0[3][0]);

    float light1[4][4] = {
                {0.1f, 0.1f, 0.1f, 1.f}, //ambient
                {0.8f, 0.8f, 0.8f, 1.f}, //diffuse
                {1.f, 1.f, 1.f, 1.f}, //specular
                {100.0, 5.0, -2.0, 1.0}, //position

    };

    glLightfv(GL_LIGHT1, GL_AMBIENT, &light1[0][0]);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, &light1[1][0]);
    glLightfv(GL_LIGHT1, GL_SPECULAR, &light1[2][0]);
    glLightfv(GL_LIGHT1, GL_POSITION, &light1[3][0]);

    float light2[4][4] = {
                {0.1f, 0.1f, 0.1f, 1.f}, //ambient
                {0.8f, 0.8f, 0.8f, 1.f}, //diffuse
                {1.f, 1.f, 1.f, 1.f}, //specular
                {-100.0, 5.0, 2.0, 1.0}, //position

    };

    glLightfv(GL_LIGHT2, GL_AMBIENT, &light2[0][0]);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, &light2[1][0]);
    glLightfv(GL_LIGHT2, GL_SPECULAR, &light2[2][0]);
    glLightfv(GL_LIGHT2, GL_POSITION, &light2[3][0]);

    float light3[4][4] = {
                {0.1f, 0.1f, 0.1f, 1.f}, //ambient
                {0.8f, 0.8f, 0.8f, 1.f}, //diffuse
                {1.f, 1.f, 1.f, 1.f}, //specular
                {-100.0, 5.0, -2.0, 1.0}, //position

    };

    glLightfv(GL_LIGHT3, GL_AMBIENT, &light3[0][0]);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, &light3[1][0]);
    glLightfv(GL_LIGHT3, GL_SPECULAR, &light3[2][0]);
    glLightfv(GL_LIGHT3, GL_POSITION, &light3[3][0]);
}

// Faz o carregamento da textura
void texturiza(string filePath, GLuint tex_id)
{
    unsigned char* imgData;
    int largura, altura, canais;
    stbi_set_flip_vertically_on_load(true);
    imgData = stbi_load(filePath.c_str(), &largura, &altura, &canais, 4);

    glBindTexture(GL_TEXTURE_2D, tex_id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, largura, altura, 0, GL_RGBA, GL_UNSIGNED_BYTE, imgData);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    stbi_image_free(imgData);
}

void desenha()
{
    glClearColor(red, green, blue, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    gluPerspective(60, w / h, 0.1, 100); //ver
    glMatrixMode(GL_MODELVIEW);

    ilumina();

    glLoadIdentity();

    gluLookAt(
        xla, yla, zla,
        xxla, yyla, zzla,
        xxxla, yyyla, zzzla);

    // Textos indicativos
    char placar[17];
    sprintf(placar, "Placar: %d x %d", n1, n2);
    escrever_texto(placar, x_placar, y_placar);

    char horario[40];
    sprintf(horario, "Horario: %d:00", timee);
    escrever_texto(horario, 1.0, y_horario);

    char luz_status[40];
    if (luz == 0){
        sprintf(luz_status, "Luz: Apagada");
        escrever_texto(luz_status, 1.0, y_luz_status);
    }else{
        if (luz == 1){
            sprintf(luz_status, "Luz: Fraca");
            escrever_texto(luz_status, 1.0, y_luz_status);
        }else if (luz == 2){
            sprintf(luz_status, "Luz: Forte");
            escrever_texto(luz_status, 1.0, y_luz_status);
        }
    }
    
    // Menu
    if (ocultar_menu == false){
        char aviso1[50] = "[W], [A], [S], [D] - Mover a bola";
        escrever_texto(aviso1, -3, y_aviso1);
        char aviso2[40] = "[C] - Reiniciar o contador";
        escrever_texto(aviso2, -3, y_aviso2);
        char aviso3[35] = "[H] - Ocultar/Exibir menu";
        escrever_texto(aviso3, -3, y_aviso3);
        char aviso4[40] = "[T] - Avanca o horario";
        escrever_texto(aviso4, -3, y_aviso4);
        char aviso5[50] = "[1], [2] - Alternar entre cameras predefinidas";
        escrever_texto(aviso5, -3, y_aviso5);
        char aviso6[40] = "Setinhas movem a camera livremente";
        escrever_texto(aviso6, -3, y_aviso6);
    }

    glRotatef(rotacionar_x, 1.0, 0.0, 0.0);
    glRotatef(rotacionar_y, 0.0, 1.0, 0.0);

    //chamamento das funções individuai
    campo();
    traves();
    arquibancada();

    //Linhas horizontais

    //formato do campo
    bresenham(2.6, 0.22, -2.6, 0.22, -1.7);
    bresenham(2.6, 0.22, -2.6, 0.22, 1.7);

    //grande area
    bresenham(2.6, 0.22, 1.8, 0.22, -1.0); //grande area direita cima
    bresenham(2.6, 0.22, 1.8, 0.22, 1.0); //grande area direita baixo
    bresenham(-2.6, 0.22, -1.8, 0.22, -1.0); //grande area esquerda cima
    bresenham(-2.6, 0.22, -1.8, 0.22, 1.0); //grande area esquerda baixo

    //pequena area
    bresenham(2.6, 0.22, 2.3, 0.22, -0.5); //area pequena direita cima
    bresenham(2.6, 0.22, 2.3, 0.22, 0.5); //area pequena direita baixo
    bresenham(-2.6, 0.22, -2.3, 0.22, -0.5); //area pequena esquerda cima
    bresenham(-2.6, 0.22, -2.3, 0.22, 0.5); //area pequena esquerda baixo

    //meio
    bresenham(0.3, 0.22, -0.3, 0.22, -0.5);
    bresenham(0.3, 0.22, -0.3, 0.22, 0.5);

    //escanteio
    bresenham(2.52, 0.22, 2.6, 0.22, 1.58);
    bresenham(2.52, 0.22, 2.6, 0.22, -1.58);
    bresenham(-2.52, 0.22, -2.6, 0.22, 1.58);
    bresenham(-2.52, 0.22, -2.6, 0.22, -1.58);

    //Linhas verticais

    //formato do campo
    glRotatef( 90.0, 0.0, 1.0, 0.0);
    bresenham(1.7, 0.22, -1.7, 0.22, 2.6); //linha direita
    bresenham(1.7, 0.22, -1.7, 0.22, -2.6);//linha esqeurda
    bresenham(1.7, 0.22, -1.7, 0.22, 0); //linha meio

    //grande area
    bresenham(1.0, 0.22, -1.0, 0.22, -1.8); //grande área esquerda
    bresenham(1.0, 0.22, -1.0, 0.22, 1.8); //grande área esquerda

    //pequena area
    bresenham(0.5, 0.22, -0.5, 0.22, 2.3); //pequena área direita
    bresenham(0.5, 0.22, -0.5, 0.22, -2.3); //pequena área esquerda

    //penalti
    bresenham(0.0, 0.22, -0.0, 0.22, 2.1); //penalti direito
    bresenham(0.0, 0.22, -0.0, 0.22, -2.1); //penalti esquerdo

    //meio-direita(1)
    bresenham(0.35, 0.22, -0.35, 0.22, 0.45); 

    //meio-esqerda(1)
    bresenham(0.35, 0.22, -0.35, 0.22, -0.45); 

    //escanteio
    bresenham(1.58, 0.22, 1.7, 0.22, 2.5);
    bresenham(1.58, 0.22, 1.7, 0.22, -2.5);
    bresenham(-1.58, 0.22, -1.7, 0.22, 2.5);
    bresenham(-1.58, 0.22, -1.7, 0.22, -2.5);

    //circulo do meio
    float z_desenha_pontos = 0.0;

    // inclinado-cima-direita
    float x_desenha_pontos = 0.5;
    z_desenha_pontos = 0.3;
    while(x_desenha_pontos >= 0.35){
        bresenham(x_desenha_pontos, 0.22, x_desenha_pontos, 0.22, z_desenha_pontos);
        z_desenha_pontos = z_desenha_pontos + 0.01;
        x_desenha_pontos = x_desenha_pontos - 0.01;
    }
    // inclinado-baixo-direita
    x_desenha_pontos = -0.5, z_desenha_pontos = 0.3;
    while(x_desenha_pontos <= -0.35){
        bresenham(x_desenha_pontos, 0.22, x_desenha_pontos, 0.22, z_desenha_pontos);
        z_desenha_pontos = z_desenha_pontos + 0.01;
        x_desenha_pontos = x_desenha_pontos + 0.01;
    }
    //inclinado baixo
    x_desenha_pontos = -0.5, z_desenha_pontos = -0.3;
    while(x_desenha_pontos <= -0.35){
        bresenham(x_desenha_pontos, 0.22, x_desenha_pontos, 0.22, z_desenha_pontos);
        z_desenha_pontos = z_desenha_pontos - 0.01;
        x_desenha_pontos = x_desenha_pontos + 0.01;
    }
    //inclinado cima
    x_desenha_pontos = 0.35, z_desenha_pontos = -0.45;
    while(x_desenha_pontos <= 0.5){
        bresenham(x_desenha_pontos, 0.22, x_desenha_pontos, 0.22, z_desenha_pontos);
        z_desenha_pontos = z_desenha_pontos + 0.01;
        x_desenha_pontos = x_desenha_pontos + 0.01;
    }

    // glLoadIdentity();

    // Atualizar o placar 
    if (ze >= 3.0 && xe == 0)
    {
        xe = 0.0;
        ye = 0.38;
        ze = 0.0;
        n1 = n1 + 1;
    }
    else if (ze >= 3.0)
    {
        xe = 0.0;
        ye = 0.38;
        ze = 0.0;
    }
    else if (ze <= -3.0 && xe == 0)
    {
        xe = 0.0;
        ye = 0.38;
        ze = 0.0;
        n2 = n2 + 1;
    }
    else if (ze <= -3.0)
    {
        xe = 0.0;
        ye = 0.38;
        ze = 0.0;
    }
    else if (xe >= 1.5 || xe <= -1.5)
    {
        xe = 0.0;
        ye = 0.38;
        ze = 0.0;
    }
    glutPostRedisplay(); // atualizar placar

    glTranslatef(xe, ye, ze);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.13, 10, 10);

    glutSwapBuffers();
}

// Teclas de funções extras
void comandar(unsigned char key, int x, int y)
{
    if (key == 'a')
    {
        // xe = xe - 1.0;
        ze = ze - 1.0;
    }
    else if (key == 'w')
    {
        // ze = ze - 1.0;
        xe = xe + 1.0;
    }
    else if (key == 's')
    {
        // ze = ze + 1.0;
        xe = xe - 1.0;
    }
    else if (key == 'd')
    {
        // xe = xe + 1.0;
        ze = ze + 1.0;
    }
    else if (key == 'h')
    {
        if (ocultar_menu == false)
        {
            ocultar_menu = true;
        }
        else if (ocultar_menu == true)
        {
            ocultar_menu = false;
        }
    }
    else if (key == '1')
    {
        rotacionar_x = 0, rotacionar_y = 0;

        y_aviso1 = -3;
        y_aviso2 = -4;
        y_aviso3 = -5;
        y_aviso4 = -6;
        y_aviso5 = -7;
        y_aviso6 = -8;

        xla = 1, yla = 4, zla = 8,
        xxla = 0, yyla = 0, zzla = 0,
        xxxla = 0, yyyla = 1, zzzla = 0;
    }
    else if (key == '2')
    {
        rotacionar_x = 0, rotacionar_y = 0;

        y_aviso1 = -1;
        y_aviso2 = -1.6;
        y_aviso3 = -2.2;
        y_aviso4 = -2.8;
        y_aviso5 = -3.4;
        y_aviso6 = -3.8;

        xla = 0, yla = 0, zla = 8,
        xxla = 0, yyla = 0, zzla = 0,
        xxxla = 0, yyyla = 1, zzzla = 0;
    }
    else if (key == 'c')
    {
        n1 = 0;
        n2 = 0;
    }else if (key == 't'){
        if (timee >= 0 && timee < 12){
            float aux;
            aux = 0.06;
            red = 0;
            green = green + aux;
            blue = blue + aux;
            timee = timee + 1;
        }else if (timee >= 12 && timee < 19){
            float aux;
            aux = 0.12;
            red = 0;
            green = green - aux;
            blue = blue - aux;
            timee = timee + 1;
        }
        else if (timee == 19){
            red = 0;
            green = 0;
            blue = 0;
            timee = timee + 1;
        }else if (timee == 23){
            timee = 0;
        }else{
            timee = timee + 1;
        }
    };
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Futebol");

    glEnable(GL_DEPTH_TEST);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glGenTextures(6, texturas);
    texturiza("./texturas/torcida_brasileira.jpeg", texturas[0]); 
    texturiza("./texturas/campo.jpg", texturas[1]); 
    texturiza("./texturas/terra.jpg", texturas[2]); 
    texturiza("./texturas/arquibancada.jpg", texturas[3]); 

    glutDisplayFunc(desenha);
    glutSpecialFunc(teclado);
    glutKeyboardFunc(comandar);

    glutMainLoop();
    return 0;
}
