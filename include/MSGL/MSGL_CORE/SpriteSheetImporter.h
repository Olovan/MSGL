#ifndef SPRITESHEETIMPORTER_H_NMSCLXVL
#define SPRITESHEETIMPORTER_H_NMSCLXVL

#include <string>
#include <vector>
#include <MSGL/MSGL_GRAPHICS/Sprite.h>


namespace msgl { namespace core {

extern std::vector<msgl::graphics::Sprite*> loadFromFile(std::string fileName);



}} //NAMESPACE


#endif /* end of include guard: SPRITESHEETIMPORTER_H_NMSCLXVL */
