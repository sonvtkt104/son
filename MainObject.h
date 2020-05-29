
#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include "BaseObject.h"
#include "CommonFunc.h"

#define WIDTH_MAIN_OBJECT 220
#define HEIGHT_MAIN_OBJECT 100


class MainObject : public BaseObject
{
public:
	MainObject();
	~MainObject();

	void HandleInputAction(SDL_Event events);
	void HandleMove();

private:
	int x_val_;
	int y_val_;
       
};



#endif