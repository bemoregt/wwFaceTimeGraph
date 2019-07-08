#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGraph.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
private:
    ofVideoGrabber cam;
    // face object detector
    ofxCv::ObjectFinder finder;
    ofPixels cap1;
    ofImage img1;
    ofxGraph graph;
    
};
