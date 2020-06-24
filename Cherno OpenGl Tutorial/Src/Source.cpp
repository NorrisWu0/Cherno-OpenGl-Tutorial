#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <Utilities/Debug.h>

GLFWwindow* window;

int main(void)
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(900, 900, "Hello World", NULL, NULL);

    if (!window)
    {
        glfwTerminate(); 
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    #pragma region Initialize GLEW
    /* GLEW can only be initialized after a context has been created*/
    if (glewInit() != GLEW_OK)
    {
        Debug::LogError("Faile to initialize GLEW!!!");
        return -1;
    }
    #pragma endregion

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

    glfwTerminate();
    return 0;
}