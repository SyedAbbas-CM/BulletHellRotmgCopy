#include "EnviromentObject.h"

const sf::Vector2f& EnviromentObject::getPos() const
{
    return this->sprite.getPosition();
}

const sf::FloatRect EnviromentObject::getbounds() const
{
    return this->sprite.getGlobalBounds();
}

void EnviromentObject::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}

int EnviromentObject::getspriteID()
{
    return this->spriteID;
}
