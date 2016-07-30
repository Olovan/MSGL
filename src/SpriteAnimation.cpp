#include <MSGL/MSGL_GRAPHICS/SpriteAnimation.h>

#include <string>

using msgl::graphics::SpriteAnimation;
using msgl::graphics::Sprite;
using msgl::graphics::Texture;
using msgl::core::Vec2;
using msgl::core::Vec2i;

//PRIVATE HELPER METHODS
bool validSpriteSheet(Texture* texture, unsigned int rows, unsigned int cols, unsigned int numFrames, Vec2 size)
{
	if(numFrames > rows * cols)
	{
		std::cout << "ERROR: Sprite Sheeet numFrames too high" << std::endl;
		return false;
	}
	else if(!size.isPositive())
	{
		std::cout << "ERROR: Sprite Sheet Size is Negative" << std::endl;
		return false;
	}
	else if(texture->width % cols != 0)
	{
		std::cout << "ERROR: Sprite Sheet texture Width is not evenly divisible by Cols" << std::endl;
		return false;
	}
	else if(texture->height % rows != 0)
	{
		std::cout << "ERROR: Sprite Sheet texture Height is not evenly divisible by Rows" << std::endl;
		return false;
	}


	return true;
}



//PUBLIC API
SpriteAnimation::SpriteAnimation()
{
}

void SpriteAnimation::update(double deltaTime)
{
	timeToNextFrame -= deltaTime;
	while(timeToNextFrame <= 0)
	{
		currentFrameIndex++;
		timeToNextFrame += (double)1 / (double)frameRate;
	}

	currentFrameIndex %= frames.size();
		
	currentFrame = frames[currentFrameIndex];
}

bool SpriteAnimation::loadFromFile(std::string fileName, unsigned int rows, unsigned int cols, unsigned int numFrames, Vec2 size)
{
	Texture* texture = new Texture(fileName);
	if(loadFromTexture(texture, rows, cols, numFrames, size))
		return true;
	return false;
}

bool SpriteAnimation::loadFromTexture(Texture* texture, unsigned int rows, unsigned int cols, unsigned int numFrames, Vec2 size)
{
	if(!validSpriteSheet(texture, rows, cols, numFrames, size))
		return false;


	for (int i = 0; i < numFrames; ++i) 
	{
		Sprite* frame = new Sprite(Vec2(0, 0), size, nullptr);
		int xSize = texture->width / cols; 
		int ySize = texture->height / rows;
		int xOffset = xSize * (i % cols);
		int yOffset = ySize * (i / cols);

		frame->setTexture(texture, Vec2i(xOffset, yOffset), Vec2i(xSize, ySize));
		frames.push_back(frame);
	}

	return true;
}

void SpriteAnimation::addFrame(Sprite* frame)
{
	frames.push_back(frame);
}


