#ifndef VSB_SEMESTRAL_PROJECT_VISUALIZER_H
#define VSB_SEMESTRAL_PROJECT_VISUALIZER_H

#include <opencv2/opencv.hpp>
#include "../core/window.h"
#include "../core/template.h"
#include "../core/dataset_info.h"
#include "../core/hash_table.h"
#include "../core/match.h"
#include "../core/group.h"

class Visualizer {
public:
    static void visualizeWindows(cv::Mat &scene, std::vector<Window> &windows, const char *title = nullptr);
    static void visualizeSingleTemplateFeaturePoints(Template &tpl, const char *title = nullptr);
    static void visualizeTriplets(Template &tpl, HashTable &table, DataSetInfo &info, cv::Size &grid, const char *title = nullptr);
    static void visualizeMatches(cv::Mat &scene, std::vector<Match> &matches, std::vector<Group> &groups);
};


#endif //VSB_SEMESTRAL_PROJECT_VISUALIZER_H
