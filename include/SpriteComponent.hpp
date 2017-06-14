/*
Copyright (c) 2017 InversePalindrome
Memento Mori - SpriteComponent.hpp
InversePalindrome.com
*/


#pragma once

#include "Component.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class SpriteComponent : public Component
{
public:
	SpriteComponent();

	sf::Sprite& getSprite();

	void updatePosition(sf::Vector2f position);
	void draw(sf::RenderWindow& window);

	sf::FloatRect getLocalBounds() const;

	void setTexture(const sf::Texture& texture);
	void setTextureRect(const sf::IntRect& rect);

	void setScale(sf::Vector2f scale);

private:
	sf::Sprite sprite;
};
