#include <OpenGLPrj.hpp>

#include <GLFW/glfw3.h>

#include <Camera.hpp>
#include <Shader.hpp>

#include <iostream>
#include <string>
#include <vector>
#include "Cube.hpp"
#include "Rubik.hpp"
#include "Vertices.hpp"


const std::string program_name = ("Camera");

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void mouse_callback(GLFWwindow *window, double xpos, double ypos);
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;

// camera
static Camera camera(glm::vec3(0.0f, 0.0f, 10.0f));
static float lastX = SCR_WIDTH / 2.0f;
static float lastY = SCR_HEIGHT / 2.0f;
static bool firstMouse = true;

// timing
static float deltaTime = 0.0f; // time between current frame and last frame
static float lastFrame = 0.0f;

static Cube cube;
static Rubik rubik1;
static Rubik rubik(1);

int main() {
  // glfw: initialize and configure
  // ------------------------------
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
  glfwWindowHint(
      GLFW_OPENGL_FORWARD_COMPAT,
      GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

  // glfw window creation
  // --------------------
  GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT,
                                        program_name.c_str(), nullptr, nullptr);
  if (window == nullptr) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
  glfwSetCursorPosCallback(window, mouse_callback);
  glfwSetScrollCallback(window, scroll_callback);

  // tell GLFW to capture our mouse
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  // glad: load all OpenGL function pointers
  // ---------------------------------------
  if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  // configure global opengl state
  // -----------------------------
  glEnable(GL_DEPTH_TEST);

  // build and compile our shader program
  // ------------------------------------
  std::string shader_location("../res/shaders/");

  std::string used_shaders("shader");

  Shader ourShader(shader_location + used_shaders + std::string(".vert"),
                   shader_location + used_shaders + std::string(".frag"));

  // set up vertex data (and buffer(s)) and configure vertex attributes
  // ------------------------------------------------------------------
  // raboti - bela kocka
//  float vertices[] = {
//      -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
//      0.5f,  -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
//      0.5f,  0.5f,  -0.5f, 1.0f, 1.0f, 1.0f,
//      0.5f,  0.5f,  -0.5f, 1.0f, 1.0f, 1.0f,
//      -0.5f, 0.5f,  -0.5f, 1.0f, 1.0f, 1.0f,
//      -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
//
//      -0.5f, -0.5f, 0.5f,  1.0f, 1.0f, 1.0f,
//      0.5f,  -0.5f, 0.5f,  1.0f, 1.0f, 1.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,
//      -0.5f, 0.5f,  0.5f,  1.0f, 1.0f, 1.0f,
//      -0.5f, -0.5f, 0.5f,  1.0f, 1.0f, 1.0f,
//
//      -0.5f, 0.5f,  0.5f,  1.0f, 1.0f, 1.0f,
//      -0.5f, 0.5f,  -0.5f, 1.0f, 1.0f, 1.0f,
//      -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
//      -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
//      -0.5f, -0.5f, 0.5f,  1.0f, 1.0f, 1.0f,
//      -0.5f, 0.5f,  0.5f,  1.0f, 1.0f, 1.0f,
//
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,
//      0.5f,  0.5f,  -0.5f, 1.0f, 1.0f, 1.0f,
//      0.5f,  -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
//      0.5f,  -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
//      0.5f,  -0.5f, 0.5f,  1.0f, 1.0f, 1.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,
//
//      -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
//      0.5f,  -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
//      0.5f,  -0.5f, 0.5f,  1.0f, 1.0f, 1.0f,
//      0.5f,  -0.5f, 0.5f,  1.0f, 1.0f, 1.0f,
//      -0.5f, -0.5f, 0.5f,  1.0f, 1.0f, 1.0f,
//      -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
//
//      -0.5f, 0.5f,  -0.5f, 1.0f, 1.0f, 1.0f,
//      0.5f,  0.5f,  -0.5f, 1.0f, 1.0f, 1.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,
//      -0.5f, 0.5f,  0.5f,  1.0f, 1.0f, 1.0f,
//      -0.5f, 0.5f,  -0.5f, 01.0f, 1.0f, 1.0f
//  };

    float vertices[] = {
            // Vertices for the front face
            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,   // Bottom left (Green)
            0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,    // Bottom right (Green)
            0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,     // Top right (Green)
            0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,     // Top right (Green)
            -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,    // Top left (Green)
            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,   // Bottom left (Green)

            // Vertices for the back face
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,    // Bottom left (Blue)
            0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,     // Bottom right (Blue)
            0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,      // Top right (Blue)
            0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,      // Top right (Blue)
            -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,     // Top left (Blue)
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,    // Bottom left (Blue)

            // Vertices for the right face
            0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,    // Bottom front (Red)
            0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,     // Bottom back (Red)
            0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,      // Top back (Red)
            0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,      // Top back (Red)
            0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,     // Top front (Red)
            0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,    // Bottom front (Red)

            // Vertices for the left face
            -0.5f, -0.5f, -0.5f, 1.0f, 0.5f, 0.0f,   // Bottom front (Orange)
            -0.5f, -0.5f, 0.5f, 1.0f, 0.5f, 0.0f,    // Bottom back (Orange)
            -0.5f, 0.5f, 0.5f, 1.0f, 0.5f, 0.0f,     // Top back (Orange)
            -0.5f, 0.5f, 0.5f, 1.0f, 0.5f, 0.0f,     // Top back (Orange)
            -0.5f, 0.5f, -0.5f, 1.0f, 0.5f, 0.0f,    // Top front (Orange)
            -0.5f, -0.5f, -0.5f, 1.0f, 0.5f, 0.0f,   // Bottom front (Orange)

            // Vertices for the top face
            -0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f,    // Front left (White)
            0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f,     // Front right (White)
            0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f,      // Back right (White)
            0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f,      // Back right (White)
            -0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f,     // Back left (White)
            -0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f,    // Front left (White)

            // Vertices for the bottom face
            -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f,   // Front left (Yellow)
            0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f,    // Front right (Yellow)
            0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 0.0f,     // Back right (Yellow)
            0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 0.0f,     // Back right (Yellow)
            -0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 0.0f,    // Back left (Yellow)
            -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f    // Front left (Yellow)
    };
    Vertices* v[] = {
             new Vertices(),
             new Vertices(),
             new Vertices(),
             new Vertices(),
             new Vertices(),
             new Vertices(),
             new Vertices(),
             new Vertices(),
             new Vertices(),
             new Vertices(),
             new Vertices(),
             new Vertices(),
             new Vertices(),
             new Vertices(),
             new Vertices(),
             new Vertices(),
             new Vertices(),
             new Vertices(),
             new Vertices(),
             new Vertices(),
             new Vertices(),
             new Vertices(),
             new Vertices(),
             new Vertices(),
             new Vertices(),
             new Vertices(),

    };
    glm::vec3 pos[26] = {
            //TOP
            glm::vec3(-1.0f, 1.0f, -1.0f), glm::vec3(0.0f, 1.0f, -1.0f), glm::vec3(1.0f, 1.0f, -1.0f),
            glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f),
            glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f),

            //MID
            glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(1.0f, 0.0f, -1.0f),
            glm::vec3(-1.0f, 0.0f, 0.0f),
            //glm::vec3(0.0f, 0.0f, 0.0f), // THIS ONE IS USELESS
            glm::vec3(1.0f, 0.0f, 0.0f),
            glm::vec3(-1.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 1.0f),

            //BOT
            glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(0.0f, -1.0f, -1.0f), glm::vec3(1.0f, -1.0f, -1.0f),
            glm::vec3(-1.0f, -1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, -1.0f, 0.0f),
            glm::vec3(-1.0f, -1.0f, 1.0f), glm::vec3(0.0f, -1.0f, 1.0f), glm::vec3(1.0f, -1.0f, 1.0f),
    };
    for(int i=0; i<26; i++){

        rubik.addCube(i, v[i], pos[i]);
    }

  // world space positions of our cubes
  glm::vec3 cubePositions[] = {
      glm::vec3(0.0f, 0.0f, 0.0f),    glm::vec3(2.0f, 5.0f, -15.0f),
      glm::vec3(-1.5f, -2.2f, -2.5f), glm::vec3(-3.8f, -2.0f, -12.3f),
      glm::vec3(2.4f, -0.4f, -3.5f),  glm::vec3(-1.7f, 3.0f, -7.5f),
      glm::vec3(1.3f, -2.0f, -2.5f),  glm::vec3(1.5f, 2.0f, -2.5f),
      glm::vec3(1.5f, 0.2f, -1.5f),   glm::vec3(-1.3f, 1.0f, -1.5f)};

  cube.position = cubePositions[0];
  cube.model =  glm::mat4(1.0f);

  unsigned int VBO, VAO;
  unsigned int VBOs[26];
  unsigned int VAOs[26];
