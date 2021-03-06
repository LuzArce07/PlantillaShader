#pragma once

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include <fstream>

#include <string>
#include <vector>

using namespace std;

class Shader {

public:
	GLuint getID(); //Obtiene el ID del Shader
	Shader(const char * rutaVertex, const char * rutaFragment);

	void enlazar();
	void desenlazar();

private:
	GLuint shaderID; //aqui guardamos lo que el glCreateProgram regrese
	void verificarCompilacion(GLuint id);
	void verificarVinculacion(GLuint id);


};
