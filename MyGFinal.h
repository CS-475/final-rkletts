#ifndef MyGFinal_DEFINED
#define MyGFinal_DEFINED
 

#include "include/GFinal.h"
#include "include/GPath.h"
#include "include/GPathBuilder.h"
#include "include/GShader.h"


class MyGFinal : public GFinal {
public:
    std::shared_ptr<GShader> createVoronoiShader(const GPoint points[],
                                                const GColor colors[],
                                                int count) override;


    std::shared_ptr<GPath> strokePolygon(const GPoint[], int count,
                                        float width, bool isClosed) override;


    ~MyGFinal() override = default;
};


#endif
