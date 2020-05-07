#include"bullet.hpp"


Bullet::Bullet() {
	shape.setRadius(10);
	shape.setFillColor(sf::Color::Red);
	active = 0;
}
//moves the bullet to the right when this is called
void Bullet::Shoot() {
//	std::cout << "Debug: moving bullet" << std::endl;
	shape.move(10,0);
}
//controls whether the bullet is shot from the player
void Bullet::MakeActive() {active = 1;}

//controls when the bullet disappears from the game window
void Bullet::MakeInactive() {active = 0;}

//gets the condition of the bullet
bool Bullet::GetActive() {return active;}
