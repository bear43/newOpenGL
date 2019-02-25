cmake_minimum_required(VERSION 3.13)
project(untitled2)

set(CMAKE_CXX_STANDARD 17)

link_libraries(-lGL -lGLU -lglut -lGLEW -lglfw)

add_executable(untitled2 main.cpp OpenGL/Buffers/VBO/VBODefault.cpp OpenGL/Buffers/VBO/VBODefault.h OpenGL/Buffers/VAO/VAO.cpp OpenGL/Buffers/VAO/VAO.h OpenGL/Buffers/Buffer.h OpenGL/Buffers/IBO/IBO.cpp OpenGL/Buffers/IBO/IBO.h File/Input/FileStringInput.cpp File/Input/FileStringInput.h File/Output/FileStringOutput.cpp File/Output/FileStringOutput.h File/File.cpp File/File.h OpenGL/Shader/VertexShader/VertexShader.cpp OpenGL/Shader/VertexShader/VertexShader.h OpenGL/Shader/FragmentShader/FragmentShader.cpp OpenGL/Shader/FragmentShader/FragmentShader.h OpenGL/Program/Program.cpp OpenGL/Program/Program.h OpenGL/Buffers/VBO/VBOAbstract.cpp OpenGL/Buffers/VBO/VBOAbstract.h OpenGL/Buffers/VBO/VBOColors.cpp OpenGL/Buffers/VBO/VBOColors.h File/Input/FileBinaryInput.cpp File/Input/FileBinaryInput.h File/BMP/BMPFile.cpp File/BMP/BMPFile.h OpenGL/Texture/Texture2D.cpp OpenGL/Texture/Texture2D.h OpenGL/Buffers/VBO/VBOTexture.cpp OpenGL/Buffers/VBO/VBOTexture.h)