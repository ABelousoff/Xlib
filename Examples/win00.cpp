
#include<iostream>
#include<X11/Xlib.h>
#include<unistd.h>

int main(){
    Display *display;
    display = XOpenDisplay(NULL);

    if(display == NULL){
        std::cout << "Error XOpenDisplay" << std::endl;
        return 1;
    }
    /*
     * эта переменная будет использоваться для хранения 
     * экрана «по умолчанию» X-сервера. screen
     * обычно X-сервер имеет только один экран (screen), 
     * поэтому мы заинтересованы только в нем.
     */
    int screen_num;

    /* размер экрана в пикселях. */
    int screen_width;
    int screen_height;

    /* эта переменная будет использоваться для хранения 
     * идентификатора корневого окна нашего экрана. 
     * У каждого экрана всегда есть корневое окно, 
     * которое покрывает весь экран и всегда существует.
     */
    Window root_window;

    /*
     * Эти переменные будут использоваться для хранения 
     * идентификаторов черного и белого цветов данного экрана. 
     */
    unsigned long white_pixel;
    unsigned long black_pixel;

    /*
     * Получить экран, используемый по-умолчанию.
     */
    screen_num = DefaultScreen(display);

    /*
     * Получить ширину экрана по умолчанию нашего X-сервера 
     * в пикселях.
     */
    screen_width = DisplayWidth(display, screen_num);

    /*
     * Получить ширинувысату экрана по умолчанию нашего X-сервера 
     * в пикселях.
     */
    screen_height = DisplayHeight(display, screen_num);

    /*
     * идентификатор корневого окна экрана.
     */
    root_window = RootWindow(display, screen_num);

    /*
     * Белый цвет
     * Черный цвет
     */
    white_pixel = WhitePixel(display, screen_num);
    black_pixel = BlackPixel(display, screen_num);

    int win_x = 0;
    int win_y = 0;

    unsigned int win_width = screen_width;
    unsigned int win_height = screen_height;
    Window win = XCreateSimpleWindow(
        display, root_window, 
        win_y, win_y,
        win_width, win_height,
        0, black_pixel, white_pixel
    );
    XMapWindow(display, win);
    XFlush(display);
    sleep(10);
    XDestroyWindow(display, screen_num);
    XCloseDisplay(display);
    return 0;
}
