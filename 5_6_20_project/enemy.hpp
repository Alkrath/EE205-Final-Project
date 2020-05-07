#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
class Enemy {
	private:
		sf::Texture enemytex;
		int health;
		sf::Vector2f enemypos;
		int speed;	
	public:
		sf::Sprite enemysprt;
		bool dead;
		Enemy();
		void Attack();
		void IsHit();
		void IsDead();
		void Move();
		std::vector<Bullet> BulletVec;	
		int GetHealth();
};
