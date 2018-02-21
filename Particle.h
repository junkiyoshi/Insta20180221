#pragma once
#include "ofMain.h"

class Particle {
public:

	Particle(float value);
	~Particle();

	void update();
	void draw();

	ofPoint make_point(float radius, float small_radius, float deg, float small_deg);
private:

	float radius;
	float small_radius;
	float deg;
	float small_deg;
	float deg_span;
	float small_deg_span;

	ofColor body_color;
};