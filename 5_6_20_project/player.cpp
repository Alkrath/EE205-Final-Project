#include"player.hpp"
#include<iostream>

Player::Player() {
	tex.loadFromFile("pogchamp.png");
	playersprt.setTexture(tex);
	playersprt.setColor(sf::Color(255, 255, 255, 255));
	playersprt.scale(1, 1);
	playersprt.setPosition(0, 300);
	BulletVec.resize(100);
	health = 100;
	direction = stop;
	hit = 0;
	speed = 5;
}

float Player::GetHealth() {return health;}

void Player::Move() {
	switch (this->direction) {
		case left:
			playersprt.move(-speed, 0);
			break;
		case right:
			playersprt.move(speed, 0);
			break;
		case up:
			playersprt.move(0, -speed);
			break;
		case down:
			playersprt.move(0, speed);
			break;
		case stop:
			playersprt.move(0, 0);
			break;
	}
	
}

void Player::SetDirection(sf::Keyboard::Key x) {
	switch(x) {
		case sf::Keyboard::Left:
			direction = left;
			break;
		case sf::Keyboard::Right:
			direction = right;
			break;
		case sf::Keyboard::Down:
			direction = down;
			break;
		case sf::Keyboard::Up:
			direction = up;
			break;
		case sf::Keyboard::Space:
			Attack();
			break;
		case sf::Keyboard::S:
			direction = stop;
			break;
	}
}

//pushes back a bullet onto the vector
//should move bullet with space bar
void Player::Attack() {
//	std::cout << "DEBUG: entering attack function" << std::endl;
	//for every bullet in the vector, look for first inactive bullet, then set active and fire.
	for (int i = 0; i < BulletVec.size(); ++i) {
		if((BulletVec[i].shape.getPosition().x) > 1400) {
		//	std::cout << "removing bullet" << std::endl;
			BulletVec[i].MakeInactive();
		}
		else if (BulletVec[i].GetActive() == 0) {
			BulletVec[i].shape.setPosition(playersprt.getPosition());
			BulletVec[i].MakeActive();
			break;
		}
	}
	
	return;
}

void Player::IsHit() {
	health = health - 10;
	hit = 0;
}

void Player::PowerUpSpeed(sf::RectangleShape buff) {
	if(playersprt.getGlobalBounds().intersects(buff.getGlobalBounds())) {
		std::cout << "Got Speed" << std::endl;
		speed = 10;
	}
}

void Player::HealthUp(sf::RectangleShape buff, int healthbar) {
	if(playersprt.getGlobalBounds().intersects(buff.getGlobalBounds())) {
		std::cout << "Got Health" << std::endl;
                health = 100;
		healthbar = 600; 
        }
}
