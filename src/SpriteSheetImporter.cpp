#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include <MSGL/MSGL_GRAPHICS/Sprite.h>
#include <MSGL/MSGL_CORE/StringUtils.h>
#include <MSGL/MSGL_CORE/Vec2i.h>
#include <MSGL/MSGL_CORE/SpriteSheetImporter.h>

using std::string;
using std::getline;
using std::vector;
using std::ifstream;
using std::istringstream;
using msgl::core::Vec2i;
using msgl::graphics::Sprite;
using msgl::graphics::Texture;

Texture* texture;

static void parseLine(string line, vector<Sprite*> &sprites)
{
	vector<std::string> words = msgl::core::splitString(line.c_str(), " ");
	if(words[0].empty())
	{
		return;
	}
	if(words[0].compare("Filename") == 0)
	{
		texture = new Texture(words[1]);
	}
	else if(words[0].compare("Sprite") == 0)
	{
		vector<string> coords = msgl::core::splitString(words[1], ",");
		Vec2i position;
		istringstream(coords[0]) >> position.x;
		istringstream(coords[1]) >> position.y;

		vector<string> sizes = msgl::core::splitString(words[2], ",");
		Vec2i size;
		istringstream(sizes[0]) >> size.x;
		istringstream(sizes[1]) >> size.y;

		Sprite* sprite = new Sprite();
		sprite->setTexture(texture, position, size);
		sprites.push_back(sprite);

	}
}


vector<Sprite*> msgl::core::loadFromFile(std::string fileName)
{
	vector<Sprite*> sprites;
	std::ifstream fileStream(fileName);

	string line;
	while(std::getline(fileStream, line))
	{
		parseLine(line, sprites);
	}

	fileStream.close();

	return sprites;
}
