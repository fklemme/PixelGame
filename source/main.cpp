#include <filesystem>
#include <memory>

#include "olcPixelGameEngine.hpp"

// Override base class with your custom functionality
class PixelGame : public olc::PixelGameEngine {
  public:
    PixelGame() { sAppName = "PixelGame"; }

  public:
    bool OnUserCreate() override {
        // Called once at the start, so create things here
        if (!std::filesystem::is_regular_file("resources/olc_pge2_logo.png")) return false;
        olc_pge2_logo = std::make_unique<olc::Sprite>("resources/olc_pge2_logo.png");

        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override {
        auto border = 5;

        auto logo_xoffset = ScreenWidth() - olc_pge2_logo->width - border;
        auto logo_yoffset = ScreenHeight() - olc_pge2_logo->height - border;
        DrawSprite(logo_xoffset, logo_yoffset, olc_pge2_logo.get());

        DrawString(logo_xoffset - 8 * 11, ScreenHeight() - (olc_pge2_logo->height + 8) / 2 - border, "Powered by");

        return true;
    }

  private:
    std::unique_ptr<olc::Sprite> olc_pge2_logo;
};

int main() {
    PixelGame game;
    game.Construct(640, 360, 2, 2);
    game.Start();
    return EXIT_SUCCESS;
}