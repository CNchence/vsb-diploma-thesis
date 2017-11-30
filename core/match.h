#ifndef VSB_SEMESTRAL_PROJECT_TEMPLATE_MATCH_H
#define VSB_SEMESTRAL_PROJECT_TEMPLATE_MATCH_H

#include <ostream>
#include <memory>
#include <utility>
#include "template.h"

namespace tless {
    /**
     * @brief Holds matched templates along with their location and final score
     */
    struct Match {
    public:
        std::shared_ptr<Template> t;
        cv::Rect objBB;
        float score, areaScore;

        // Constructors
        Match(std::shared_ptr<Template> t, cv::Rect &bb, float score, float areaScore)
                : t(t), objBB(bb), score(score), areaScore(areaScore) {}

        // Operators
        bool operator==(const Match &rhs) const;
        bool operator!=(const Match &rhs) const;
        bool operator<(const Match &rhs) const;
        bool operator>(const Match &rhs) const;
        bool operator<=(const Match &rhs) const;
        bool operator>=(const Match &rhs) const;
        friend std::ostream &operator<<(std::ostream &os, const Match &match);
    };
}

#endif
