#include <GL/glut.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cstdio>

// Valores iniciais (Esfera, look at, menu, avisos)
float xe = 0.0, ye = 0.38, ze = 2.0;
int n1 = 0, n2 = 0;

int xla = 1, yla = 4, zla = 8, 
    xxla = 0, yyla = 0, zzla = 0, 
    xxxla = 0, yyyla = 1, zzzla = 0;

bool ocultar_menu = false;

int x_placar = -3;
int y_placar = 3;

float y_aviso1 = -3.0;
float y_aviso2 = -4.0;
float y_aviso3 = -5.0;
float y_aviso4 = -6.0;
float y_aviso5 = -7.0;

// Campo
float vertex[8][3] = 
{
    {-3.0, 0.0, 2.2},      //vertice A 
    {-3.0, 0.2, 2.2},      //vertice B
    {3.0, 0.2, 2.2},       //vertice C
    {3.0, 0.0, 2.2},       //vertice D
    {-3.0, 0.0, -2.2},     //vertice E 
    {-3.0, 0.2, -2.2},     //vertice F 
    {3.0, 0.2, -2.2},      //vertice G
    {3.0, 0.0, -2.2},      //vertice H
};

GLfloat color[8][3] = 
{
    {0.0, 0.7, 0.7},       //vertice A
    {0.0, 0.7, 0.7},       //vertice B 
    {0.0, 0.7, 0.7},       //vertice C
    {0.0, 0.7, 0.7},       //vertice D
    {0.0, 0.7, 0.7},       //vertice E
    {0.0, 0.7, 0.7},       //vertice F
    {0.0, 0.7, 0.7},       //vertice G
    {0.0, 0.7, 0.7},       //vertice H
};

float vertex_subcampo[8][3] = 
{
    {-2.3, 0.22, 1.6},      //vertice A 
    {-2.3, 0.22, 1.6},      //vertice B
    {2.3, 0.22, 1.6},       //vertice C
    {2.3, 0.22, 1.6},       //vertice D
    {-2.3, 0.22, -1.6},     //vertice E 
    {-2.3, 0.22, -1.6},     //vertice F 
    {2.3, 0.22, -1.6},      //vertice G
    {2.3, 0.22, -1.6},      //vertice H
};

GLfloat color_subcampo[8][3] = 
{
    {1.0, 0.6, 0.1},       //vertice A
    {1.0, 0.6, 0.1},       //vertice B 
    {1.0, 0.6, 0.1},       //vertice C
    {1.0, 0.6, 0.1},       //vertice D
    {1.0, 0.6, 0.1},       //vertice E
    {1.0, 0.6, 0.1},       //vertice F
    {1.0, 0.6, 0.1},       //vertice G
    {1.0, 0.6, 0.1},       //vertice H
};

// Rede
float vertex_rede[8][3] = 
{
    {-0.05, 0.5, 1.6},        //vertice A 
    {-0.05, 1.0, 1.6},        //vertice B 
    {0.05, 1.0, 1.6},         //vertice C
    {0.05, 0.5, 1.6},         //vertice D
    {-0.05, 0.5, -1.6},       //vertice E 
    {-0.05, 1.0, -1.6},       //vertice F 
    {0.05, 1.0, -1.6},        //vertice G
    {0.05, 0.5, -1.6},        //vertice H
};

GLfloat color_rede[8][3] = 
{
    {0.8, 0.8, 0.8},           //vertice A
    {0.8, 0.8, 0.8},           //vertice B 
    {0.8, 0.8, 0.8},           //vertice C
    {0.8, 0.8, 0.8},           //vertice D
    {0.6, 0.6, 0.6},           //vertice E
    {0.6, 0.6, 0.6},           //vertice F
    {0.6, 0.6, 0.6},           //vertice G
    {0.6, 0.6, 0.6},           //vertice H
};

