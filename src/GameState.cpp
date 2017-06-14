/*
Copyright (c) 2017 InversePalindrome
Memento Mori - GameState.cpp
InversePalindrome.com
*/


#include "GameState.hpp"
#include "StateMachine.hpp"
#include "SpriteComponent.hpp"
#include "VelocityComponent.hpp"


GameState::GameState(StateMachine& stateMachine, SharedData& sharedData) :
	State(stateMachine, sharedData),
	entityManager(systemManager, sharedData.textures),
	systemManager()
{
	systemManager.setEntityManager(entityManager);
}

void GameState::handleEvent(const sf::Event& event)
{
	if (sharedData.keyBindings.isActive(KeyBindings::ActionID::Escape))
	{
		stateMachine.pushState(StateMachine::StateID::Pause);
	}

	this->systemManager.handleEvent();
}

void GameState::update(sf::Time deltaTime)
{
	this->systemManager.update(deltaTime);
}

void GameState::draw()
{
	this->systemManager.draw(this->sharedData.window);
}