#pragma once

enum ConditionEffect
{
	Dead = 1 << 0,
	Quiet = 1 << 1,
	Weak = 1 << 2,
	Slowed = 1 << 3,
	Sick = 1 << 4,
	Dazed = 1 << 5,
	Stunned = 1 << 6,
	Blind = 1 << 7,
	Hallucinating = 1 << 8,
	Drunk = 1 << 9,
	Confused = 1 << 10,
	StunImmume = 1 << 11,
	Invisible = 1 << 12,
	Paralyzed = 1 << 13,
	Speedy = 1 << 14,
	Bleeding = 1 << 15,
	NotUsed = 1 << 16,
	Healing = 1 << 17,
	Damaging = 1 << 18,
	Berserk = 1 << 19,
	Paused = 1 << 20,
	Stasis = 1 << 21,
	StasisImmune = 1 << 22,
	Invincible = 1 << 23,
	Invulnerable = 1 << 24,
	Armored = 1 << 25,
	ArmorBroken = 1 << 26,
	Hexed = 1 << 27,
	AnotherSpeedy = 1 << 28,
	Unstable = 1 << 29,
	Darkness = 1 << 30
};

class ConditionEffects
{
private:
	unsigned int effects;
public:
	bool hasEffect(ConditionEffect effect)
	{
		return !!(effects & effect);
	}
	void addEffect(ConditionEffect effect)
	{
		effects |= effect;
	}
	void removeEffect(ConditionEffect effect)
	{
		effects &= ~effect;
	}
};

