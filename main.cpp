#include <GL/freeglut.h>
#include <cmath>
#include <cstdlib>
#include <iostream>

// VARIABLES DE TRANSFORMACION

float autoX = 0.0f;
float autoAngulo = 0.0f;
float autoEscala = 1.0f;

// Arbol izquierdo
float arbolAngulo = 0.0f;
float arbolEscala = 1.0f;

// Edificio
float edificioEscala = 1.0f;

// Sol
float solX = 0.0f;
float solY = 0.0f;

const float PI = 3.1415926f;


// FUNCIONES BASICAS

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
        float angulo = 2.0f * PI * static_cast<float>(i) / 100.0f;

        float x = centroX + radio * std::cos(angulo);
        float y = centroY + radio * std::sin(angulo);

        glVertex2f(x, y);
    }

    glEnd();
}


// SUPERFICIE PRINCIPAL

void dibujarPiso()
{
    dibujarRectangulo(
        -10.0f, -4.5f,
         10.0f, -2.5f,
         0.2f, 0.7f, 0.2f
    );
}


// CARRETERA


void dibujarCarretera()
{
    dibujarRectangulo(
        -10.0f, -7.5f,
         10.0f, -4.5f,
         0.25f, 0.25f, 0.25f
    );

    for (float x = -9.0f; x < 10.0f; x += 4.0f)
    {
        dibujarRectangulo(
            x, -6.1f,
            x + 2.0f, -5.9f,
            1.0f, 1.0f, 1.0f
        );
    }
}


// EDIFICIO - MODELO LOCAL

void dibujarModeloEdificio()
{
    // Cuerpo
    dibujarRectangulo(
        -2.5f, 0.0f,
         2.5f, 5.5f,
         0.75f, 0.55f, 0.35f
    );

    // Techo
    glColor3f(0.6f, 0.15f, 0.1f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-3.0f, 5.5f);
        glVertex2f( 3.0f, 5.5f);
        glVertex2f( 0.0f, 7.2f);
    glEnd();

    // Puerta
    dibujarRectangulo(
        -0.6f, 0.0f,
         0.6f, 2.3f,
         0.35f, 0.15f, 0.05f
    );

    // Ventana izquierda
    dibujarRectangulo(
        -1.9f, 2.7f,
        -0.8f, 4.0f,
         0.4f, 0.8f, 1.0f
    );

    // Ventana derecha
    dibujarRectangulo(
         0.8f, 2.7f,
         1.9f, 4.0f,
         0.4f, 0.8f, 1.0f
    );
}

void dibujarEdificio()
{
    glPushMatrix();

    // Ubicacion del edificio en el mundo
    glTranslatef(0.0f, -2.5f, 0.0f);

    // Escala aplicada desde la base del edificio
    glScalef(edificioEscala, edificioEscala, 1.0f);

    dibujarModeloEdificio();

    glPopMatrix();
}


// ARBOL - MODELO LOCAL

void dibujarModeloArbol()
{
    // Tronco
    dibujarRectangulo(
        -0.3f, 0.0f,
         0.3f, 2.5f,
         0.45f, 0.22f, 0.05f
    );

    // Copa
    dibujarCirculo(
        0.0f, 3.3f,
        1.3f,
        0.0f, 0.5f, 0.0f
    );
}

void dibujarArbolIzquierdo()
{
    glPushMatrix();

    // Posicion del arbol izquierdo
    glTranslatef(-6.0f, -2.5f, 0.0f);

    // Rotacion y escala respecto a la base del arbol
    glRotatef(arbolAngulo, 0.0f, 0.0f, 1.0f);
    glScalef(arbolEscala, arbolEscala, 1.0f);

    dibujarModeloArbol();

    glPopMatrix();
}

void dibujarArbolDerecho()
{
    glPushMatrix();

    glTranslatef(6.0f, -2.5f, 0.0f);
    dibujarModeloArbol();

    glPopMatrix();
}

// SOL

void dibujarSol()
{
    glPushMatrix();

    // Traslacion interactiva del sol
    glTranslatef(-7.5f + solX, 5.5f + solY, 0.0f);

    dibujarCirculo(
        0.0f, 0.0f,
        0.9f,
        1.0f, 0.85f, 0.0f
    );

    glPopMatrix();
}


// AUTOMOVIL - MODELO LOCAL