// Suporte
float vertex_suporte_esquerdo[8][3] = 
{
    {-0.1, 0.2, 1.7},        //vertice A 
    {-0.1, 1.1, 1.7},        //vertice B 
    {0.1, 1.1, 1.7},         //vertice C
    {0.1, 0.2, 1.7},         //vertice D
    {-0.1, 0.2, 1.6},        //vertice E 
    {-0.1, 1.1, 1.6},        //vertice F 
    {0.1, 1.1, 1.6},         //vertice G
    {0.1, 0.2, 1.6},         //vertice H
};

GLfloat color_suporte_esquerdo[8][3] = 
{
    {1, 1, 1},           //vertice A
    {1, 1, 1},           //vertice B 
    {1, 1, 1},           //vertice C
    {1, 1, 1},           //vertice D
    {1, 1, 1},           //vertice E
    {1, 1, 1},           //vertice F
    {1, 1, 1},           //vertice G
    {1, 1, 1},           //vertice H
};

float vertex_suporte_direito[8][3] = 
{
    {-0.1, 0.2, -1.7},        //vertice A 
    {-0.1, 1.1, -1.7},        //vertice B 
    {0.1, 1.1, -1.7},        //vertice C
    {0.1, 0.2, -1.7},        //vertice D
    {-0.1, 0.2, -1.6},       //vertice E 
    {-0.1, 1.1, -1.6},       //vertice F 
    {0.1, 1.1, -1.6},       //vertice G
    {0.1, 0.2, -1.6},       //vertice H
};

GLfloat color_suporte_direito[8][3] = 
{
    {1, 1, 1},           //vertice A
    {1, 1, 1},           //vertice B 
    {1, 1, 1},           //vertice C
    {1, 1, 1},           //vertice D
    {1, 1, 1},           //vertice E
    {1, 1, 1},           //vertice F
    {1, 1, 1},           //vertice G
    {1, 1, 1},           //vertice H
};

void quad(int a,int b,int c,int d)
{
    glBegin(GL_QUADS);
        glColor3fv(color[a]);
        glVertex3fv(vertex[a]);

        glColor3fv(color[b]);
        glVertex3fv(vertex[b]);

        glColor3fv(color[c]);
        glVertex3fv(vertex[c]);

        glColor3fv(color[d]);
        glVertex3fv(vertex[d]);
    glEnd();
}

void sub_campo(int a,int b,int c,int d)
{
    glBegin(GL_QUADS);
        glColor3fv(color_subcampo[a]);
        glVertex3fv(vertex_subcampo[a]);

        glColor3fv(color_subcampo[b]);
        glVertex3fv(vertex_subcampo[b]);

        glColor3fv(color_subcampo[c]);
        glVertex3fv(vertex_subcampo[c]);

        glColor3fv(color_subcampo[d]);
        glVertex3fv(vertex_subcampo[d]);
    glEnd();
}

void rede(int a,int b,int c,int d)
{
    glBegin(GL_QUADS);
        glColor3fv(color_rede[a]);
        glVertex3fv(vertex_rede[a]);

        glColor3fv(color_rede[b]);
        glVertex3fv(vertex_rede[b]);

        glColor3fv(color_rede[c]);
        glVertex3fv(vertex_rede[c]);

        glColor3fv(color_rede[d]);
        glVertex3fv(vertex_rede[d]);
    glEnd();
}

void suporte_esquerdo(int a,int b,int c,int d)
{
    glBegin(GL_QUADS);
        glColor3fv(color_suporte_esquerdo[a]);
        glVertex3fv(vertex_suporte_esquerdo[a]);

        glColor3fv(color_suporte_esquerdo[b]);
        glVertex3fv(vertex_suporte_esquerdo[b]);

        glColor3fv(color_suporte_esquerdo[c]);
        glVertex3fv(vertex_suporte_esquerdo[c]);

        glColor3fv(color_suporte_esquerdo[d]);
        glVertex3fv(vertex_suporte_esquerdo[d]);
    glEnd();
}

void suporte_direito(int a,int b,int c,int d)
{
    glBegin(GL_QUADS);
        glColor3fv(color_suporte_direito[a]);
        glVertex3fv(vertex_suporte_direito[a]);

        glColor3fv(color_suporte_direito[b]);
        glVertex3fv(vertex_suporte_direito[b]);

        glColor3fv(color_suporte_direito[c]);
        glVertex3fv(vertex_suporte_direito[c]);

        glColor3fv(color_suporte_direito[d]);
        glVertex3fv(vertex_suporte_direito[d]);
    glEnd();
}

