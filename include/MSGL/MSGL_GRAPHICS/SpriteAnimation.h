#ifndef SPRITEANIMATION_H_NDGWZFYS
#define SPRITEANIMATION_H_NDGWZFYS

#include <MSGL/MSGL_GRAPHICS/Texture.h>
#include <MSGL/MSGL_GRAPHICS/Sprite.h>

#include <string>
#include <vector>

namespace msgl { namespace graphics {


class SpriteAnimation
{
public:
	bool playing = false;
	double timeToNextFrame;
	unsigned int frameRate = 20;
	unsigned int currentFrameIndex;
	core::Vec2 position;
	std::vector<Sprite*> frames;
	Sprite *currentFrame;

	SpriteAnimation ();

	void update(double deltaTime);
	bool loadFromFile(std::string fileName, unsigned int rows, unsigned int cols, unsigned int numFrames, core::Vec2 size);
	bool loadFromTexture(Texture* texture, unsigned int rows, unsigned int cols, unsigned int numFrames, core::Vec2 size);
	void addFrame(Sprite* frame);

private:
};


}} //NAMESPACE

#endif /* end of include guard: SPRITEANIMATION_H_NDGWZFYS */
