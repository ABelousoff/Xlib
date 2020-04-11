static void SetWindowManagerHints(
    Display *d, /*Указатель на структуру Display*/
    char *PClass,/*Класс программы*/
    char *argv[],/*Аргументы программы*/
    int argc,/*Число аргументов*/
    Window w,/*Идентификатор окна*/
    int x,/*Координаты левого верхнего*/
    int y,/*угла окна*/
    int win_wdt,/*Ширина  окна*/
    int win_hgt,/*Высота окна*/
    int win_wdt_min,/*Минимальная ширина окна*/
    int win_hgt_min,/*Минимальная высота окна*/
    char *ptrTitle,/*Заголовок окна*/
    char *ptrITitle,/*Заголовок пиктограммы окна*/
    Pixmap pixmap/*Рисунок пиктограммы*/
){
    XSizeHints size_hints;
    XWMHints wm_hints;
    XClassHint class_hint;
    XTextProperty w_name, i_name;
    if(
        !XStringListToTextProperty(&ptrITitle, 1, &w_name) ||
        !XStringListToTextProperty(&ptrITitle, 1, &i_name)
    )
    {
        std::cout << "No memory!" << std::endl;
        exit(1);
    }

    size_hints.flags = PPosition | PSize | PMinSize;
    size_hints.min_width = win_wdt_min;
    size_hints.min_height = win_hgt_min;
    wm_hints.flags = StateHint | IconPixmapHint | InputHint;
    wm_hints.initial_state = NormalState;
    wm_hints.input = True;
    wm_hints.icon_pixmap = pixmap;
    class_hint.res_name = argv[0];
    class_hint.res_class = PClass;

    XSetWMProperties(
        d, w, &w_name, &i_name, argv, argc, 
        &size_hints, &wm_hints, &class_hint
    );
}
