//
//	Created by millefeuille on 18/5/2021
//

#include "Enemy.hpp"

Enemy::Enemy() {}

Enemy::Enemy(const Enemy &src) {
	*this = src;
}

Enemy::Enemy(int hp, const std::string &type)
	: _type(type), _hp(hp) {}

Enemy::~Enemy() {}

Enemy &Enemy::operator=(const Enemy &rhs) {
	if (this == &rhs)
		return *this;
	_hp = rhs.getHp();
	_type = rhs.getType();
	return *this;
}

std::string Enemy::getType() const {
	return _type;
}

int Enemy::getHp() const {
	return _hp;
}

void Enemy::takeDamage(int damages) {
	if (_hp >= damages)
		_hp -= damages;
}
