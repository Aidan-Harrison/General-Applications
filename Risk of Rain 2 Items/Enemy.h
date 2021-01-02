#ifndef Enemy_h
#define Enemy_h

// Add derived classes
class Enemy {
private:
	int m_EHealth;
public:
	Enemy() = default;
	Enemy(short health)
		:m_EHealth(health)
	{
	}
	~Enemy() = default;
	inline int GetHealth() const { return m_EHealth; }
};

class Beetle : public Enemy {
private:

public:
	Beetle() = default;
	~Beetle() = default;
};

#endif