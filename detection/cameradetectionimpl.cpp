//Author: Wojciech Ceret
//Implementation of algorithm that determines detection of objects by cameras.
#include "cameradetectionimpl.h"
#include "icameranoise.h"
#include <cmath>
#include <iostream>

void CameraDetectionImpl::calculate(    const std::list<Camera*>& camera_list,
                                        const std::list<TrafficParticipant*>& tp_list,
                                              std::list<CameraObservation*>& observation_list
                                   )
{

    std::pair<float, float> cam_coordinates = std::pair<float, float> (0.0, 0.0);
    std::pair<float, float>  tp_coordinates = std::pair<float, float> (0.0, 0.0);
    std::pair<float, float>  tp_coordinates_noised = std::pair<float, float> (0.0, 0.0);
    float distance, noised_distance, azimuth, noised_azimuth;
    CameraObservation* observation_ptr;

    //for every camera on the list
    for(std::list<Camera*>::const_iterator cam_it = camera_list.cbegin();
        cam_it != camera_list.cend();
        ++cam_it){

        //for every traffic participant on the list
        for(std::list<TrafficParticipant*>::const_iterator tp_it = tp_list.cbegin();
            tp_it != tp_list.cend();
            ++tp_it){

            //set coordinates of camera
            cam_coordinates.first  = (*cam_it)->x_;
            cam_coordinates.second = (*cam_it)->y_;
            //set coordinates of traffic participant
            tp_coordinates.first  = (*tp_it)->x_;
            tp_coordinates.second = (*tp_it)->y_;
            //calculate real distance
            distance = this->distance(cam_coordinates, tp_coordinates);
            //decision if traffic participant within camera's range
            if(distance > (*cam_it)->range_)
                continue;   //if out of range then skip
            //calculate real azimuth
            azimuth = this->azimuth(cam_coordinates, tp_coordinates);
            //decision if traffic participant within camera's angle
            if(!withinTheAngle((*cam_it)->azimuth_, (*cam_it)->angle_, azimuth))
                continue;   //if out of angle then skip
            //introduce noise
            tp_coordinates_noised =
                (this->NoiseGenerator)->introduceNoise(tp_coordinates.first,
                                                       tp_coordinates.second,
                                                       distance,
                                                       10);
            //calculate noised distance
            noised_distance = this->distance(cam_coordinates, tp_coordinates_noised);
            //calculate noised azimuth
            noised_azimuth = this->azimuth(cam_coordinates, tp_coordinates_noised);
            //create new observation
            observation_ptr = new CameraObservation(**cam_it,
                                                    tp_coordinates_noised.first,
                                                    tp_coordinates_noised.second,
                                                    noised_distance,
                                                    noised_azimuth);
            //insert observation to list of observations
            observation_list.push_back(observation_ptr);
        }

    }

}

float CameraDetectionImpl::distance(const std::pair<float, float> A,
                                    const std::pair<float, float> B
                                   )
{
    return hypot((A.first - B.first), (A.second - B.second));
}

float CameraDetectionImpl::distance(const float a_, const float b_)
{
    return hypot(a_, b_);
}

float CameraDetectionImpl::azimuth(const std::pair<float, float> A,
                                   const std::pair<float, float> B
                                  )
{
    const float PI = acos((float)-1.0);
    float delta_x = B.first - A.first;
    float delta_y = B.second - A.second;
    float distance = this->distance(delta_x, delta_y);

    if((delta_x == 0.0 && delta_y == 0.0) || distance == 0.0)
        return 0.0;
    if(delta_x >= 0.0 && delta_y >= 0.0)//1st quarter
        return 90.0 - (acos(delta_x / distance) * 180.0 / PI);
    if(delta_x < 0.0 && delta_y >= 0.0)  //2nd quarter
        return 450.0 - (acos(delta_x / distance) * 180.0 / PI);
    if(delta_y < 0.0)                  //3rd & 4th quarter
        return 90.0 + (acos(delta_x / distance) * 180.0 / PI);

    return 0.0;
}

bool CameraDetectionImpl::withinTheAngle(float cam_azimuth,
                                         float cam_angle,
                                         float tp_azimuth
                                        )
{
    float cam_azimuth_ = cam_azimuth;
    float cam_angle_ = cam_angle;
    float tp_azimuth_ = tp_azimuth;

    normalizeAzimuth(cam_azimuth_);
    normalizeAngle(cam_angle_);
    normalizeAzimuth(tp_azimuth_);

    float max_azimuth_ = cam_azimuth_ + cam_angle_ / 2.0;
    float min_azimuth_ = cam_azimuth_ - cam_angle_ / 2.0;

    normalizeAzimuth(max_azimuth_);
    normalizeAzimuth(min_azimuth_);

    if(min_azimuth_ <= max_azimuth_){
        if(min_azimuth_ <= tp_azimuth_ && tp_azimuth_ <= max_azimuth_){
            return true;
        }
        else {
            return false;
        }
    }
    else {
        if(min_azimuth_ <= tp_azimuth_ || tp_azimuth_ <= max_azimuth_){
            return true;
        }
        return false;
    }
}

void CameraDetectionImpl::normalizeAzimuth(float& azimuth_)
{
    /* Makes azimuth a value in [0.0, 360.0) degrees without changing it's meaning (direction). */
    while(azimuth_ < 0.0){
        azimuth_ += 360.0;
    }
    while(azimuth_ >= 360.0){
        azimuth_ -= 360.0;
    }
}

void CameraDetectionImpl::normalizeAngle(float& angle_)
{
    /* Forces angle be a value in [0.0, 360.0] degrees. */
    if(angle_ > 360.0){
        angle_ = 360.0;
    }
    if(angle_ < 0.0){
        angle_ = 0.0;
    }
}
