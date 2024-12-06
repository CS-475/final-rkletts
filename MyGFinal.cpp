#include <memory>
std::unique_ptr<MyGFinal> GCreateFinal() {
	return std::make_unique<MyFinal>();
}
