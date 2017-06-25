/*
Copyright (c) 2017 InversePalindrome
Memento Mori - RoundNumber.cpp
InversePalindrome.com
*/


#include "RoundNumber.hpp"


const std::array<std::pair<std::size_t, std::string>, 13u> RoundNumber::romanNumerals =
{ 
std::make_pair(1000, "M") , std::make_pair(900, "CM") , std::make_pair(500, "D"), std::make_pair(400, "CD"),
std::make_pair(100, "C"), std::make_pair(90, "XC"), std::make_pair(50, "L"), std::make_pair(40, "XL"), 
std::make_pair(10, "X"), std::make_pair(9, "IX"), std::make_pair(5, "V" ), std::make_pair(4, "IV"), std::make_pair(1, "I"), };

RoundNumber::RoundNumber(const sf::Font& font) :
	roundNumberText("I", font, 150u)
{
	roundNumberText.setColor(sf::Color(176u, 7u, 7u, 255));
	roundNumberText.setOutlineThickness(5.f);
	roundNumberText.setOutlineColor(sf::Color::Black);
	roundNumberText.setStyle(sf::Text::Bold);
	roundNumberText.setPosition(sf::Vector2f(2350.f, -10.f));
}

void RoundNumber::update(std::size_t roundNumber)
{
	if (this->roundNumber != roundNumber)
	{
		this->roundNumberText.setString(this->toRomanNumeral(roundNumber));
		this->roundNumber = roundNumber;
	}
}

void RoundNumber::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->roundNumberText);
}

std::string RoundNumber::toRomanNumeral(std::size_t roundNumber)
{
	std::string romanNumeral;

	for (auto& romanNumber : this->romanNumerals)
	{
		while (roundNumber >= romanNumber.first)
		{
			romanNumeral += romanNumber.second;
			roundNumber -= romanNumber.first;
		}
	}

	return romanNumeral;
}