//  unsigned int VAO1;
    glGenVertexArrays(26, VAOs);
//    glGenVertexArrays(1, &VAO1);
    glGenBuffers(26, VBOs);
  for(int i=0; i<26; i++){
      glBindVertexArray(VAOs[i]);

      glBindBuffer(GL_ARRAY_BUFFER, VBOs[i]);
      glBufferData(GL_ARRAY_BUFFER, sizeof(v[i]->vertices), v[i]->vertices, GL_STATIC_DRAW);

      // position attribute
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
      glEnableVertexAttribArray(0);
      // texture coord attribute
      glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                            reinterpret_cast<void *>(3 * sizeof(float)));
      glEnableVertexAttribArray(1);
  }

//  glGenVertexArrays(1, &VAO);
//  glGenBuffers(1, &VBO);
//  glBindVertexArray(VAO);
//
//  glBindBuffer(GL_ARRAY_BUFFER, VBO);
//  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//  // position attribute
//  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
//  glEnableVertexAttribArray(0);
//  // texture coord attribute
//  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
//                        reinterpret_cast<void *>(3 * sizeof(float)));
//  glEnableVertexAttribArray(1);
//
//  // load and create a texture
//  // -------------------------
//  unsigned int texture1, texture2;
//  // texture 1
//  // ---------
//  glGenTextures(1, &texture1);
//  glBindTexture(GL_TEXTURE_2D, texture1);
//  // set the texture wrapping parameters
//  glTexParameteri(
//      GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
//      GL_REPEAT); // set texture wrapping to GL_REPEAT (default wrapping method)
//  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//  // set texture filtering parameters
//  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//  // load image, create texture and generate mipmaps
//  int width, height, nrChannels;
//  stbi_set_flip_vertically_on_load(
//      true); // tell stb_image.h to flip loaded texture's on the y-axis.
//  // The FileSystem::getPath(...) is part of the GitHub repository so we can
//  // find files on any IDE/platform; replace it with your own image path.
//  unsigned char *data = stbi_load("../res/textures/Solid_red.png", &width,
//                                  &height, &nrChannels, 0);
//  if (data) {
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
//                 GL_UNSIGNED_BYTE, data);
//    glGenerateMipmap(GL_TEXTURE_2D);
//  } else {
//    std::cout << "Failed to load texture" << std::endl;
//  }
//  stbi_image_free(data);
//  // texture 2
//  // ---------
//  glGenTextures(1, &texture2);
//  glBindTexture(GL_TEXTURE_2D, texture2);
//  // set the texture wrapping parameters
//  glTexParameteri(
//      GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
//      GL_REPEAT); // set texture wrapping to GL_REPEAT (default wrapping method)
//  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//  // set texture filtering parameters
//  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//  // load image, create texture and generate mipmaps
//  data = stbi_load("../res/textures/awesomeface.png", &width, &height,
//                   &nrChannels, 0);
//  if (data) {
//    // note that the awesomeface.png has transparency and thus an alpha channel,
//    // so make sure to tell OpenGL the data type is of GL_RGBA
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
//                 GL_UNSIGNED_BYTE, data);
//    glGenerateMipmap(GL_TEXTURE_2D);
//  } else {
//    std::cout << "Failed to load texture" << std::endl;
//  }
//  stbi_image_free(data);

  // tell opengl for each sampler to which texture unit it belongs to (only has
  // to be done once)
  // -------------------------------------------------------------------------------------------
