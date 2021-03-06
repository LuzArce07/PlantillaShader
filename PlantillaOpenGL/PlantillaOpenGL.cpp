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


//CUADRO PISO
vector<Vertice> cuadroPiso;
GLuint vertexArrayCuadroPisoID;
GLuint bufferCuadroPisoID;

//TRIANGULO
vector<Vertice> triangulo;
GLuint vertexArrayTrianguloID;
GLuint bufferTrianguloID;

//TRIANGULO DE LADO
vector<Vertice> trianguloLado;
GLuint vertexArrayTrianguloLadoID;
GLuint bufferTrianguloLadoID;

//CUADRADO
vector<Vertice> cuadrado;
GLuint vertexArrayCuadradoID;
GLuint bufferCuadradoID;

//CUADRADO LADO
vector<Vertice> cuadradoLado;
GLuint vertexArrayCuadradoLadoID;
GLuint bufferCuadradoLadoID;

//ESCALERAS
vector<Vertice> escaleras;
GLuint vertexArrayEscalerasID;
GLuint bufferEscalerasID;

//ESCALERAS LADO
vector<Vertice> escalerasLado;
GLuint vertexArrayEscalerasLadoID;
GLuint bufferEscalerasLadoID;




void inicializarCuadroPiso() {

	Vertice v1 = { //Esto es para inicializar 1 vertice
		vec3(-1.0f,-0.25f,0.0f),
		vec4(0.0f,0.7f,0.0f,1.0f)
	};

	Vertice v2 = {
		vec3(1.0f,-0.25f,0.0f),
		vec4(0.0f,0.7f,0.0f,1.0f)
	};

	Vertice v3 = {
		vec3(1.0f,-1.0f,0.0f),
		vec4(0.0f,0.7f,0.0f,1.0f)
	};

	Vertice v4 = {
		vec3(-1.0f,-1.0f,0.0f),
		vec4(0.0f,0.7f,0.0f,1.0f)
	};

	cuadroPiso.push_back(v1);
	cuadroPiso.push_back(v2);
	cuadroPiso.push_back(v3);
	cuadroPiso.push_back(v4);

}


void inicializarCuadrado() {
	Vertice v1 = {
		vec3(0.0,0.3,0.0), //posicion
		vec4(1.0f,0.5f,0.0f,0.0f) //color
	};
	
	Vertice v2 = {
		vec3(-0.05,0.25,0.0),
		vec4(1.0f,0.5f,0.0f,0.0f) //color
	};

	Vertice v3 = {
		vec3(-0.05,0.20,0.0),
		vec4(1.0f,0.5f,0.0f,0.0f) //color
	};

	Vertice v4 = {
		vec3(0.0,0.20,0.0),
		vec4(1.0f,0.5f,0.0f,0.0f) //color
	};

	//estos se mandan llamar 1 por 1
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);

}


void inicializarCuadradoLado() {
	Vertice v1 = {
		vec3(0.0,0.3,0.0), //posicion
		vec4(1.0f,0.8f,0.0f,1.0f) //color
	};

	Vertice v2 = {
		vec3(0.05,0.25,0.0),
		vec4(1.0f,0.8f,0.0f,1.0f) //color
	};

	Vertice v3 = {
		vec3(0.05,0.20,0.0),
		vec4(1.0f,0.8f,0.0f,1.0f) //color
	};

	Vertice v4 = {
		vec3(0.0,0.20,0.0),
		vec4(1.0f,0.8f,0.0f,1.0f) //color
	};

	//estos se mandan llamar 1 por 1
	cuadradoLado.push_back(v1);
	cuadradoLado.push_back(v2);
	cuadradoLado.push_back(v3);
	cuadradoLado.push_back(v4);

}


void inicializarEscaleras() {
	Vertice v1 = {
		vec3(0.0f,0.20f,0.0f), //posicion
		vec4(0.0f,0.0f,0.0f,1.0f) //color
	};

	Vertice v2 = {
		vec3(0.1f,-0.38f,0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f) //color
	};

	Vertice v3 = {
		vec3(0.25f,-0.32f,0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f) //color
	};

	Vertice v4 = {
		vec3(0.04f,0.20f,0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f) //color
	};

	//estos se mandan llamar 1 por 1
	escaleras.push_back(v1);
	escaleras.push_back(v2);
	escaleras.push_back(v3);
	escaleras.push_back(v4);

}


