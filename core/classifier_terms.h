#ifndef VSB_SEMESTRAL_PROJECT_CLASSIFIER_TERMS_H
#define VSB_SEMESTRAL_PROJECT_CLASSIFIER_TERMS_H

#include <opencv2/core/types.hpp>
#include <ostream>
#include <memory>
#include "template.h"

/**
 * struct ClassifierTerms
 *
 * Holds information about loaded data set and all thresholds for further computation
 */
struct ClassifierTerms {
public:
    // Params and thresholds
    struct {
        // Hasher
        struct {
            cv::Size grid; // Triplet grid size
            int minVotes; // Minimum number of votes to classify template as window candidate
            int tablesCount; // Number of tables to generate
            int maxDistance; // Max distance between each point in triplet
            int binCount; // Number of bins for depth ranges
        } hasher;

        // Matcher
        struct {
            int pointsCount; // Number of feature points to extract for each template
            float tMatch; // number indicating how many percentage of points should match [0.0 - 1.0]
            float tOverlap; // overlap threshold, how much should 2 windows overlap in order to calculate non-maxima suppression [0.0 - 1.0]
            uchar tColorTest; // HUE value max threshold to pass comparing colors between scene and template [0-180]
            cv::Range neighbourhood; // area to search around feature point to look for match [-num, num]
        } matcher;

        // Objectness
        struct {
            int step; // Stepping for sliding window
            float tEdgesMin; // Min threshold applied in sobel filtered image thresholding [0.01f]
            float tEdgesMax; // Max threshold applied in sobel filtered image thresholding [0.1f]
            float tMatch; // Factor of minEdgels window should contain to be classified as valid [30% -> 0.3f]
        } objectness;
    } params;

    // Data set info
    struct {
        int minEdgels;
        cv::Size smallestTemplate;
        cv::Size maxTemplate;
    } info;

    // Constructors
    ClassifierTerms();

    // Persistence
    static std::shared_ptr<ClassifierTerms> load(cv::FileStorage fsr);
    void save(cv::FileStorage &fsw);
    
    // Methods
    void resetInfo();

    friend std::ostream &operator<<(std::ostream &os, const ClassifierTerms &terms);
};

#endif //VSB_SEMESTRAL_PROJECT_CLASSIFIER_TERMS_H
