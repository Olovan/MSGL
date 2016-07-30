#ifndef KEYLISTENER_H_Q1MFZZOB
#define KEYLISTENER_H_Q1MFZZOB

namespace msgl { namespace core {

class KeyListener
{
public:
	KeyListener ();
	virtual ~KeyListener ();
	virtual void keyPressed(int key, int mods) = 0;
	virtual void keyReleased(int key, int mods) = 0;
	virtual void keyHeld(int key, int mods) = 0;
private:
	/* data */
};

}} //NAMESPACE


#endif /* end of include guard: KEYLISTENER_H_Q1MFZZOB */
