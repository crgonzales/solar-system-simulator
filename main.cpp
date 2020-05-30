#include <iostream>
#include <cmath>
#include <string>
#include <vector>



class Point {
public:
	float x;
	float y;
	float z; 
	Point() {
		x = 0;
		y = 0;
		z = 0;
	};
	Point(float argX, float argY, float argZ) {
		x = argX;
		y = argY;
		z = argZ;
		
	}
};

class body {
public:
	Point Position;
	Point Velocity;
	float mass;
	
	std::string name;
	body(Point argPosition, float argMass, float argVelocity, std::string argName) {
		Position = argPosition;


	}


};

float displacement(Point initial, Point final) {
	return(

		sqrt(
			pow((final.x - initial.x), 2) +
			pow((final.y - initial.y), 2) +
			pow((final.z - initial.z), 2)
		)
		);
}
Point calculateSingleBodyAcceleration(std::vector<body> bodyList, int index) {
	float const_G = 6.67408e-11;
	Point acceleration = { 0, 0, 0 };
	float distance;
	float temp;
	for (int i = 0; i < bodyList.size(); i++) {
		if (i = index) {
			continue;
		}
		distance = displacement(bodyList[index].Position, bodyList[i].Position);
		temp = const_G * bodyList[i].mass / pow(distance,3);
		acceleration.x += temp * (bodyList[i].Position.x - bodyList[index].Position.x);
		acceleration.y += temp * (bodyList[i].Position.y - bodyList[index].Position.y);
		acceleration.z += temp * (bodyList[i].Position.z - bodyList[index].Position.z);

	}
	return acceleration;
}

void updateVelocity(std::vector<body> bodyList, float time_step) {
	for (int i = 0; i < bodyList.size(); i++) {
		Point acceleration = calculateSingleBodyAcceleration(bodyList, i);

		bodyList[i].Velocity.x += (acceleration.x * time_step);
		bodyList[i].Velocity.y += (acceleration.y * time_step);
		bodyList[i].Velocity.z += (acceleration.z * time_step);
	}

}

void updatePosition(std::vector<body> bodyList, float time_step) {
	for (int i = 0; i < bodyList.size(); i++) {
		bodyList[i].Position.x += (bodyList[i].Velocity.x * time_step);
		bodyList[i].Position.y += (bodyList[i].Velocity.y * time_step);
		bodyList[i].Position.z += (bodyList[i].Velocity.z * time_step);

	}
}

void massEffect(std::vector<body> bodyList, float time_step) {
	
	updateVelocity(bodyList, time_step);
	updatePosition(bodyList, time_step);
}




int main() {

	


}