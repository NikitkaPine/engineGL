#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include"shaderClass.h"
#include"Texture.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include"Camera.h"

const unsigned int width = 800;
const unsigned int height = 800;
/*GLfloat vertices[] = {
	// Front face
	-0.25f, 0.0f, 0.25f,    0.9f, 0.5f, 0.37f,  0.0f, 0.0f,  0.0f, 0.0f, 1.0f, // 0
	-0.25f, 0.5f, 0.25f,    0.9f, 0.5f, 0.37f,  0.0f, 1.0f,  0.0f, 0.0f, 1.0f, // 1
	 0.25f, 0.5f, 0.25f,    0.9f, 0.9f, 0.02f,  1.0f, 1.0f,  0.0f, 0.0f, 1.0f, // 2
	 0.25f, 0.0f, 0.25f,    0.8f, 0.45f, 0.07f, 1.0f, 0.0f,  0.0f, 0.0f, 1.0f, // 3

	 // Back face
	 -0.25f, 0.0f, -0.25f,   0.9f, 0.5f, 0.37f,  0.0f, 0.0f,  0.0f, 0.0f, -1.0f, // 4
	 -0.25f, 0.5f, -0.25f,   0.9f, 0.5f, 0.37f,  0.0f, 1.0f,  0.0f, 0.0f, -1.0f, // 5
	  0.25f, 0.5f, -0.25f,   0.9f, 0.9f, 0.02f,  1.0f, 1.0f,  0.0f, 0.0f, -1.0f, // 6
	  0.25f, 0.0f, -0.25f,   0.8f, 0.45f, 0.07f,  1.0f, 0.0f,  0.0f, 0.0f, -1.0f, // 7

	  // Left face
	  -0.25f, 0.0f, -0.25f,   0.9f, 0.5f, 0.37f,  0.0f, 0.0f,  -1.0f, 0.0f, 0.0f, // 8
	  -0.25f, 0.5f, -0.25f,   0.9f, 0.5f, 0.37f,  0.0f, 1.0f,  -1.0f, 0.0f, 0.0f, // 9
	  -0.25f, 0.5f, 0.25f,    0.9f, 0.9f, 0.02f,  1.0f, 1.0f,  -1.0f, 0.0f, 0.0f, //10
	  -0.25f, 0.0f, 0.25f,    0.8f, 0.45f, 0.07f,  1.0f, 0.0f,  -1.0f, 0.0f, 0.0f, //11

	  // Right face
	   0.25f, 0.0f, -0.25f,   0.9f, 0.5f, 0.37f,  0.0f, 0.0f,  1.0f, 0.0f, 0.0f, //12
	   0.25f, 0.5f, -0.25f,   0.9f, 0.5f, 0.37f,  0.0f, 1.0f,  1.0f, 0.0f, 0.0f, //13
	   0.25f, 0.5f, 0.25f,    0.9f, 0.9f, 0.02f,  1.0f, 1.0f,  1.0f, 0.0f, 0.0f, //14
	   0.25f, 0.0f, 0.25f,    0.8f, 0.45f, 0.07f,  1.0f, 0.0f,  1.0f, 0.0f, 0.0f, //15

	   // Bottom face
	   -0.25f, 0.0f, -0.25f,   0.9f, 0.5f, 0.37f,  0.0f, 0.0f,  0.0f, -1.0f, 0.0f, //16
		0.25f, 0.0f, -0.25f,   0.9f, 0.5f, 0.37f,  1.0f, 0.0f,  0.0f, -1.0f, 0.0f, //17
		0.25f, 0.0f, 0.25f,    0.9f, 0.9f, 0.02f,  1.0f, 1.0f,  0.0f, -1.0f, 0.0f, //18
	   -0.25f, 0.0f, 0.25f,    0.8f, 0.45f, 0.07f,  0.0f, 1.0f,  0.0f, -1.0f, 0.0f, //19

	   // Top face
	   -0.25f, 0.5f, -0.25f,   0.9f, 0.5f, 0.37f,  0.0f, 0.0f,  0.0f, 1.0f, 0.0f, //20
		0.25f, 0.5f, -0.25f,   0.9f, 0.5f, 0.37f,  1.0f, 0.0f,  0.0f, 1.0f, 0.0f, //21
		0.25f, 0.5f, 0.25f,    0.9f, 0.9f, 0.02f,  1.0f, 1.0f,  0.0f, 1.0f, 0.0f, //22
	   -0.25f, 0.5f, 0.25f,    0.8f, 0.45f, 0.07f,  0.0f, 1.0f,  0.0f, 1.0f, 0.0f  //23
};


GLuint indices[] = {
	// Front face
	0, 1, 2,
	2, 3, 0,

	// Back face
	4, 5, 6,
	6, 7, 4,

	// Left face
	8, 9,10,
	10,11, 8,

	// Right face
	12,13,14,
	14,15,12,

	// Bottom face
	16,17,18,
	18,19,16,

	// Top face
	20,21,22,
	22,23,20
};

GLfloat lightVertices[] =
{
	// Front face
	3.5f, 1.0f, -2.5f,
	3.5f, 2.0f, -2.5f,
	2.5f, 2.0f, -2.5f,
	2.5f, 1.0f, -2.5f,

	// Back face
	3.5f, 1.0f, -3.5f,
	3.5f, 2.0f, -3.5f,
	2.5f, 2.0f, -3.5f,
	2.5f, 1.0f, -3.5f
};

GLuint lightIndices[] =
{
	// Front face
   0, 1, 2,
   2, 3, 0,

   // Back face
   4, 5, 6,
   6, 7, 4,

   // Left face
   4, 5, 1,
   1, 0, 4,

   // Right face
   3, 2, 6,
   6, 7, 3,

   // Bottom face
   4, 0, 3,
   3, 7, 4,

   // Top face
   1, 5, 6,
   6, 2, 1
	
};*/
// Vertices coordinates
GLfloat vertices[] =
{ //     COORDINATES     /        COLORS          /    TexCoord   /        NORMALS       //
	-1.0f,0.0f,  1.0f,		0.0f, 0.0f, 0.0f,		0.0f,0.0f,		0.0f,1.0f,0.0f,
	-1.0f,0.0f, -1.0f,		0.0f, 0.0f, 0.0f,		0.0f,1.0f,		0.0f,1.0f,0.0f,
	 1.0f,0.0f, -1.0f,		0.0f, 0.0f, 0.0f,		1.0f,1.0f,		0.0f,1.0f,0.0f,
	 1.0f,0.0f,  1.0f,		0.0f, 0.0f, 0.0f,		1.0f,0.0f,		0.0f,1.0f,0.0f
};