//  ourShader.use();
//  ourShader.setInt("texture1", 0);
//  ourShader.setInt("texture2", 1);

  // render loop
  // -----------
  while (!glfwWindowShouldClose(window)) {
    // per-frame time logic
    // --------------------
    float currentFrame = static_cast<float>(glfwGetTime());
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    // input
    // -----
    processInput(window);

    // render
    // ------
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // bind textures on corresponding texture units
//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, texture1);
//    glActiveTexture(GL_TEXTURE1);
//    glBindTexture(GL_TEXTURE_2D, texture2);

    // activate shader
    ourShader.use();

    // pass projection matrix to shader (note that in this case it could change
    // every frame)
    glm::mat4 projection = glm::perspective(
        glm::radians(camera.Zoom), SCR_WIDTH * 1.0f / SCR_HEIGHT, 0.1f, 100.0f);
    ourShader.setMat4("projection", projection);

    // camera/view transformation
    glm::mat4 view = camera.GetViewMatrix();
    ourShader.setMat4("view", view);
//   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // render boxes
    for(int i=0; i<26; i++){

            glBindVertexArray(VAOs[i]);
        glBindBuffer(GL_ARRAY_BUFFER, VBOs[i]);
//        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(v[i]->vertices), v[i]->vertices);
        glFlush();
        glFinish();
            Cube *c = rubik.cubes[i];
//        for(auto c : rubik.cubes){
//            glm::mat4 model = c->model;
//            model = glm::translate(model, c->position);
//            //model = glm::translate(model, glm::vec3(0.0f, 0.0f, -4.0f));
//            ourShader.setMat4("model", model);
//            glDrawArrays(GL_TRIANGLES, 0, 36);
//
//        }
        glm::mat4 model = c->model;
        model = glm::translate(model, c->position);
        //model = glm::translate(model, glm::vec3(0.0f, 0.0f, -4.0f));
        ourShader.setMat4("model", model);

        glDrawArrays(GL_TRIANGLES, 0, 36);

        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(v[i]->vertices), v[i]->vertices);
        glFlush();
        glFinish();

    }
    //glBindVertexArray(VAO);
    //single cube
