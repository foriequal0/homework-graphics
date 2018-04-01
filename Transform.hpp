//
// Created by foriequal0 on 18. 3. 31.
//

#ifndef SNU_GRAPHICS_TRANSFORM_HPP
#define SNU_GRAPHICS_TRANSFORM_HPP

#include <Eigen/Dense>


class Transform {
public:
    class Guard;

    Eigen::Quaternionf orientation = Eigen::Quaternionf(1.0f, 0.0f, 0.0f, 0.0f);
    Eigen::Vector3f scale = Eigen::Vector3f(1.0f, 1.0f, 1.0f);
    Eigen::Vector3f position = Eigen::Vector3f(0.0f, 0.0f, 0.0f);
    auto guard() const -> Guard;

    inline Transform& setScale(float x, float y, float z) {
        scale = {x, y, z};
        return *this;
    }

    inline Transform& setPosition(float x, float y, float z) {
        position = {x, y, z};
        return *this;
    }

    inline Transform& setOrientation(float w, float x, float y, float z) {
        orientation = {w, x, y, z};
        return *this;
    }
};

class Transform::Guard {
    bool entered = false;
public:
    explicit Guard(bool entered = false);
    Guard(const Guard&) = default;
    Guard(Guard&&) = default;
    Guard& operator=(const Guard&) = default;
    Guard& operator=(Guard&&) = default;
    ~Guard();
    void exit();
};

#endif //SNU_GRAPHICS_TRANSFORM_HPP