// Indices for vertices order
GLuint indices[] =
{
	0,1,2,
	0,2,3
};

GLfloat lightVertices[] =
{ //     COORDINATES     //
	-0.1f, -0.1f,  0.1f,
	-0.1f, -0.1f, -0.1f,
	 0.1f, -0.1f, -0.1f,
	 0.1f, -0.1f,  0.1f,
	-0.1f,  0.1f,  0.1f,
	-0.1f,  0.1f, -0.1f,
	 0.1f,  0.1f, -0.1f,
	 0.1f,  0.1f,  0.1f
};

GLuint lightIndices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};


//imp triangle vertices
//GLfloat vertices[] = {
//imp	// Positions          // Colors         // Texture Coords
/*		-0.5f, 0.0f, 0.0f, 0.9f, 0.5f, 0.37f, 0.0f, 0.0f, // 0
		-0.5f,  1.0f, 0.0f,   0.9f, 0.5f, 0.37f,   0.0f, 1.0f, // 1
		0.5f,  1.0f, 0.0f,   0.9f, 0.9f, 0.02f,   1.0f, 1.0f, // 2
		0.5f,  0.0f, 0.0f,   0.8f, 0.45f, 0.07f,  1.0f, 0.0f, // 3
		-0.5f,  0.0f, 1.0f,   0.9f, 0.5f, 0.37f,   0.0f, 0.0f, // 4
		-0.5f,  1.0f, 1.0f,   0.9f, 0.5f, 0.37f,   0.0f, 1.0f, // 5
		0.5f,  1.0f, 1.0f,   0.9f, 0.9f, 0.02f,   1.0f, 1.0f, // 6
		0.5f,  0.0f, 1.0f,   0.8f, 0.45f, 0.07f,  1.0f, 0.0f  // 7


//todo TRIANGLE
		-0.5f, -0.5f * float(sqrt(3)) / 3,	0.0f,	0.9f,0.5f,	0.37f, // Lower left corner
		0.5f,  -0.5f * float(sqrt(3)) / 3,		0.0f,	0.9f,0.5f,	0.37f, // Lower right corner
		0.0f,   0.5f * float(sqrt(3)) * 2 / 3,	0.0f,	0.9f,0.9f,	0.02f, // Upper corner
		-0.25f,  0.5f * float(sqrt(3)) / 6,		0.0f,	0.8f,0.45f,	0.07f, // Inner left
		0.25f,   0.5f * float(sqrt(3)) / 6,		0.0f,	0.8f,0.45f,	0.07f, // Inner right
		0.0f,  -0.5f * float(sqrt(3)) / 3,		0.0f,	0.9f,0.9f,	0.47f  // Inner down
};*/


