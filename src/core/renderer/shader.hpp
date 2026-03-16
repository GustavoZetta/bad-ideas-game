#pragma once

#include "native/glglfw.h"

#include <glm/common.hpp>
#include <glm/matrix.hpp>

#include <string>

class Shader {
  public:
    // Added because the compiler does not create an default
    // constructor if the class have an destructor
    Shader();

    // Deletes the shader program
    ~Shader();

    // Because of "~Shader();", the compiler does not make an
    // default operator to move the shader class
    // This will make so the Shader class can freely be moved again
    Shader(Shader &&other) noexcept : m_id(other.m_id) {
        other.m_id = 0; // Stops double delete
    }

    Shader &operator=(Shader &&other) noexcept {
        if (this != &other) {
            glDeleteProgram(m_id);
            m_id = other.m_id;
            other.m_id = 0;
        }
        return *this;
    }

    // Creates the shader program, calls createModule twice to create both shader modules
    void createShader(const std::string &vertexSrc, const std::string &fragmentSrc);

    // Returns the shader program ID
    unsigned int ID();

    void setInt(const char *uniformName, int integer, bool useProgram = false);
    void setMat4x4(const char *uniformName, const glm::mat4 &matrix, bool useProgram = false);

    void setVec4f(const char *uniformName, const glm::vec4 &vector, bool useProgram = false);
    void setVec3f(const char *uniformName, const glm::vec3 &vector, bool useProgram = false);
    void setVec2f(const char *uniformName, const glm::vec2 &vector, bool useProgram = false);

    void setVec4f(const char *uniformName, float x, float y, float z, float w, bool useProgram = false);
    void setVec3f(const char *uniformName, float x, float y, float z, bool useProgram = false);
    void setVec2f(const char *uniformName, float x, float y, bool useProgram = false);

  private:
    // Creates a shader module, which is just the shader source code compiled and ready to make a shader program
    unsigned int createModule(const char *shaderSrc, unsigned int shaderType);

    // Shader program ID
    unsigned int m_id;
};