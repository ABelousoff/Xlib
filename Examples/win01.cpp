#include<iostream>
#include<X11/Xlib.h>
#include<X11/Xutil.h>

int main(int argc, char **argv){
    Display *d;
    int screen;
    Window parent, w;
    Visual *visual;
    int depth;
    XSetWindowAttributes attr;
    XSizeHints sizeHints;
    XClassHint classHint;
    d = XOpenDisplay(NULL);
    if(d == NULL) {
        std::cout << "Error!" << std::endl;
        return 1;
    }
    /*Получаем дефолтные сведения*/
    screen = DefaultScreen(d);          //Экран по умолчанию
    parent = RootWindow(d, screen);     //Корневое окно
    depth = DefaultDepth(d, screen);    //Глубина цветности экрана
    visual = DefaultVisual(d, screen);  //Вызуальные характеристики
    /*Фон для окна верхнего уровня*/
    attr.background_pixel = WhitePixel(d, screen);
    /*Создаем окно*/
    w = XCreateWindow(
        d, parent, 100, 100, 900, 600,//CWBackPixel - цвет фона окна
        0, depth, InputOutput, visual, CWBackPixel, &attr
    );
    /*Заголовок окна*/
    XStoreName(d, w, "MYWindows");
    /*Заголовок иконок*/
    XSetIconName(d, w, "Icon");
    /*Ограничения на размеры окна*/
    sizeHints.flags = PMinSize | PMaxSize;
    sizeHints.min_width = 900;
    sizeHints.min_height = 600;
    sizeHints.max_width = 900;
    sizeHints.max_height = 600;
    XSetWMNormalHints(d, w, &sizeHints);
    /*Делаем окно видимым*/
    XMapWindow(d, w);
    XMoveWindow(d, w, 500, 200);
    //------------------- GC ----------------------
    XColor color;
    Colormap colormap = DefaultColormap(d, screen);
    GC gc = XCreateGC(d, w, 0, NULL);
    XGCValues values;


    XEvent e;
    XSelectInput(d, w, ButtonPressMask | ExposureMask);
    while(1){
        XNextEvent(d, &e);
        if(e.type == Expose){
            // Первый способ изменения цвета
            XParseColor(d, colormap, "rgb:7b/68/ee", &color);
            XAllocColor(d, colormap, &color);
            values.foreground = color.pixel;
            XChangeGC(d, gc, GCForeground, &values);       //Изменяет значения GC
            
            // Второй способ изменения цвета
            XParseColor(d, colormap, "rgb:f0/6e/8c", &color);
            XAllocColor(d, colormap, &color);
            XSetForeground(d, gc, color.pixel);
            XFillRectangle(d, w, gc, 100, 50, 600, 500);
        }
        if(e.xbutton.button == 3){//Выход из программы нажатием правой кнопкой мыши
            break;
        }
    }
    XDestroyWindow(d, w);
    XCloseDisplay(d);
    return 0;
}
