#ifndef __MYAPPS_MENU_H__
#define __MYAPPS_MENU_H__

#include "MenuItemInterface.h"


class MyAppsMenu : public MenuItemInterface {
public:
    void optionsMenu(void);
    void draw(void);
    String getName(void);

private:
    String _name = "MyApps";
    void configMenu(void);
};

#endif