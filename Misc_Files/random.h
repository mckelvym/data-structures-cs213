#ifndef RANDOM_H

class random_gen
{
	public:
		random_gen();
		int bounds(int low, int high);
		void reset();
};

#define RANDOM_H
#endif