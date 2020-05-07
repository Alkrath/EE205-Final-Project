#include"enemy.hpp"
using namespace std;

//enemy class constructor
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
//	BulletVec.resize(100);
	timeMax = sf::seconds(0.5f);
	timeToFire = fireRate.restart();
}
//waits for specific time to fire a bullet, then grabs the first inactive bullet to make it active
void Enemy::Attack() {
/*
	if(fireRate.getElapsedTime() == timeMax) {
		timeToFire = fireRate.restart();
		for(int i = 0; i < BulletVec.size(); ++i) {
			if((BulletVec[i].shape.getPosition().x) > -20) {
               	 	//      std::cout << "removing bullet" << std::endl;
                        	BulletVec[i].MakeInactive();
                	}
                	else if (BulletVec[i].GetActive() == 0) {
                        	BulletVec[i].shape.setPosition(enemysprt.getPosition());
                        	BulletVec[i].MakeActive();
                        	break;
                	}
	
		}
	}
*/
}
//test for bullet collision in main program, call if true
void Enemy::IsHit() {
//	std::cout << "boss is hit" << std::endl;
	health = health - 10;
	if (health == 0) {
		this->IsDead();
	}
}

//called if enemy health is 0, sets death condition to true
void Enemy::IsDead() {
	std::cout << "You Win" << std::endl;
	dead = 1;
}

//moves the enemy sprite at a constant speed, back and forth at the end of the screen
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

bool Enemy::GetDead() {return dead;}
