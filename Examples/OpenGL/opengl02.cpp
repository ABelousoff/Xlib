#include<X11/Xlib.h>
#include<X11/Xutil.h>
#include<X11/Xos.h>
#include<X11/Xatom.h>
/* GLX headers */
#include<GL/gl.h>
#include<GL/glx.h>
#include<GL/glu.h>

Display *d;
Window w;
XWindowAttributes winattr;

void DrawTriangle(void){
    //-- void DrawTriangle(void);
    static int angle;
    XGetWindowAttributes(d, w, &winattr);
    glViewport(0, 0, winattr.width, winattr.height);
    
    glClearColor(0.3f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0f, 0.3f, 0.0f);

    glPushMatrix();
    glRotatef(angle, 0.0, 1.0, 1.0);

    glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-0.5f, 0.5f, 0.0f);
        glVertex3f(0.5f, 0.5f, 0.0f);
    glEnd();

    glPopMatrix();

    glXSwapBuffers(d, w);
    //--
    usleep(1000);
    angle += 1;
}

int main(int argc, char **argv){
    d = XOpenDisplay(NULL);
    int screen = DefaultScreen(d);
    Window root = RootWindow(d, screen);

    XSetWindowAttributes attr;

    unsigned int depth = DefaultDepth(d, screen);
    XEvent e;

    /* GLX vars*/
    GLint att[] = {GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None};
    XVisualInfo *visual = glXChooseVisual(d, screen, att);
    GLXContext glc = glXCreateContext(d, visual, NULL, GL_TRUE);
    /*----------------*/

    attr.border_pixel = BlackPixel(d, screen);
    attr.background_pixel = WhitePixel(d, screen);
    attr.override_redirect = True;
    /*attr.colormap = CopyFromParent;*/
    attr.colormap = XCreateColormap(d, root, visual->visual, AllocNone);
    attr.event_mask = ExposureMask | KeyPressMask;

    w = XCreateWindow(
        d, root, 200, 200, 900, 700,
        0, visual->depth, InputOutput, visual->visual,
        CWBackPixel | CWColormap | CWBorderPixel | CWEventMask,
        &attr
    );
    XMapWindow(d, w);

    glXMakeCurrent(d, w, glc);
    glEnable(GL_DEPTH_TEST);

    while (1)
    {
        if(XPending(d) == 0){
            DrawTriangle();
            continue;
        }
        XNextEvent(d, &e);
        if(e.type == Expose){

        }
        if(e.type == KeyPress){
            break;
        }
    }
    XDestroyWindow(d, w);
    XCloseDisplay(d);
    return 0;
}
