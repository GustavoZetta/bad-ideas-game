#include "texture.hpp"

#include "logger.hpp"

#include "../native/glglfw.h"
#include "../native/stb_image.h"

Texture::Texture(const char *filepath, bool alpha) : width(0), height(0), internal_format(GL_RGB), img_format(GL_RGB), min_filter_mode(GL_LINEAR), max_filter_mode(GL_LINEAR), wrap_mode_s(GL_REPEAT), wrap_mode_t(GL_REPEAT) {
    if (alpha) {
        internal_format = GL_RGBA;
        img_format = GL_RGB;
    }

    int width;
    int height;
    int nrChannels;

    unsigned char *data = stbi_load(filepath, &width, &height, &nrChannels, 0);

    createTexture(width, height, data);
    stbi_image_free(data);
}

void Texture::createTexture(int w, int h, unsigned char *data) {
    width = w;
    height = h;

    glGenTextures(1, &m_id);

    glBindTexture(GL_TEXTURE_2D, m_id);
    glTexImage2D(GL_TEXTURE_2D, 0, internal_format, w, h, 0, img_format, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap_mode_s);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap_mode_t);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filter_mode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, max_filter_mode);

    glBindTexture(GL_TEXTURE_2D, 0);
}

unsigned int Texture::ID() {
    return m_id;
}