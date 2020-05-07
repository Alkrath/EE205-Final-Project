#include"enemy.hpp"
using namespace std;
Enemy::Enemy() {
	enemytex.loadFromFile("hypers.png");
	enemysprt.setTexture(enemytex);
	enemysprt.setColor(sf::Color(255, 255, 255, 255));
	enemysprt.setScale(0.7, 0.7);
	speed = -6;
	enemysprt.setPosition(1200, 300);
	enemypos = enemysprt.getPosition();
	health = 300;
	dead = 0;
	BulletVec.resize(100);
}

void Enemy::Attack() {

}
//test for bullet collision in main program, call if true
void Enemy::IsHit() {
//	std::cout << "boss is hit" << std::endl;
	health = health - 10;
	if (health == 0) {
		this->IsDead();
	}
}

void Enemy::IsDead() {
	std::cout << "You Win" << std::endl;
}

void Enemy::Move() {
	enemypos.y = enemypos.y + speed;
	enemysprt.setPosition(enemypos.x, enemypos.y);
	if(enemypos.y < 0){
//		cout << "entering reverse function" << endl;
		speed = -speed;
	}
	else if(enemypos.y > 500)
		speed = -speed;

}

int Enemy::GetHealth() {return health;}
