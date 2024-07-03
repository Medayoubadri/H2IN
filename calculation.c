#include "calculation.h"

// Function to calculate water intake based on gender, age, weight, and activity level
float calculateWaterIntake(char gender, int age, float weight, char activityLevel)
{
	float baseWaterIntake = weight * 0.033;  // A common guideline is 33 ml per kg of body weight

	// Adjust based on activity level
	if (activityLevel == 'L' || activityLevel == 'l')
	{
		baseWaterIntake *= 1.0;  // No change for low activity
	}
	else if (activityLevel == 'M' || activityLevel == 'm')
	{
		baseWaterIntake *= 1.2;  // 20% more for medium activity
	}
	else if (activityLevel == 'H' || activityLevel == 'h')
	{
		baseWaterIntake *= 1.5;  // 50% more for high activity
	}

	return baseWaterIntake;
}
