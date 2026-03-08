#pragma once

#include <string>

class Texture {
  public:
    // Texture Image Info
    int width;
    int height;
    unsigned int img_format;      // The format of the texture that OpenGL will store as
    unsigned int internal_format; // Format of the image data used in createTexture()
    // Filtering Modes
    unsigned int min_filter_mode; // if texture is smaller than the size requested to be rendered
    unsigned int max_filter_mode; // if texture is bigger than the size requested to be rendered
    // Wrapping texture mode (Like GL_REPEAT)
    unsigned int wrap_mode_s;
    unsigned int wrap_mode_t;

  public:
    // Gets its content from a file
    Texture(const std::string &filepath, bool alpha);

    // Returns the OpenGL Texture ID
    unsigned int ID();

  private:
    // Creates the Open GL texture
    void createTexture(int width, int height, unsigned char *data);

    // Texture ID
    unsigned int m_id;
};