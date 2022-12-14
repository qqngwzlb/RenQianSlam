/*
 * @Description: 从点云中截取一个立方体部分
 * @Author: Ren Qian
 * @Date: 2020-03-04 20:09:37
 */

#ifndef LIDAR_LOCALIZATION_MODELS_CLOUD_FILTER_BOX_FILTER_HPP_
#define LIDAR_LOCALIZATION_MODELS_CLOUD_FILTER_BOX_FILTER_HPP_

#include <pcl/filters/crop_box.h>
#include "lidar_localization/models/cloud_filter/cloud_filter_interface.hpp"

namespace lidar_localization {
class BoxFilter: public CloudFilterInterface {
  public:
    BoxFilter(YAML::Node node);
    BoxFilter() = default;

    bool Filter(const CloudData::CLOUD_PTR& input_cloud_ptr, CloudData::CLOUD_PTR& filtered_cloud_ptr) override;

    void SetSize(std::vector<float> size);
    void SetOrigin(std::vector<float> origin);
    std::vector<float> GetEdge();

  private:
    void CalculateEdge();

  private:
    pcl::CropBox<CloudData::POINT> pcl_box_filter_;   //盒子大小

    std::vector<float> origin_; //窗口的中心点 
    std::vector<float> size_;   //窗口大小
    std::vector<float> edge_;   //根据origin_和size_计算的方形窗口的两个点 
};
}

#endif 