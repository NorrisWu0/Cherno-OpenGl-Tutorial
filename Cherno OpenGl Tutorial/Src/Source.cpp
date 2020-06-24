#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <Utilities/Debug.h>

GLFWwindow* window;

int main(void)
{
    #pragma region Initialize GLFW
    /* Initialize the library */
    if (!glfwInit())
    {
        Debug::LogError("Faile to initialize GLFW!!!", "Setup");
        return -1;
    }
    else
        Debug::LogInfo("GLFW has been initialized successfully.", "Setup");

    #pragma endregion

    #pragma region Create Window
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(900, 900, "Hello World", NULL, NULL);

    if (!window)
    {
        Debug::LogError("Faile to create a window!!!", "Setup");        
        glfwTerminate(); 
        return -1;
    }
    else
        Debug::LogInfo("Window has been initialized successfully.", "Setup");


    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    #pragma endregion

    #pragma region Initialize GLEW
    /* GLEW can only be initialized after a context has been created*/
    if (glewInit() != GLEW_OK)
    {
        Debug::LogError("Faile to initialize GLEW!!!", "Setup");
        return -1;
    }
    else
        Debug::LogInfo("GLEW has been initialized successfully.", "Setup");

    Debug::LogInfo((char*)glGetString(GL_VERSION), "OpenGL Verion");
    #pragma endregion

    #pragma region The Update Loop
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        #pragma region Testing
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, 0.0f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.f, 1.0f);
        glEnd();
        #pragma endregion

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    #pragma endregion

    glfwTerminate();
    return 0;
}