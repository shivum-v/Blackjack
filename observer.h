#ifndef Observer_H
#define Observer_H

class Observer {
    public:
        virtual void notify(bool, bool) = 0;
        virtual ~Observer();
};

#endif