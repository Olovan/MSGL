#ifndef TEXTURE_H_5OGSU3KO
#define TEXTURE_H_5OGSU3KO


#include <GL/gl.h>

#include <iostream>
#include <string>

namespace msgl { namespace graphics {

class Texture
{
public:
	std::string fileName;
	GLuint id;
	int width;
	int height;
	int comp;

	Texture ();
	Texture (std::string fileName);
	void createFromFile(std::string fileName);
	void bind();
	void unbind();

private:
	/* data */
};

}} //Namespaces


#endif /* end of include guard: TEXTURE_H_5OGSU3KO */
