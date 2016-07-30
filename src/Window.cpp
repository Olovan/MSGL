#include <MSGL/MSGL_GRAPHICS/Window.h>
#include <MSGL/MSGL_CORE/Input.h>
#include <GL/gl.h>

#include <iostream>

using namespace msgl::graphics;
using msgl::core::Input;



Window::Window() : Window::Window(640, 480, "Title")
{
}

Window::Window(unsigned int width, unsigned int height, std::string name)
{
	//Init GLFW
	if(!glfwInit())
	{
		std::cout << "GLFW FAILED TO INIT" << std::endl;
	}
	//Create Window
	if((id = glfwCreateWindow(width, height, name.c_str(), NULL, NULL)) == nullptr)
	{
		std::cout << "Window Creation Failed" << std::endl;
	}
	//Set Window Settings
	this->height = height;
	this->width = width;
	glfwSwapInterval(1);
	glfwMakeContextCurrent(id);
	glfwSetWindowUserPointer(id, this);
	glfwSetWindowSizeCallback(id, Window::resizeCallback);

	//Initialize Projection and Model Matricies
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Set up input 
	Input::getInstance().setCallbacks(id);
}

bool Window::shouldClose()
{
	return glfwWindowShouldClose(id);
}

void Window::resize(unsigned int width, unsigned int height)
{
	glfwSetWindowSize(id, width, height);
	this->height = height;
	this->width = width;
	glViewport(0, 0, width, height);
}

void Window::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::swapBuffer()
{
	glfwSwapBuffers(id);
}

void Window::pollEvents()
{
	glfwPollEvents();
}

void Window::setOrtho(double left, double right, double bottom, double top, double near, double far)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(left, right, bottom, top, near, far);
}

void Window::resizeCallback(GLFWwindow *window, int width, int height)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->width = width;
	win->height = height;
	glViewport(0, 0, width, height);
}
