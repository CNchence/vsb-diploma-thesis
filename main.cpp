#include <iostream>
#include "utils/timer.h"
#include "objdetect/classifier.h"

int main() {
    // Init classifier
    Classifier classifier;

    // Run classifier
//    classifier.train("data/templates.txt", "data/trained/", "data/models/", { 0, 20, 25, 23, 120, 250, 774, 998, 1100, 400, 478, 1095, 1015, 72 });
//    classifier.train("data/templates.txt", "data/trained/", "data/models/");
    classifier.detect("data/trained_templates.txt", "data/trained/", "data/scene_01/");

    // TODO
    // 1) Test I - depth not being filtered as it should
    // 2) Visualizer for hashing is probably broken
    // 3) consider adding minimum magnitude for edges for feature extraction

    return 0;
}