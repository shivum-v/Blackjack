#ifndef Textdisplay_H
#define Textdisplay_H
#include "observer.h"
#include "table.h"

class TextDisplay : public Observer {
        Table& table;
    public:
        TextDisplay(Table&);
        virtual void notify(bool, bool) override;
        ~TextDisplay();
};

#endif