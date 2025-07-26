#include <OGL3D/Game/OGame.h>
#include <iostream>

int main() {
    try {
        OGame game;
        game.run();
    }
    catch (const std::exception& e) {
        std::clog << "Exception: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}
