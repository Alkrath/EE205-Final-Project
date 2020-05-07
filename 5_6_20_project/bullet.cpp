#include"bullet.hpp"


Bullet::Bullet() {
	shape.setRadius(10);
	shape.setFillColor(sf::Color::Red);
	active = 0;
}

void Bullet::Shoot() {
//	std::cout << "Debug: moving bullet" << std::endl;
	shape.move(10,0);
}

void Bullet::MakeActive() {active = 1;}

void Bullet::MakeInactive() {active = 0;}

bool Bullet::GetActive() {return active;}
