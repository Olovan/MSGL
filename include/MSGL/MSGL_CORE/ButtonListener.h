#ifndef BUTTONLISTENER_H_8BJYTXTZ
#define BUTTONLISTENER_H_8BJYTXTZ


namespace msgl { namespace core {

class ButtonListener
{
public:
	ButtonListener ();
	virtual ~ButtonListener ();
	virtual void buttonPressed(int button, int mods) = 0;
	virtual void buttonHeld(int button, int mods) = 0;
	virtual void buttonReleased(int button, int mods) = 0;
private:
	/* data */
};

}} //NAMESPACE


#endif /* end of include guard: BUTTONLISTENER_H_8BJYTXTZ */
