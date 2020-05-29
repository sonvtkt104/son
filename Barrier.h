#pragma once
#ifndef Barrier_H_
#define Barrier_H_

#include "CommonFunc.h"
#include "BaseObject.h"

#define WIDTH_BARRIER 180
#define HEIGHT_BARRIER 59

class Barrier: public BaseObject
{
public:
	Barrier();
	~Barrier();
	void HandleMove(const int& x_bordr, const int& y_bordr);

	void set_x_xal(const int& val) { x_val_ = val; }
	void set_y_val(const int& val) { y_val_ = val; }
	int get_x_val() const { return x_val_; }
	int get_y_val() const { return y_val_; }

private:
	int x_val_;
	int y_val_;

};



#endif // Barrier_H_

