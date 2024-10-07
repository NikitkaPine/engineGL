#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"

//imp triangle vertices
GLfloat vertices[] = {
//imp			COORDINATE									COLOR	
		-0.5f, -0.5f * float(sqrt(3)) / 3,		0.0f,	0.9f,0.5f,	0.37f, // Lower left corner
		0.5f,  -0.5f * float(sqrt(3)) / 3,		0.0f,	0.9f,0.5f,	0.37f, // Lower right corner
		0.0f,   0.5f * float(sqrt(3)) * 2 / 3,	0.0f,	0.9f,0.9f,	0.02f, // Upper corner
		-0.25f,  0.5f * float(sqrt(3)) / 6,		0.0f,	0.8f,0.45f,	0.07f, // Inner left
		0.25f,   0.5f * float(sqrt(3)) / 6,		0.0f,	0.8f,0.45f,	0.07f, // Inner right
		0.0f,  -0.5f * float(sqrt(3)) / 3,		0.0f,	0.9f,0.9f,	0.47f  // Inner down
};


GLuint indices[] =
{
	0,3,5,
	3,2,4,
	5,4,1
};


int main()
{
	// Initialize GLFW
	glfwInit();



	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	
	// Create a GLFWwindow object of 800 by 800 pixels
	GLFWwindow* window = glfwCreateWindow(800, 800, "Triangles test", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);



	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, 800, 800);

	Shader shaderProgram("default.vert", "default.frag");

	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));

	VAO1.LinkAttrib(VBO1, 0,3, GL_FLOAT,6*sizeof(float), (void*)0);	
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3*sizeof(float)));
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();


	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.12f, 0.42f, 0.68f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shaderProgram.Activate();
		glUniform1f(uniID, 0.5f);
		VAO1.Bind();
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);

		// Take care of all GLFW events
		glfwPollEvents();
	}

	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}