#include <MSGL/MSGL_CORE/Input.h>

#include <vector>
#include <algorithm>

using msgl::core::Input;
using msgl::core::KeyListener;
using msgl::core::ButtonListener;
using msgl::core::Vec2;

//Declarations
bool Input::keys[MAX_KEYS];
bool Input::buttons[MAX_BUTTONS];
Input* Input::INSTANCE;
Vec2 Input::mousePos;
std::vector<KeyListener*> Input::keyListeners;
std::vector<ButtonListener*> Input::buttonListeners;

Input::Input()
{
	for (int i = 0; i < MAX_KEYS; ++i) {
		keys[i] = 0;
	} for (int i = 0; i < MAX_BUTTONS; ++i) {
		buttons[i] = 0;
	}
	mousePos = Vec2(0, 0);

	keyListeners = std::vector<KeyListener*>();
	buttonListeners = std::vector<ButtonListener*>();
}

void Input::setCallbacks(GLFWwindow* window)
{
	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, button_callback);
	glfwSetCursorPosCallback(window, mousePos_callback);
}

Input::~Input()
{
}

Input& Input::getInstance() //NOT THREAD SAFE (however it should be called first by Window's constructor)
{
	if(INSTANCE == nullptr)
	{
		INSTANCE = new Input();
	}

	return *INSTANCE;
}

void Input::addKeyListener(KeyListener* listener)
{
	keyListeners.push_back(listener);
}

void Input::addButtonListener(ButtonListener* listener)
{
	buttonListeners.push_back(listener);
}
void Input::removeKeyListener(KeyListener* listener)
{
	keyListeners.erase(std::remove(keyListeners.begin(), keyListeners.end(), listener), keyListeners.end());
}
void Input::removeButtonListener(ButtonListener* listener)
{
	buttonListeners.erase(std::remove(buttonListeners.begin(), buttonListeners.end(), listener), buttonListeners.end());
}

void Input::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	switch(action)
	{
		case GLFW_PRESS:
			keys[key] = true;
			for(KeyListener* listener : keyListeners)
			{
				listener->keyPressed(key, mods);
			}
			break;
		case GLFW_RELEASE:
			keys[key] = false;
			for(KeyListener* listener : keyListeners)
			{
				listener->keyReleased(key, mods);
			}
			break;
		case GLFW_REPEAT:
			for(KeyListener* listener : keyListeners)
			{
				listener->keyReleased(key, mods);
			}
			break;
	}
}

void Input::button_callback(GLFWwindow* window, int button, int action, int mods)
{
	switch(action)
	{
		case GLFW_PRESS:
			buttons[button] = true;
			for(ButtonListener* listener : buttonListeners)
			{
				listener->buttonPressed(button, mods);
			}
			break;
		case GLFW_RELEASE:
			buttons[button] = false;
			for(ButtonListener* listener : buttonListeners)
			{
				listener->buttonReleased(button, mods);
			}
			break;
		case GLFW_REPEAT:
			for(ButtonListener* listener : buttonListeners)
			{
				listener->buttonHeld(button, mods);
			}
			break;
	}
}

void Input::mousePos_callback(GLFWwindow* window, double xPos, double yPos)
{
	mousePos = Vec2(xPos, yPos);
}
