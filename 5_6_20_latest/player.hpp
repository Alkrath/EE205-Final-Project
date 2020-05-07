#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include"bullet.hpp"
enum Dir {stop, up, down, left, right};

class Player {
	private:
		float health;
		float speed;
		int direction;
			
		
	public:
		//sprite acts as body, handles collision logic
		bool hit;
		sf::Texture tex;
		sf::Sprite playersprt;
		Player(); // constructor
		std::vector<Bullet> BulletVec; //holds a set amount of bullets that the player can shoot
		void Move();
		void SetDirection(sf::Keyboard::Key x);
		void Attack(); //Goes through the vector of bullets to find the first inactive bullet and make its active
		void IsHit();	
		float GetHealth();
		//power ups that affect the player characteristics
		void PowerUpSpeed(sf::RectangleShape buff);
		void HealthUp(sf::RectangleShape buff, int x);
};
