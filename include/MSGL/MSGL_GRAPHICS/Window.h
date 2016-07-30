#ifndef WINDOW_H_B5XJVNTJ
#define WINDOW_H_B5XJVNTJ

#include <GLFW/glfw3.h>
#include <string>

namespace msgl { namespace graphics {

struct Window{
	GLFWwindow* id;
	unsigned int width, height;
	std::string title;

	Window();
	Window(unsigned int width, unsigned int height, std::string title);
	bool shouldClose();
	void resize(unsigned int width, unsigned int height);
	void pollEvents();
	void clear();
	void swapBuffer();
	void setOrtho(double left, double right, double bottom, double top, double near, double far);

	static void resizeCallback(GLFWwindow *window, int width, int height);
};

}} //NAMESPACE


#endif /* end of include guard: WINDOW_H_B5XJVNTJ */
