#include <string>
#include <cmath>
#include <algorithm>

#include <raylib.h>

import features.player;
import features.scene;

import constants;

void Player::draw(float deltaTime) {
	DrawCircle(static_cast<int>(position_.x), static_cast<int>(position_.y), 15, BLACK);
	DrawCircle(static_cast<int>(position_.x), static_cast<int>(position_.y), 13, WHITE);

	if (position_.y >= constants::tile_size * 2) {
		oxygen_ -= 10.0f * deltaTime;
	}
	else {
		oxygen_ += 13.0f * deltaTime;
	}

	oxygen_ = std::clamp(oxygen_, 0.0f, 100.0f);

	std::string oxygenText = "Oxygen: " + std::to_string(static_cast<int>(oxygen_));

	std::string treasureText = "Treasure: $" + std::to_string(treasure_);

	DrawText(oxygenText.data(), 10, 10, 25, BLACK);
	DrawText(treasureText.data(), 10, 40, 25, BLACK);
}

int Player::getTreasure() {
	return treasure_;
}

float Player::getOxygen() {
	return oxygen_;
}

scene::Tile Player::getTile() {
	return {
		static_cast<int>(std::floor(position_.x / constants::tile_size)),
		static_cast<int>(std::floor(position_.y / constants::tile_size))
	};
}

void Player::addTreasure(int value) {
	treasure_ += value;
}

void Player::addX(float x) {
	if (position_.x <= 18 && x < 0) {
		return;
	}
	else if (position_.x >= constants::window::x - 18 && x > 0) {
		return;
	}
	position_.x += x;
}

void Player::addY(float y) {
	if (position_.y <= 18 && y < 0) {
		return;
	}
	else if (position_.y >= constants::window::y - 18 && y > 0) {
		return;
	}
	position_.y += y;
}