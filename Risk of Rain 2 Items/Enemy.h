#ifndef Enemy_h
#define Enemy_h

// Add derived classes
class Enemy {
private:
	int m_EHealth;
public:
	Enemy(short health)
		:m_EHealth(health)
	{
	}
	~Enemy() {};
	inline int GetHealth() const { return m_EHealth; }
};

#endif