#include <MSGL/MSGL_GRAPHICS/Sprite.h>

#include <iostream>
#include <cstring>

using msgl::core::Vec2;
using msgl::core::Vec2i;
using msgl::graphics::Sprite;
using msgl::graphics::Texture;

Sprite::Sprite() : Sprite::Sprite(1, 1, nullptr)
{
}

Sprite::Sprite(float width, float height, Texture* texture) : Sprite::Sprite(0, 0, width, height, texture)
{
}

Sprite::Sprite(float x, float y, float width, float height, Texture* texture) : Sprite::Sprite(Vec2(x, y), Vec2(width, height), texture)
{

}

Sprite::Sprite(Vec2 pos, Vec2 size, Texture* texture) 
{
	this->position = pos;
	this->size = size;
	this->texture = texture;
	this->z = 0;
	
	setOrigin(Vec2(0, 0));
	setColor(255, 255, 255, 255);
	if(texture != nullptr)
		setTexture(texture);
}

void Sprite::draw()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glAlphaFunc(GL_GREATER, 0.2);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_INDEX_ARRAY);

	//Move and rotate
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(position.x, position.y, z);

	//Bind data
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glColorPointer(4, GL_UNSIGNED_BYTE, 0, colors);

	if(texture != nullptr) //Only Do Texture stuff if Texture is available
	{
		texture->bind();
		glEnable(GL_TEXTURE_2D);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glMatrixMode(GL_TEXTURE); //Normalize pixel coords
		glPushMatrix();
		glLoadIdentity();
		if(flipTexture)
			glScaled(1/(double)texture->width, -1/(double)texture->height, 1);
		else
			glScaled(1/(double)texture->width, 1/(double)texture->height, 1);
		glTexCoordPointer(2, GL_INT, 0, texCoords);
	}

	//Draw
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, indices);

	//Cleanup Matricies and bound data
	texture->unbind();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	if(texture != nullptr)
	{
		glMatrixMode(GL_TEXTURE);
		glPopMatrix();
	}
}

void Sprite::setOrigin(Vec2 origin)
{
	this->origin = origin;
	float tmp[] = {
		-origin.x,	 -origin.y,	  z,
		size.x-origin.x, -origin.y,	  z,
		-origin.x,	 size.y-origin.y, z,
		size.x-origin.x, size.y-origin.y, z,
	};

	for (int i = 0; i < 12; ++i) {
		vertices[i] = tmp[i];
	}
}

void Sprite::setTexture(Texture* texture)
{
	setTexture(texture, Vec2i(0, 0), Vec2i(texture->width, texture->height));
}

void Sprite::setTexture(Texture* texture, Vec2i coords, Vec2i size)
{
	if(!(coords.isPositive() && size.isPositive()))
	{
		std::cout << "Negative Texture Coords/Size" << std::endl;
		return;
	}
	this->texture = texture;

	int tmp[] = {
		coords.x, 		coords.y + size.y,
		coords.x + size.x, 	coords.y + size.y,
		coords.x, 		coords.y,
		coords.x + size.x, 	coords.y,
	};
	std::memcpy(texCoords, tmp, sizeof(texCoords));
}

void Sprite::setColor(byte r, byte g, byte b, byte a)
{
	byte tmp[] = {
		r, g, b, a,
		r, g, b, a,
		r, g, b, a,
		r, g, b, a,
	};
	std::memcpy(colors, tmp, sizeof(colors));
}
