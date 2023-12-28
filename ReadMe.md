# Rubik's cube

## Controls

### Camera movement

Move left - press A key on keyboard

Move right - press D key on keyboard

Move up - press W key on keyboard

Move down - press S key on keyboard


### Rotations of the cube

- Regular rotations:

Left face rotation - press L key on keyboard

Right face rotation - press R key on keyboard

Front face rotation - press F key on keyboard

Back face rotation - press B key on keyboard

Top face rotation - press T key on keyboard

Down face rotation - press SPACE key on keyboard

- Prime rotations:

Left face rotation - press LEFT_SHIFT + L key on keyboard

Right face rotation - press LEFT_SHIFT + R key on keyboard

Front face rotation - press LEFT_SHIFT + F key on keyboard

Back face rotation - press LEFT_SHIFT + B key on keyboard

Top face rotation - press LEFT_SHIFT + T key on keyboard

Down face rotation - press LEFT_SHIFT + SPACE key on keyboard


# OpenGLPrj

Project for Basics of Computer Graphics course at [FCSE](https://finki.ukim.mk/). It is a striped down version of [Polythonic/Glitter](https://github.com/Polytonic/Glitter) project that includes:
  - [GLAD](https://github.com/Dav1dde/glad) as OpenGL Function Loader
  - [GLFW](https://github.com/glfw/glfw) for Windowing and Input
  - [GLM](https://github.com/g-truc/glm) for OpenGL Mathematics
  - [stb](https://github.com/nothings/stb) for images and texture loading

## Setup
  Recursively clone the repository:

    git clone --recursive https://github.com/joksim/OpenGLPrj.git
    
  If you are using an IDE that supports CMake builds (QtCreator, Jetbrains CLion, Visual Studio), open the cloned directory as project (the directory `OpenGLPrj` with the `CMakeLists.txt` file).

  We recomend using [out of source builds](https://cgold.readthedocs.io/en/latest/tutorials/out-of-source.html]).

  Project files can be generated using the following steps:

### Using CMake from cmd/git bash/powershell:
  
  - Create a folder for the project build (e.g. build). It can be in the same level/directory as the OpenGLPrj. The hierarchy should be as depicted

        |
        |-- build/
        |-- OpenGLPrj/

  - Using CMake generate the specified project files into the build directory:
  
        cd build
        cmake ../OpenGLPrj/
   
  Open the project files in the spedified IDE (Visual Studio, QtCreator, ...)

###  Using cmake-gui:
     
  Open the `cmake-gui` app. For the source folder select the `OpenGLPrj` directory. For build directory choose an empty directory (for example, directory named `build` at the same level as `OpenGLPrj`. With both folders choosen, click **Configure** and if successfull procede to **Generate** the build files. A tutorial is given at: [https://cgold.readthedocs.io/en/latest/tutorials/cmake-stages.html#](https://cgold.readthedocs.io/en/latest/tutorials/cmake-stages.html#).
  
  
