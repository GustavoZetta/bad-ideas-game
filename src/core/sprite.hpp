
#include <glm/common.hpp>

class Sprite {
  public:
    // Just stores the VAO, it does nothing with it
    Sprite(unsigned int VAO);

    unsigned int getVAO();

  public:
    glm::vec2 position;
    glm::vec2 size;
    float rotation;

  private:
    unsigned int m_VAO;
};