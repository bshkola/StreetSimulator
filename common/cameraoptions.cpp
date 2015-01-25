#include "cameraoptions.h"

CameraOptions::CameraOptions(float angle, float direction, float range)
    : angle_(angle), direction_(direction), range_(range) {
}

float CameraOptions::getAngle() const {
    return angle_;
}

float CameraOptions::getDirection() const {
    return direction_;
}

float CameraOptions::getRange() const {
    return range_;
}
