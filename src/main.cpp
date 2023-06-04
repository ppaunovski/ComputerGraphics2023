#include <OpenGLPrj.hpp>

#include <GLFW/glfw3.h>

#include <Shader.hpp>

#include <iostream>
#include <string>
#include <vector>

const std::string program_name = ("Transformation basics");

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;

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

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // build and compile our shader program
    // ------------------------------------

    std::string shader_location("../res/shaders/");

    std::string used_shaders("shader");

//  Shader ourShader(shader_location + used_shaders + std::string(".vert"),
//                   shader_location + used_shaders + std::string(".frag"));
    Shader ourShader("../res/shaders/shader.vert",
                     "../res/shaders/shader.frag"
    );
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
            -0.55f, -0.45f, -0.5f, 0.2f, 0.1f, 0.5f,
            -0.55f, -0.45f, 0.0f, 0.2f, 0.1f, 0.5f,
            -0.3f, -0.45f, -0.5f, 0.2f, 0.1f, 0.5f,

            -0.55f, -0.45f, 0.0f, 0.2f, 0.1f, 0.5f,
            -0.3f, -0.45f, -0.5f, 0.2f, 0.1f, 0.5f,
            -0.3f, -0.45f, 0.0f, 0.2f, 0.1f, 0.5f,

            -0.3f, -0.45f, -0.5f, 0.2f, 0.1f, 0.5f,
            -0.3f, -0.45f, 0.0f, 0.2f, 0.1f, 0.5f,
            -0.3f, 0.45f, 0.0f, 0.2f, 0.1f, 0.5f,

            -0.3f, -0.45f, -0.5f, 0.2f, 0.1f, 0.5f,
            -0.3f, 0.45f, 0.0f, 0.2f, 0.1f, 0.5f,
            -0.3f, 0.45f, -0.5f, 0.2f, 0.1f, 0.5f,

            -0.3f, 0.45f, 0.0f, 0.2f, 0.1f, 0.5f,
            -0.3f, 0.45f, -0.5f, 0.2f, 0.1f, 0.5f,
            -0.55f, 0.45f, -0.5f, 0.2f, 0.1f, 0.5f,

            -0.55f, 0.45f, -0.5f, 0.2f, 0.1f, 0.5f,
            -0.3f, 0.45f, 0.0f, 0.2f, 0.1f, 0.5f,
            -0.55f, 0.45f, 0.0f, 0.2f, 0.1f, 0.5f,

            -0.55f, 0.45f, 0.0f, 0.2f, 0.1f, 0.5f,
            -0.3f, 0.45f, 0.0f, 0.2f, 0.1f, 0.5f,
            -0.55f, -0.45f, 0.0f, 0.2f, 0.1f, 0.5f,

            -0.55f, -0.45f, 0.0f, 0.2f, 0.1f, 0.5f,
            -0.3f, -0.45f, 0.0f, 0.2f, 0.1f, 0.5f,
            -0.3f, 0.45f, 0.0f, 0.2f, 0.1f, 0.5f,

            -0.55f, -0.45f, 0.0f, 0.2f, 0.1f, 0.5f,
            -0.55f, -0.45f, -0.5f, 0.2f, 0.1f, 0.5f,
            -0.55f, 0.45f, 0.0f, 0.2f, 0.1f, 0.5f,

            -0.55f, -0.45f, -0.5f, 0.2f, 0.1f, 0.5f,
            -0.55f, 0.45f, 0.0f, 0.2f, 0.1f, 0.5f,
            -0.55f, 0.45f, -0.5f, 0.2f, 0.1f, 0.5f,

            -0.55f, -0.45f, -0.5f, 0.2f, 0.1f, 0.5f,
            -0.3f, -0.45f, -0.5f, 0.2f, 0.1f, 0.5f,
            -0.3f, 0.45f, -0.5f, 0.2f, 0.1f, 0.5f,

            -0.55f, 0.45f, -0.5f, 0.2f, 0.1f, 0.5f,
            -0.3f, 0.45f, -0.5f, 0.2f, 0.1f, 0.5f,
            -0.3f, -0.45f, -0.5f, 0.2f, 0.1f, 0.5f

    };

    std::vector<float> vert;

