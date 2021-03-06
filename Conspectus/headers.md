## Файлы заголовков
> **<X11/Xlib.h>** Основной

> **<X11/X.h>** Этот файл объявляет типы и константы для протокола X, которые должны использоваться приложениями. Он включается автоматически из <X11 / Xlib.h>, **поэтому код приложения никогда не должен ссылаться на этот файл напрямую.**

> **<X11/Xcms.h>** Этот файл содержит символы для большинства средств управления цветом. Все функции, типы и символы с префиксом «Xcms» плюс макросы контекста преобразования цвета объявлены в этом файле.**<X11 / Xlib.h> должен быть включен до включения этого файла.**

> **<X11/Xutil.h>** В этом файле объявляются различные функции, типы и символы, используемые для взаимодействия между клиентами и служебных функций приложения. **<X11 / Xlib.h> должен быть включен до включения этого файла.**

> **<X11/Xresource.h>** Этот файл объявляет все функции, типы и символы для средств менеджера ресурсов. **<X11 / Xlib.h> должен быть включен до включения этого файла.**

> **<X11/Xatom.h>** Этот файл объявляет все предопределенные атомы, которые являются символами с префиксом «XA_».

> **<X11/cursorfont.h>** Этот файл объявляет символы курсора для стандартного шрифта курсора. Все символы курсора имеют префикс "XC_".

> **<X11/keysymdef.h>** Этот файл объявляет все стандартные значения KeySym, которые являются символами с префиксом «XK_». KeySyms расположены в группах, и символ препроцессора управляет включением каждой группы. Символ препроцессора должен быть определен до включения файла для получения связанных значений. Символы препроцессора являются **XK_MISCELLANY, XK_XKB_KEYS, XK_3270, XK_LATIN1, XK_LATIN2, XK_LATIN3, XK_LATIN4, XK_KATAKANA, XK_ARABIC, XK_CYRILLIC, XK_GREEK, XK_TECHNICAL, XK_SPECIAL, XK_PUBLISHING, XK_APL, XK_HEBREW, XK_THAI** и **XK_KOREAN**.

> **<X11/keysym.h>** Этот файл определяет символы препроцессора **XK_MISCELLANY, XK_XKB_KEYS, XK_LATIN1, XK_LATIN2, XK_LATIN3, XK_LATIN4** и **XK_GREEK**, а затем включает в себя **<X11 / keysymdef.h>**.

> **<X11/Xlibint.h>** Этот файл автоматически включает в себя **<X11 / Xlib.h>**.

> **<X11/Xproto.h>** Этот файл объявляет типы и символы для базового протокола X для использования при реализации расширений. Он включается автоматически из **<X11 / Xlibint.h>**, поэтому приложению и коду расширения никогда не нужно напрямую ссылаться на этот файл.

> **<X11/Xprotostr.h>** Этот файл объявляет типы и символы для базового протокола X для использования при реализации расширений. Он включается автоматически из **<X11 / Xlibint.h>**, поэтому приложению и коду расширения никогда не нужно напрямую ссылаться на этот файл.

> **<X11/X10.h>** Этот файл объявляет все функции, типы и символы, используемые для функций совместимости X10
