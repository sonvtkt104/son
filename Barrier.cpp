#include "Barrier.h"
#include "CommonFunc.h"

Barrier::Barrier()
{
	rect_.x = SCREEN_WIDTH;
	rect_.y = SCREEN_HEIGHT*0.5;
	rect_.w = WIDTH_BARRIER;
	rect_.h = HEIGHT_BARRIER;
	x_val_ = 0;
	y_val_ = 0;

}

Barrier::~Barrier()
{

}

void Barrier::HandleMove(const int& x_bordr, const int& y_bordr)
{
	rect_.x -= x_val_;
	if (rect_.x < 0)
	{
		rect_.x = SCREEN_WIDTH;
		int rand_y = rand() % 500;
		rect_.y = rand_y;
	}
}



