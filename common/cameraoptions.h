#ifndef CAMERAOPTIONS_H
#define CAMERAOPTIONS_H

class CameraOptions
{
public:
    CameraOptions(float angle, float direction, float range);

    float getAngle() const;
    float getDirection() const;
    float getRange() const;

private:
    const float angle_;
    const float direction_;
    const float range_;
};

#endif // CAMERAOPTIONS_H
