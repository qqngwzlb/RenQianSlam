/*
 * @Description:
 * @Author: Ren Qian
 * @Date: 2019-07-17 18:17:49
 */
#ifndef LIDAR_LOCALIZATION_SENSOR_DATA_CLOUD_DATA_HPP_
#define LIDAR_LOCALIZATION_SENSOR_DATA_CLOUD_DATA_HPP_

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

namespace lidar_localization {
  class CloudData {
    public:
      using POINT = pcl::PointXYZ;    //using取别名
      using CLOUD = pcl::PointCloud<POINT>;
      using CLOUD_PTR = CLOUD::Ptr;
      CLOUD_PTR cloud_ptr; 
      //CLOUD_PTR 等价  pcl::PointCloud<pcl::PointXYZ>::Ptr
      
    public:
      CloudData()
        :cloud_ptr( new CLOUD() ) {     // CLOUD==>  pcl::PointCloud< pcl::PointXYZ >
      }

    public:
      double time = 0.0;
      
  };
}

#endif