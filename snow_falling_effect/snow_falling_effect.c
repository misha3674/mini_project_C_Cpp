#include "snow_falling_effect.h"
#include <GL/gl.h>
#include "glfw/include/glfw3.h"
//------------------------------------------------------------------------------
#define SCREEN_WIDTH        800
#define SCREEN_HEIGHT       600
#define IS_FULL_SCREEN      0
//------------------------------------------------------------------------------
GLFWwindow* window;
int    scr_width     = 0;
int    scr_height    = 0;
float  w_ratio       = 0.f;
float  h_ratio       = 0.f;
//------------------------------------------------------------------------------
void resize_clb     (GLFWwindow*, int, int);
void key_click_clb  (GLFWwindow*, int, int, int, int);
void mouse_click_clb(GLFWwindow*, int, int, int);
//------------------------------------------------------------------------------
int gl_init()
{
    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              "snow",
                              IS_FULL_SCREEN ? glfwGetPrimaryMonitor() : NULL,
                              NULL);

    glfwSetWindowPos(window,0,20);

    glfwGetWindowSize(window, &scr_width, &scr_height);
    w_ratio = (float)scr_width  / (float)SCREEN_WIDTH;
    h_ratio = (float)scr_height / (float)SCREEN_HEIGHT;

    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback        (window, key_click_clb);
    glfwSetWindowSizeCallback (window, resize_clb);
    glfwSetMouseButtonCallback(window, mouse_click_clb);


    glViewport(0, 0, (GLsizei)SCREEN_WIDTH, (GLsizei)SCREEN_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 1);
    glfwSwapInterval(1);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POINT_SMOOTH);

    return 1;
}
void snow_falling()
{
    if(gl_init() == -1)
        return;
    glClearColor(0.1,0.4,0.8,0);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();


        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();
}

//------------------------------------------------------------------------------
void resize_clb(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    glfwGetWindowSize(window, &scr_width, &scr_height);
    w_ratio = (float)scr_width  / (float)SCREEN_WIDTH;
    h_ratio = (float)scr_height / (float)SCREEN_HEIGHT;
}
//------------------------------------------------------------------------------
void key_click_clb(GLFWwindow *pWindow, int aKey, int aScanCode, int aAction, int aMods)
{
    if(aKey == GLFW_KEY_ESCAPE && aAction == GLFW_PRESS)
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
}
//------------------------------------------------------------------------------
void mouse_click_clb(GLFWwindow *pWindow, int aBtn, int aAction, int aMods)
{
    if(aBtn == GLFW_MOUSE_BUTTON_1)
    {
        switch(aAction)
        {
            case GLFW_PRESS:
            {
                break;
            }
        }
    }
}
//------------------------------------------------------------------------------
