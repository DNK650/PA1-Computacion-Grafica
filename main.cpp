#include <GL/freeglut.h>
#include <cmath>

void dibujarRectangulo(
        float x1, float y1,
        float x2, float y2,
        float r, float g, float b)
{
    glColor3f(r, g, b);

    glBegin(GL_QUADS);

    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);

    glEnd();
}


void dibujarCirculo(
        float centroX,
        float centroY,
        float radio,
        float r, float g, float b)
{
    glColor3f(r, g, b);

    glBegin(GL_POLYGON);

    for (int i = 0; i < 100; i++)
    {
        float angulo = 2.0f * 3.1415926f * i / 100;

        float x = centroX + radio * cos(angulo);
        float y = centroY + radio * sin(angulo);

        glVertex2f(x, y);
    }

    glEnd();
}



// SUPERFICIE PRINCIPAL


void dibujarPiso()
{
    // Césped
    dibujarRectangulo(
        -10.0f, -4.5f,
         10.0f, -2.5f,
         0.2f, 0.7f, 0.2f
    );
}

// CARRETERA

void dibujarCarretera()
{
    // Asfalto
    dibujarRectangulo(
        -10.0f, -7.5f,
         10.0f, -4.5f,
         0.25f, 0.25f, 0.25f
    );

    // Líneas centrales de la carretera
    for (float x = -9.0f; x < 10.0f; x += 4.0f)
    {
        dibujarRectangulo(
            x, -6.1f,
            x + 2.0f, -5.9f,
            1.0f, 1.0f, 1.0f
        );
    }
}


// EDIFICIO PRINCIPAL


void dibujarEdificio()
{
    // Cuerpo
    dibujarRectangulo(
        -2.5f, -2.5f,
         2.5f,  3.0f,
         0.75f, 0.55f, 0.35f
    );

    // Techo
    glColor3f(0.6f, 0.15f, 0.1f);

    glBegin(GL_TRIANGLES);

    glVertex2f(-3.0f, 3.0f);
    glVertex2f( 3.0f, 3.0f);
    glVertex2f( 0.0f, 4.7f);

    glEnd();


    // Puerta
    dibujarRectangulo(
        -0.6f, -2.5f,
         0.6f, -0.2f,
         0.35f, 0.15f, 0.05f
    );


    // Ventana izquierda
    dibujarRectangulo(
        -1.9f, 0.2f,
        -0.8f, 1.5f,
         0.4f, 0.8f, 1.0f
    );


    // Ventana derecha
    dibujarRectangulo(
         0.8f, 0.2f,
         1.9f, 1.5f,
         0.4f, 0.8f, 1.0f
    );
}


// ÁRBOL

void dibujarArbol(float x)
{
    // Tronco
    dibujarRectangulo(
        x - 0.3f, -2.5f,
        x + 0.3f,  0.0f,
        0.45f, 0.22f, 0.05f
    );

    // Copa
    dibujarCirculo(
        x, 0.8f,
        1.3f,
        0.0f, 0.5f, 0.0f
    );
}

// SOL
void dibujarSol()
{
    dibujarCirculo(
        -7.5f, 5.5f,
        0.9f,
        1.0f, 0.85f, 0.0f
    );
}

// AUTOMÓVIL
void dibujarAuto()
{
    // Carrocería
    dibujarRectangulo(
        -1.7f, -6.3f,
         1.7f, -5.3f,
         0.9f, 0.1f, 0.1f
    );

    // Parte superior
    glColor3f(0.8f, 0.1f, 0.1f);

    glBegin(GL_POLYGON);

    glVertex2f(-1.0f, -5.3f);
    glVertex2f(-0.5f, -4.7f);
    glVertex2f( 0.8f, -4.7f);
    glVertex2f( 1.3f, -5.3f);

    glEnd();


    // Rueda izquierda
    dibujarCirculo(
        -1.0f, -6.4f,
        0.4f,
        0.05f, 0.05f, 0.05f
    );


    // Rueda derecha
    dibujarCirculo(
         1.0f, -6.4f,
         0.4f,
         0.05f, 0.05f, 0.05f
    );
}

// ESCENA COMPLETA

void dibujarEscena()
{
    glClear(GL_COLOR_BUFFER_BIT);

    dibujarPiso();

    dibujarCarretera();

    dibujarEdificio();

    dibujarArbol(-6.0f);
    dibujarArbol(6.0f);

    dibujarSol();

    dibujarAuto();

    glutSwapBuffers();
}


// CONFIGURACIÓN

void inicializar()
{
    // Color del cielo
    glClearColor(
        0.45f,
        0.75f,
        1.0f,
        1.0f
    );

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glOrtho(
        -10.0, 10.0,
        -7.5, 7.5,
        -1.0, 1.0
    );

    glMatrixMode(GL_MODELVIEW);
}


// MAIN

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(
        GLUT_DOUBLE |
        GLUT_RGB
    );

    glutInitWindowSize(
        800,
        600
    );

    glutInitWindowPosition(
        100,
        100
    );

    glutCreateWindow(
        "PA1 - Computacion Grafica"
    );

    inicializar();

    glutDisplayFunc(
        dibujarEscena
    );

    glutMainLoop();

    return 0;
}