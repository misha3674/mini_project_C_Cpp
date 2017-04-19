#include "snow_falling_effect.h"
#include <stdio.h>
#include <GL/gl.h>
#include "glfw/include/glfw3.h"
//------------------------------------------------------------------------------
#define SCREEN_WIDTH        800
#define SCREEN_HEIGHT       600
#define IS_FULL_SCREEN      0
#define FLAKE               1
//------------------------------------------------------------------------------
GLFWwindow* window;
int    scr_width     = 0;
int    scr_height    = 0;
float  w_ratio       = 0.f;
float  h_ratio       = 0.f;
GLuint scra[SCREEN_WIDTH][SCREEN_HEIGHT] = {{0}};
//------------------------------------------------------------------------------
void resize_clb     (GLFWwindow*, int, int);
void key_click_clb  (GLFWwindow*, int, int, int, int);
void mouse_click_clb(GLFWwindow*, int, int, int);
//------------------------------------------------------------------------------
void processing_snow(int);
void draw_snow();
void setFlake(int x, int y);
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
    unsigned flake_on_line = 3;
    glClearColor(0.1,0.4,0.8,0);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        processing_snow(flake_on_line);
        draw_snow();
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
void processing_snow(int flake_on_line)
{
    int dx = 0;
    int dy = 0;
    static int isWind = 0;
    static int wave = 0;
    if(rand()%800 == 12)
        isWind = 1;
    if(isWind)
    {
        wave++;
        // when wave of wind went to end screen, to need stop wind
        if(wave > (int)(SCREEN_WIDTH*0.25))
        {
            wave = 0;
            isWind = 0;
        }
    }
    for(int i = 0; i < flake_on_line; i++)
    {
        setFlake(rand()%SCREEN_WIDTH,0);
    }
    for(int j = SCREEN_HEIGHT - 1; j>=0; j--)
    {
        for(int i = 0; i < SCREEN_WIDTH; i++)
        {
            if(scra[i][j] == FLAKE)
            {
                scra[i][j] = 0;
                dx = 0;
                dy = 0;
                if(isWind)
                {

                    // evenly blow wind
                    // each iteration wave +1
                    if(i < wave)
                    {
                        dx = (rand() % 2) ? 1 : -1;
                        dy = 1;
                    }
                    else
                    {
                        dx = -1;
                        dy = (rand() % 2) ? 1 : -1;
                    }
                }
                else
                {
                    dx = (rand() % 2) ? 1 : -1;
                    dy = 1;
                }
                setFlake(i+dx,j+dy);
            }
        }
    }
}
//------------------------------------------------------------------------------
void draw_snow()
{
    glColor3ub(254,254,254);
    glPointSize(2);
    glBegin(GL_POINTS);
        for(int j = SCREEN_HEIGHT - 1; j>=0; j--)
        {
            for(int i = 0; i < SCREEN_WIDTH; i++)
            {
                if(scra[i][j] == FLAKE)
                {
                    glVertex2i(i,j);
                }
            }
        }
    glEnd();
}
void setFlake(int x, int y)
{
    unsigned int isOkX = 0;
    unsigned int isOkY = 0;
    isOkX = ((x >=0) && (x<SCREEN_WIDTH));
    isOkY = ((y >=0) && (y<SCREEN_HEIGHT));
    if(isOkX && isOkY)
        scra[x][y] = FLAKE;
    //else
     //   printf("outside\n");
}
