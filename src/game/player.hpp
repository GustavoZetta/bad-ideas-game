#pragma once

#include "core/gameobject.hpp"

class Player : public GameObject {
  public:
    bool walking;
    float playerSpeed;

  public:
    Player();

    void setWalking(bool value);
};