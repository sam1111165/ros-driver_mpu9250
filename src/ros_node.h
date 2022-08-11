/// \file ros_node.h
/// \brief Defines the ros_node class.
#ifndef ROS_NODE_H
#define ROS_NODE_H

#include "driver.h"

#include <ros/ros.h>

///
/// \brief Implements the driver's ROS node functionality.
///
class ros_node
{
public:
    // CONSTRUCTORS
    ///
    /// \brief ros_node Initializes the ROS node.
    /// \param driver The MPU9250 driver instance.
    /// \param argc Number of main() args.
    /// \param argv The main() args.
    ///
    sensor_msgs::Imu message_imu;
    ros_node(driver* driver, int argc, char **argv);
    ~ros_node();

    // METHODS
    ///
    /// \brief spin Runs the node.
    ///
    void spin();

private:
    // VARIABLES
    ///
    /// \brief m_driver The driver instance.
    ///
    driver* m_driver;
    ///
    /// \brief m_node The node's handle.
    ///
    ros::NodeHandle* m_node;
    ///
    /// \brief m_publisher_imu The publisher for IMU messages.
    ///
    ros::Publisher m_publisher_imu;
    ///
    /// \brief m_publisher_mag The publisher for MagneticField messages.
    ///
    ros::Publisher m_publisher_mag;
    ///
    /// \brief m_publisher_temp The publisher for Temperature messages.
    ///
    ros::Publisher m_publisher_temp;

    // METHODS
    ///
    /// \brief deinitialize_driver Deinitializes the driver.
    ///
    void deinitialize_driver();

    ///
    /// \brief data_callback The callback function for when new data is available.
    /// \param data The latest data read from the MPU9250/AK8963.
    ///
    void data_callback(driver::data data);
};

#endif // ROS_NODE_H
