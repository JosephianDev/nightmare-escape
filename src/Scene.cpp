#ifndef SCENE
#define SCENE

class Scene {
public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void input() = 0;
    virtual void render() = 0;
    virtual void cleanup() = 0;
};

#endif