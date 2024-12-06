#ifndef MyGFinal_DEFINED
#define MyGFinal_DEFINED

#include "include/GFinal.h"

class MyFinal : public GFinal {
Public:
	std::shared_ptr<GShader> createVoronoiShader(const GPoint ponts[], const GColor colors[], int count) override;
};

#endif
