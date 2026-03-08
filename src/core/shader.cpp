#include <glm/gtc/type_ptr.hpp>

#include <array>

#include "util.hpp"

#include "shader.hpp"

unsigned int Shader::createModule(const char *shaderSrc, unsigned int shaderType) {

    unsigned int shaderP = glCreateShader(shaderType);

    glShaderSource(shaderP, 1, &shaderSrc, NULL);
    glCompileShader(shaderP);

    int sucess;
    glGetShaderiv(shaderP, GL_COMPILE_STATUS, &sucess);
    if (!sucess) {
        char errorLog[1024];
        glGetShaderInfoLog(shaderP, 1024, NULL, errorLog);
        Logger::log("Shader Module compilation error:\n");
        Logger::log(errorLog);
    }

    return shaderP;
}

void Shader::createShader(const std::string &vertexSrc, const std::string &fragmentSrc) {
    std::array<unsigned int, 2> modules = {};

    modules[0] = Shader::createModule(vertexSrc.c_str(), GL_VERTEX_SHADER);
    modules[1] = Shader::createModule(fragmentSrc.c_str(), GL_FRAGMENT_SHADER);

    m_id = glCreateProgram();
    for (unsigned int shaderModule : modules) {
        glAttachShader(m_id, shaderModule);
    }
    glLinkProgram(m_id);

    int sucess;
    glGetProgramiv(m_id, GL_LINK_STATUS, &sucess);
    if (!sucess) {
        char errorLog[1024];
        glGetProgramInfoLog(m_id, 1024, NULL, errorLog);
        Logger::log("Shader Linking error:\n");
        Logger::log(errorLog);
    }

    // Cleaning modules cause it isn't need after the program creation
    for (unsigned int shaderModule : modules) {
        glDeleteShader(shaderModule);
    }
}

Shader::Shader() : m_id(0) {}

Shader::~Shader() {
    glDeleteProgram(m_id);
}

unsigned int Shader::ID() {
    return m_id;
}

// General

void Shader::setInt(const char *uniformName, int integer, bool useProgram) {
    if (useProgram) {
        glUseProgram(m_id);
    }
    glUniform1i(glGetUniformLocation(m_id, uniformName), integer);
}

void Shader::setMat4x4(const char *uniformName, const glm::mat4 &matrix, bool useProgram) {
    if (useProgram) {
        glUseProgram(m_id);
    }

    glUniformMatrix4fv(glGetUniformLocation(m_id, uniformName), 1, false, glm::value_ptr(matrix));
}

// GLM vec

void Shader::setVec4f(const char *uniformName, const glm::vec4 &vector, bool useProgram) {
    if (useProgram) {
        glUseProgram(m_id);
    }

    glUniform4f(glGetUniformLocation(m_id, uniformName), vector.x, vector.y, vector.z, vector.w);
}

void Shader::setVec3f(const char *uniformName, const glm::vec3 &vector, bool useProgram) {
    if (useProgram) {
        glUseProgram(m_id);
    }

    glUniform3f(glGetUniformLocation(m_id, uniformName), vector.x, vector.y, vector.z);
}

void Shader::setVec2f(const char *uniformName, const glm::vec2 &vector, bool useProgram) {
    if (useProgram) {
        glUseProgram(m_id);
    }

    glUniform2f(glGetUniformLocation(m_id, uniformName), vector.x, vector.y);
}

// Raw Data

void Shader::setVec4f(const char *uniformName, float x, float y, float z, float w, bool useProgram) {
    if (useProgram) {
        glUseProgram(m_id);
    }

    glUniform4f(glGetUniformLocation(m_id, uniformName), x, y, z, w);
}

void Shader::setVec3f(const char *uniformName, float x, float y, float z, bool useProgram) {
    if (useProgram) {
        glUseProgram(m_id);
    }

    glUniform3f(glGetUniformLocation(m_id, uniformName), x, y, z);
}

void Shader::setVec2f(const char *uniformName, float x, float y, bool useProgram) {
    if (useProgram) {
        glUseProgram(m_id);
    }

    glUniform2f(glGetUniformLocation(m_id, uniformName), x, y);
}
