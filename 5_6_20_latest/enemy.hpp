#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
class Enemy {
	private:
		sf::Texture enemytex;
		int health;
		sf::Vector2f enemypos;
		int speed;
		sf::Clock fireRate;
		sf::Time timeToFire;
		sf::Time timeMax;
		bool dead;	
	public:
		sf::Sprite enemysprt;
		Enemy();
		void Attack();
		void IsHit();
		void IsDead();
		void Move();
	//	std::vector<Bullet> BulletVec;	
		int GetHealth();
		bool GetDead();
};
