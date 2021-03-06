//
// Created by foriequal0 on 18. 3. 31.
//

#include <GL/gl.h>
#include <GL/glut.h>
#include <Eigen/OpenGLSupport>
#include "Transform.hpp"

namespace snu_graphics {
Transform::Guard::Guard(bool entered) : entered(entered) {}

Transform::Guard::~Guard() {
  if (entered) {
    exit();
  }
}

void Transform::Guard::exit() {
  glPopMatrix();
  entered = false;
}

Transform::Guard Transform::guard() const {
  glPushMatrix();
  glTranslate(position);
  glScale(scale);
  glRotate(orientation);
  return Transform::Guard(true);
}

Eigen::Vector3f Transform::to_local(Eigen::Vector3f origin) const {
  return orientation.toRotationMatrix().transpose() * (origin - position).cwiseQuotient(scale);
}
}