#include "monty.h"

/**
 * getGlobalMonty - a singleton to store data to be used between functions
 * Return: itself with it's data
 */

GlobalMonty *getGlobalMonty()
{
	static GlobalMonty Monty = {0};

	return (&Monty);
}
