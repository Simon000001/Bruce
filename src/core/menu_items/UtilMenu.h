#ifndef __UTIL_MENU_H__
#define __UTIL_MENU_H__

#include "MenuItemInterface.h"

class UtilMenu : public MenuItemInterface {
public:
    void optionsMenu(void);
    void draw(void);
    String getName(void);

private:
    String _name = "Util";
    void configMenu(void);
};

#endif