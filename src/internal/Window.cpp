#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window {
private:
    int width;
    int height;
    const char *title;
    GLFWwindow *window;

    bool init(){
        // Inizializzazione di GLFW
        if (!glfwInit())
        {
            // Inizializzazione di GLFW fallita
            std::cerr << "Error: Failed to initialize GLFW" << std::endl;
            return false;
        }

        // Inizializzazione di GLEW
        GLenum glewError = glewInit();
        if (glewError != GLEW_OK)
        {
            // Inizializzazione di GLEW fallita
            std::cerr << "Error: Failed to initialize GLEW" << std::endl;
            return false;
        }
        return true;
    }
public:
    Window(){
        if (!init()){
            // La GLFW o la GLEW non sono state inizializzate correttamente
            std::cerr << "Error: Unable to initialize OpenGL Libs" << std::endl;
            return;
        }
    }

    ~Window() {
        glfwTerminate();
    }

    bool create(int w, int h, const char *t) {
        setWidth(w);
        setHeight(h);
        setTitle(t);

        window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        if(!window) {
            // Creazione della finestra OpenGL fallita
            std::cerr << "Error: Failed to create the OpenGL window" << std::endl;
            return false;
        }
        glfwMakeContextCurrent(window);
        return true;
    }

    bool isOpen() {
        // Chiamiamo swapBuffers() per aggiornare la visualizzazione
        glfwSwapBuffers(window);
        // Chiamiamo glfwPollEvents() per gestire gli eventi
        glfwPollEvents();

        return !glfwWindowShouldClose(window);
    }

    // Setter per larghezza
    void setWidth(int newWidth) {
        width = newWidth;
    }

    // Getter per larghezza
    int getWidth() const {
        return width;
    }

    // Setter per altezza
    void setHeight(int newHeight) {
        height = newHeight;
    }

    // Getter per altezza
    int getHeight() const {
        return height;
    }

    // Setter per il titolo
    void setTitle(const char *newTitle) {
        title = newTitle;
    }

    // Getter per il titolo
    const char *getTitle() const {
        return title;
    }
};

/*
int main() {
    Window window(800, 600, "OpenGL Window");

    while (window.isOpen()) {
        // Logic and rendering here
    }

    return 0;
}
*/