#pragma once

#include <string>

class Shader {
  public:

    // The shader gets created as soon the constructor is called,
    // so it needs the correct OpenGL context.
    // Without correct context, as being something 
    // like "static Shader coolshader()",
    // expect errors
    Shader();

    // Returns the shader program ID
    unsigned int ID();

  private:
    // Puts the content of a file into a string and returns it (It doesn't care if it is shader code or not lol)
    static std::string getShaderSource(const std::string& filePath);
    // Creates a compiled shader code and returns the ID which can be put into a shader program
    static unsigned int createShaderModule(const char *shaderSrc, unsigned int shaderType);
    // Creates the shader program and returns the ID
    static unsigned int createShaderProgram();

    // Shader program ID
    unsigned int m_id;
};