//    for (int i=0; i<36; i++){
//        vert.push_back(vertices[6*i]);
//        vert.push_back(vertices[6*i+1]);
//        vert.push_back(vertices[6*i+2]);
//        vert.push_back(vertices[6*i+3]);
//        vert.push_back(vertices[6*i+4]);
//        vert.push_back(vertices[6*i+5]);
//    }

    int theta, phi;
    int d_theta=5, d_phi=5;
    float x, y, z;
    float r=0.5f, g=0.5f, b=0.5f;
    float DTOR = 0.0174532925;
    int counter=0;

    for(theta = -90; theta <= 90-d_theta; theta += d_theta){

        for (phi = 0; phi <= 360-d_phi; phi += d_phi){
            x = glm::cos(theta*DTOR) * glm::cos(phi*DTOR);
            y = glm::cos(theta*DTOR) * glm::sin(phi*DTOR);
            z = glm::sin(theta*DTOR);

            vert.push_back(x);
            vert.push_back(y);
            vert.push_back(z);
            vert.push_back(r);
            vert.push_back(g);
            vert.push_back(b);
            counter++;

            x = glm::cos((theta+d_theta)*DTOR) * glm::cos(phi*DTOR);
            y = glm::cos((theta+d_theta)*DTOR) * glm::sin(phi*DTOR);
            z = glm::sin((theta+d_theta)*DTOR);

            vert.push_back(x);
            vert.push_back(y);
            vert.push_back(z);
            vert.push_back(r);
            vert.push_back(g);
            vert.push_back(b);
            counter++;

            x = glm::cos((theta+d_theta)*DTOR) * glm::cos((phi+d_phi)*DTOR);
            y = glm::cos((theta+d_theta)*DTOR) * glm::sin((phi+d_phi)*DTOR);
            z = glm::sin((theta+d_theta)*DTOR);

            vert.push_back(x);
            vert.push_back(y);
            vert.push_back(z);
            vert.push_back(r);
            vert.push_back(g);
            vert.push_back(b);
            counter++;

            if (theta > -90 && theta < 90){
                x = glm::cos(theta*DTOR) * glm::cos((phi+d_phi)*DTOR);
                y = glm::cos(theta*DTOR) * glm::sin((phi+d_phi)*DTOR);
                z = glm::sin(theta*DTOR);

                vert.push_back(x);
                vert.push_back(y);
                vert.push_back(z);
                vert.push_back(r);
                vert.push_back(g);
                vert.push_back(b);
                counter++;
            }
        }
    }


    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vert.size()*sizeof(float), &vert[0], GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                          static_cast<void *>(nullptr));
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                          reinterpret_cast<void *>(3 * sizeof(float)));
    glEnableVertexAttribArray(1);



    glEnable(GL_DEPTH_TEST);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        // activate shader
        ourShader.use();

        // create transformations
        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 projection = glm::mat4(1.0f);

        model = model =
                glm::rotate(model,  glm::radians(20.0f),
                            glm::vec3(0.5f, 0.0f, 0.0f));
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
        projection =
                glm::perspective(glm::radians(45.0f),
                                 (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        // retrieve the matrix uniform locations
        unsigned int modelLoc = glGetUniformLocation(ourShader.ID, "model");
        unsigned int viewLoc = glGetUniformLocation(ourShader.ID, "view");
        // pass them to the shaders (3 different ways)
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
        // note: currently we set the projection matrix each frame, but since the
        // projection matrix rarely changes it's often best practice to set it
        // outside the main loop only once.
        ourShader.setMat4("projection", projection);

        // render container
        glBindVertexArray(VAO);

        glDrawArrays(GL_LINE_STRIP, 0, counter);

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
    glDeleteBuffers(1, &EBO);

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
}

// glfw: whenever the window size changed (by OS or user resize) this callback
// function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    // make sure the viewport matches the new window dimensions; note that width
    // and height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
