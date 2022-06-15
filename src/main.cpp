#include "Controller.h"
int main() try
{
    Controller gameController;
    gameController.run();
}
catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return EXIT_FAILURE;
}

catch (...) {
    std::cerr << "Unknown exception\n";
    return EXIT_FAILURE;
}