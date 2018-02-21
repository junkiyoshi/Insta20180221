#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	ofEnableDepthTest();
	ofSetLineWidth(1.2);

	for (int i = 0; i < 255; i++) {

		std::unique_ptr<Particle> particle(new Particle(i));
		this->particles.push_back(std::move(particle));
	}
}

//--------------------------------------------------------------
void ofApp::update() {

	for (int i = 0; i < this->particles.size(); i++) {

		this->particles[i]->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 0.5);

	for (int i = 0; i < this->particles.size(); i++) {

		this->particles[i]->draw();
	}

	
	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}