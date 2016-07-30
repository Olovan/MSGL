#include <MSGL/msglCore.h>
#include <MSGL/msglGraphics.h>

#include<GL/gl.h>

#include <iostream>

using msgl::core::Vec2;
using msgl::core::Vec2i;
using msgl::graphics::Window;
using msgl::graphics::Sprite;
using msgl::graphics::Texture;
using msgl::graphics::SpriteAnimation;
using msgl::core::Input;

class InputTest : public msgl::core::KeyListener, public msgl::core::ButtonListener
{
public:
	//ButtonListener
	void buttonPressed(int button, int mods)
	{
		if(button == GLFW_MOUSE_BUTTON_1)
		{
			std::cout << "Mouse Coords: " << Input::mousePos.x << ", " << Input::mousePos.y << std::endl;
		}
	}
	void buttonReleased(int button, int mods)
	{
	}
	void buttonHeld(int button, int mods)
	{
	}


	//KeyListener
	void keyPressed(int key, int mods)
	{
		if(key == GLFW_KEY_SPACE)
			std::cout << "Space Pressed" << std::endl;
	}
	void keyReleased(int key, int mods)
	{
	}
	void keyHeld(int key, int mods)
	{
	}
};


int main(int argc, char *argv[])
{
	Window window;
	window.setOrtho(-10, 10, (double)-(window.height/(double)window.width) * 10, ((double)window.height/(double)window.width) * 10, -10, 10);

	Texture tex("images/Spaceman.png");
	//SpriteAnimation anim;

	//anim.loadFromFile("images/TestSpriteSheet.png", 1, 6, 6, Vec2(2, 2));
	//anim.frameRate = 6;
	
	//Load up Images from Sprite Sheet and put them into Animation
	std::vector<Sprite*> sprites = msgl::core::loadFromFile(argv[1]);
	SpriteAnimation anim2;
	anim2.frameRate = 8;
	for(Sprite* sprite : sprites)
	{
		sprite->position = Vec2(-5, -5);
		sprite->size = Vec2(5, 5);
		sprite->setOrigin(sprite->origin);
		anim2.addFrame(sprite);
	}

	Sprite sprite(Vec2(-2, 0), Vec2(3, 3), &tex);

	Input::addKeyListener(new InputTest);
	Input::addButtonListener(new InputTest);

	while(!window.shouldClose())
	{
		window.clear();

		//anim.update(0.016);
		anim2.update(0.016);

		//Draw calls
		sprite.draw();
		//anim.currentFrame->draw();
		anim2.currentFrame->draw();

		window.swapBuffer();

		window.pollEvents();
	}

	return 0;
}