//    glm::mat4 model = cube.model;
//    model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.0f));
//    ourShader.setMat4("model", model);
//      glDrawArrays(GL_TRIANGLES, 0, 36);

//rubik
//      glm::mat4 model = rubik.cubes[0]->model;
//      model = glm::translate(model, rubik.cubes[0]->position);
//      model = glm::translate(model, glm::vec3(0.0f, 0.0f, -4.0f));
//      ourShader.setMat4("model", model);
//      glDrawArrays(GL_TRIANGLES, 0, 36);
//      for(auto c : rubik.cubes){
//          glm::mat4 model = *c->model;
//          model = glm::translate(model, *c->position);
//          //model = glm::translate(model, glm::vec3(0.0f, 0.0f, -4.0f));
//          ourShader.setMat4("model", model);
//          glDrawArrays(GL_TRIANGLES, 0, 36);
//      }

//    for (unsigned int i = 1; i < 2; i++) {
//      // calculate the model matrix for each object and pass it to shader before
//      // drawing
//      glm::mat4 model = glm::mat4(
//          1.0f); // make sure to initialize matrix to identity matrix first
//      model = glm::translate(model, cubePositions[i]);
//      float angle = 20.0f * i;
//      model =
//          glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//      ourShader.setMat4("model", model);
//
//      glDrawArrays(GL_TRIANGLES, 0, 36);
//    }

    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved
    // etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // optional: de-allocate all resources once they've outlived their purpose:
  // ------------------------------------------------------------------------
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(26, VAOs);
    glDeleteBuffers(26, VBOs);

  // glfw: terminate, clearing all previously allocated GLFW resources.
  // ------------------------------------------------------------------
  glfwTerminate();
  return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this
// frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);

  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    camera.ProcessKeyboard(FORWARD, deltaTime*2);
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    camera.ProcessKeyboard(BACKWARD, deltaTime*2);
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    camera.ProcessKeyboard(LEFT, deltaTime*2);
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    camera.ProcessKeyboard(RIGHT, deltaTime*2);


        //PRIMES
        if ((glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) || rubik.isConcreteRotating[FP] )
            rubik.startRotation(deltaTime*2, (SIDE)FP, true);
        else if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS || rubik.isConcreteRotating[F] )
            rubik.startRotation(deltaTime*2, (SIDE)F, false);

        if ((glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) || rubik.isConcreteRotating[BP] )
            rubik.startRotation(deltaTime*2, (SIDE)BP, true);
        else if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS || rubik.isConcreteRotating[B] )
            rubik.startRotation(deltaTime*2, (SIDE)B, false);

        if ((glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) || rubik.isConcreteRotating[RP] )
            rubik.startRotation(deltaTime*2, (SIDE)RP, true);
        else if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS || rubik.isConcreteRotating[R] )
            rubik.startRotation(deltaTime*2, (SIDE)R, false);

        if ((glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) || rubik.isConcreteRotating[LP] )
            rubik.startRotation(deltaTime*2, (SIDE)LP, true);
        else  if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS || rubik.isConcreteRotating[L] )
            rubik.startRotation(deltaTime*2, (SIDE)L, false);

        if ((glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) || rubik.isConcreteRotating[TP] )
            rubik.startRotation(deltaTime*2, (SIDE)TP, true);
        else if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS || rubik.isConcreteRotating[T] )
            rubik.startRotation(deltaTime*2, (SIDE)T, false);

        if ((glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) || rubik.isConcreteRotating[DP] )
            rubik.startRotation(deltaTime*2, (SIDE)DP, true);
        else if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS || rubik.isConcreteRotating[D] )
            rubik.startRotation(deltaTime*2, (SIDE)D, false);

        //REGULARS





  if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
        rubik.rotateOwnAxis(deltaTime, glm::vec3(0.0f,1.0f,0.0f));


}

// glfw: whenever the window size changed (by OS or user resize) this callback
// function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  // make sure the viewport matches the new window dimensions; note that width
  // and height will be significantly larger than specified on retina displays.
  glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow *window, double xposd, double yposd) {
  float xpos = static_cast<float>(xposd);
  float ypos = static_cast<float>(yposd);
  if (firstMouse) {
    lastX = xpos;
    lastY = ypos;
    firstMouse = false;
  }

  float xoffset = xpos - lastX;
  float yoffset =
      lastY - ypos; // reversed since y-coordinates go from bottom to top

  lastX = xpos;
  lastY = ypos;

  camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
  camera.ProcessMouseScroll(static_cast<float>(yoffset));
}
