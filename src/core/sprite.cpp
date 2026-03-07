
#include "sprite.hpp"

#include "../native/glglfw.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/matrix.hpp>

Sprite::Sprite(unsigned int VAO) : m_VAO(VAO) {}

unsigned int Sprite::getVAO() {
    return m_VAO;
}