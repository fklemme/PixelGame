#include "olcPixelGameEngine.hpp"

// Override base class with your custom functionality
class PixelGame : public olc::PixelGameEngine {
  public:
    PixelGame() { 
        // TODO: Show credit to OLC in the game (as part of license)
        sAppName = "PixelGame";
    }

  public:
    bool OnUserCreate() override {
        // Called once at the start, so create things here
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override {
        // Called once per frame, draws random coloured pixels
        for (int x = 0; x < ScreenWidth(); x++)
            for (int y = 0; y < ScreenHeight(); y++)
                Draw(x, y, olc::Pixel(rand() % 256, rand() % 256, rand() % 256));
        return true;
    }
};

int main() {
    PixelGame game;
    game.Construct(192, 108, 4, 4);
    game.Start();
    return EXIT_SUCCESS;
}