/*GLuint indices[] =
{
	// Front face
   0, 1, 2,
   2, 3, 0,

   // Back face
   4, 5, 6,
   6, 7, 4,

   // Left face
   4, 5, 1,
   1, 0, 4,

   // Right face
   3, 2, 6,
   6, 7, 3,

   // Bottom face
   4, 0, 3,
   3, 7, 4,

   // Top face
   1, 5, 6,
   6, 2, 1

//todo TRIANGLE
	0,3,5,
	3,2,4,
	5,4,1
};*/


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
	GLFWwindow* window = glfwCreateWindow(width,height, "Triangles test", NULL, NULL);
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
	glViewport(0, 0, width, height);

	Shader shaderProgram("default.vert", "default.frag");

	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));

	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);	
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3*sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();


	//LIGHT

	Shader lightShader("light.vert", "light.frag");

	VAO lightVAO;
	lightVAO.Bind();

	VBO lightVBO(lightVertices, sizeof(lightVertices));
	EBO lightEBO(lightIndices, sizeof(lightIndices));

	lightVAO.LinkAttrib(lightVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);

	lightVAO.Unbind();
	lightVBO.Unbind();
	lightEBO.Unbind();


	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	glm::vec3 lightPos = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	glm::vec3 cubePos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 cubeModel = glm::mat4(1.0f);
	cubeModel = glm::translate(cubeModel, cubePos);


	lightShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
	glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	shaderProgram.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(cubeModel));
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	//GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

	//TEXTURE

	Texture planksTex("planks.png", GL_TEXTURE_2D,0, GL_RGBA, GL_UNSIGNED_BYTE);
	planksTex.texUnit(shaderProgram, "tex0", 0);
	Texture planksSpec("planksSpec.png", GL_TEXTURE_2D, 1, GL_RED, GL_UNSIGNED_BYTE);
	planksSpec.texUnit(shaderProgram, "tex1", 1);

	glEnable(GL_DEPTH_TEST);


	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	//float rotation = 0.0f;
	//double prevTime = glfwGetTime();

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.7f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



		camera.Inputs(window);
		camera.updateMatrix(45.0f, 0.1f, 100.0f);


		shaderProgram.Activate();
		glUniform3f(glGetUniformLocation(shaderProgram.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
		camera.Matrix(shaderProgram, "camMatrix");

		/*double crntTime = glfwGetTime();
		if (crntTime - prevTime >= 1 / 60) 
		{
			rotation += 0.5f;
			prevTime = crntTime;
		}

		glEnable(GL_DEPTH_TEST);

		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 proj = glm::mat4(1.0f);

		model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));
		view = glm::translate(view, glm::vec3(0.0f, -0.5f, -2.0f));
		proj = glm::perspective(glm::radians(45.0f),(float)(width/height),0.1f,100.0f);

		int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		int projLoc = glGetUniformLocation(shaderProgram.ID, "proj");
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

		glUniform1f(uniID, 0.5f);*/

		planksTex.Bind();
		planksSpec.Bind();

		VAO1.Bind();
		glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);

		lightShader.Activate();
		camera.Matrix(lightShader, "camMatrix");
		lightVAO.Bind();
		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);

		// Take care of all GLFW events
		glfwPollEvents();
	}

	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	planksTex.Delete();
	planksSpec.Delete();
	shaderProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}