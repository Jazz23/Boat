#pragma once

#define MAX_EFFECTS 50 //set this corrrectly
class ConditionEffects
{
private:
	bool effects[MAX_EFFECTS+1] = { false };
public:
	bool hasEffect(size_t effect)
	{
		if (effect <= MAX_EFFECTS)
			return effects[effect];
	}
	void addEffect(size_t effect)
	{
		if (effect <= MAX_EFFECTS)
			effects[effect] = true;
	}
	void removeEffect(size_t effect)
	{
		if (effect <= MAX_EFFECTS)
			effects[effect] = false;
	}
};