#version 330 core
//Primera linea SIEMPRE es la version

//Atributos de entrada (vienen dede el Vertex shader)
in vec4 fragmentColor;

//Atributo de salida
out vec4 salidaColor;

//Funcion Main
void main{
	
	salidaColor = fragmentColor;

}