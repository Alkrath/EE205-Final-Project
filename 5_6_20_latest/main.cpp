#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>
#include"player.hpp"
#include"enemy.hpp"
int main() {
	//create window
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Battle of The Twitch Emotes");
	window.setFramerateLimit(60);
	//background images
	sf::Texture ground;
	sf::Sprite bg;
	sf::Sprite bg2;
	float bgspeed = -6;

	ground.loadFromFile("twitchchat.png");
	bg.setTexture(ground);
	bg2.setTexture(ground);
	bg.setScale(4, 1);
	bg2.setScale(4, 1);
	bg.setPosition(0,0);
	bg2.setPosition(0,714);
	
	//initialize health bar
	int healthx = 600;
	int healthMax = 600;
	int healthy = 35;
	sf::RectangleShape healthBar;
	sf::RectangleShape healthBarBG;
	healthBar.setSize(sf::Vector2f(healthx, healthy));
	healthBar.setFillColor(sf::Color::Green);
	healthBarBG.setSize(sf::Vector2f(healthx, healthy));
	healthBarBG.setFillColor(sf::Color::Red);
	
//	initialize power ups on screen
	sf::RectangleShape speedBuff;
	speedBuff.setSize(sf::Vector2f(75, 75));
	speedBuff.setFillColor(sf::Color::Blue);
	speedBuff.setPosition(800, 700);

	sf::RectangleShape healthBuff;
	healthBuff.setSize(sf::Vector2f(75, 75));
	healthBuff.setFillColor(sf::Color::Green);
	healthBuff.setPosition(500, 700);	
	
	//player and boss constructed
	Player player;
	Enemy boss;

	//Start main game loop
	while(window.isOpen()) {
	//while game window is active check for kb or mouse action
		sf::Event event;
		while(window.pollEvent(event)){
			switch(event.type)
			{
				case sf::Event::Closed: 
					window.close();
					break;
				case sf::Event::KeyPressed:
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
						{
							player.SetDirection(event.key.code);
							player.Move();
							window.draw(player.playersprt);
						}
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
						{
							player.SetDirection(event.key.code);
							player.Move();
							window.draw(player.playersprt);
						}
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
						{
							player.SetDirection(event.key.code);
							player.Move();
							window.draw(player.playersprt);
						}
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
						{
							player.SetDirection(event.key.code);
							player.Move();
							window.draw(player.playersprt);
						}
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
						{
							player.Attack();
						}
					break;

			}
		}
	//moves the background and repeats it
		bg.move(0, bgspeed);
		bg2.move(0, bgspeed);
		if (bg.getPosition().y < -714) {
			bg.setPosition(0, 714);
		}
		if(bg2.getPosition().y < -714) {
			bg2.setPosition(0, 714);
		}
		//moves boss every frame with preset movement
		boss.Move();
		//detects collision with player every frame
		if (player.hit) {
			healthx = healthx - 60;
			player.IsHit();
			healthBar.setSize(sf::Vector2f(healthx, healthy));	
		}
		//sets boundaries for the player
		if(player.playersprt.getPosition().x < 0) {
			player.playersprt.setPosition(0, (player.playersprt.getPosition().y));
		}
		if(player.playersprt.getPosition().x > 1282) {
			player.playersprt.setPosition(1200, (player.playersprt.getPosition().y));
			player.hit = 1;
		}
		if(player.playersprt.getPosition().y < 0) {
			player.playersprt.setPosition((player.playersprt.getPosition().x), 0);
		}
		if(player.playersprt.getPosition().y > 558) {
			player.playersprt.setPosition((player.playersprt.getPosition().x), 558);
		}

		//checks if player dies
		if(player.GetHealth() == 0) {
			std::cout << "player ded" << std::endl;
		}

		// check player bullets collision on enemy, if there is, enemy takes damage
	        for (int j = 0; j < player.BulletVec.size(); j++) {
                	if (player.BulletVec[j].shape.getGlobalBounds().intersects(boss.enemysprt.getGlobalBounds())) {
                        	if(player.BulletVec[j].GetActive() == 1) {
				player.BulletVec[j].MakeInactive();
                        	boss.IsHit();
                        	}
                        }
        	}
		//checks condition of the enemy, if dead, lay them sideways
		if(boss.GetDead() == 1) {
			boss.enemysprt.setRotation(90);
		}
		//continually check for whether the player touches the buffs
		player.PowerUpSpeed(speedBuff);
		player.HealthUp(healthBuff, healthx);
			
	//clears window
		window.clear();
	
	//refreshes display of everything
		window.draw(bg);
		window.draw(bg2);
		window.draw(healthBarBG);
		window.draw(healthBar);
		window.draw(player.playersprt);
		window.draw(boss.enemysprt);
		window.draw(speedBuff);
		window.draw(healthBuff);
		 //check through each bullet in the player bullet vector, if active, then draw
                for(int count = 0; count < player.BulletVec.size(); ++count) {
                        if (player.BulletVec[count].GetActive() == 1){
			//	std::cout << "Debug: drawing and moving bullet" << std::endl;
				player.BulletVec[count].Shoot();
                                window.draw(player.BulletVec[count].shape);
			}
                }

		window.display();
	}
}
