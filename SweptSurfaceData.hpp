//
// Created by foriequal0 on 18. 5. 5.
//

#ifndef SNU_GRAPHICS_SWEPTSURFACEDATA_H
#define SNU_GRAPHICS_SWEPTSURFACEDATA_H

#include <string>
#include <istream>
#include <vector>
#include <Eigen/Dense>
#include "Transform.hpp"
#include "Unit.hpp"

namespace snu_graphics {
enum class CurveType {
  BSPLINE, CATMULL_ROM,
};

struct CrossSection {
  float scale;
  Eigen::Quaternionf rotation;
  Eigen::Vector3f position;
  std::vector<Eigen::Vector3f> points;
};

struct SweptSurfaceData {
  CurveType curve_type;
  int num_control_points;
  std::vector<CrossSection> cross_sections;

  std::vector<Triangle> sweep_surface() const;

  static SweptSurfaceData load(const std::string &filename);
  static SweptSurfaceData load(std::istream &file);
};
}
#endif //SNU_GRAPHICS_SWEPTSURFACEDATA_H
