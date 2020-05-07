#include<SFML/Graphics.hpp>
#include<iostream>
class Bullet {
	private:
		bool active;

	public:
		sf::CircleShape shape;
		Bullet();
		virtual void Shoot();
		void MakeActive();
		void MakeInactive();
		bool GetActive();	
};