void inicializarEscalerasLado() {
	Vertice v1 = {
		vec3(-0.012f,0.27f,0.0f), //posicion
		vec4(0.5f,0.5f,0.5f,1.0f) //color
	};

	Vertice v2 = {
		vec3(-0.015f,0.27f,0.0f),
		vec4(0.5f,0.5f,0.5f,1.0f) //color
	};

	Vertice v3 = {
		vec3(-0.27f,-0.32f,0.0f),
		vec4(0.5f,0.5f,0.5f,1.0f) //color
	};

	Vertice v4 = {
		vec3(-0.15f,-0.41f,0.0f),
		vec4(0.5f,0.5f,0.5f,1.0f) //color
	};

	//estos se mandan llamar 1 por 1
	escalerasLado.push_back(v1);
	escalerasLado.push_back(v2);
	escalerasLado.push_back(v3);
	escalerasLado.push_back(v4);

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


	/*CUADRO PISO*/
	//Elegir un vertice array
	glBindVertexArray(vertexArrayCuadroPisoID);
	//Dibujar 
	glDrawArrays(GL_QUADS, 0, cuadroPiso.size());


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


	/*ESCALERAS*/
	//Elegir un vertice array
	glBindVertexArray(vertexArrayEscalerasID);
	//Dibujar 
	glDrawArrays(GL_QUADS, 0, escaleras.size());


	/*ESCALERAS LADO*/
	//Elegir un vertice array
	glBindVertexArray(vertexArrayEscalerasLadoID);
	//Dibujar 
	glDrawArrays(GL_QUADS, 0, escalerasLado.size());


	/*CUADRADO*/
	//Elegir un vertice array
	glBindVertexArray(vertexArrayCuadradoID);
	//Dibujar 
	glDrawArrays(GL_QUADS, 0, cuadrado.size());


	/*CUADRADO LADO*/
	//Elegir un vertice array
	glBindVertexArray(vertexArrayCuadradoLadoID);
	//Dibujar 
	glDrawArrays(GL_QUADS, 0, cuadradoLado.size());
	

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
	
	inicializarCuadroPiso();
	inicializarTriangulo();
	inicializarTrianguloLado();
	inicializarEscaleras();
	inicializarEscalerasLado();
	inicializarCuadrado();
	inicializarCuadradoLado();
	

	const char *rutaVertex = "VertexShader.shader";
	const char *rutaFragment = "FragmentShader.shader";

	shader = new Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos 
	posicionID = glGetAttribLocation(shader->getID(),"posicion");
	colorID = glGetAttribLocation(shader->getID(), "color");

	//Desenlazar el shader
	shader->desenlazar();

	
	/*VERTEX ARRAY Y BUFFER PARA EL CUADRO PISO*/

	//Crear un vertex array
	glGenVertexArrays(1, &vertexArrayCuadroPisoID);
	glBindVertexArray(vertexArrayCuadroPisoID);

	//Crear un vertex buffer
	glGenBuffers(1, &bufferCuadroPisoID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferCuadroPisoID);

	//Llenar el buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * cuadroPiso.size(), cuadroPiso.data(), GL_STATIC_DRAW);

	/*PARA TRIANGULO LADO (no se modifica pero se manda para cada nueva forma a dibujar)*/
	//Habilitar atributos de shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	//Especificar a OpenGL como se va a comunicar
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));




	/*VERTEX ARRAY Y BUFFER PARA EL TRIANGULO*/

	//Crear un vertex array
	glGenVertexArrays(1, &vertexArrayTrianguloID);
	glBindVertexArray(vertexArrayTrianguloID);

	//Crear un vertex buffer
	glGenBuffers(1, &bufferTrianguloID);
	glBindBuffer(GL_ARRAY_BUFFER,bufferTrianguloID);

	//Llenar el buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * triangulo.size(), triangulo.data(), GL_STATIC_DRAW);

	/*PARA TRIANGULO (no se modifica pero se manda para cada nueva forma a dibujar)*/
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

	/*PARA TRIANGULO LADO (no se modifica pero se manda para cada nueva forma a dibujar)*/
	//Habilitar atributos de shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	//Especificar a OpenGL como se va a comunicar
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));
	



	/*VERTEX ARRAY Y BUFFER PARA LAS ESCALERAS*/

	//Crear un vertex array
	glGenVertexArrays(1, &vertexArrayEscalerasID);
	glBindVertexArray(vertexArrayEscalerasID);

	//Crear un vertex buffer
	glGenBuffers(1, &bufferEscalerasID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferEscalerasID);

	//Llenar el buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * escaleras.size(), escaleras.data(), GL_STATIC_DRAW);

	/*PARA CUADRADO (no se modifica pero se manda para cada nueva forma a dibujar)*/
	//Habilitar atributos de shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	//Especificar a OpenGL como se va a comunicar
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));





	/*VERTEX ARRAY Y BUFFER PARA LAS ESCALERAS LADO*/

	//Crear un vertex array
	glGenVertexArrays(1, &vertexArrayEscalerasLadoID);
	glBindVertexArray(vertexArrayEscalerasLadoID);

	//Crear un vertex buffer
	glGenBuffers(1, &bufferEscalerasLadoID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferEscalerasLadoID);

	//Llenar el buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * escalerasLado.size(), escalerasLado.data(), GL_STATIC_DRAW);

	/*PARA CUADRADO (no se modifica pero se manda para cada nueva forma a dibujar)*/
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

	/*PARA CUADRADO (no se modifica pero se manda para cada nueva forma a dibujar)*/
	//Habilitar atributos de shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	//Especificar a OpenGL como se va a comunicar
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));




	/*VERTEX ARRAY Y BUFFER PARA EL CUADRADO LADO*/

	//Crear un vertex array
	glGenVertexArrays(1, &vertexArrayCuadradoLadoID);
	glBindVertexArray(vertexArrayCuadradoLadoID);

	//Crear un vertex buffer
	glGenBuffers(1, &bufferCuadradoLadoID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferCuadradoLadoID);

	//Llenar el buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * cuadradoLado.size(), cuadradoLado.data(), GL_STATIC_DRAW);

	/*PARA CUADRADO LADO (no se modifica pero se manda para cada nueva forma a dibujar)*/
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

