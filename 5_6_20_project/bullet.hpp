#include<SFML/Graphics.hpp>
#include<iostream>
class Bullet {
	private:
		bool active;

	public:
		sf::CircleShape shape;
		Bullet();
		void Shoot();
		void MakeActive();
		void MakeInactive();
		bool GetActive();	
};
