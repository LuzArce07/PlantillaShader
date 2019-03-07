// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>

#include "Shader.h"
#include "Vertice.h"

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

using namespace std;

Shader *shader;
GLuint posicionID;
GLuint colorID;

//para dibujar un nueva figura, necesito estos 3 elementos:

//TRIANGULO
vector<Vertice> triangulo;
GLuint vertexArrayTrianguloID;
GLuint bufferTrianguloID;

//CUADRADO
vector<Vertice> cuadrado;
GLuint vertexArrayCuadradoID;
GLuint bufferCuadradoID;

//TRIANGULO DE LADO
vector<Vertice> trianguloLado;
GLuint vertexArrayTrianguloLadoID;
GLuint bufferTrianguloLadoID;

void inicializarCuadrado() {
	Vertice v1 = {
		vec3(-0.8,0.8,0.0), //posicion
		vec4(0.4,0.7,0.1,1.0) //color
	};
	
	Vertice v2 = {
		vec3(-0.4,0.8,0.0),
		vec4(0.4,0.7,0.1,1.0) //color
	};

	Vertice v3 = {
		vec3(-0.4,0.5,0.0),
		vec4(0.4,0.7,0.1,1.0) //color
	};

	Vertice v4 = {
		vec3(-0.8,0.5,0.0),
		vec4(0.4,0.7,0.1,1.0) //color
	};

	//estos se mandan llamar 1 por 1
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);

}


void inicializarTriangulo() {

	Vertice v1 = { //Esto es para inicializar 1 vertice
		vec3(0.0f,0.3f,0.0f),
		vec4(1.0f,0.8f,0.0f,1.0f)
	};

	Vertice v2 = {
		vec3(-0.1f,-0.45f,0.0f),
		vec4(1.0f,0.8f,0.0f,1.0f)
	};

	Vertice v3 = {
		vec3(0.3f,-0.3f,0.0f),
		vec4(1.0f,0.8f,0.0f,1.0f)
	};

	triangulo.push_back(v1);
	triangulo.push_back(v2);
	triangulo.push_back(v3);

}


void inicializarTrianguloLado() {

	Vertice v1 = { //Esto es para inicializar 1 vertice
		vec3(0.0f,0.3f,0.0f),
		vec4(1.0f,0.5f,0.0f,1.0f)
	};

	Vertice v2 = {
		vec3(-0.3f,-0.3f,0.0f),
		vec4(1.0f,0.5f,0.0f,1.0f)
	};

	Vertice v3 = {
		vec3(-0.1f,-0.45f,0.0f),
		vec4(1.0f,0.5f,0.0f,1.0f)
	};

	trianguloLado.push_back(v1);
	trianguloLado.push_back(v2);
	trianguloLado.push_back(v3);

}

void dibujar() {
	
	//Elegir el shader
	shader->enlazar();


	/*TRIANGULO*/
	//Elegir un vertice array
	glBindVertexArray(vertexArrayTrianguloID);
	//Dibujar 
	glDrawArrays(GL_TRIANGLES, 0, triangulo.size());


	/*TRIANGULO LADO*/
	//Elegir un vertice array
	glBindVertexArray(vertexArrayTrianguloLadoID);
	//Dibujar 
	glDrawArrays(GL_TRIANGLES, 0, trianguloLado.size());


	/*CUADRADO*/
	//Elegir un vertice array
	glBindVertexArray(vertexArrayCuadradoID);
	//Dibujar 
	glDrawArrays(GL_QUADS, 0, cuadrado.size());




	//Soltar el vertex array 
	glBindVertexArray(0);
	//Soltar el shader
	shader->desenlazar();

}

void actualizar() {

}

int main()
{

	//Declaramos apuntador de ventana
	GLFWwindow *window;

	//Si no se pudo iniciar glfw
	//terminamos ejecución
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	//Si se pudo iniciar GLFW
	//Entonces inicializamos la ventana
	window = glfwCreateWindow(1024,768,"Ventana",NULL,NULL);

	//Si no podemos iniciar la ventana 
	//Entonces terminamos ejecución
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//Establecemos el contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido el contexto, activamos funciones modernas
	//Esto solo va a funcionar si ya establecido el contexto
	glewExperimental = true;
	GLenum errorGlew = glewInit();

	if (errorGlew != GLEW_OK) {

		cout << glewGetErrorString(errorGlew);

	}

	//Variable para la version de OPENGL
	const GLubyte *versionGL = glGetString(GL_VERSION);
	//Imprimir la variable
	cout << "Versión OPENGL: " << versionGL; //Salida de C++


	/*--------------------------------------------------------------------------------------------------*/

	//AQUI INICIALIZAMOS LOS METODOS 
	inicializarTriangulo();
	inicializarTrianguloLado();
	inicializarCuadrado();



	const char *rutaVertex = "VertexShader.shader";
	const char *rutaFragment = "FragmentShader.shader";

	shader = new Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos 
	posicionID = glGetAttribLocation(shader->getID(),"posicion");
	colorID = glGetAttribLocation(shader->getID(), "color");

	//Desenlazar el shader
	shader->desenlazar();

	
	
	/*VERTEX ARRAY Y BUFFER PARA EL TRIANGULO*/

	//Crear un vertex array
	glGenVertexArrays(1, &vertexArrayTrianguloID);
	glBindVertexArray(vertexArrayTrianguloID);

	//Crear un vertex buffer
	glGenBuffers(1, &bufferTrianguloID);
	glBindBuffer(GL_ARRAY_BUFFER,bufferTrianguloID);

	//Llenar el buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * triangulo.size(), triangulo.data(), GL_STATIC_DRAW);

	/*PARA TRIANGULO*/
	//Habilitar atributos de shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	//Especificar a OpenGL como se va a comunicar
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));




	/*VERTEX ARRAY Y BUFFER PARA EL TRIANGULO LADO*/

	//Crear un vertex array
	glGenVertexArrays(1, &vertexArrayTrianguloLadoID);
	glBindVertexArray(vertexArrayTrianguloLadoID);

	//Crear un vertex buffer
	glGenBuffers(1, &bufferTrianguloLadoID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferTrianguloLadoID);

	//Llenar el buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * trianguloLado.size(), trianguloLado.data(), GL_STATIC_DRAW);

	/*PARA TRIANGULO*/
	//Habilitar atributos de shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	//Especificar a OpenGL como se va a comunicar
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));




	/*VERTEX ARRAY Y BUFFER PARA EL CUADRADO*/

	//Crear un vertex array
	glGenVertexArrays(1, &vertexArrayCuadradoID);
	glBindVertexArray(vertexArrayCuadradoID);

	//Crear un vertex buffer
	glGenBuffers(1, &bufferCuadradoID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferCuadradoID);

	//Llenar el buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * cuadrado.size(), cuadrado.data(), GL_STATIC_DRAW);

	/*PARA CUADRADO*/
	//Habilitar atributos de shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	//Especificar a OpenGL como se va a comunicar
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));





	//Soltar vertex array y buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	
	/*----------------------------------------------------------------------------------------------------*/


	//Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Establece region de dibujo
		glViewport(0, 0, 1024, 768);

		//Establece el color de borrado
		glClearColor(0.2, 0.2, 1, 1);
		
		//Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();
		actualizar();

		//Cambiar los buffers
		glfwSwapBuffers(window);

		//Reconocer si hay entradas
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;

}

