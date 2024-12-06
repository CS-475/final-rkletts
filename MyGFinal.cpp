#include "MyGFinal.h"

std::unique_ptr<GFinal> GCreateFinal() {
    return std::make_unique<MyFinal>();
}
