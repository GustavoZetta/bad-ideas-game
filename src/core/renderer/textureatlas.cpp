#include "core/renderer/textureatlas.hpp"

TextureAtlas::TextureAtlas() {
    
}

void TextureAtlas::addEntry(const std::string &name, int x, int y, int w, int h) {
    AtlasEntry entry;
    entry.uvOffset = glm::vec2(
        (float)x / sprite->width,
        (float)y / sprite->height);
    entry.uvSize = glm::vec2(
        (float)w / sprite->width,
        (float)h / sprite->height);
    m_entries[name] = entry;
}

AtlasEntry TextureAtlas::getEntry(const std::string &name) {
    return m_entries.at(name);
}