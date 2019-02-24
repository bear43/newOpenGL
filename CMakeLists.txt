cmake_minimum_required(VERSION 3.13)
project(untitled2)

set(CMAKE_CXX_STANDARD 17)

link_libraries(-lGL -lGLU -lglut -lGLEW -lglfw)

add_executable(untitled2 main.cpp OpenGL/Buffers/VBO/VBODefault.cpp OpenGL/Buffers/VBO/VBODefault.h OpenGL/Buffers/VAO/VAO.cpp OpenGL/Buffers/VAO/VAO.h OpenGL/Buffers/Buffer.h OpenGL/Buffers/IBO/IBO.cpp OpenGL/Buffers/IBO/IBO.h File/Input/FileInput.cpp File/Input/FileInput.h File/Output/FileOutput.cpp File/Output/FileOutput.h File/File.cpp File/File.h OpenGL/Shader/VertexShader/VertexShader.cpp OpenGL/Shader/VertexShader/VertexShader.h OpenGL/Shader/FragmentShader/FragmentShader.cpp OpenGL/Shader/FragmentShader/FragmentShader.h OpenGL/Program/Program.cpp OpenGL/Program/Program.h OpenGL/Buffers/VBO/VBOAbstract.cpp OpenGL/Buffers/VBO/VBOAbstract.h OpenGL/Buffers/VBO/VBOColors.cpp OpenGL/Buffers/VBO/VBOColors.h)