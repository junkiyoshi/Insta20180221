#include "Particle.h"

//--------------------------------------------------------------
Particle::Particle(float value) {

	this->radius = 230;
	this->small_radius = 70;
	this->deg = value / 255.f * 360.f;
	this->small_deg = ofRandom(0, 360);
	this->deg_span = 1;
	this->small_deg_span = 10;
	//this->body_color.setHsb(value, 255, 255);
	this->body_color = ofColor(255);
}

//--------------------------------------------------------------
Particle::~Particle() {

}

//--------------------------------------------------------------
void Particle::update() {

	this->deg += this->deg_span;
	this->small_deg += this->small_deg_span;
}

//--------------------------------------------------------------
void Particle::draw() {

	ofSetColor(this->body_color, 255);
	ofVec3f point = make_point(this->radius, this->small_radius, this->deg, this->small_deg);
	ofDrawSphere(point, 1.5);

	for (int i = 0; i < 12; i++) {

		ofSetColor(this->body_color, 255 - i * 25);
		ofVec3f point_1 = make_point(this->radius, this->small_radius, this->deg - this->deg_span * i, this->small_deg - this->small_deg_span * i);
		ofVec3f point_2 = make_point(this->radius, this->small_radius, this->deg - this->deg_span * (i + 1), this->small_deg - this->small_deg_span * (i + 1));
		ofDrawLine(point_1, point_2);
	}
}

//--------------------------------------------------------------
ofPoint Particle::make_point(float radius, float small_radius, float deg, float small_deg) {

	float x_1 = radius * cos(deg * DEG_TO_RAD);
	float y_1 = radius * sin(deg * DEG_TO_RAD);

	float x_2 = small_radius * cos(small_deg * DEG_TO_RAD) * cos(deg * DEG_TO_RAD);
	float y_2 = small_radius * cos(small_deg * DEG_TO_RAD) * sin(deg * DEG_TO_RAD);

	float x = x_1 + x_2;
	float y = y_1 + y_2;
	float z = small_radius * sin(small_deg * DEG_TO_RAD);

	return ofVec3f(x, y, z);
}
