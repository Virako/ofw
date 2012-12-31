#include <irrlicht.h>
#include "driverChoice.h"

using namespace irr;

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

int main()
{
    // ask user for driver
    video::E_DRIVER_TYPE driverType=driverChoiceConsole();
    if (driverType==video::EDT_COUNT)
        return 1;

    IrrlichtDevice* device = createDevice(driverType,
            core::dimension2d<u32>(640, 480), 16, false, false, false, NULL);
    if (device == 0)
        return 1; // could not create selected driver.

    device->setWindowCaption(L"OFW");

    video::IVideoDriver* driver = device->getVideoDriver();
    scene::ISceneManager* smgr = device->getSceneManager();
    gui::IGUIEnvironment* guienv = device->getGUIEnvironment();

    while(device->run())
    {
        driver->beginScene(true, true, video::SColor(255,113,113,133));
        smgr->drawAll();
        guienv->drawAll(); // draw the gui environment (the logo)
        driver->endScene();
    }
    device->drop();
    return 0;
}
