# PA1 - Computación Gráfica

Proyecto académico desarrollado en **C++ con OpenGL y FreeGLUT** para el curso de Computación Gráfica.

## Descripción

El proyecto representa una **escena 2D interactiva** compuesta por:

- Cielo
- Césped
- Carretera
- Edificio principal
- Árboles
- Sol
- Automóvil

Los elementos fueron construidos mediante primitivas geométricas de OpenGL, utilizando rectángulos, triángulos, polígonos y círculos aproximados.

## Tecnologías utilizadas

- C++
- OpenGL
- FreeGLUT
- CMake
- CLion
- MinGW
- Git y GitHub

## Transformaciones implementadas

La escena utiliza las principales transformaciones geométricas vistas en el curso:

- **Traslación**
- **Rotación**
- **Escala**

Se emplean funciones como:

```cpp
glTranslatef(...)
glRotatef(...)
glScalef(...)
```

También se utilizan:

```cpp
glPushMatrix()
glPopMatrix()
```

para aislar las transformaciones de cada objeto.

## Visualización

La escena utiliza una proyección ortogonal configurada mediante:

```cpp
glOrtho(-10.0, 10.0, -7.5, 7.5, -1.0, 1.0);
```

Esto permite trabajar con un sistema de coordenadas 2D definido y mantener las proporciones de los objetos.

## Controles

### Automóvil

| Tecla | Acción |
|---|---|
| A | Mover a la izquierda |
| D | Mover a la derecha |
| Q | Rotar en un sentido |
| E | Rotar en el sentido contrario |
| + | Aumentar escala |
| - | Reducir escala |

### Árbol izquierdo

| Tecla | Acción |
|---|---|
| R / T | Rotar |
| Z / X | Aumentar o reducir escala |

### Edificio

| Tecla | Acción |
|---|---|
| C / V | Aumentar o reducir escala |

### Sol

| Tecla | Acción |
|---|---|
| I | Mover hacia arriba |
| K | Mover hacia abajo |
| J | Mover hacia la izquierda |
| L | Mover hacia la derecha |

### Controles generales

| Tecla | Acción |
|---|---|
| 0 | Reiniciar transformaciones |
| ESC | Cerrar el programa |

## Estructura del proyecto

```text
PA1_Computacion_Grafica/
│
├── CMakeLists.txt
├── main.cpp
├── .gitignore
└── README.md
```

## Cómo ejecutar el proyecto

### 1. Clonar el repositorio

```bash
git clone URL_DEL_REPOSITORIO
```

Luego ingresar a la carpeta:

```bash
cd PA1-Computacion-Grafica
```

### 2. Abrir en CLion

Abrir la carpeta clonada desde CLion.

El proyecto utiliza **CMake** y descarga/configura **FreeGLUT** automáticamente mediante `FetchContent`.

La primera configuración puede tardar algunos minutos.

### 3. Compilar y ejecutar

En CLion:

1. Esperar a que CMake termine de configurar el proyecto.
2. Seleccionar el ejecutable `PA1_Computacion_Grafica`.
3. Presionar **Run**.

Si todo está correctamente configurado, se abrirá una ventana con la escena 2D interactiva.

## Trabajo con Git

Antes de comenzar a trabajar:

```bash
git pull
```

Después de realizar cambios:

```bash
git add .
git commit -m "Descripcion del cambio"
git push
```

## Objetivo académico

El proyecto busca evidenciar la aplicación práctica de:

- Sistemas de coordenadas
- Primitivas geométricas
- Transformaciones geométricas
- Composición de transformaciones
- Proyección ortogonal
- Organización del código mediante funciones
- Interacción por teclado
- Uso de Git/GitHub para control de versiones

## Integrantes

- Integrante 1: Meza Pastrana, Diego Armando
- Integrante 2: Castillo Espinoza, Welking Ronaldo
## Curso

**Computación Gráfica**

## Producto Académico

**PA1 - Construcción de una escena gráfica 2D con OpenGL**
