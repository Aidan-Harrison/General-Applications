#include "Collision.h"

bool Collision::Check(Collision& otherCol) {
	if (col.getPosition().x < otherCol.col.getPosition().x + otherCol.col.getSize().x && col.getSize().x + otherCol.col.getSize().x > otherCol.col.getPosition().x
		&& col.getPosition().y < otherCol.col.getPosition().y + otherCol.col.getSize().y && col.getSize().y + otherCol.col.getSize().y > otherCol.col.getPosition().y) {
		return true;
	}
}