void campo()
{
    quad(0,3,2,1);
    quad(2,3,7,6);
    quad(0,4,7,3);
    quad(1,2,6,5);
    quad(4,5,6,7);
    quad(0,1,5,4);
}

void sub_campo()
{
    sub_campo(0,3,2,1);
    sub_campo(2,3,7,6);
    sub_campo(0,4,7,3);
    sub_campo(1,2,6,5);
    sub_campo(4,5,6,7);
    sub_campo(0,1,5,4);
}

void rede()
{
    rede(0,3,2,1);
    rede(2,3,7,6);
    rede(0,4,7,3);
    rede(1,2,6,5);
    rede(4,5,6,7);
    rede(0,1,5,4);
}

void suporte_esquerdo()
{
    suporte_esquerdo(0,3,2,1);
    suporte_esquerdo(2,3,7,6);
    suporte_esquerdo(0,4,7,3);
    suporte_esquerdo(1,2,6,5);
    suporte_esquerdo(4,5,6,7);
    suporte_esquerdo(0,1,5,4);
}

void suporte_direito()
{
    suporte_direito(0,3,2,1);
    suporte_direito(2,3,7,6);
    suporte_direito(0,4,7,3);
    suporte_direito(1,2,6,5);
    suporte_direito(4,5,6,7);
    suporte_direito(0,1,5,4);
}

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

double rotacionar_y = 0; 
double rotacionar_x = 0;
void teclado( int key, int x, int y ) 
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

void escrever_texto(const char *string, float x, float y) 
{
    
    int j = strlen( string );

    glColor3f(1.0,1.0,1.0);
    glRasterPos2f(x, y);

    for( int i = 0; i < j; i++ ) {
    glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, string[i] );
    }
}

void desenha()
{
    glClearColor( 0, 0.1, 0.1, 1 );
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    int w = glutGet( GLUT_WINDOW_WIDTH );
    int h = glutGet( GLUT_WINDOW_HEIGHT );
    gluPerspective( 60, w / h, 0.1, 100 );

    glMatrixMode( GL_MODELVIEW );

    glLoadIdentity();

    gluLookAt
        ( 
        xla, yla, zla, 
        xxla, yyla, zzla,
        xxxla, yyyla, zzzla
        );
    
    // Textos indicativos
    char placar[17];
    sprintf(placar, "Placar: %d x %d", n1, n2);
    escrever_texto(placar, x_placar, y_placar);

    // Menu
    if (ocultar_menu == false){
        char aviso1[50] = "[A], [D] - Mover a bola";
        escrever_texto(aviso1, -3, y_aviso1);
        char aviso2[40] = "[C] - Reiniciar o contador";
        escrever_texto(aviso2, -3, y_aviso2);
        char aviso3[35] = "[H] - Ocultar/Exibir menu";
        escrever_texto(aviso3, -3, y_aviso3);
        char aviso4[50] = "[1], [2] - Alternar entre cameras predefinidas";
        escrever_texto(aviso4, -3, y_aviso4);
        char aviso5[40] = "Setinhas movem a camera livremente";
        escrever_texto(aviso5, -3, y_aviso5);
    }

    glRotatef( rotacionar_x, 1.0, 0.0, 0.0 );
    glRotatef( rotacionar_y, 0.0, 1.0, 0.0 );
    
    campo();
    sub_campo();
    rede();
    suporte_esquerdo();
    suporte_direito();


    //Linhas horizontais

    bresenham(2.3, 0.23, -2.3, 0.23, -1.6);
    bresenham(2.3, 0.23, -2.3, 0.23, 1.6);

    //Linhas verticais

    glRotatef( 90.0, 0.0, 1.0, 0.0);

    bresenham(1.62, 0.23, -1.62, 0.23, -2.3);
    bresenham(1.62, 0.23, -1.62, 0.23, 2.3);

    bresenham(1.62, 0.23, -1.62, 0.23, -0.8);
    bresenham(1.62, 0.23, -1.62, 0.23, 0.8);

    bresenham(1.62, 0.23, -1.62, 0.23, 0.0);

    //pontilhado
    bresenham(1.7, 0.23, 1.8, 0.23, -0.8);
    bresenham(1.9, 0.23, 2.0, 0.23, -0.8);

    bresenham(1.7, 0.23, 1.8, 0.23, 0.8);
    bresenham(1.9, 0.23, 2.0, 0.23, 0.8);

    bresenham(-1.7, 0.23, -1.8, 0.23, -0.8);
    bresenham(-1.9, 0.23, -2.0, 0.23, -0.8);

    bresenham(-1.7, 0.23, -1.8, 0.23, 0.8);
    bresenham(-1.9, 0.23, -2.0, 0.23, 0.8);

    //glLoadIdentity();

    if (ze >= 3.0 && xe == 0){
        xe = 0.0;
        ye = 0.38;
        ze = -2.0;
        n1 = n1 + 1;
    }else if (ze >= 3.0){
        xe = 0.0;
        ye = 0.38;
        ze = -2.0;
    }else if (ze <= -3.0 && xe == 0){
        xe = 0.0;
        ye = 0.38;
        ze = 2.0;
        n2 = n2 + 1;
    }else if (ze <= -3.0){
        xe = 0.0;
        ye = 0.38;
        ze = 2.0;
    }else if (xe >= 1.5 || xe <= -1.5){
        xe = 0.0;
        ye = 0.38;
        ze = 2.0;
    }
    glutPostRedisplay(); //atualizar placar
    
    glTranslatef(xe, ye, ze);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.13, 10, 10);

    glutSwapBuffers();
}

