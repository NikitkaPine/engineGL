#include"Mesh.h"

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
// Vertices coordinates
Vertex vertices[] =
{ //               COORDINATES           /            COLORS          /           NORMALS         /       TEXTURE COORDINATES    //
	Vertex{glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
	Vertex{glm::vec3(1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)}
};

// Indices for vertices order
GLuint indices[] =
{
	0, 1, 2,
	0, 2, 3
};

Vertex lightVertices[] =
{ //     COORDINATES     //
	Vertex{glm::vec3(-0.1f, -0.1f,  0.1f)},
	Vertex{glm::vec3(-0.1f, -0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f, -0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f, -0.1f,  0.1f)},
	Vertex{glm::vec3(-0.1f,  0.1f,  0.1f)},
	Vertex{glm::vec3(-0.1f,  0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f,  0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f,  0.1f,  0.1f)}
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

	Texture textures[]
	{
		Texture("planks.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("planksSpec.png","specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};


	Shader shaderProgram("default.vert", "default.frag");
	std::vector <Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
	std::vector <GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));
	std::vector <Texture> tex(textures, textures + sizeof(textures) / sizeof(Texture));
	Mesh floor(verts, ind, tex);

	//LIGHT

	Shader lightShader("light.vert", "light.frag");
	std::vector <Vertex> lightVerts(lightVertices, lightVertices + sizeof(lightVertices) / sizeof(Vertex));
	std::vector<GLuint> lightInd(lightIndices, lightIndices + sizeof(lightIndices) / sizeof(GLuint));
	Mesh light(lightVerts, lightInd, tex);


	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	glm::vec3 objectPos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 objectModel = glm::mat4(1.0f);
	objectModel = glm::translate(objectModel, objectPos);


	lightShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
	glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	shaderProgram.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(objectModel));
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);


	

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

		floor.Draw(shaderProgram, camera);
		light.Draw(lightShader, camera);

		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}

	
	shaderProgram.Delete();
	lightShader.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}