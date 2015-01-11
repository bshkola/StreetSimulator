//Author: Wojciech Ceret
//Implementation of algorithm that determines detection of objects by cameras.
#include "cameradetectionimpl.h"
#include "icameranoise.h"
#include <cmath>

void CameraDetectionImpl::calculate(    const std::list<Camera*>& camera_list,
                                        const std::list<TrafficParticipant*>& tp_list,
                                              std::list<CameraObservation*>& observation_list
                                   )
{

    std::pair<float, float> cam_coordinates (0.0, 0.0);
    std::pair<float, float>  tp_coordinates (0.0, 0.0);
    std::pair<float, float>  tp_coordinates_noised (0.0, 0.0);
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
            cam_coordinates.first  = (*cam_it)->x;
            cam_coordinates.second = (*cam_it)->y;
            //set coordinates of traffic participant
            tp_coordinates.first  = (*tp_it)->x;
            tp_coordinates.second = (*tp_it)->y;
            //calculate real distance
            distance = this->distance(cam_coordinates, tp_coordinates);
            //decision if traffic participant within camera's range
            if(distance > (*cam_it)->range)
                continue;   //if out of range then skip
            //calculate real azimuth
            azimuth = this->azimuth(cam_coordinates, tp_coordinates);
            //decision if traffic participant within camera's angle
            if(!withinTheAngle((*cam_it)->azimuth, (*cam_it)->angle, azimuth))
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

};

float CameraDetectionImpl::distance(const std::pair<float, float> A,
                                    const std::pair<float, float> B
                                   )
{
    return hypot((A.first - B.first), (A.second - B.second));
};

float CameraDetectionImpl::azimuth(const std::pair<float, float> A,
                                   const std::pair<float, float> B
                                  )
{
    const float PI = acos(-1.0);
    float distance = this->distance(A, B);
    float delta_x = B.first - A.first;
    float delta_y = B.second - A.second;

    if(delta_x == 0.0 && delta_y == 0.0)
        return 0.0;
    if(delta_x >= 0.0 && delta_y >= 0.0)//1st quarter
        return 90.0 - (180.0 / PI * acos(delta_x / distance));
    if(delta_x < 0.0 && delta_y > 0.0)  //2nd quarter
        return 450.0 - (180.0 / PI * acos(delta_x / distance));
    if(delta_y <= 0.0)                  //3rd & 4th quarter
        return 90.0 + (180.0 / PI * acos(delta_x / distance));

    return 0.0;
};

bool CameraDetectionImpl::withinTheAngle(float cam_azimuth,
                                         float cam_angle,
                                         float tp_azimuth
                                        )
{
    float max_azimuth = cam_azimuth + cam_angle / 2.0;
    float mim_azimuth = cam_azimuth - cam_angle / 2.0;
    
    if(max_azimuth < 360.0){
        if(mim_azimuth <= tp_azimuth && tp_azimuth <= max_azimuth){
            return true;
        }
        else {
            return false;
        }
    }
    else {
        if(mim_azimuth <= tp_azimuth && tp_azimuth < 360.0){
            return true;
        }
        if(0.0 <= tp_azimuth && tp_azimuth <= max_azimuth - 360.0){
            return true;
        }
        return false;
    }
};
