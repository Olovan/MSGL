#include <MSGL/MSGL_GRAPHICS/Texture.h>

#define STB_IMAGE_IMPLEMENTATION
#include <MSGL_3RD_PARTY/stb_image.h>

#include <GL/gl.h>
#include <iostream>

using msgl::graphics::Texture;

Texture::Texture()
{
	id = 0;
	comp = 0;
	width = 0;
	height = 0;
}

Texture::Texture(std::string fileName)
{
	GLubyte* data = stbi_load(fileName.c_str(), &width, &height, &comp, STBI_rgb_alpha);
	if(data == nullptr)
	{
		std::cout << "Texture " << fileName << " was unable to be loaded into Memory" << std::endl;
		id = 0;
		return;
	}
	glGenTextures(1, &id);

	bind();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	unbind();

	delete(data); //Clean up File Data

	this->fileName = fileName;
}

void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, id);
}

void Texture::unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
