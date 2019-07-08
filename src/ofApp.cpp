#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//-------------------------------------------------------
void ofApp::setup() {
    // cam ready
    ofSetVerticalSync(true);
    ofSetFrameRate(30);
    // cam size
    cam.setup(320, 240);
    
    // for face detection
    finder.setup("haarcascade_frontalface_default.xml");
    finder.setPreset(ObjectFinder::Fast);
    finder.setUseHistogramEqualization(true);
    //finder.setMinSizeScale(5.0);
    
    // for graph
    ofSetFrameRate(30);
    // ofxGraph uses ofxGui as a internal setting UI
    ofxGuiSetFont(ofToDataPath("ofxGraph/DIN Alternate Bold.ttf"), 10);
    
    // ofxGraph Init
    graph.setup("X Position of Box");
    graph.setDx(1.0); // which means delta of time
    graph.setColor(ofColor::white); // ofColor(255,255,255)
    graph.setPosition(10, 250);
    graph.setSize(620, 220);
    graph.setAutoScale(true, 1.0);
}

//-------------------------------------------------------
void ofApp::update() {
    cam.update();
    
    if(cam.isFrameNew()) {
        finder.update(cam);
        if(finder.size()>0){
            cv::Rect roi = toCv(finder.getObject(0));
            
            //ofLog() << meanRect << endl;
            graph.add(roi.x );
        }
    }
}

//-------------------------------------------------------
void ofApp::draw() {
    //
    ofSetColor(255, 255, 255);
    cam.draw(0, 0);
    finder.draw();
    // black box for text
    ofDrawBitmapStringHighlight(ofToString(finder.size()), 10, 20);

    
    // graph
    //ofBackground(50,50,50);
    graph.draw();
}