void dibujarModeloAuto()
{
    // Carroceria
    dibujarRectangulo(
        -1.7f, -0.7f,
         1.7f,  0.3f,
         0.9f, 0.1f, 0.1f
    );

    // Parte superior
    glColor3f(0.8f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
        glVertex2f(-1.0f, 0.3f);
        glVertex2f(-0.5f, 0.9f);
        glVertex2f( 0.8f, 0.9f);
        glVertex2f( 1.3f, 0.3f);
    glEnd();

    // Rueda izquierda
    dibujarCirculo(
        -1.0f, -0.8f,
        0.4f,
        0.05f, 0.05f, 0.05f
    );

    // Rueda derecha
    dibujarCirculo(
         1.0f, -0.8f,
         0.4f,
         0.05f, 0.05f, 0.05f
    );
}

void dibujarAuto()
{
    glPushMatrix();

    // T: ubicar/mover el auto en el mundo
    glTranslatef(autoX, -5.6f, 0.0f);

    // R: rotacion sobre su centro local
    glRotatef(autoAngulo, 0.0f, 0.0f, 1.0f);

    // S: escala uniforme sobre su centro local
    glScalef(autoEscala, autoEscala, 1.0f);

    dibujarModeloAuto();

    glPopMatrix();
}


// TECLADO

void reiniciarTransformaciones()
{
    autoX = 0.0f;
    autoAngulo = 0.0f;
    autoEscala = 1.0f;

    arbolAngulo = 0.0f;
    arbolEscala = 1.0f;

    edificioEscala = 1.0f;

    solX = 0.0f;
    solY = 0.0f;
}

void teclado(unsigned char tecla, int, int)
{
    switch (tecla)
    {
        // AUTOMOVIL
        case 'd':
        case 'D':
            autoX += 0.3f;
            break;

        case 'a':
        case 'A':
            autoX -= 0.3f;
            break;

        case 'q':
        case 'Q':
            autoAngulo += 5.0f;
            break;

        case 'e':
        case 'E':
            autoAngulo -= 5.0f;
            break;

        case '+':
            autoEscala += 0.1f;
            break;

        case '-':
            autoEscala -= 0.1f;
            if (autoEscala < 0.2f)
                autoEscala = 0.2f;
            break;

        // ARBOL IZQUIERDO
        case 'r':
        case 'R':
            arbolAngulo += 5.0f;
            break;

        case 't':
        case 'T':
            arbolAngulo -= 5.0f;
            break;

        case 'z':
        case 'Z':
            arbolEscala += 0.1f;
            break;

        case 'x':
        case 'X':
            arbolEscala -= 0.1f;
            if (arbolEscala < 0.2f)
                arbolEscala = 0.2f;
            break;

        // EDIFICIO
        case 'c':
        case 'C':
            edificioEscala += 0.05f;
            break;

        case 'v':
        case 'V':
            edificioEscala -= 0.05f;
            if (edificioEscala < 0.5f)
                edificioEscala = 0.5f;
            break;

        // SOL
        case 'j':
        case 'J':
            solX -= 0.2f;
            break;

        case 'l':
        case 'L':
            solX += 0.2f;
            break;

        case 'i':
        case 'I':
            solY += 0.2f;
            break;

        case 'k':
        case 'K':
            solY -= 0.2f;
            break;

        // REINICIAR
        case '0':
            reiniciarTransformaciones();
            break;

        // ESC
        case 27:
            std::exit(0);
    }

    glutPostRedisplay();
}


// ESCENA COMPLETA


void dibujarEscena()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Reiniciar MODELVIEW en cada frame
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    dibujarPiso();
    dibujarCarretera();
    dibujarEdificio();
    dibujarArbolIzquierdo();
    dibujarArbolDerecho();
    dibujarSol();
    dibujarAuto();

    glutSwapBuffers();
}


// CONFIGURACION OPENGL


void inicializar()
{
    // Color del cielo
    glClearColor(
        0.45f,
        0.75f,
        1.0f,
        1.0f
    );

    // Proyeccion ortogonal 2D
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(
        -10.0, 10.0,
        -7.5, 7.5,
        -1.0, 1.0
    );

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mostrarControles()
{
    std::cout << "========================================\n";
    std::cout << " PA1 - COMPUTACION GRAFICA / CONTROLES\n";
    std::cout << "========================================\n";
    std::cout << "AUTO:\n";
    std::cout << "  A / D   -> Trasladar izquierda/derecha\n";
    std::cout << "  Q / E   -> Rotar\n";
    std::cout << "  + / -   -> Escalar\n\n";

    std::cout << "ARBOL IZQUIERDO:\n";
    std::cout << "  R / T   -> Rotar\n";
    std::cout << "  Z / X   -> Escalar\n\n";

    std::cout << "EDIFICIO:\n";
    std::cout << "  C / V   -> Aumentar / reducir escala\n\n";

    std::cout << "SOL:\n";
    std::cout << "  I / J / K / L -> Trasladar\n\n";

    std::cout << "OTROS:\n";
    std::cout << "  0       -> Reiniciar transformaciones\n";
    std::cout << "  ESC     -> Salir\n";
    std::cout << "========================================\n";
}


// MAIN

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(
        GLUT_DOUBLE |
        GLUT_RGB
    );

    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);

    glutCreateWindow(
        "PA1 - Computacion Grafica"
    );

    inicializar();
    mostrarControles();

    glutDisplayFunc(dibujarEscena);
    glutKeyboardFunc(teclado);

    glutMainLoop();

    return 0;
}
