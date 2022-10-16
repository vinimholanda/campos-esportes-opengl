#include <GL/glut.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cstdio>

// Valores iniciais (Esfera, look at, menu, avisos)
float xe = 0.0, ye = 0.38, ze = 0.0;
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
    {-3.0, 0.0, 2.0},      //vertice A 
    {-3.0, 0.2, 2.0},      //vertice B
    {3.0, 0.2, 2.0},       //vertice C
    {3.0, 0.0, 2.0},       //vertice D
    {-3.0, 0.0, -2.0},     //vertice E 
    {-3.0, 0.2, -2.0},     //vertice F 
    {3.0, 0.2, -2.0},      //vertice G
    {3.0, 0.0, -2.0},      //vertice H
};

GLfloat color[8][3] = 
{
    {0.5, 0.35, 0.05},     //vertice A
    {0.0, 0.5, 0.0},       //vertice B 
    {0.0, 0.5, 0.0},       //vertice C
    {0.5, 0.35, 0.05},     //vertice D
    {0.5, 0.35, 0.05},     //vertice E
    {0.0, 0.5, 0.0},       //vertice F
    {0.0, 0.5, 0.0},       //vertice G
    {0.5, 0.35, 0.05},     //vertice H
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

GLfloat color_trave_esquerda[8][3] = 
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

GLfloat color_trave_direita[8][3] = 
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

void trave_esquerda(int a,int b,int c,int d)
{
    glBegin(GL_QUADS);
        glColor3fv(color_trave_esquerda[a]);
        glVertex3fv(vertex_trave_esquerda[a]);

        glColor3fv(color_trave_esquerda[b]);
        glVertex3fv(vertex_trave_esquerda[b]);

        glColor3fv(color_trave_esquerda[c]);
        glVertex3fv(vertex_trave_esquerda[c]);

        glColor3fv(color_trave_esquerda[d]);
        glVertex3fv(vertex_trave_esquerda[d]);
    glEnd();
}

void trave_direita(int a,int b,int c,int d)
{
    glBegin(GL_QUADS);
        glColor3fv(color_trave_direita[a]);
        glVertex3fv(vertex_trave_direita[a]);

        glColor3fv(color_trave_direita[b]);
        glVertex3fv(vertex_trave_direita[b]);

        glColor3fv(color_trave_direita[c]);
        glVertex3fv(vertex_trave_direita[c]);

        glColor3fv(color_trave_direita[d]);
        glVertex3fv(vertex_trave_direita[d]);
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

void trave_esquerda()
{
    trave_esquerda(0,3,2,1);
    trave_esquerda(2,3,7,6);
    trave_esquerda(0,4,7,3);
    trave_esquerda(1,2,6,5);
    trave_esquerda(4,5,6,7);
    trave_esquerda(0,1,5,4);
}

void trave_direita()
{
    trave_direita(0,3,2,1);
    trave_direita(2,3,7,6);
    trave_direita(0,4,7,3);
    trave_direita(1,2,6,5);
    trave_direita(4,5,6,7);
    trave_direita(0,1,5,4);
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
        char aviso1[50] = "[W], [A], [S], [D] - Mover a bola";
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
    trave_esquerda();
    trave_direita();

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

    //glLoadIdentity();

    if (ze >= 3.0 && xe == 0){
        xe = 0.0;
        ye = 0.38;
        ze = 0.0;
        n1 = n1 + 1;
    }else if (ze >= 3.0){
        xe = 0.0;
        ye = 0.38;
        ze = 0.0;
    }else if (ze <= -3.0 && xe == 0){
        xe = 0.0;
        ye = 0.38;
        ze = 0.0;
        n2 = n2 + 1;
    }else if (ze <= -3.0){
        xe = 0.0;
        ye = 0.38;
        ze = 0.0;
    }else if (xe >= 1.5 || xe <= -1.5){
        xe = 0.0;
        ye = 0.38;
        ze = 0.0;
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
        ze = ze - 1.0;
    }
    else if(key == 'w'){
        //ze = ze - 1.0;
        xe = xe + 1.0;
    }
    else if(key == 's'){
        //ze = ze + 1.0;
        xe = xe - 1.0;
    }
    else if (key == 'd'){
        //xe = xe + 1.0;
        ze = ze + 1.0;

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
    glutCreateWindow( "Futebol" );
    glutDisplayFunc( desenha );
    glutSpecialFunc( teclado );
    glutKeyboardFunc(comandar);
    glEnable( GL_DEPTH_TEST );
    glutMainLoop();
    return 0;
}
