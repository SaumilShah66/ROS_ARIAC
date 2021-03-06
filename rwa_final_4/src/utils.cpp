/**
 *  Copyright 2020 Varun Asthana, Saumil Shah, Nalin Das, Markose Jacob, Aditya Goswami
 *  @file utils.cpp
 * 
 *  @author Varun Asthana
 *  @author Saumil Shah
 *  @author Nalin Das
 *  @author Markose Jacob
 *  @author Aditya Goswami
 * 
 *  @date 11/29/2020
 * 
 *  @brief Utility functions implementation
 * 
 *  @section DESCRIPTION
 *
 *  Source file for Utility functions implementation.
 *
 */
#include "utils.h"
#include <geometry_msgs/Pose.h>

std::unordered_map<std::string, double> model_height = {
        {"piston_rod_part_red", 0.0065}, // modified because it sinks into the surface a bit
        {"piston_rod_part_green", 0.0065},
        {"piston_rod_part_blue", 0.0065},
        {"pulley_part_red", 0.07},
        {"pulley_part_green", 0.07},
        {"pulley_part_blue", 0.07},
        {"gear_part_red", 0.012},
        {"gear_part_green", 0.012},
        {"gear_part_blue", 0.012},
        {"gasket_part_red", 0.03},
        {"gasket_part_green", 0.03},
        {"gasket_part_blue", 0.03},
        {"disk_part_red", 0.023},
        {"disk_part_green", 0.023},
        {"disk_part_blue", 0.023}
};

std::vector<double> quaternionToEuler(geometry_msgs::Pose pose) {
    std::vector<double> pose_angles = {};
    tf2::Quaternion q( pose.orientation.x,
                        pose.orientation.y,
                        pose.orientation.z,
                        pose.orientation.w);
    tf2::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);
    pose_angles = {roll, pitch, yaw};
    return pose_angles;
}