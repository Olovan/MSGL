#ifndef SPRITE_H_OTXGR3W0
#define SPRITE_H_OTXGR3W0


#include <MSGL/MSGL_CORE/Vec2.h>
#include <MSGL/MSGL_CORE/Vec2i.h>
#include <MSGL/MSGL_GRAPHICS/Texture.h>

#include <GL/gl.h>

typedef unsigned char byte; //TODO put this somewhere on its own so it's not floating in my code

namespace msgl { namespace graphics {

class Sprite
{
public:
	core::Vec2 position;
	float z;
	core::Vec2 size;
	core::Vec2 origin;
	Texture* texture;
	bool flipTexture = false;

	Sprite ();
	Sprite (float width, float height, Texture* texture);
	Sprite (float x, float y, float width, float height, Texture* texture);
	Sprite (core::Vec2 pos, core::Vec2 size, Texture* texture);

	void draw();
	void setOrigin(core::Vec2 origin);
	void setTexture(Texture* texture);
	void setTexture(Texture* texture, core::Vec2i coords, core::Vec2i size);
	void setColor(byte r, byte g, byte b, byte a);

private:
	/* data */
	GLuint indices[6] = {
		0, 1, 2,
		2, 1, 3
	};
	float vertices[4 * 3];
	GLubyte colors[4 * 4];
	int texCoords[4 * 2]; 
};

}} //Namespace


#endif /* end of include guard: SPRITE_H_OTXGR3W0 */
