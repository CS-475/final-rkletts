#include "myGFinal.h"
#include <cmath>




namespace {
    std::shared_ptr<GPath> final_addStrokedLine(GPoint p0, GPoint p1, float width, bool roundCap) {
        float slope = (p1.y - p0.y) / (p1.x - p0.x);
        float perp = -1 / slope;


        float corner_angle = atan(perp);


        float corner_dx = cos(corner_angle) * width / 2;
        float corner_dy = sin(corner_angle) * width / 2;


        GPoint c0 = {p0.x + corner_dx, p0.y + corner_dy};
        GPoint c1 = {p0.x - corner_dx, p0.y - corner_dy};
        GPoint c2 = {p1.x - corner_dx, p1.y - corner_dy};
        GPoint c3 = {p1.x + corner_dx, p1.y + corner_dy};


        GPathBuilder builder;
        builder.moveTo(c0);
        builder.lineTo(c1);
        builder.lineTo(c2);
        builder.lineTo(c3);


        return builder.detach();
    }
}

// MyGFinal::MyGFinal() = default;


// MyGFinal::~MyGFinal() = default;


std::shared_ptr<GShader> MyGFinal::createVoronoiShader(const GPoint points[], const GColor colors[], int count) {
    return nullptr;
}
std::shared_ptr<GPath> MyGFinal::strokePolygon(const GPoint points[], int count, float width, bool isClosed) {
    if (count < 2) return nullptr;
   
    GPathBuilder builder;
    float halfWidth = width/2;


    auto getNormal = [](GPoint p0, GPoint p1, float scale) -> std::pair<float, float> {
        float dx = p1.x - p0.x;
        float dy = p1.y - p0.y;
        float len = sqrt(dx*dx + dy*dy);
        if (len == 0) return {0, 0};
        return {(-dy / len) * scale, (dx / len) * scale};
    };


    auto [nx, ny] = getNormal(points[0], points[1], halfWidth);
    builder.moveTo({points[0].x + nx, points[0].y + ny});


    for (int i = 0; i < count - 1; i++) {
        GPoint curr = points[i];
        GPoint next = points[i + 1];
       
        auto [nx1, ny1] = getNormal(curr, next, halfWidth);
       
        builder.lineTo({next.x + nx1, next.y + ny1});
    }


    for (int i = count - 1; i > 0; i--) {
        GPoint curr = points[i];
        GPoint prev = points[i - 1];
       
        auto [nx, ny] = getNormal(prev, curr, halfWidth);
        builder.lineTo({curr.x - nx, curr.y - ny});
    }


    if (isClosed) {
        GPoint first = points[0];
        GPoint last = points[count-1];
        auto [nx, ny] = getNormal(last, first, halfWidth);
        builder.lineTo({first.x + nx, first.y + ny});
    } else {
        auto [nx, ny] = getNormal(points[0], points[1], halfWidth);
        builder.lineTo({points[0].x + nx, points[0].y + ny});
    }


    return builder.detach();
}


std::unique_ptr<GFinal> GCreateFinal() {
    return std::make_unique<MyGFinal>();
}