void comandar(unsigned char key, int x, int y)
{
    if (key == 'a'){
        //xe = xe - 1.0;
        if(ze == 1.0){
           ze = ze - 1.0;
           ye = ye + 1.0; 
        }else if(ze == 0.0){
           ze = ze - 1.0;
           ye = ye - 1.0;
        }else{
           ze = ze - 1.0;
        }
    }
    else if (key == 'd'){
        //xe = xe + 1.0;
        if(ze == 1.0){
           ze = ze + 1.0;
        }else if(ze == 0.0){
           ze = ze + 1.0;
           ye = ye - 1.0;
        }else if(ze == -1.0){
           ze = ze + 1.0;
           ye = ye + 1.0; 
        }else{
           ze = ze + 1.0;
        }

    }else if (key == 'h'){
        if(ocultar_menu == false){
           ocultar_menu = true; 
        }else if(ocultar_menu == true){
            ocultar_menu = false;
        }
    }else if (key == '1'){
        rotacionar_x = 0, rotacionar_y = 0;

        y_aviso1 = -3;
        y_aviso2 = -4;
        y_aviso3 = -5;
        y_aviso4 = -6;
        y_aviso5 = -7;

        xla = 1, yla = 4, zla = 8, 
        xxla = 0, yyla = 0, zzla = 0, 
        xxxla = 0, yyyla = 1, zzzla = 0;
    }else if (key == '2'){
        rotacionar_x = 0, rotacionar_y = 0;

        y_aviso1 = -1;
        y_aviso2 = -1.6;
        y_aviso3 = -2.2;
        y_aviso4 = -2.8;
        y_aviso5 = -3.4;


        xla = 0, yla = 0, zla = 8, 
        xxla = 0, yyla = 0, zzla = 0, 
        xxxla = 0, yyyla = 1, zzzla = 0;
    }else if (key == 'c'){
        n1 = 0;
        n2 = 0;
    }
    glutPostRedisplay();
}

int main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE );
    glutInitWindowSize( 640, 480 );
    glutCreateWindow( "Volei" );
    glutDisplayFunc( desenha );
    glutSpecialFunc( teclado );
    glutKeyboardFunc(comandar);
    glEnable( GL_DEPTH_TEST );
    glutMainLoop();
    return 0;
}
