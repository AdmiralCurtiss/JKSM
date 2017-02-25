#include <array>
#include <string>

#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <sf2d.h>

#include "gstr.h"
#include "global.h"
#include "date.h"
#include "ui.h"

std::string GetString(const char *hint)
{
    hidScanInput();

    u32 held = hidKeysHeld();
    if(held & KEY_L)
        return GetDate(DateTimeFormat::FORMAT_YDM);
    else if(held & KEY_R)
        return GetDate(DateTimeFormat::FORMAT_YMD);

    SwkbdState keyState;
    char input[64];

    swkbdInit(&keyState, SWKBD_TYPE_NORMAL, 2, 64);
    swkbdSetHintText(&keyState, hint);
    swkbdSetFeatures(&keyState, SWKBD_PREDICTIVE_INPUT);
    std::array<SwkbdDictWord, static_cast<size_t>(DateTimeFormat::COUNT)> dates;
    for (size_t i = 0; i < dates.size(); ++i) {
        swkbdSetDictWord(&dates[i], "2016", GetDate(static_cast<DateTimeFormat>(i)));
    }
    swkbdSetInitialText(&keyState, GetDate(DateTimeFormat::FORMAT_YMD));
    swkbdSetDictionary(&keyState, &dates[0], static_cast<int>(dates.size()));

    swkbdInputText(&keyState, input, 64);

    return std::string(input);
}

int getInt(const char *hint, int init, int maxValue)
{
    SwkbdState keyState;
    char input[8];

    swkbdInit(&keyState, SWKBD_TYPE_NUMPAD, 2, 8);
    swkbdSetHintText(&keyState, hint);
    if(init != -1)
    {
        sprintf(input, "%i", init);
        swkbdSetInitialText(&keyState, input);
    }

    SwkbdButton pressed = swkbdInputText(&keyState, input, 8);
    int ret;
    //Cancel
    if(pressed == SWKBD_BUTTON_LEFT)
        ret = -1;
    else
    {
        ret = strtol(input, NULL, 10);
        if(ret > maxValue)
            ret = maxValue;
    }
    return ret;
}
