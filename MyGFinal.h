#ifndef MyGFinal_DEFINED
#define MyGFinal_DEFINED

#include "include/GFinal.h"

class MyFinal : public GFinal {
public:
    std::shared_ptr<GShader> createVoronoiShader(const GPoint points[], const GColor colors[], int count) override;
};

#endif
