#ifndef VSB_SEMESTRAL_PROJECT_WINDOW_H
#define VSB_SEMESTRAL_PROJECT_WINDOW_H

#include <opencv2/core/types.hpp>
#include "template.h"

/**
 * struct Window
 *
 * After objectness detection, each sliding window containing object is represented using this structure.
 * These windows are then used further down the cascade in template matching.
 */
struct Window {
public:
    int x;
    int y;
    int width;
    int height;
    int edgels;
    std::vector<Template *> candidates;

    // Constructors
    explicit Window(int x = 0, int y = 0, int width = 0, int height = 0, int edgels = 0, const std::vector<Template *> &candidates = {})
        : x(x), y(y), width(width), height(height), edgels(edgels), candidates(candidates) {}

    // Methods
    cv::Point tl();
    cv::Point tr();
    cv::Point bl();
    cv::Point br();

    cv::Size size();
    bool hasCandidates();

    // Overloads
    bool operator==(const Window &rhs) const;
    bool operator!=(const Window &rhs) const;
    bool operator<(const Window &rhs) const;
    bool operator>(const Window &rhs) const;
    bool operator<=(const Window &rhs) const;
    bool operator>=(const Window &rhs) const;
    friend std::ostream &operator<<(std::ostream &os, const Window &w);
};

#endif //VSB_SEMESTRAL_PROJECT_WINDOW_H
