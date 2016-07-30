#ifndef INPUT_H_CLI6EYG7
#define INPUT_H_CLI6EYG7


#include <MSGL/MSGL_GRAPHICS/Window.h>
#include <MSGL/MSGL_CORE/Vec2.h>
#include <MSGL/MSGL_CORE/KeyListener.h>
#include <MSGL/MSGL_CORE/MouseListener.h>
#include <MSGL/MSGL_CORE/ButtonListener.h>

#include <GLFW/glfw3.h>

#include <vector>


namespace msgl { namespace core {

class Input
{
friend class msgl::graphics::Window;

private:
	static Input *INSTANCE; 
	static const int MAX_KEYS = 1024;
	static const int MAX_BUTTONS = 128;
	static std::vector<KeyListener*> keyListeners;
	static std::vector<ButtonListener*> buttonListeners;
	static void setCallbacks(GLFWwindow* window);
	static void key_callback(GLFWwindow* window, int key, int scancode, int actions, int mods);
	static void button_callback(GLFWwindow* window, int button, int action, int mods);
	static void mousePos_callback(GLFWwindow* window, double xPos, double yPos);
	Input ();
	/* data */
public:
	virtual ~Input ();
	static Input& getInstance();
	static bool keys[MAX_KEYS];
	static bool buttons[MAX_BUTTONS];
	static Vec2 mousePos;
	static void addKeyListener(KeyListener *listener);
	static void addButtonListener(ButtonListener *listener);
	static void removeKeyListener(KeyListener *listener);
	static void removeButtonListener(ButtonListener *listener);

protected:
};

}} //NAMESPACE


#endif /* end of include guard: INPUT_H_CLI6EYG7 */
