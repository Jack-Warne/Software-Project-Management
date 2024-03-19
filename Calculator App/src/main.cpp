
#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main() {
	//	A variation of the OpenFrameworks code for starting a window. This one also prevents the window from being resized
	ofGLFWWindowSettings settings;
	settings.resizable = false;
	settings.setSize(1024, 768);
	ofCreateWindow(settings);

	return ofRunApp(new ofApp);
}